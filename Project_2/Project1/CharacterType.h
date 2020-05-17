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

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType() : id(0) {};
	// Overloaded constructor
	CharacterType(const std::string& newFirst,
		const std::string& newLast, int newId);

	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirst,
		const std::string& newLast, int newId);

	// getFirstName
	std::string getFirstName() const;
	// getLastName
	std::string getLastName() const;
	// getID
	int getID() const;

	// printName
	void printName() const;
	// printCharacterInfo
	void printCharacterInfo() const;
	// printID
	void printID() const;

	// Destructor
	~CharacterType();
private:
	std::string firstName;
	std::string lastName;
	int id;
};

#endif