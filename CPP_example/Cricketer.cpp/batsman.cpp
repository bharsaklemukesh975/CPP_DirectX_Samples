/**
 * Copyright [year] <Copyright Owner>
 * This is file for implementataion for Batsman class.
 * Batsman class contains attribute and function for Batsman.
 *
 */
#include <string>
#include<sstream>
#include"batsman.h"
/*constructor to initialize  attribute of batsman*/
Batsman::Batsman():Player()
{
	avg = run = century = out = halfcen = 0;
}
inline void Batsman::serialize()
{ 
	fstream fp;
	std::string Details_player;
	std::stringstream Details;
	Details.clear();
	fp.open("data.csv", std::ios::app);
	if (fp.is_open() && (fp))
	{
		Details << type << ",";
		Details << name << ",";
		Details << matches << ",";
		Details << age << ",";
		Details << run << ",";
		Details << century << ",";
		Details << halfcen << ",";
        Details << out << ",";
        Details << avg << ",";
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
inline void Batsman::deserialize(std::stringstream &Details)
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
	run = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	century = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	halfcen = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	out = stoi(temp);
	temp = "";
	std::getline(Details, temp, ',');
	avg = stoi(temp);
}
/*function to show the attribute of batsman*/
inline void Batsman::Show_info()
{
	Player::Show_info();
	cout << "\nAverage       :" << avg;
	cout << "\nRun           :" << run;
    cout << "\nCentury       :" << century;
    cout << "\nHalf Century  :" << halfcen;
    cout << "\n\n";
}
/*function to read the common as well as attribute batsman*/
inline void Batsman::Get_info()
{
	Player::Get_info();
	type = "Batsman";
    cout << "\nEnter total run of bastman :";
    cin >> run;
    cout << "\nEnter Number of century :";
    cin >> century;
    cout << "\nEnter Number of Half century :";
    cin >> halfcen;
    cout << "\nHow many time bastman got out:";
    cin >> out;
    /*compute the avreage run of batsman*/
    if (out == 0)
	{
		avg = run;
	}
	else
	{
		avg = run / out;
	}	
}
