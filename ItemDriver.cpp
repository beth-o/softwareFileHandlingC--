/*Name:     Beth Marlatt
Class:      CIS269, HW9
Project:    Create a menu-driven software ordering system that
    extracts inventory from a file into a binary tree for searching,
    inserting and deleting, then uploads the modified tree to the file
    when the user is done.
Date:       November 24, 2017
NOTE:       Although I put lots and lots of time into this it is extremely clunky and bugs not worked out- fair warning...
*/

#include <iostream>
#include <vector>
#include<fstream>
#include "ItemClass.h"
#include "windows.h"
#include "conio.h"
using namespace std;

//I made some global variables (not best practice but easier for me
//so I wasn't passing so many parameters to my functions
char decision = 'N';
char choice;
string v, n;   //version,name
int k, q;       //key, quantity
double p;       //price
char checkChoiceStr(char d, string& b); //check user input for new item function below
char checkChoiceInt(char d, int &b);    //check user input for new item function below
char checkChoiceDbl(char d, double &b); //check user input for new item function below
void inputItem(vector<ItemClass> &v);   //function accepts vector of ItemClass objects

int main() {

    //modify window background and font color
    system("color F0");
    //declare a new class to take/put file input/output
    ItemClass classObj;

    //declare a vector to hold the objects for
    //later sorting and placing into a tree structure
    vector<ItemClass> classVector;

    //call read item which will stream file into member vars, then into separate
    //objects, and finally into a vector of objects
    classObj.readItem(classVector);

    //sort the vector to prepare for placing in a tree
    classObj.sortVector(classVector);
    cout << "\n  Here is the current inventory: \n" << endl;

    classObj.printAll(classVector);
    cout << " ----------------End of Items----------------- \n\n";

    cout <<"\n\t\tSoftware File System\n\n" << endl;
    cout << "\t ------------Main Menu-----------------\t" << endl;
    cout << "\t|  (S)earch for Software               |\t" << endl;
    cout << "\t|  (A)dd Software                      |\t" << endl;
    cout << "\t|  (U)pdate Software Item              |\t" << endl;
    cout << "\t|  (D)elete Software Item              |\t" << endl;
    cout << "\t|  (V)iew Inventory                    |\t" << endl;
    cout << "\t|  (Q)uit System                       |\t" << endl;
    cout << "\t -------------------------------------\t" << endl;

    //string to hold user input
    string titleToSearch;

//jump labels used (my bad)
search:
    //flush cin input before taking new search values
    cin.clear();
    fflush(stdin);
    cout << "\n\n  What software are you looking for? " << endl;

    getline(cin, titleToSearch);

    //now search using tree formation-returns the subscript of the search item if found
    int position = classObj.searchBinaryTree(classVector, titleToSearch);

//jump label
backToBegin:
    cout << "  \nWhat is your choice: " ;
    cin >> choice;
    choice = toupper(choice);

    //case statements for menu
    switch (choice) {
    case 'A':           //Add
        inputItem(classVector);
        goto backToBegin;
        break;
    case 'U': {         //Update
        cin.clear();
        fflush(stdin);
        classVector[position].printItem();
        cout << "\n  Is this the item you'd like to update? " ;
        cin >> decision;
        decision = toupper(decision);
        if (decision == 'Y') {
            cout << "  New quantity on hand: " ;
            cin >> q;
            classVector[position].setQuantity(q);
            cout << "  New price for software: " ;
            cin >> p;
            classVector[position].setPrice(p);
            cout << "\n\n  Updated Item Information: " << endl;
            classVector[position].printItem();
        }
        if (decision != 'Y') {
            goto search;
        }
        goto backToBegin;
    }
    break;
    case 'S': {             //Search
        string titleToSearch;
        cin.clear();
        fflush(stdin);
        cout << "  \nWhat software are you looking for? " << endl;
        getline(cin, titleToSearch);

        //now search using tree formation-this function returns the integer of the object's location
        int position = classObj.searchBinaryTree(classVector, titleToSearch);//displays item if found returns position in obj array
        // classVector[position].printItem();

        goto backToBegin;
    }
    break;

    case 'V': {             //View
        cout << "  Here is the current inventory listing: " << endl;
        classObj.printAll(classVector);
        goto backToBegin;
    }
    break;

    case 'D': {
        cout << "  Delete " ;
        classVector[position].printItem();
        cout << "? " ;
        cin.clear();
        cin >> decision;
        decision = toupper(decision);
        if (decision == 'Y') {
            cout << "  Deleting.. " << classVector[position].getName() << endl;
            vector<ItemClass> ::iterator i1 = classVector.begin();
            classVector.erase(classVector.begin()+position);
            cout << "\n\n\n"<< endl;
        }
        goto backToBegin;
    }
    break;

    default:                //default switch is quit- but actually just proceeds to save
        cout << "Quit Program." << endl;
    }

    cout << "\nDo you want to save all your changes\n to the file before exiting? " ;
    cin.clear();
    cin >> decision;
    decision = toupper(decision);
    if (decision == 'Y') {
        cout << "\n\nSaving to file...\n" << endl;
        classObj.saveAll(classVector);
    }
    return 0;
}


//--------------------checkChoice Double Function --------------------------
char checkChoiceDbl(char d, double &b) {
    d = toupper(d);
    while(d == 'N') {
        cout << "Re-enter your software name: " ;
        cin >> b;
        cout << "You entered: " << b << endl;
        cout << "Is this correct (enter y, or n)? ";
        cin >> d;
        d = toupper(d);
    }
    return d;
}

//--------------------checkChoice String Function --------------------------
char checkChoiceStr(char d, string &b) {
    d = toupper(d);
    while(d == 'N') {
        cout << "Re-enter your software name: " ;
        cin >> b;
        cout << "You entered: " << b << endl;
        cout << "Is this correct (enter y, or n)? ";
        cin >> d;
        d = toupper(d);
    }
    return d;
}

//--------------------checkChoice Integer Function --------------------------
char checkChoiceInt(char d, int &b) {

    while(d == 'N') {
        cout << "Re-enter your software name: " ;
        cin >> b;
        cout << "You entered: " << b << endl;
        cout << "Is this correct (enter y, or n)? ";
        cin >> d;
        d = toupper(d);
    }
    return d;
}

//--------------------inputItem Function ---------------------------
void inputItem(vector<ItemClass>&vec) {
    cin.clear();
    ItemClass classObj;
    cout << "Full name of the software: " << endl ;
    cin.ignore();
    fflush(stdin);
    getline(cin,n);
    cout << "You entered: " << n << endl;
    cout << "Is this correct? (y/n) " ;
    cin >> decision;
    checkChoiceStr(decision, n);

    classObj.setName(n);

    cout << "Enter version Info: " ;
    cin.ignore();
    fflush(stdin);
    cin >> v;
    cout << "You entered: " << v << endl ;
    cout << "Is this correct (y/n) " ;
    cin >> decision;
    checkChoiceStr(decision, v);

    classObj.setVersion(v);

    cout << "Enter quantity on hand: " ;
    cin.ignore();
    fflush(stdin);
    cin >> q;
    cout << "You entered: " << q << endl;
    cout << "Is this correct (y/n)? " ;
    cin >> decision;
    checkChoiceInt(decision, q);

    classObj.setQuantity(q);

    cout << "Enter the price: " ;
    cin.ignore();
    fflush(stdin);
    cin >> p ;
    cout << "You entered: " << p << endl;
    cout << "Is this correct (y/n)? " ;
    cin >> decision;
    checkChoiceDbl(decision, p);

    classObj.setPrice(p);

    cout << "\n\nReview the software information before saving." << endl;
    cout << "\tFull Name: \t" << n << endl;
    cout << "\tVersion: \t" << v << endl;
    cout <<"\tQuantity: \t" << q << endl;
    cout << "\tPrice: \t\t$" << p << endl << endl;
    cout << "Save to inventory vector (y/n)? " ;
    cin >> decision;
    decision = toupper(decision);
    if (decision == 'Y') {
        cout << "Are you sure you want to save? " ;
        cin >> decision;
        decision = toupper(decision);
        if (decision == 'N') {
            //  quitProgram();
        }

        if (decision == 'Y') {

            k = vec.size()+2;
            classObj.setKey(k);

            // classObj.setItem(n, v, k, q, p);
            vec.push_back(classObj);
            cout << "Here is the updated vector contents: " << endl;
            classObj.printAll(vec);
        }
    }
}
