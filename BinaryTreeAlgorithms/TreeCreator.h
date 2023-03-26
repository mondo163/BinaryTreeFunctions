/* The tree creator is in charge of building and editing the binary tree
*  
* 
*/


#ifndef TREECREATOR_H
#define TREECREATOR_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

struct node{
    int     data;
    node    *left;
    node    *right;

    node():data(0), left(NULL), right(NULL){}
    node(const int aData):data(aData), left(NULL), right(NULL){}
};

void build(node *&root);
int getNodes();
int getNumbers();
void build(node *&root, int iterations);
void insertNode(node *&root, int value);

void display(node *root);
void display(node *root, int level);
void traverse(node *root);

void destroy(node *&root);

#endif
