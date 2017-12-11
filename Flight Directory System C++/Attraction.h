/****************************************
 Program: main.cpp, Attraction.h, City.h
 Culture.h, Shopping.h, Sport.h
 Course:  OOPDS
 Year:    20015/16 Trimester 2
 Name:    MOTASIM BIR RAHMAN
 ID:      1141328114
 Lecture: TC03
 Lab:     TT07
 Email:   motasim@incogmito.com
 Phone:   017-2114056
 ****************************************/

#ifndef Attraction_H_
#define Attraction_H_
#include <string>
using namespace std;

class Attraction {
    int id;
    string name;
	int typeID;
public:
	enum TypeID{ SPORT , CULTURE, SHOPPING };
	Attraction(int id, string name) : id(id), name(name){}
	string extra;
	string getName();
	int gettypeID();
	void setTypeID(int);
	virtual void display() = 0 ;
};

#endif
