/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: tgust
 *
 * Created on October 1, 2019, 2:14 PM
 */

#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <class T2>
struct Link{
    T2 data;
    int timesSearched;
    Link *nextptr;
    Link *backptr;
};

template <class T>
class List{
private:
    
    Link<T> * list;
    int size;
    Link<T> * mergeSortD(Link<T>*);
    Link<T> * mergeSortA(Link<T>*);
    Link<T>* split(Link<T>*);
    Link<T> * MerAsc(Link<T>*, Link<T>*);
    Link<T> * MerDes(Link<T>*, Link<T>*);
    void prioritySearchSort();
    Link<T>* mergePriorSort(Link<T>*);
    Link<T>* MerPrior(Link<T>*, Link<T>*);
public:
    List();
    List(int);
    List(int, T);
    List(int, T*);
    virtual ~List();
    void prntLst();
    //void dstryLst();
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    Link<T> * findEnd();
    bool findVal(T);
    int lstSize(){
        return size;
    }
    int cntVal(T);
    T getNth(const int &);
    void sortD();
    void sortA();
    Link<T>* searchVal(T);
    
    
    //Link operator =(const Link &);
    
    
    
    
};
template <class T>
List<T>::List(){
    size=0;
    Link<T>*list=0;
}
template <class T>
List<T>::List(int size){
    this->size=size;
    //cnt=static_cast<T>(size);
    Link<T> * list =0;
    for (int i=0; i<size; i++){
        
        push_front(static_cast<T>(rand()%90+10));
    }
    
}
template <class T>
List<T>::List(int size, T val){
    size=1;
    Link<T> *list=0;
    push_front(val);
}
template <class T>
List<T>::List(int size, T *val){
    this->size=size;
    list=0;
    for (int i=0; i<size; i++){
        push_front(val[i]);
    }
}
template <class T>
List<T>::~List(){
    Link<T> * front= list, *back;
    while (front){
        Link<T>*temp=front;
        front=front->nextptr;
        delete temp;
    }
    list->nextptr=0;
}
template <class T>
void List<T>::prntLst(){
    Link<T> * front = list;
    while (front){
        
        //cout<<front->timesSearched<<" ";
        cout<<front->data<<"  ";
        front=front->nextptr;
    }
    cout<<endl;
}
template <class T>
void List<T>::push_front(T val){
    
    Link<T> * front=new Link<T>;
    
    front->data=val;
    
    front->nextptr=list;
    
    front->backptr=0;
    front->timesSearched=0;
    //cout<<front->timesSearched;
    
    if(list!=0)list->backptr=front;
    
    //cout<<front->timesSearched<<endl;
    size++;
    list=front;
    
}
template <class T>
void List<T>::push_back(T val){
    Link<T>* back= new Link<T>;
    back->data=val;
    back->nextptr=0;
    back->timesSearched=0;
    Link<T> *end=findEnd();
    if(end!=0)end->nextptr=back;
    back->backptr=end;
    
    size++;
    
}
template <class T>
T List<T>::pop_front(){
    //if (!list)return 0;
    T val = list->data;
    Link<T>*front=list->nextptr;
    delete list;
    front->backptr=0;
    list=front;
    size--;
    return val;
}
template <class T>
T List<T>::pop_back(){
    //if(!list)return 0;
    Link<T> *front=list,*back;
    while(front->nextptr){
        back=front;
        front=front->nextptr;
    }
    T val=front->data;
    delete front;
    back->nextptr=0;
    size--;
    return val;
}
template <class T>
Link<T> *List<T>::findEnd(){
    Link<T> *front= list, *back;
    while(front){
        back=front;
        front=front->nextptr;
    }
    return back;
}
template <class T>
bool List<T>::findVal(T val){
    Link<T> * front= list;
    while (front){
        if (front->data==val){
            front->timesSearched+=1;
            prioritySearchSort();
            return true;
        }
        front=front->nextptr;
        
    }
    return false;
}
template <class T>
int List<T>::cntVal(T val){
    Link<T>*front =list;
    int cnt=0;
    while (front){
        if (front->data==val)cnt++;
        front=front->nextptr ;
        
    }
    return cnt;
}
template <class T>
T List<T>::getNth(const int& sub){
    T val;
    Link<T>*temp=list;
    for (int i=0; i<sub; i++){
        temp=temp->nextptr;
    }
    val=temp->data;
    return val;
}
template <class T>
Link<T>* List<T>::MerAsc(Link<T>*a, Link<T>*b){
    if (!a)return b;
    else if (!b)return a;
    
    if (a->data<b->data){
        a->nextptr=MerAsc(a->nextptr,b);
        a->nextptr->backptr=b;
        a->backptr=0;
        return a;
    }
    else {
        b->nextptr=MerAsc(a,b->nextptr);
        b->nextptr->backptr=b;
        b->backptr=0;
        return b;
    }
}
template <class T>
Link<T>* List<T>::MerDes(Link <T> *a, Link<T>*b){
    if (!a)return b;
    else if (!b)return a;
    
    if (a->data>b->data){
        a->nextptr=MerAsc(a->nextptr,b);
        a->nextptr->backptr=b;
        a->backptr=0;
        return a;
    }
    else {
        b->nextptr=MerAsc(a,b->nextptr);
        b->nextptr->backptr=b;
        b->backptr=0;
        return b;
    }
}
template <class T>
Link<T>* List<T>::split(Link<T> * source){
    Link <T>*fast=source, *slow=source;
    while (fast->nextptr&&fast->nextptr->nextptr){
        fast=fast->nextptr->nextptr;
        slow=slow->nextptr;
    }
    Link<T> *temp=slow->nextptr;
    slow->nextptr=0;
    return temp;
}
template <class T>    
Link<T>* List<T>::mergeSortA(Link<T>* front){
    if (!front||!front->nextptr)return front;
    Link<T> *second=split(front);
    front=mergeSortA(front);
    second=mergeSortA(second);
    
    return MerAsc(front,second);
    
}
template <class T>
Link<T>* List<T>::mergeSortD(Link<T>* front){
    if (!front||!front->nextptr)return front;
    Link<T> *second=split(front);
    front=mergeSortD(front);
    second=mergeSortD(second);
    
    return MerDes(front,second);
}
template <class T>
void List<T>::sortA(){
    list=mergeSortA(list);
}
template <class T>
void List<T>::sortD(){
    list=mergeSortD(list);
}
template <class T>
void List<T>::prioritySearchSort(){
    list=mergePriorSort(list);
}
template <class T>
Link<T>* List<T>::mergePriorSort(Link<T>* front){
    if (!front||!front->nextptr)return front;
    Link<T> *second=split(front);
    front=mergePriorSort(front);
    second=mergePriorSort(second);
    
    return MerPrior(front,second);
}
template <class T>
Link<T>* List<T>::MerPrior(Link<T>* a, Link<T>* b){
    //cout<<a->data<<endl;
    if (!a)return b;
    else if (!b)return a;
    
    //cout<<a->timesSearched<<endl;
    //cout<<a->timesSearched<<endl;
    if (a->timesSearched>=b->timesSearched){
        a->nextptr=MerPrior(a->nextptr,b);
        a->nextptr->backptr=b;
        a->backptr=0;
        return a;
    }
    else {
        b->nextptr=MerPrior(a,b->nextptr);
        b->nextptr->backptr=b;
        b->backptr=0;
        return b;
    }
    //else return a;
}
template <class T>
Link<T>* List<T>::searchVal(T val){
    Link<T> * front= list;
    while (front){
        if (front->data==val){
            front->timesSearched+=1;
            prioritySearchSort();
            return front;
        }
        front=front->nextptr;
        
    }
    return 0;
}
#endif /* LIST_H */

