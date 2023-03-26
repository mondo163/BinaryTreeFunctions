#ifndef TABLE_H
#define TABLE_H
#include "TreeCreator.h"

//prototypes
int getNewValue();
void insert(node *&root, int value);
void findNext(node *&prev, node *&curr);
void remove(node *&root, int target);
void removeEven(node *&root);
void copyTree(node **newRoot, node *&root);
int getMax(node *root);
void printLeaves(node *root);
void traverseReverse(node *root);
//int average(node *root);
int getNodeCount(node *root);
#endif
