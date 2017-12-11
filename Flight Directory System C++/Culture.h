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

#ifndef Culture_H_
#define Culture_H_
#include<string>
#include "Attraction.h"

class Culture: public Attraction {
    double entrenceFee;
	int typeID;
public:
    Culture (int id, string name, double entrenceFee);
    double getEntrenceFee();
    void display();
};


#endif
