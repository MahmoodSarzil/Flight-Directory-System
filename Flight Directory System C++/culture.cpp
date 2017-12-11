#include "Culture.h"
#include <iostream>
using namespace std;

// Constructor Defination - Culture Class
Culture::Culture(int id, string name, double entrenceFee)
: Attraction(id, name), entrenceFee(entrenceFee) {
	this->extra = entrenceFee;
	setTypeID(Attraction::CULTURE);
}

// Display Function for Culture (Used for Attraction Selection)
void Culture::display(){
	cout << "Type:Culture \t Attraction Name: " << getName() << "\nEnterence Fees: " << this->extra << endl;
}

// Getter function for EntrenceFee - Culture
double Culture::getEntrenceFee(){
	return entrenceFee;
}
