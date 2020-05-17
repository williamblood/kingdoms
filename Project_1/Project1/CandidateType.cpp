/*
	KaibaCorp
	Bearden, Reese (TTh 6:30)
	Blood, William (TTh 6:30)
	Diep, Vincent (TTh 2:20)
	Huynh, Andy (TTh 6:30)
	Nguyen, Andrew (MW 11:10)

	May 12, 2020

	CS A250
	Project 2
*/

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

// Default constructor
CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {0};
}

// Copy constructor
CandidateType::CandidateType(const CandidateType& other)
	: CharacterType(other.getFirstName(), other.getLastName(),
		other.getID())
{
	totalVotes = other.totalVotes;
	numOfKingdoms = other.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];

	for (int i = 0; i < numOfKingdoms; ++i)
	{
		kingdomVotes[i] = other.kingdomVotes[i];
	}
}

// Copy assignment operator
CandidateType& CandidateType::operator=(const CandidateType& other)
{
	if (&other == this)
	{
		cerr << "Attempted self-assignment.";
	}
	else
	{
		setCharacterInfo(other.getFirstName(),
			other.getLastName(), other.getID());

		if (numOfKingdoms != other.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[other.numOfKingdoms];
		}

		numOfKingdoms = other.numOfKingdoms;
		totalVotes = other.totalVotes;

		for (int i = 0; i < numOfKingdoms; ++i)
		{
			kingdomVotes[i] = other.kingdomVotes[i];
		}
	}

	return *this;
}

// updateVotesByKingdom
void CandidateType::updateVotesByKingdom(int index, int numOfVotes)
{
	totalVotes += numOfVotes;
	kingdomVotes[index] += numOfVotes;
}

// getTotalVotes
int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

// getVotesByKingdom
int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

// printCandidateInfo
void CandidateType::printCandidateInfo() const
{
	printID();
	cout << " - ";
	printName();
}

// printCandidateTotalVotes
void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << endl << "=> Total Votes (all kingdoms): " << totalVotes;
}

// Destructor
CandidateType::~CandidateType()
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}