#include "Attraction.h"
#include <iostream>
using namespace std;

// Getter fucntion for name - Attraction Class
string Attraction::getName(){
	return name;
}

// Getter fucntion for typeID - Attraction Class
int Attraction::gettypeID() {
	return typeID;
}

void Attraction::setTypeID(int t){
	typeID = t;
}