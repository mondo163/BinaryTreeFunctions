/*
* This is 
* 
* 
*/

#include "TreeCreator.h"

void build(node *&root){
    srand(time(NULL));
    if(!root){
        build(root, getNodes());
    }
}

int getNodes(){
    return rand() % 20 + 1;
}

int getNumbers(){
   return rand() % 1000 + 1;
}

void build(node *&root, int iterations){ 
    if(iterations != 0){
        if (!root){
            root = new node(getNumbers());
           
            build(root, iterations-1);
        }else{ 
            insertNode(root, getNumbers());
            
            build(root, iterations-1); 
        }
    }
}

void insertNode(node *&root, int value){
    if (root){
        if (value < root->data){
            insertNode(root->left, value);
        }else{
            insertNode(root->right, value);
        }
    }else{
        root = new node(value);
    }
}

void display(node *root){
    cout << " === Now displaying the list in order === " << endl;
    traverse(root);
    cout << endl << endl;

    cout << " -- Displaying tree levels -- " << endl;
    display(root, 1);
    cout << endl;
}

void display(node *root, int level){
    if (root){
        cout << "level " << level << ": "
             << root->data;
        
        if(!root->left && !root->right)
            cout << "*" << endl;
        else 
            cout << endl;
        
        display(root->left, level+1);
        display(root->right, level+1);
    }
}

void traverse(node *root){
    if (root){
        traverse(root->left);
        cout << " " << root->data;
        traverse(root->right);
    }
}

void destroy(node *&root){
    if (root){
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = NULL;
    }
}
