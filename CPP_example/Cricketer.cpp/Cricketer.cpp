/**
 * @author  Mukesh Bharsakle <bharsaklemukesh975@gmail.com>
 * Copyright [year] <Copyright Owner>
 * This program is to accept a data of a cricketer.
 * Classify them as a batsman & bowler.Create a base
 * class of a player and inherit bowler and batsman from it
 * and create a Team class (collection class) to hold the list of all players.
 *
 */
#include"team.h"
#include<conio.h>
#include<vld.h>
#include<memory>
int main()
{
	try
	{
		char ch = ' ';
		void (Team::*fptr)();
		Team *t = new Team();
		fptr = &Team::readf;
		(t->*fptr)();
		do
		{
			/*to clear the screen*/
			system("CLS");
            cout << "\n\n****************Menu*********************";
            cout << "\n1.Show data";
            cout << "\n2.Read data";
            cout << "\n3.Delete data";
            cout << "\n4.Search data";
            cout << "\n5.Exit";
            /*read the input from user store it in ch*/
            cout << "\nEnter your choice:";
            cin >> ch;
            switch (ch)
			{
			case '1':
				fptr = &Team::Show;
				(t->*fptr)();
				break;
			case '2':
				fptr = &Team::Read;
				(t->*fptr)();
				break;
			case '3':
				fptr = &Team::Delet;
				(t->*fptr)();
				break;
			case '4':
				fptr = &Team::Search;
				(t->*fptr)();
				break;
				/*if choice is 5 then exit from program*/
			case '5':
				cout << "\nExit....!";
				break;
			default:
				cout << "\nInvalid choice.....!";
			}
			cout << "\n\nPress any key......";
			_getch();
			/*terminating condition*/
		}while(ch != '5');
		fptr = &Team::write;
		(t->*fptr)();
	    delete t;
	}
	catch (std::bad_alloc *t)
	{
		cout << "\nAllocation Failure!!\n";
	}
	return 0;
}
