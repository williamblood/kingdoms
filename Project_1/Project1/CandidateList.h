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

class Node
{
public:
	Node() : link(nullptr) {}
	Node(const CandidateType& newCandidate, Node* theLink)
		: candidate(newCandidate), link(theLink) {}
	Node* getLink() const { return link; }
	CandidateType getCandidate() const { return candidate; }
	void setCandidate(const CandidateType& newCandidate)
	{
		candidate = newCandidate;
	}
	void setLink(Node* theLink) { link = theLink; }
	~Node() {}
private:
	CandidateType candidate;
	Node* link;		//pointer that points to next node
};

class CandidateList
{
public:
	// Default constructor
	CandidateList() : count{ 0 }, first(nullptr), last(nullptr) {};

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

	// clearList
	void clearList();
	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int id, Node*& ptr) const;
	// printCandidate
	void printCandidate(int pos, Node*& ptr) const;
	// printHeader
	void printHeader() const;

	Node* first; 	// pointer to the first candidate in the list
	Node* last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};

#endif