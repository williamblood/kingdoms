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

// addCandidate
void CandidateList::addCandidate(const CandidateType& candidate)
{
	Node* temp = new Node(candidate, nullptr);

	if (count == 0)
	{
		last = temp;
		first = temp;
	}
	else if (count > 0)
	{
		last->setLink(temp);
		last = last->getLink();
	}

	++count;
}

// getWinner
int CandidateList::getWinner() const
{
	if (count == 0)
	{
		cerr << "    => List is empty.";
		return 0;
	}
	else
	{
		Node* temp = first;
		int idStore{ 0 }, 
			top{ 0 };

		while (temp != nullptr)
		{
			const int VOTE_COUNT = 
				temp->getCandidate().getTotalVotes();

			if (VOTE_COUNT > top)
			{
				top = VOTE_COUNT;
				idStore = temp->getCandidate().getID();
			}
			temp = temp->getLink();
		}

		return idStore;
	}
}

// isEmpty
bool CandidateList::isEmpty() const
{
	return (count == 0);
}

// searchCandidate(public)
bool CandidateList::searchCandidate(int id) const
{
	Node* temp = nullptr;
	return searchCandidate(id, temp);
}

// printCandidateName
void CandidateList::printCandidateName(int id) const
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{
		temp->getCandidate().printName();
	}
}

// printAllCandidates
void CandidateList::printAllCandidates() const
{
	if (count == 0)
	{
		cerr << "    => List is empty.";
	}
	else
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			temp->getCandidate().printCandidateInfo();
			cout << endl;
			temp = temp->getLink();
		}
	}
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int id, int index) const
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{
		cout << "    *" << right << setw(3)
			<< temp->getCandidate().getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int id) const
{
	Node* temp = nullptr;
	if (searchCandidate(id, temp))
	{			
		cout << "    => Total votes: "
			<< temp->getCandidate().getTotalVotes() << endl;
	}
}

// printFinalResults
void CandidateList::printFinalResults() const
{
	if (first == nullptr)
	{
		cerr << "    => List is empty.";
	}
	else
	{
		cout << string(12, '*') << " FINAL RESULTS "
			<< string(12, '*') << "\n\n";

		cout << left << setw(15) << "LAST" 
			<< left << setw(10) << "FIRST" 
			<< right << setw(5) << "TOTAL"
			<< right << setw(7) << "POS" << endl;

		cout << left << setw(15) << "NAME"
			<< left << setw(10) << "NAME"
			<< right << setw(5) << "VOTES"
			<< right << setw(7) << "#" << endl;

		cout << string(40, '_') << "\n\n";

		Node* winner = first;
		int prevHighestVoteCount = 0;

		while (winner != nullptr)
		{
			const int PREV_VOTE_COUNT =
				winner->getCandidate().getTotalVotes();
		
			if (PREV_VOTE_COUNT > prevHighestVoteCount)
			{
				prevHighestVoteCount = PREV_VOTE_COUNT;
			}
			winner = winner->getLink();
		}
		
		++prevHighestVoteCount;
		
		for (int pos = 1; pos <= count; ++pos)
		{
			Node* temp = first;
			int highestVoteCount = 0;
		
			while (temp != nullptr)
			{
				const int TEMP_VOTES =
					temp->getCandidate().getTotalVotes();
		
				if (TEMP_VOTES > highestVoteCount - 1 &&
					TEMP_VOTES < prevHighestVoteCount)
				{
					highestVoteCount = TEMP_VOTES;
					winner = temp;
				}
				temp = temp->getLink();
			}
			prevHighestVoteCount = highestVoteCount;
			
			
			cout << left << setw(15) 
				<< winner->getCandidate().getLastName()
				<< left << setw(10) 
				<< winner->getCandidate().getFirstName()
				<< right << setw(5) << highestVoteCount
				<< right << setw(7) << pos << endl;
				
			if (pos % 5 == 0)
			{
				cout << string(40, '-') << "\n";
			}
		}
		cout << string(40, '_') << endl;
	}
}

// clearList
void CandidateList::clearList()
{
	Node* temp = first;
	while (temp != nullptr)
	{
		temp = temp->getLink();
		delete first;
		first = temp;
	}

	count = 0;
	first = nullptr;
	last = nullptr;
}

// Destructor
CandidateList::~CandidateList()
{
	clearList();
}

//searchCandidate(private)
bool CandidateList::searchCandidate(int id, Node*& ptr) const
{
	if (count == 0)
	{
		cerr << "    => List is empty." << endl;
	}
	else
	{
		ptr = first;
		while (ptr != nullptr)
		{
			if (ptr->getCandidate().getID() == id)
			{
				return true;
			}
			ptr = ptr->getLink();
		}
		if (ptr == nullptr)
		{
			cerr << "    => ID not in the list." << endl;
		}
	}
	return false;
}
