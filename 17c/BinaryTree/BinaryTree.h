/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: tgust
 *
 * Created on November 29, 2019, 3:59 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>
#include <string>
#include <valarray>
using namespace std;
template <class T>
struct node{
     T data;
     node *left;
     node *right;
};
template <class T2>
class BinaryTree{
private:
    node<T2> *root;
public:
    BinaryTree(){
        root=NULL;
    }
    BinaryTree(T2 val){
        root=new node<T2>;
        root->data=val;
        root->left=NULL;
        root->right=NULL;
    }
    
    ~BinaryTree(){
        cleanup(root);
    }
    void cleanup(node<T2>*&);
    node<T2>* newNode(T2);
    void prntPst();
    void prntPst(node<T2>*);
    void prntIn();
    void prntIn(node<T2>*);
    void prntPre();
    void prntPre(node<T2>*);
    void prntLev();
    void prntLev(int);
    void prntLev(node<T2>*,int);
    int height(node<T2>*);
    int diff(node<T2>*);
    void insertNode(T2);
    node<T2>* insert(node<T2>*, node<T2>*);
    void remove(T2);
    void deleteNode(T2, node<T2>*&);
    void deletion(node<T2>*&);
    node<T2>* balance(node<T2>*);
    void balance();
    node<T2>* leftrota(node<T2>*);
    node<T2>* rightrota(node<T2>*);
    node<T2>* doubleleft(node<T2>*);
    node<T2>* doubleright(node<T2>*);
    
};
template <class T2>
node<T2>* BinaryTree<T2>::newNode(T2 val){
     node<T2> *n;
     n=new node<T2>;
     n->data = val;
     n->left = NULL;
     n->right = NULL;
     return n;
}
template <class T2>
void BinaryTree<T2>::prntPst(){
    //node* temp=root;
    if (root == NULL)return;
     // first recur on left subtree
     prntPst(root->left);
     // then recur on right subtree
     prntPst(root->right);
     // now deal with the node
     cout<<root->data<<" ";
     //delete temp;
}
template <class T2>
void BinaryTree<T2>::prntPst(node<T2> *root){
    //node* temp=root;
    if (root == NULL)return;
     // first recur on left subtree
     prntPst(root->left);
     // then recur on right subtree
     prntPst(root->right);
     // now deal with the node
     cout<<root->data<<" ";
     //delete temp;
}
template <class T2>
void BinaryTree<T2>::prntIn(){
    //node* temp=root;
     if (root == NULL)return;
     /* first recur on left child */
     prntIn(root->left);
     /* then print the data of node */
     cout<<root->data<<" ";  
     /* now recur on right child */
     prntIn(root->right);
     //delete temp;
}
template <class T2>
void BinaryTree<T2>::prntIn(node<T2>* root){
    //node* temp=root;
     if (root == NULL)return;
     /* first recur on left child */
     prntIn(root->left);
     /* then print the data of node */
     cout<<root->data<<" ";  
     /* now recur on right child */
     prntIn(root->right);
     //delete temp;
}
template <class T2>
void BinaryTree<T2>::prntPre(){
    //node* temp=root;
     if (root == NULL)return;
     /* first print data of node */
     cout<<root->data<<" ";  
     /* then recur on left subtree */
     prntPre(root->left);  
     /* now recur on right subtree */
     prntPre(root->right);
}
template <class T2>
void BinaryTree<T2>::prntPre(node<T2> *root){
    //node* temp=root;
     if (root == NULL)return;
     /* first print data of node */
     cout<<root->data<<" ";  
     /* then recur on left subtree */
     prntPre(root->left);  
     /* now recur on right subtree */
     prntPre(root->right);
}
template <class T2>
void BinaryTree<T2>::prntLev(){
    
    int h = height(root);
    for (int i=1;i<=h;i++){prntLev( i);
    cout<<endl;
    }  
}
template <class T2>
void BinaryTree<T2>::prntLev(int level){
    ///node * temp=root;
    if (root == NULL){
        
        return;}  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}
template <class T2>
void BinaryTree<T2>::prntLev(node<T2> *root,int level){
    //node * temp=root;
    if (root == NULL){
        cout<<"  ";
        return;}  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}
template <class T2>
int BinaryTree<T2>::height(node<T2>* temp){
//    if (node == NULL)return 0; 
//    
//    //compute the height of each subtree
//    int lheight = height(node->left);
//    int rheight = height(node->right);
//    //use the larger one
//    if (lheight > rheight)return(lheight + 1);  
//    else return(rheight + 1);
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
template <class T2>
int BinaryTree<T2>::diff(node<T2>*temp){
    int l_height=height(temp->left);
    int r_height=height(temp->right);
    int b_factor=l_height-r_height;
    return b_factor;
}
template<class T2>
void BinaryTree<T2>::insertNode(T2 val){
    node<T2> *insNode=newNode(val);
  
    root=insert (root,insNode);
//    root=balance(root);
}
template <class T2>
node<T2>* BinaryTree<T2>::insert(node<T2>* root, node<T2>* branch){
   
    if (root==nullptr) {
        root=branch;
        
    }
    else if (branch->data<root->data){root->left=insert (root->left,branch);
    root=balance(root);
    }
    else {root->right=insert (root->right,branch);
    root=balance(root);
    }
    return root;
    
}
template <class T2>
void BinaryTree<T2>::remove (T2 val){
    deleteNode(val, root);
    root=balance(root);
}
template <class T2>
void BinaryTree<T2>::deleteNode(T2 val, node<T2>* &root){
    if (val<root->data){deleteNode(val,root->left);
    root=balance(root);
    }
    else if (val>root->data){
        deleteNode(val,root->right);
    root=balance(root);
    }
    else deletion(root);
    
}
template <class T2>
void BinaryTree<T2>::deletion(node<T2>*& root){
    node<T2>* temp=nullptr;
    if (root==nullptr)cout<<"Can't delete empty node, value is not present"<<endl;
    else if (root->right==nullptr){
        temp=root;
        root=root->left;
        delete temp;
    }
    else if (root->left==nullptr){
        temp=root;
        root=root->right;
        delete temp;
    }
    else{
        temp=root->right;
        while (temp->left)temp=temp->left;
        temp->left=root->left;
        temp=root;
        root=root->right;
        delete temp;
    }
}
template <class T2>
node<T2>* BinaryTree<T2>::balance(node<T2>* root){
//    if (root == NULL)return 0; 
    int bal_factor=diff(root);
//    }while(rheight>lheight+1||lheight>rheight+1);

    if (bal_factor>1){
        
        if (diff(root->left)>0){
            root=leftrota(root);
        }
        else
        root=doubleleft(root);


    }
    else if (bal_factor<-1){
        
        if (diff(root->right)>0){
            root=doubleright(root);
           
        }
        else
        root=rightrota(root);
            
        
        

    }
    
//    }while(rheight>lheight+1||lheight>rheight+1);
    return root;
  
}
template <class T2>
void BinaryTree<T2>::balance(){
    int rheight, lheight;
    do{
    root=balance(root);
    rheight=height(root->right);
    lheight=height(root->left);
    }while(rheight>lheight+1||lheight>rheight+1);
}
template <class T2>
node<T2>* BinaryTree<T2>::rightrota(node<T2>* root){
    node<T2>* temp;
//    temp=root;
//    root=root->left;
//    temp->left=root->right;
//    root->right=temp;
    temp=root->right;
    root->right=temp->left;
    temp->left=root;
//    temp=root;
    return temp;
}
template <class T2>
node<T2>* BinaryTree<T2>::leftrota(node<T2>* root){
    node<T2>* temp;
//    temp=root;
//    root=root->right;
//    temp->right=root->left;
//    root->left=temp;
    temp=root->left;
    root->left=temp->right;
    temp->right=root;
//    temp=root;
    return temp;
}
template <class T2>
node<T2>* BinaryTree<T2>::doubleleft(node<T2>* root){
    node<T2>* temp;
//    cout<<"Double left";
//    root->right=rightrota(root->right);
//    root=leftrota(root);
    temp=root->left;
    root->left=rightrota(temp);
    return leftrota(root);
//    temp=root;
//    return temp;
}
template <class T2>
node<T2>* BinaryTree<T2>::doubleright(node<T2>* root){
    node <T2>*temp;
//    cout<<"Double right";
    temp=root->right;
    root->right=leftrota(temp);
    return rightrota(root);
//    temp=root;
//    return temp;
    
}
template<class T2>
void BinaryTree<T2>::cleanup(node<T2>*&root){
    if (root==NULL)return;
    cleanup(root->right);
    cleanup(root->left);
    delete root;
    root=NULL;
    
}
#endif /* BINARYTREE_H */

