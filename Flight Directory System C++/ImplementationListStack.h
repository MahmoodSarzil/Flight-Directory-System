#include <iostream>
#include "interfaceListStack.h"
using namespace std;


template <class TItem> List <TItem>::List(){
	head=0;
	tail=0;
	lengthList=0;
}

template <class TItem> List <TItem>::~List(){}

template <class TItem> bool List<TItem>::isEmpty() const{
	return (head==0);
}

template <class TItem> void List<TItem>::insertBack(TItem x){
	ListNode <TItem> *temp=new ListNode<TItem>(x);
	if(!isEmpty()){
		tail->next=temp;
		tail=temp;
		lengthList++;
	} else {
		head=temp;
		tail=temp;
		lengthList++;
	}
}

template <class TItem> void List<TItem>::SortInsert(TItem x){
	if (!isEmpty()){
		ListNode <TItem> *temp = head;
		for (int i = 1; i <= lengthList; i++){
			if (*x < *temp->getInfo()){
				insertTo(x, i-1);
				return;
			}
			else {
				temp = temp->next;
			}
		}
	}
	insertBack(x);
}

template <class TItem> void List<TItem>::insertBack(ListNode<TItem>* x){
	if(head!=0){ //тоже самое, что и !isEmpty(), но мы боремся за производительность.
		tail->next=x;
		tail=x;
		lengthList++;
	} else {
		head=x;
		tail=x;
		lengthList++;
	}
}

template <class TItem> void List<TItem>::insertFront(TItem x){
	ListNode <TItem> *temp=new ListNode<TItem>(x);
	if(!isEmpty()){
		temp->next=head;
		head=temp;
		lengthList++;
	} else {
		head=temp;
		tail=temp;
		lengthList++;
	}
}

template <class TItem> void List<TItem>::insertTo(TItem x, int n){
	ListNode<TItem> *temp=new ListNode<TItem>(x);
	if(!isEmpty()){
		if(n>=lengthList){
			insertBack(x);
		}
		if(n<=0){
			insertFront(x);
		}
		if(n>0 && n<lengthList){
			ListNode<TItem> *tPtr=head;
			ListNode<TItem> *tNxt=0;
			for(int i=1; i<n; i++){
				tPtr=tPtr->next;
			}
			tNxt=tPtr->next;
			tPtr->next=temp;
			temp->next=tNxt;
			lengthList++;
		}

	} else {
		head=temp;
		tail=temp;
		lengthList++;
	}
}

template <class TItem> void List<TItem>::removeBack(){
	if(!isEmpty()){
		ListNode<TItem> *tPtr=head;
		for (int i = 1; i<lengthList - 1; i++){  //узнаем новую вершину
			tPtr=tPtr->next;
		}
		if(tail!=head){
			tail=tPtr;
			tPtr=tPtr->next;
			tail->next=0;
			lengthList--;
			delete tPtr;
		} else {
			head=tail=0;
			lengthList--;
			delete tPtr;
		}

	}
}

template <class TItem> void List<TItem>::removeFront(){
	if(!isEmpty()){
		if(head!=tail){
			ListNode<TItem> *tmp=head;
			head=head->next;
			lengthList--;
			delete tmp;
		} else {
			head=tail=0;
			lengthList--;
		}
	}
}

template <class TItem> void List<TItem>::removeFrom(int n){
	if(!isEmpty()){
		if(n>=lengthList){
			removeBack();
		}
		if(n<=1){
			removeFront();
		}
		if(n>1 && n<lengthList){
			ListNode<TItem> *tPtr=head;
			ListNode<TItem> *tNxt=0;
			ListNode<TItem> *temp=0;
			for(int i=1; i<n-1; i++){
				tPtr=tPtr->next;
			}
			tNxt=(tPtr->next)->next;
			temp=tPtr->next;
			tPtr->next=tNxt;
			lengthList--;
			delete temp;
		}
	}
}

template <class TItem> void List<TItem>::removeAll(){
	for(int i=1; i<=lengthList;){ //цикл с пустым третьим параметром, т.к. происходит декремент lengthList в функции removeFront()
		removeFront();            //все проверки происходят в removeFront()
	}
}

template <class TItem> void List<TItem>::excludeFront(){
	if(head!=0){ //тоже самое, что и !isEmpty(), но мы боремся за производительность.
		if(head!=tail){
			ListNode<TItem>* tmp=head;
			head=head->next;
			tmp->next=0;
			lengthList--;
		} else {
			head=tail=0;
			lengthList=0;
		}
	}
}

template <class TItem> void List<TItem>::excludeAll(){
	if(!isEmpty()){
		ListNode<TItem>* tmp=head;
		for(lengthList; lengthList>1; lengthList--){
			tmp=head;
			head=head->next;
			tmp->next=0;
		}
		head=tail=0;
		lengthList=0;
	}
}

template <class TItem> int List<TItem>::find(TItem x) const{
	if(!isEmpty()){
		ListNode <TItem> *temp=head;
		for(int i=1; i<=lengthList; i++){
			if(x==temp->info){
				return i;
				break;
			} else {
				temp=temp->next;
			}
		}
		return 0;
	} else {
		return 0;
	}
}

template <class TItem> ListNode<TItem>* List<TItem>::getFrom(int n) const{
	if(!isEmpty()){
		if(n>lengthList){
			return NULL;
		}
		if(n<=0){
			return NULL;
		}
		if(n>0 && n<=lengthList){
			ListNode<TItem> *tPtr=head;
			for(int i=1; i<n; i++){
				tPtr=tPtr->next;
			}
			return tPtr;
		}
	} else {
		return NULL;
	}
}

template <class TItem> List<int> List<TItem>::findAll(TItem x) const{
	List<int> list;
	if(!isEmpty()){
		ListNode <TItem> *temp=head;
		for(int i=1; i<=lengthList; i++){
			if(x==(temp->info)){
				list.insertBack(i);
				temp=temp->next;
			} else {
				temp=temp->next;
			}
		}
		return list;
	} else {
		return list;
	}
}

template <class TItem> void List <TItem>::print() const{
	if(!isEmpty()){
		ListNode<TItem> *tPtr=head;
		for(int i=1; i<lengthList; i++){
			cout<<tPtr->info<<" -> ";
			tPtr=tPtr->next;
		}
		cout<<tPtr->info;
	} else {
		cout<<"NULL";
	}
}

template <class TItem> ostream& operator<< (ostream& out, const List<TItem>& lst){
	lst.print();
	return out;
}

template <class TItem> void operator<< (List<TItem>& lst, TItem x){
	lst.insertFront(x);
}

template <class TItem> void operator>> (List<TItem>& lst, TItem x){
	lst.insertBack(x);
}

template <class TItem> void operator>> (List<TItem>& lst, ListNode<TItem>* x){
	lst.insertBack(x);
}

template <class TItem> bool List<TItem>::operator== (const List<TItem>& right){
	if(!isEmpty() && !right.isEmpty()){
		if(lengthList==right.lengthList){
			ListNode<TItem> *tmpL=head;
			ListNode<TItem> *tmpR=right.head;//getFrom(1) возвращает ссылку на голову листа
			for(int i=1; i<=lengthList; i++){
				if(tmpL->info==tmpR->info){
					tmpL=tmpL->next;
					tmpR=tmpR->next;
				} else {
					delete tmpL;
					delete tmpR;
					return false;
					break;
				}
			}
			delete tmpL;
			delete tmpR;
			return true;
		} else {
			return false;
		}
	} else {
		if((isEmpty() && !right.isEmpty()) || (!isEmpty() && right.isEmpty())){
			return false;
		}
		if(isEmpty() && right.isEmpty()){
			return true;
		}
	}
}

template <class TItem> List<TItem>& List<TItem>::operator= (const List<TItem>& right){
	if (this!=&right){ // защита от неправильного самоприсваивания
		ListNode<TItem> *tmp=right.head; //можно getFrom(1)
		removeAll();
		for(int i=1; i<=right.lengthList; i++){
			insertBack(tmp->info);
			tmp=tmp->next;
		}
		delete tmp;
	}
	return *this;
};

////////////////////////////////////////////////////////////////////////
template <class TItem> void ListNode <TItem>::setInfo(TItem x){
	info=x;
	next=0;
}

template <class TItem> ListNode <TItem>::ListNode(TItem x){
	setInfo(x);
}

template <class TItem> ListNode<TItem>::~ListNode(){}

template <class TItem> TItem ListNode<TItem>::getInfo() const{
	return info;
}


