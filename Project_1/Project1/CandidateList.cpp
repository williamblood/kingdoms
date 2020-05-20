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
		cerr << "    => List is empty." << endl;
		return 0;
	}
	else
	{
		Node* temp = first;
		int idStore = 0, 
			top = 0;

		while (temp != nullptr)
		{
			int voteCount = 
				temp->getCandidate().getTotalVotes();

			if (voteCount > top)
			{
				top = voteCount;
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
		cerr << "    => List is empty." << endl;
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
		cerr << "    => List is empty." << endl;
	}
	else
	{
		printHeader();

		Node* winner = first;
		int prevHighestVoteCount = 0;

		while (winner != nullptr)
		{
			int prevVoteCount =
				winner->getCandidate().getTotalVotes();
		
			if (prevVoteCount > prevHighestVoteCount)
			{
				prevHighestVoteCount = prevVoteCount;
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
				int tempVotes =
					temp->getCandidate().getTotalVotes();
				
				if (tempVotes > highestVoteCount - 1 &&
					tempVotes < prevHighestVoteCount)
				{
					highestVoteCount = tempVotes;
					winner = temp;
				}
				temp = temp->getLink();
			}
			prevHighestVoteCount = highestVoteCount;
			
			printCandidate(pos, winner);
		}
		cout << string(40, '_') << endl;	// Footer delimiter
	}
}

// clearList
void CandidateList::clearList()
{
	Node* temp = first;
	while (first != nullptr)
	{
		first = first->getLink();
		delete temp;
		temp = first;
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

// searchCandidate(private)
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

// printHeader
void CandidateList::printHeader() const
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

	cout << string(40, '_') << "\n\n";	// Header delimiter
}

// printCandidate
void CandidateList::printCandidate(int pos, Node*& ptr) const
{
	cout << left << setw(15)
		<< ptr->getCandidate().getLastName()
		<< left << setw(10)
		<< ptr->getCandidate().getFirstName()
		<< right << setw(5)
		<< ptr->getCandidate().getTotalVotes()
		<< right << setw(7) << pos << endl;

	// Prints dashed separator line after every 5th position
	if (pos % 5 == 0)
	{
		cout << string(40, '-') << "\n";
	}
}