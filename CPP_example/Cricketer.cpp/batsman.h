/**
 * Copyright [2015] <Mukesh Bharsakle>
 * This is header file for Batsman class.
 * Batsman class contains attribute and function for Batsman.
 *
 */

#ifndef BATSMAN_H_
#define BATSMAN_H_
#include<string>
#include<sstream>
#include<fstream>
#include"player.h"
/* derived class Batsman from base class Player*/
class Batsman:public Player
{
protected :
	int avg, run, out, century, halfcen;
public :
	Batsman();
	Batsman(std::vector<std::unique_ptr<Batsman>>,int);
	void serialize();
	void deserialize(std::stringstream&);
	void Show_info();
	void Get_info();
};
#endif  // BATSMAN_H_
