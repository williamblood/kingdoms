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

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>

class CandidateList
{
public:

	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;
	// searchCandidate
	bool searchCandidate(int id) const;

	// printCandidateName
	void printCandidateName(int id) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int id, int index) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int id) const;

	// printFinalResults
	void printFinalResults() const;
	// Destructor
	~CandidateList();

	

private:
	// searchCandidate
	bool searchCandidate(int id, std::list<CandidateType>::const_iterator& itr) const;

	std::list<CandidateType> candidates;
};

#endif