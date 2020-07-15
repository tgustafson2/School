/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: tgust
 *
 * Created on May 31, 2019, 11:17 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"

using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};


#endif /* PROB3TABLEINHERITED_H */

