
#include "Shopping.h"
#include <iostream>
using namespace std;

// Constructor Defination - Shopping Class
Shopping::Shopping(int id, string name, string Malls)
: Attraction(id, name), Malls(Malls) {
	this->extra = Malls;
	setTypeID(Attraction::SHOPPING);
}

// Getter Function for Malls - Shopping (Used for Attraction Selection)
string Shopping::getMalls(){
	return Malls;
}

// Display Function for Shopping (Used for Attraction Selection)
void Shopping::display()
{
	cout << "Type:Shopping \t Attraction Name: " << getName() << "\nMalls: " << this->extra << endl;

}