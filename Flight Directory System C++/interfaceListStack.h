#include <iostream>
using namespace std;


#ifndef interface
#define interface

template <class TItem> class List;
template <class TItem> class Stack;
//////////////////////////////////////////////////////////////////////////////////////////
template <class TItem> class ListNode{
friend class List<TItem>;
friend class Stack<TItem>;
private:
	TItem info;
	ListNode *next;
public:
	ListNode(TItem);
	~ListNode();
	void setInfo(TItem);
	TItem getInfo() const;
	//ListNode<TItem>* getNext(ListNode*) const; //принимает элемент и возвращает ссылку на следующий.
};
//////////////////////////////////////////////////////////////////////////////////////////


template <class TItem> class List{
private:
	ListNode<TItem> *head;
	ListNode<TItem> *tail;
	int lengthList; //длина списка
public:
	List();
	~List();
	void SortInsert(TItem);
	void insertBack(TItem);
	void insertFront(TItem);
	void insertTo(TItem, int);
	void insertBack(ListNode<TItem>*);
	ListNode<TItem>* getFrom(int) const; //Использовать в крайнем случае
	void print() const;
	void removeBack();
	void removeFront();
	void removeFrom(int);
	void removeAll();
	void excludeFront(); //отрывает первый элемент из списка, при этом он остается висеть в оперативной памяти.
	void excludeAll(); //разрывает связь между всеми элементами, но при этом они все хранятся в ОП (список становится пустым)
	void concatenation(const List<TItem>*); //приклеивание к концу данного списка, другого(при этом второй список не изменяется) и списки полностью независимы
	bool isEmpty() const;
	int find(TItem) const;
	List<int> findAll(TItem) const; // найти все TItem и вернуть в списке их места.
	bool operator== (const List<TItem>&);
	List<TItem>& operator= (const List<TItem>&);
};


#endif
