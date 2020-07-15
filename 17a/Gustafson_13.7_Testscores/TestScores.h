/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScores.h
 * Author: tgust
 *
 * Created on April 30, 2019, 9:40 PM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H
class TestScores{
private:
    int test1;
    int test2;
    int test3;
    float sum;
public:
    TestScores(int x, int y, int z){
        test1=x;
        test2=y;
        test3=z;
        sum=x+y+z;
       
    }
    void set1(int x){
        test1=x;
    }
    void set2(int y){
        test2=y;
    }
    void set3(int z){
        test3=z;
    }
    int get1(){
        return test1;
    }
    int get2(){
        return test2;
    }
    int get3(){
        return test3;
    }
    float getaverage(){
        return sum/3;
    }
};


#endif /* TESTSCORES_H */

