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

#ifndef Shopping_H_
#define Shopping_H_
#include<string>
#include "Attraction.h"

class Shopping: public Attraction {
    string Malls;
public:
    Shopping (int id, string name, string Malls);
    string getMalls();
    void display();
};


#endif
