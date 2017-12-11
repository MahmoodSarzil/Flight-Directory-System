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
	//ListNode<TItem>* getNext(ListNode*) const; //��������� ������� � ���������� ������ �� ���������.
};
//////////////////////////////////////////////////////////////////////////////////////////


template <class TItem> class List{
private:
	ListNode<TItem> *head;
	ListNode<TItem> *tail;
	int lengthList; //����� ������
public:
	List();
	~List();
	void SortInsert(TItem);
	void insertBack(TItem);
	void insertFront(TItem);
	void insertTo(TItem, int);
	void insertBack(ListNode<TItem>*);
	ListNode<TItem>* getFrom(int) const; //������������ � ������� ������
	void print() const;
	void removeBack();
	void removeFront();
	void removeFrom(int);
	void removeAll();
	void excludeFront(); //�������� ������ ������� �� ������, ��� ���� �� �������� ������ � ����������� ������.
	void excludeAll(); //��������� ����� ����� ����� ����������, �� ��� ���� ��� ��� �������� � �� (������ ���������� ������)
	void concatenation(const List<TItem>*); //������������ � ����� ������� ������, �������(��� ���� ������ ������ �� ����������) � ������ ��������� ����������
	bool isEmpty() const;
	int find(TItem) const;
	List<int> findAll(TItem) const; // ����� ��� TItem � ������� � ������ �� �����.
	bool operator== (const List<TItem>&);
	List<TItem>& operator= (const List<TItem>&);
};


#endif
