/**
 * Copyright [year] <Copyright Owner>
 * This is header file for Team class.
 * Bowler class contains collection of players.
 *
 */

#ifndef TEAM_H_
#define TEAM_H_
#include"batsman.h"
#include"bowler.h"
#include<vector>
#include<memory>
/*class Team is a collection of players */
class Team
{
public :
	/*Vector of class Player*/
	std::vector<std::unique_ptr<Player>> team;
	int  pl_no;
	Team();
	void write();
	void readf();
	void Show();
	void Read();
	void Delet();
	void Search();
  };
#endif  // TEAM_H_
