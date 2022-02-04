/*
 *Copyright [year] <Copyright Owner>
 * This is header file for player class.
 * Player class contains common attribute and function for player.
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<memory>
using std::string;
using std::cout;
using std::cin;
using std::fstream;
/*Player is base class */
class Player
{
public:
	int matches, age;
	string name, type;
	Player();
	virtual void serialize() = 0;
	virtual void deserialize(std::stringstream&) = 0;
	virtual void Show_info();
	virtual void Get_info();
};
#endif  // PLAYER_H_
