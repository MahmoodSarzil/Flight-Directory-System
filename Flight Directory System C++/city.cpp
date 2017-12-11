#include "City.h"
#include "ImplementationListStack.h"

// Constructor Defination - City Class
City::City(string name): name(name) {
	attractions = new List<Attraction*>;
}

bool City::displayAttraction() const {
	ListNode<Attraction*>* tmp;// = new ListNode<Attraction*>();
	int flag = 0;
	for (int i = 1; (tmp = attractions->getFrom(i)) != NULL; i++){
		cout << i << ") ";
		tmp->getInfo()->display();
		flag++;
	}
	if (flag == 0){
		cout << "\nNo attraction found for this category in this city. Try Another category or city";
		return false;
	}
	return true;
}

bool City::displayAttractionById(int id) const {
	ListNode<Attraction*>* tmp;// = new ListNode<Attraction*>();
	int flag = 0;
	for (int i = 1; (tmp = attractions->getFrom(i)) != NULL; i++){
		if (tmp->getInfo()->gettypeID() == id){
			cout << i << ") ";
			tmp->getInfo()->display(); // Prints Attraction
			flag++;
		}
	}
	if (flag == 0){
		cout << "\nNo attraction found for this category in this city. Try Another category or city";
		return false;
	}
	return true;
}


string City::getname() {
	return name;
}

bool City::operator<(const City &obj) const {
	return name < obj.name;
} // End of Stackoverflow fix

void City::SortInsert(Attraction* at){
	attractions->insertBack(at);
	//attractions->SortRadix(10);
}

// Getter Function - City Class
int City::getid() {
	return id;
}