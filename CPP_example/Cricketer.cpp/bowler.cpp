/**
 * opyright [year] <Copyright Owner>
 * This is file for implementataion for Bowler class.
 * Bowler class contains attribute and function for Bowler.
 *
 */

#include"bowler.h"
#include<string>
#include<sstream>
/*call Players's constructor to initialize common attribute of Player*/
Bowler::Bowler():Player()
{
	over = bavg = brun = wicket = economy = half = 0;
}
/*function to show the common as well as attribute bowler*/
inline void Bowler::serialize()
{
	fstream fp;
	std::string Details_player;
	std::stringstream Details;
	fp.open("data.csv", std::ios::app);
	if (fp.is_open() && (fp))
	{
		Details << type << ",";
		Details << name << ",";
		Details << matches << ",";
		Details << age << ",";
		Details << wicket << ",";
		Details << brun << ",";
		Details << bavg << ",";
		Details << half << ",";
		Details << over << ",";
		Details >> Details_player;
		fp << Details_player;
		fp << "\n";
	}
	else
	{
		cout << "\n Error";
	}
	fp.close();
}

inline void Bowler::deserialize(std::stringstream &Details)
{
	string temp = "";
	std::getline(Details, temp, ',');
	type = temp;
	temp = "";
	std::getline(Details, temp, ',');
	name = temp;
	temp = "";
	std::getline(Details, temp, ',');
	matches = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	age = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	wicket = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	brun = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	bavg = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	half = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	over = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	economy = stoi(temp);
}

inline void Bowler::Show_info()
{
	Player::Show_info();
	cout << "\nAverage       :" << bavg;
	cout << "\nWicket        :" << wicket;
	cout << "\neconomy       :" << economy;
	cout << "\n5-wickets     :" << half;
	cout << "\n\n";
}
/*function to read the common as well as attribute bowler*/
inline void Bowler::Get_info()
{
	Player::Get_info();
	type = "Bowler";
	cout << "\nEnter total of wicket he got :";
	cin >> wicket;
	cout << "\nEnter total runs he gave :";
	cin >> brun;
	if (wicket == 0)
	{
		bavg = 0;
	}
	else
	{
		bavg = brun / wicket;
	}
	cout << "\nHow many times he got 5 wicket :";
	cin >> half;
	cout << "\nHow many over he bowld:";
	cin >> over;
	/*compute the economy of bowler*/
	economy = brun / over;
}
