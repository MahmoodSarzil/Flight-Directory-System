
#include "Sport.h"
#include <iostream>
using namespace std;

//Constructor Defination - Sport Class
Sport::Sport(int id, string name, int ageLimit)
: Attraction(id, name), ageLimit(ageLimit) {
	this->extra = ageLimit;
	setTypeID( Attraction::SPORT );
}

// Display Function for Sport (Attraction Selection)
void Sport::display(){
	cout << "Type:Sport \t Attraction Name: " << getName() << "\nAge Limit: " << this->extra << endl;
}
