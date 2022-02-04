/**
 * Copyright [year] <Copyright Owner>
 * This is file for implementataion for player class.
 * Player class contains common attribute and function for player.
 *
 */
#include"player.h"
#include<string>

/*Constructor to initialize members of class Player */
Player::Player()
{
	matches = age = 0;
	name = "";
	type = "";
    // snprintf(sizeof(name), name, "%s", " ");
}
/*function to show the common attribute of Palyer*/
inline void Player::Show_info()
{
	cout << "\nType of Player:" << type;
    cout << "\nName of Player:" << name;
    cout << "\nMatches       :" << matches;
    cout << "\nAge           :" << age;
}
/* function to read the common attribute of Palyer*/
inline void Player::Get_info()
{
	cout << "\nEnter the name of player:";
	cin >> name;
	cout << "\nenter number of matches:";
	cin >> matches;
	cout << "\nEnter Age of player:";
	cin >> age;
}
