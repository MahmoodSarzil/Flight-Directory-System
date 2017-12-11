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

#ifndef City_H_
#define City_H_
#include "Attraction.h"
#include "interfaceListStack.h"
#include<string>

class City {
    int id;
    string name;
public:
    City (string name);
	bool displayAttraction() const;
	bool displayAttractionById(int) const;
	void display() const;
    string getname();
    int getid();
    bool operator<(const City &rhs) const; // suggested from stackoverflow
	void SortInsert(Attraction*);
	List<Attraction*>* attractions;


};

#endif
