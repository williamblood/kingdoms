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

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

// Overloaded constructor
CharacterType::CharacterType(const string& newFirst,
    const string& newLast, int newId)
{
    firstName = newFirst;
    lastName = newLast;
    id = newId;
}

// setCharacterInfo
void CharacterType::setCharacterInfo(const string& newFirst,
    const string& newLast, int newId)
{
    firstName = newFirst;
    lastName = newLast;
    id = newId;
}

// getFirstName
string CharacterType::getFirstName() const
{
    return firstName;
}

// getLastName
string CharacterType::getLastName() const
{
    return lastName;
}

// getID
int CharacterType::CharacterType::getID() const
{
    return id;
}

// printName
void CharacterType::printName() const
{
    cout << lastName << ", " << firstName;
}

// printCharacterInfo
void CharacterType::printCharacterInfo() const
{
    printID();
    cout << " " << firstName << " " << lastName;
}

// printID
void CharacterType::printID() const
{
    cout << "ID# " << id;
}

// Destructor
CharacterType::~CharacterType()
{ }