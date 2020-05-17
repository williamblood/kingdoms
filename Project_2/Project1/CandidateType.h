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

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne"
};

class CandidateType : public CharacterType
{
public:
	//overloaded equals
	bool operator==(int) const;

	// Default constructor
	CandidateType();
	// Copy constructor
	CandidateType(const CandidateType& other);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType& other);

	// updateVotesByKingdom
	void updateVotesByKingdom(int index, int numOfVotes);

	// getTotalVotes
	int getTotalVotes() const;
	// getVotesByKingdom
	int getVotesByKingdom(int index) const;

	// printCandidateInfo
	void printCandidateInfo() const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes() const;

	// Destructor
	~CandidateType();

private:
	int totalVotes;
	int numOfKingdoms;
	int* kingdomVotes;
};

#endif