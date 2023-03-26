#include "TreeCreator.h"
#include "table.h"

int main(){
    node    *root = NULL;
    build(root);
    display(root);

//inserts value
   /* int value = getNewValue();
    insert(root, value);
    cout << "Inserting " << value << " into list." << endl << endl;
    display(root);*/
    
//removes target value
   /* remove(root, value);    
    cout << "Removing " << value << " from list." << endl << endl;
    display(root);
    
//removes evens
    removeEven(root);
    cout << "Removing Evens." << endl<< endl;
    display(root);*/
    
//copy tree
   /* node    *newRoot = NULL;
    copyTree(&(newRoot), root);
    cout << "Displaying copy:" << endl << endl;
    display(newRoot);
    destroy(newRoot);*/

//Max value
    //cout << "The max value of the list is " << getMax(root) << endl;
    
//displays leaves
    /*cout << endl << " == Displaying Leaves == " << endl;
    printLeaves(root);
    cout << endl;*/

//prints in reverse
    cout << " == Now printing in reverse == " << endl;
    traverseReverse(root);

    cout << endl << "The node count is: " << getNodeCount(root) << endl;

    destroy(root);
}
