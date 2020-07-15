/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this  file, choose Tools | Templates
 * and open the  in the editor.
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
#include <valarray>
using namespace std;
 
struct node{
     pair<int,string> data;
     node *left;
     node *right;
};
 
class BinaryTree{
private:
    node *root;
public:
    BinaryTree(pair<int,string> val){
        root=new node;
        root->data=val;
        root->left=NULL;
        root->right=NULL;
    }
    BinaryTree(){
        root=NULL;
    }
    ~BinaryTree(){
        cleanup(root);
    }
    void cleanup(node*&);
    node* newNode(pair<int,string>);
    void prntPst();
    void prntPst(node*);
    void prntIn();
    void prntIn(node*);
    void prntPre();
    void prntPre(node*);
    void prntLev();
    void prntLev(int);
    void prntLev(node*,int);
    int height(node*);
    int diff(node*);
    void insertNode(pair<int,string>);
    node* insert(node*, node*);
    void remove(pair<int,string>);
    void deleteNode(pair<int,string>, node*&);
    void deletion(node*&);
    node* balance(node*);
    void balance();
    node* leftrota(node*);
    node* rightrota(node*);
    node* doubleleft(node*);
    node* doubleright(node*);
    
};
 
node* BinaryTree::newNode(pair<int,string> val){
     node *n;
     n=new node;
     n->data = val;
     n->left = NULL;
     n->right = NULL;
     return n;
}
 
void BinaryTree::prntPst(){
    //node* temp=root;
    if (root == NULL)return;
     // first recur on left subtree
     prntPst(root->left);
     // then recur on right subtree
     prntPst(root->right);
     // now deal with the node
     cout<<root->data.second<<" "<<root->data.first<<endl;
     //delete temp;
}
 
void BinaryTree::prntPst(node *root){
    //node* temp=root;
    if (root == NULL)return;
     // first recur on left subtree
     prntPst(root->left);
     // then recur on right subtree
     prntPst(root->right);
     // now deal with the node
     cout<<root->data.second<<" "<<root->data.first<<endl;
     //delete temp;
}
 
void BinaryTree::prntIn(){
    //node* temp=root;
     if (root == NULL)return;
     /* first recur on left child */
     prntIn(root->left);
     /* then print the data of node */
     cout<<root->data.second<<" "<<root->data.first<<endl;  
     /* now recur on right child */
     prntIn(root->right);
     //delete temp;
}
 
void BinaryTree::prntIn(node* root){
    //node* temp=root;
     if (root == NULL)return;
     /* first recur on left child */
     prntIn(root->left);
     /* then print the data of node */
     cout<<root->data.second<<" "<<root->data.first<<endl;  
     /* now recur on right child */
     prntIn(root->right);
     //delete temp;
}
 
void BinaryTree::prntPre(){
    //node* temp=root;
     if (root == NULL)return;
     /* first print data of node */
     cout<<root->data.second<<" "<<root->data.first<<endl;  
     /* then recur on left subtree */
     prntPre(root->left);  
     /* now recur on right subtree */
     prntPre(root->right);
}
 
void BinaryTree::prntPre(node *root){
    //node* temp=root;
     if (root == NULL)return;
     /* first print data of node */
     cout<<root->data.second<<" "<<root->data.first<<endl;  
     /* then recur on left subtree */
     prntPre(root->left);  
     /* now recur on right subtree */
     prntPre(root->right);
}
 
void BinaryTree::prntLev(){
    
    int h = height(root);
    for (int i=1;i<=h;i++){prntLev( i);
    cout<<endl;
    }  
}
 
void BinaryTree::prntLev(int level){
    ///node * temp=root;
    if (root == NULL){
        
        return;}  
    if (level == 1)  
        cout << root->data.second << " "<<root->data.first;  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}
 
void BinaryTree::prntLev(node *root,int level){
    //node * temp=root;
    if (root == NULL){
        cout<<"  ";
        return;}  
    if (level == 1)  
        cout << root->data.second << " "<<root->data.first;  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}
 
int BinaryTree::height(node* temp){
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
 
int BinaryTree::diff(node*temp){
    int l_height=height(temp->left);
    int r_height=height(temp->right);
    int b_factor=l_height-r_height;
    return b_factor;
}

void BinaryTree::insertNode(pair<int,string> val){
    node *insNode=newNode(val);
  
    root=insert (root,insNode);
//    root=balance(root);
}
 
node* BinaryTree::insert(node* root, node* branch){
   
    if (root==NULL) {
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
 
void BinaryTree::remove (pair<int,string> val){
    deleteNode(val, root);
    root=balance(root);
}
 
void BinaryTree::deleteNode(pair<int,string> val, node* &root){
    if (val<root->data){deleteNode(val,root->left);
    root=balance(root);
    }
    else if (val>root->data){
        deleteNode(val,root->right);
    root=balance(root);
    }
    else deletion(root);
    
}
 
void BinaryTree::deletion(node*& root){
    node* temp=NULL;
    if (root==NULL)cout<<"Can't delete empty node, value is not present"<<endl;
    else if (root->right==NULL){
        temp=root;
        root=root->left;
        delete temp;
    }
    else if (root->left==NULL){
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
 
node* BinaryTree::balance(node* root){
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
 
void BinaryTree::balance(){
    int rheight, lheight;
    do{
    root=balance(root);
    rheight=height(root->right);
    lheight=height(root->left);
    }while(rheight>lheight+1||lheight>rheight+1);
}
 
node* BinaryTree::rightrota(node* root){
    node* temp;
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
 
node* BinaryTree::leftrota(node* root){
    node* temp;
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
 
node* BinaryTree::doubleleft(node* root){
    node* temp;
//    cout<<"Double left";
//    root->right=rightrota(root->right);
//    root=leftrota(root);
    temp=root->left;
    root->left=rightrota(temp);
    return leftrota(root);
//    temp=root;
//    return temp;
}
 
node* BinaryTree::doubleright(node* root){
    node *temp;
//    cout<<"Double right";
    temp=root->right;
    root->right=leftrota(temp);
    return rightrota(root);
//    temp=root;
//    return temp;
    
}

void BinaryTree::cleanup(node*&root){
    if (root==NULL)return;
    cleanup(root->right);
    cleanup(root->left);
    delete root;
    root=NULL;
    
}
#endif /* BINARYTREE_H */

