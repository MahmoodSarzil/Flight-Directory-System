/****************************************
Program: main.cpp, Attraction.h, City.h
Culture.h, Shopping.h, Sport.h

Mahmood Sarzil
****************************************/

#include "Attraction.h"
#include "Sport.h"
#include "Culture.h"
#include "ImplementationListStack.h"
#include "Shopping.h"
#include "City.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <strings.h>

#define COUNTPARAM 2
using namespace std;

List <City*>* c = new List<City*>();
int** linkCity = new int*[256];

void cityMenu(City& ci, bool admin = false);
void adminInterFace();
void addAttractionCityMenu(City& ci);
void delAttractionCityMenu(City& ci);
void addCityMenu();
void delCityMenu();
bool dfs(int source, int dest);
void init(int** in, int size);
void userInteface();
void selectInterface();
void userCityMenu();
void userFlightInterface();
void addFlightMenu();
void delFlightMenu();
void LoadCity(const char*);
void SaveCity(const char*);
void SaveFlying(const char*);
void LoadFlying(const char*);

int main() {
	init(linkCity, 256);

	while (true)
	{
		selectInterface();
	}

	return 0;
}

char* TrimStart(char* in){
	int i = 0, j = 0;
	while (in[j++] == ' ');
	j--;
	char* out = new char[strlen(in) - j];
	while (out[i++] = in[j++]);
	return out;
}

char* TrimEnd(char* in){
	int len = strlen(in);
	int j = len - 1;
	while (in[j--] == ' ');
	j++;
	char* out = new char[j + 2];
	int i = j;
	out[j + 1] = '\0';
	while (j>-1)
		out[i--] = in[j--];
	return out;
}

char* Trim(char* in){
	return TrimEnd(TrimStart(in));
}

void SaveCity(const char* config){
	ofstream f(config);
	ListNode<City*>* tmp;
	int countCity = 1;
	while (tmp = c->getFrom(countCity++))
	{
		f << "City = " << tmp->getInfo()->getname() << endl; // Prints Cities
		ListNode<Attraction*>* tmp2;// = new ListNode<Attraction*>();
		for (int i = 1; (tmp2 = tmp->getInfo()->attractions->getFrom(i)) != NULL; i++){
			if (tmp2->getInfo()->gettypeID() == tmp2->getInfo()->SPORT)
				f << "SPORT = ";
			if (tmp2->getInfo()->gettypeID() == tmp2->getInfo()->CULTURE)
				f << "CULTURE = ";
			if (tmp2->getInfo()->gettypeID() == tmp2->getInfo()->SHOPPING)
				f << "SHOPPING = ";
			f << tmp2->getInfo()->getName() << ", " << tmp2->getInfo()->extra<<endl;
		}
		f << endl;
		f.flush();
	}
	f.close();
}

void LoadFlying(const char* file){
	ifstream fin(file);
	ListNode<City*>* tmp;
	int countCity = 1;
	while (tmp = c->getFrom(countCity++)){}

	for (int r = 0; r<countCity; r++)
	{
		for (int c = 0; c<countCity; c++)
		{
			fin >> linkCity[r][c];
		}
	}
}

void SaveFlying(const char* file){
	ofstream fout(file);
	ListNode<City*>* tmp;
	int countCity = 1;
	while (tmp = c->getFrom(countCity++)){}

	for (int r = 0; r<countCity; r++)
	{
		for (int c = 0; c<countCity; c++)
		{
			fout << linkCity[r][c] << "\t";
		}
		fout << "\n";
	}
}

void LoadCity(const char* config){
	int size = 256;
	ifstream f(config);
	City* tmp = NULL;
	if (f){
		//заносим данные в словарь из файла
		while (!f.eof()){
			char* s = new char[size];
			f.getline(s, size);
			//обрезаем пробелы
			s = TrimStart(s);
			//если есть ; это комментарий
			if (s[0] == ';' )
				continue;
			if (strlen(s) == 0 && tmp){
				c->SortInsert(new City(*tmp));
				tmp = NULL;
			}

			char* Object = new char[256];
			char* name = new char[256];
			char* extra = new char[256];

			if (sscanf(s, "%[^]%*[=\]=%[^]%*[,\],%[^]%*", Object, name, extra) > 1){
				if (strcmp(Trim(Object), "City") == 0 && !tmp){
					tmp = new City(Trim(name));
				} else if (tmp){
					if (strlen(name) > 0){
						if (strcmp(Trim(Object), "SPORT")==0){
							tmp->SortInsert(new Sport(0, name, atoi(extra)));
						}
						else if (strcmp(Trim(Object),  "CULTURE")==0)
						{
							tmp->SortInsert(new Culture(0, string(name), atof(extra)));
						}
						else if (strcmp(Trim(Object), "SHOPPING")==0)
						{
							tmp->SortInsert(new Shopping(0, name, Trim(extra)));
						}
					}
				}
			}
		}
		if (tmp)
			c->SortInsert(new City(*tmp));
		f.close();
	}
}

void selectInterface(){
	cout << "\n1. user";
	cout << "\n2. admin";
	cout << "\nChoose a City ID ==> ";
	int ch = 0;
	cin >> ch;
	string pass = "123";
	string INpass;
	switch (ch) //Switch case used for detecting type
	{
	case 1:
		userInteface();
		break;
	case 2:
		cout << "\nEnter admin password: ";
		cin >> INpass;
		if (INpass == pass)
			adminInterFace();
		break;
	default:
		break;
	}
}

void userInteface(){
	cout << "\nSelect a city from the list below:\n";
	cout << "-----------------------------------";

	int ch;
	while (1){
		cout << "\n1. City Guide";
		cout << "\n2. Flight Guide ";
		cout << "\n3. Exit ";
		cout << "\nChoose ID ==> ";
		cin >> ch;

		switch (ch) //Switch case used for detecting type
		{
		case 1:
			userCityMenu();
			break;
		case 2:
			userFlightInterface();
			break;
		case 3:
			return;
		default:
			break;
		}

	}
}

void addFlightMenu(){
	cout << "\n------- Start of Flight Guide Editor --------\n\n";

	ListNode<City*>* tmp;
	int countCity = 1;
	while (tmp = c->getFrom(countCity))
	{
		cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
	}
	cout << "\nChoose Source City from the city list: ";
	int source = 0;
	int dest = 0;
	cin >> source;

	cout << "\n";
	countCity = 1;
	while (tmp = c->getFrom(countCity))
	{
		cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
	}
	cout << "\nChoose Destination city from the list: ";
	cin >> dest;
	if (dest > countCity || source > countCity || dest < 1 || source < 1){
		cout << "Incorrect input" << endl;
	}
	else {
		linkCity[source][dest] = true;
	}
}

void delFlightMenu(){
	cout << "\n------- Start of Flight Guide Editor --------\n\n";
	string* cityIdToName = new string[256];

	ListNode<City*>* tmp;// = new ListNode<Attraction*>();
	int countCity = 1;
	while (tmp = c->getFrom(countCity))
	{
		cityIdToName[countCity++] = tmp->getInfo()->getname(); // Prints Cities
	}

	int c = 1;
	// Display cities directly connected
	for (int i = 0; i<countCity; i++)
	{
		for (int j = 0; j<countCity; j++)
		{
			if (linkCity[i][j])
			{
				cout << c++ << ". " << cityIdToName[i] << " -> " << cityIdToName[j] << endl;
			}
		}
	}
	if (c == 1){
		cout << "\nNot Exists Link\n";
		return;
	}
	cout << "\nChoose City Link ID for delete: ";
	int ch = 0;
	cin >> ch;
	if (ch > countCity || ch < 1 ){
		cout << "\nIncorrect input" << endl;
	}
	else {
		c = 1;
		// Display cities directly connected
		for (int i = 0; i<countCity; i++)
		{
			for (int j = 0; j<countCity; j++)
			{
				if (linkCity[i][j] && ch == c++)
				{
					linkCity[i][j] = false;
					return;
				}
			}
		}

	}
}

void init(int** in, int size){
	for (int i = 0; i < size; i++){
		in[i] = new int[256];
		for (int j = 0; j < 256; j++)
			in[i][j] = 0;
	}
}

void userCityMenu(){
	cout << "------- Start of City Guide --------\n";

	char ch;
	while (1){
		cout << "\n";

		ListNode<City*>* tmp;// = new ListNode<Attraction*>();
		int countCity = 1;
		while (tmp = c->getFrom(countCity))
		{
			cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
		}

		cout << "\nQ. Exit";
		cout << "\nChoose a City ID ==> ";
		cin >> ch;
		int temp = ch - '0';
		if (ch == 'q' || ch == 'Q'){
			break;
		}
		else if (temp>countCity){
			cout << "\nChoose valid option. Try Again!";
		}
		else{
			cityMenu(*c->getFrom(temp)->getInfo());
		}

	}
}

bool dfs(int source, int dest)
{
	ListNode<City*>* tmp;
	int totalCities = 1;
	while (tmp = c->getFrom(totalCities))
	{
		totalCities++;
	}

	// WarshallТs Algorithm
	for (int k = 0; k<totalCities; k++)
	{
		for (int i = 0; i<totalCities; i++)
		{
			for (int j = 0; j<totalCities; j++)
			{
				if (linkCity[i][k] && linkCity[k][j])
				{
					linkCity[i][j] = true;
				}
			}
		}
	}

	if (linkCity[source][dest])
		return true;
	return false;
}

void userFlightInterface(){
	cout << "\n------- Start of Flight Guide --------\n\n";

	ListNode<City*>* tmp;
	int countCity = 1;
	while (tmp = c->getFrom(countCity))
	{
		cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
	}
	cout << "\nChoose your Current City from the city list: ";
	int source = 0;
	int dest = 0;
	cin >> source;

	cout << "\n";
	countCity = 1;
	while (tmp = c->getFrom(countCity))
	{
		cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
	}
	cout << "\nChoose your destination city from the list: ";
	cin >> dest;
	if (dest > countCity || source > countCity || dest < 1 || source < 1){
		cout << "Incorrect input" << endl;
	} else {
		cout << "Output: ";
		if (linkCity[source][dest]){
			cout << "Direct Flight";
		}
		else
		{
			if(dfs(source, dest))
				cout << "Indirect Flight";
			else
				cout << "No link";
		}
		cout << endl;
	}
}

void adminInterFace(){
	cout << "Select a city from the list below:\n";
	cout << "-----------------------------------\n";

	char ch;
	while (1){
		cout << "\n";

		ListNode<City*>* tmp;// = new ListNode<Attraction*>();
		int countCity = 1;
		while (tmp = c->getFrom(countCity))
		{
			cout << countCity++ << ". " << tmp->getInfo()->getname() << endl; // Prints Cities
		}

		cout << "\nA. Add city";
		cout << "\nL. Load city from file";
		cout << "\nS. Save city in file";
		cout << "\nD. Remove City";
		cout << "\nF. Add a flight";
		cout << "\nC. Load flight from file";
		cout << "\nV. Save flight in file";
		cout << "\nX. Remove a Flight";
		cout << "\nQ. Exit";
		cout << "\nChoose a City ID ==> ";

		cin >> ch;
		int temp = ch - '0';
		if (ch == 'q' || ch == 'Q'){
			break;
		}
		else if (ch == 'A' || ch == 'a'){
			addCityMenu();
		}
		else if (ch == 'F' || ch == 'f'){
			addFlightMenu();
		}
		else if (ch == 'L' || ch == 'l'){
			cout << "\nInter file name: ";
			char* file = new char[256];
			cin.ignore();
			cin.getline(file, 256);
			LoadCity(file);
		}
		else if (ch == 'S' || ch == 's'){
			cout << "\nInter file name: ";
			char* file = new char[256];
			cin.ignore();
			cin.getline(file, 256);
			SaveCity(file);
		}
		else if (ch == 'C' || ch == 'c'){
			cout << "\nInter file name: ";
			char* file = new char[256];
			cin.ignore();
			cin.getline(file, 256);
			LoadFlying(file);
		}
		else if (ch == 'V' || ch == 'v'){
			cout << "\nInter file name: ";
			char* file = new char[256];
			cin.ignore();
			cin.getline(file, 256);
			SaveFlying(file);
		}
		else if (ch == 'X' || ch == 'x'){
			delFlightMenu();
		}
		else if (ch == 'd' || ch == 'D'){
			delCityMenu();
		}
		else if (temp>countCity){
			cout << "\nChoose valid option. Try Again!";
		}
		else{
			cityMenu(*c->getFrom(temp)->getInfo(), true);
		}

	}
}

void delAttractionCityMenu(City& ci){
	cout << "\nAll Attractions:\n"; // For showing All Attraction
	ci.displayAttraction();
	int id = 0;
	cout << "\n Insert ID for delete ==> ";
	cin >> id;
	ci.attractions->removeFrom(id);
}

void delCityMenu(){
	int id = 0;
	cout << "\n Insert ID ==> ";
	cin >> id;
	c->removeFrom(id);
}

void addCityMenu(){
	cout << "Insert name: ";
	char *name = new char[256];
	cin.ignore();
	cin.getline(name, 256);
	c->insertBack(new City(name));
}

void addAttractionCityMenu(City& ci){
	cout << "Insert name: ";
	char* name = new char[256];
	cin.ignore();
	cin.getline(name, 256);

	char type;
	double pay = 0;
	char* malls = new char[256];
	int age = 0;
	cout << "\nSelect a type of attraction from the list below:";
	cout << "\n" << Attraction::SPORT << ". Sports";
	cout << "\n" << Attraction::CULTURE << ". Culture";
	cout << "\n" << Attraction::SHOPPING << ". Shopping";
	cout << "\nChoose a type ID ==> ";
	cin >> type;
	int typeId = type - '0';
	switch (typeId) //Switch case used for detecting type
	{
	case Attraction::SPORT:
		cout << "\n Insert age ==> ";
		cin >> age;
		age = age > 0 ? age : 0;
		ci.SortInsert(new Sport(0, name, age));
		break;
	case Attraction::CULTURE:
		cout << "\n Insert entrence fee ==> ";
		pay = pay > 0 ? pay : 0;
		cin >> pay;
		ci.SortInsert(new Culture(0, name, pay));
		break;
	case Attraction::SHOPPING:
		cout << "\n Insert malls ==> ";
		cin.ignore();
		cin.getline(malls, 256);
		string malls(malls);
		ci.SortInsert(new Shopping(0, name, malls));
		break;
	}
	//c->insertBack(new City(name));

}

// City Menu Fucntion. After Selecting a City this menu will be called
void cityMenu(City& ci, bool admin){

	char ch;
	do{
		cout << "\nSelect a type of attraction from the list below:\n";
		cout << "-------------------------------------------------\n";
		cout << "\n" << Attraction::SPORT << ". Sports";
		cout << "\n" << Attraction::CULTURE << ". Culture";
		cout << "\n" << Attraction::SHOPPING << ". Shopping";
		cout << "\n3. Show All Attractions";
		if (admin){
			cout << "\n4. Add Attractions";
			cout << "\n5. Delete Attractions";
		}
		cout << "\n6. Back To Main Menu";
		cout << "\n\nChoose an attraction type ==> ";
		cin >> ch;
		int i, flag = 0;
		i = ch - '0';

		switch (i){
		case Attraction::SPORT: case Attraction::CULTURE: case Attraction::SHOPPING:
			cout << "\nHere you go! Your attractions are listed below\n";
			cout << "-----------------------------------------------\n";
			ci.displayAttractionById(i);

			break;
		case 3:
			cout << "\nAll Attractions:\n"; // For showing All Attraction
			cout << "------------------\n";
			ci.displayAttraction();

			break;
		case 4:
			if (admin)
				addAttractionCityMenu(ci);
			break;
		case 5:
			if (admin)
				delAttractionCityMenu(ci);
			break;
		case 6:
			return;
		default:
			cout << "\nInvalid Option. Try Again!";
		}
	} while (ch != '5');

}

