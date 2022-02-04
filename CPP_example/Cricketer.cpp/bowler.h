/**
 *
 * This is header file for Bowler class.
 *Copyright [year] <Copyright Owner>
 * Bowler class contains attribute and function for Bowler.
 *
 */
#ifndef BOWLER_H_
#define BOWLER_H_
#include<string>
#include<sstream>
#include"player.h"
/*derived class Bowler from base class Player*/
class Bowler:public Player
{
protected :
	int bavg, over, brun, wicket, economy, half;
public :
	Bowler();
	Bowler(std::vector<std::unique_ptr<Bowler>>,int);
	void serialize();
	void deserialize(std::stringstream&);
	void Show_info();
	void Get_info();
};
#endif  // BOWLER_H_
