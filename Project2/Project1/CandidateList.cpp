/*
	KaibaCorp
	Bearden, Reese (TTh 6:30)
	Blood, William (TTh 6:30)
	Diep, Vincent (TTh 2:20)
	Huynh, Andy (TTh 6:30)
	Nguyen, Andrew (MW 11:10)

	May 12, 2020

	CS A250
	Project 1 - Part D
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

// friend function overloaded ==
bool operator==(const CandidateType& obj, int id)
{
	return obj.getID() == id;
}

// constructor
CandidateList::CandidateList()
{
}

// addCandidate
void CandidateList::addCandidate(const CandidateType& candidate)
{
	candidates.push_back(candidate); 
}

// getWinner
int CandidateList::getWinner() const
{
	auto iter = candidates.cbegin();
	auto iterEnd = candidates.cend();
	
	int idStore{ 0 },	// should we do idStore = 0,
		top{ 0 };		// and top = 0; for consistency?
						// since we got a (-1) for one of our thingies being = { 0 };
	for (iter; iter != iterEnd; ++iter)
	{
		if (iter->getTotalVotes() > top)
		{
			top = iter->getTotalVotes();
			idStore = iter->getID();
		}
	}
	return idStore;	
}

// isEmpty
bool CandidateList::isEmpty() const
{
	return candidates.empty(); 
}

// searchCandidate(public)
bool CandidateList::searchCandidate(int id) const
{
	auto iter = candidates.cbegin();
	return searchCandidate(id, iter); 
}

// printCandidateName
void CandidateList::printCandidateName(int id) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{
		iter->printName();
	}
}

// printAllCandidates
void CandidateList::printAllCandidates() const
{
	auto iter = candidates.cbegin();
	auto iterEnd = candidates.end();
	for(iter; iter != iterEnd; ++iter)
	{
		iter->printCandidateInfo();
		std::cout << endl;
	}
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int id, int index) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{
		std::cout << "    *" << right << setw(3)
			<< iter->getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int id) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{			
		std::cout << "    => Total votes: "
			<< iter->getTotalVotes() << endl;
	}
}

// printFinalResults
void CandidateList::printFinalResults() const
{
	std::cout << string(12, '*') << " FINAL RESULTS "
		<< string(12, '*') << "\n\n";

	std::cout << left << setw(15) << "LAST" 
		<< left << setw(10) << "FIRST" 
		<< right << setw(5) << "TOTAL"
		<< right << setw(7) << "POS" << endl;

	std::cout << left << setw(15) << "NAME"
		<< left << setw(10) << "NAME"
		<< right << setw(5) << "VOTES"
		<< right << setw(7) << "#" << endl;

	std::cout << string(40, '_') << "\n\n";

	auto winner = candidates.cbegin();
	auto iterEnd = candidates.cend();
	int prevHighestVoteCount = 0;

	for(winner; winner != iterEnd; ++winner)
	{
		const int PREV_VOTE_COUNT =
			winner->getTotalVotes();
	
		if (PREV_VOTE_COUNT > prevHighestVoteCount)
		{
			prevHighestVoteCount = PREV_VOTE_COUNT;
		}
	}
	
	++prevHighestVoteCount;

	size_t candidateCount = candidates.size();

	for (size_t pos = 1; pos <= candidateCount; ++pos)
	{
		auto iter = candidates.cbegin();
		int highestVoteCount = 0;
	
		for(iter; iter != iterEnd ; ++iter)
		{
			const int TEMP_VOTES =
				iter->getTotalVotes();
	
			if (TEMP_VOTES > highestVoteCount - 1 &&
				TEMP_VOTES < prevHighestVoteCount)
			{
				highestVoteCount = TEMP_VOTES;
				winner = iter;
			}
		}
		prevHighestVoteCount = highestVoteCount;
		
		
		std::cout << left << setw(15) 
			<< winner->getLastName()
			<< left << setw(10) 
			<< winner->getFirstName()
			<< right << setw(5) << highestVoteCount
			<< right << setw(7) << pos << endl;
			
		if (pos % 5 == 0)
		{
			std::cout << string(40, '-') << "\n";
		}
	}
	std::cout << string(40, '_') << endl;
	
}

// Destructor
CandidateList::~CandidateList()
{
}

//searchCandidate(private)
bool CandidateList::searchCandidate(int id, 
	list<CandidateType>::const_iterator& itr) const
{
	itr = find(itr, candidates.cend(), id);
	return (itr != candidates.cend());
}
