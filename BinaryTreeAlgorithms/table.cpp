#include "TreeCreator.h"

int getNewValue(){
    return rand()%1000+1;
}

void insert(node *&root, int value){
    if(root){
        if(value < root->data){
            insert(root->left, value);
        }else
            insert(root->right, value);
    }else{
        root = new node(value);   
    }
}

void findNext(node *&prev, node *&curr){
    if(curr){
        if (curr->left){
            prev = curr;
            curr = curr->left;
            findNext(prev, curr);
        }
    }
}

void remove(node *&root, int target){
    if(root){
        if(root->data == target){
            node    *remove = NULL;
            if(!root->right && !root->left){
                delete root;
                root = NULL;
            }else if(!root->right){
                remove = root;
                root = root->left;
                delete remove;
                remove = NULL;
            }else if(!root->left){
                remove = root;
                root = root->right;
                delete remove;
                remove = NULL;
            }else{
                node    *prev = NULL;
                node    *curr = root->right;
    
                findNext(prev, curr);
                
                root->data = curr->data;
            
                if (!prev)
                    root->right = curr->right;
                else
                    prev->left = curr->right;

                curr->right = NULL;
                delete curr;
            }
        }else if (target < root->data){
            remove(root->left, target);
        }else{
            remove(root->right, target);
        }
    }
}

void removeEven(node *&root){
    if(root){
        if((root->data)%2 == 0){
            node    *remove = NULL;
            if(!root->right && !root->left){
                delete root;
                root = NULL;
            }else if(!root->right){
                remove = root;
                root = root->left;
                delete remove;
                remove = NULL;
            }else if(!root->left){
                remove = root;
                root = root->right;
                delete remove;
                remove = NULL;
            }else{
                node    *prev = NULL;
                node    *curr = root->right; 
                     
                findNext(prev, curr);

                root->data = curr->data;
            
                if (!prev)
                    root->right = curr->right;
                else
                    prev->left = curr->right;

                curr->right = NULL;
                delete curr;
            }
        removeEven(root);
        }else{
            removeEven(root->left);
            removeEven(root->right);
        }
    }
}

void copyTree(node **newRoot, node *&root){
    if(root){
        *newRoot = new node(root->data);
    
        copyTree(&(*newRoot)->left, root->left);
        copyTree(&(*newRoot)->right, root->right);
    }
}

int getMax(node *root){
    if (root->right){
        return getMax(root->right);
    }else
        return root->data;
}

void printLeaves(node *root){
    if(root){
        if (!root->left && !root->right)
            cout << " " << root->data;
        else{
            printLeaves(root->left);
            printLeaves(root->right);
        }
    }
    
}

void traverseReverse(node *root){
    if(root){
        traverseReverse(root->right);
        cout << root->data << " ";
        traverseReverse(root->left);
    }
}

/*int average(node *root){

}*/

int getNodeCount(node *root){
    if (root){
        return 1 + getNodeCount(root->left) + getNodeCount(root->right);
    }
    return 0;
}


