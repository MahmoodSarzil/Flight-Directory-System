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

#ifndef Sport_H_
#define Sport_H_
#include<string>
#include "Attraction.h"
using namespace std;
class Sport : public Attraction {
    int ageLimit;
public:
    Sport (int id, string name, int ageLimit);
    int getAgeLimit();
	void display();
};

#endif

