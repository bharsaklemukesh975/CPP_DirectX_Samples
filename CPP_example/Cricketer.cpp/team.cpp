/**
 * Copyright [year] <Copyright Owner>
 * This is file for implementataion for Team class.
 * Team class contains collection of player.
 *
 */
#include "team.h"
#include<conio.h>
#include<string>
#include<fstream>
#include<memory>
#include<vector>
using std::fstream;
void Team::write()
{
	remove("data.csv");
	fstream fp("data.csv", std::ios::out);
	fp.close();
	for(int i = 0; i < pl_no ; i++)
	{
		team[i]->serialize();
	}
	team.clear();
}
void Team::readf()
{
	try
	{
		pl_no = 0;
		fstream fp("data.csv", std::ios::in);
        string::iterator pt;
        if (fp.is_open() && (!fp.eof()))
		{
			string type = "", str = "";
            while (!fp.eof())
			{
				str = "";
				fp >> str;
				std::stringstream Details(str);
                if (str.empty() || str == " " || str == "\n")
					break;
				type = "";
				pt = str.begin();
				while (*pt != ',')
				{
					type = type + *pt;
					++pt;
				}
				if (type == "Batsman")
				{
					team.push_back(std::unique_ptr<Batsman>(new Batsman()));
					team[pl_no]->deserialize(Details);
				}
				else if(type == "Bowler")
				{
					team.push_back(std::unique_ptr<Bowler>(new Bowler()));
					team[pl_no]->deserialize(Details);
				}
				else
				{
					pl_no--;
				}
				if (pl_no < 11)
				{
					pl_no++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			cout << "\n Error";
		}
		fp.close();
	}
	catch (std::bad_alloc *team) 
	{
		cout << "\nAllocation Failure!!\n";
	}
}
Team::Team()
{
	pl_no = 0;
}
void Team::Show()
{
	if (pl_no != 0)
	{
		/*for loop to show the records of all the Player*/
		for (int i = 0; i < pl_no; i++)
		{
			/*call the function to show the record of player*/
			team[i]->Show_info();
			_getch();
		}
	}
	else
	{
		/*if no record is available show message as empty data*/
		cout << "\nEmpty Data...!";
	}
}
 void Team::Read()
 {
	 char choice = ' ';
	 int flag = 0;
	 /* Read the choice to read record of batsman or bowler*/
	 cout << "\n********Enter type of player*****************";
	 cout << "\n1.Batsman\n2.Bowler:";
	 cin >> choice;
	 if (pl_no < 11)
	 {
		 /*if choice is 1 then read the record of batsman*/
		 if(choice == '1'  )
		 {
			 team.push_back(std::unique_ptr<Batsman>(new Batsman()));
		 }
		 /*if choice is 2 then read the record of bowler*/
		 else if (choice == '2')
		 {
			 team.push_back(std::unique_ptr<Bowler>(new Bowler()));
		 }
		 else
		 {
			 /*else show message as invalid choice*/
			 cout << "\n Invalid Choice...!";
			 flag = 1;
		 }
		 if(flag == 0)
		 {
			 /*call the function to read the record of player*/
			 team[pl_no++]->Get_info();
             cout << "\n Record is Inserted...!";
		 } 
	 }
	 else
	 {
		 cout<< "\n Overflow...Can't Insert...!";
	 }
}
 void Team::Delet()
 {
	 string name;
     int del = 0, flag = 0;
	 cout << "\nEnter the name of Player to be remove:";
	 cin >> name;
	 if (pl_no > 0)
	 {
		 std::vector<std::unique_ptr<Player>>::iterator team_iterator = team.begin();
		 for (int i = 0; i < pl_no; i++, team_iterator++) 
		 {
			 /*strcmp use to compare the name to be find in record*/
			 if (team[i]->name == name)
			 {
				 team.erase(team_iterator);
				 flag = 1;
				 break;
			 }
		 }
		 if (flag == 0)
		 {
			 cout << "\nNot Found...!";
		 }
		 else
		 {
			 /*decrement count of object of player*/
			 pl_no--;
             cout << "\n Record is deleted...!";
		 }
	 }
	 else
	 {
		 /*if no record is available show message  as Underflow...Can't Delete. */
		 cout << "\n Underflow...Can't Delete...!";
	 }
 }
void Team::Search()
{
	string name;
    /*search record of Player*/
	int flag = 0;
	/*Read name of Player which user want to search*/
	cout << "\nEnter the name of Player to be search:";
	cin >> name;
	if (pl_no != 0)
	{
		for (int i = 0; i < pl_no; i++)
		{
			/*strcmp use to compare the name to be find in record*/
			if (team[i]->name == name)
			{
				/*show the info of player*/
				team[i]->Show_info();
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nNot Found...!";
		}
	}
	else
	{
		/*if no record is available show message  as Empty Data*/
		cout << "\nEmpty Data...!";
	}
}
