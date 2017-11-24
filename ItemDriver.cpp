#include <iostream>
#include<ostream>
#include <vector>
#include<list>
#include<fstream>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include "ItemClass.h"
using namespace std;

char decision = 'N';
char choice;
char checkChoiceStr(char d, string& b);
char checkChoiceInt(char d, int &b);
char checkChoiceDbl(char d, double &b);
char quitProgram(); //quit program function
void inputItem();
void sortVector(vector<ItemClass> &v);
void swapItems(string &a, string &b);
void printVector(vector<ItemClass> &v);
void resetVars(string &n, string &v, int &k, int &q, double &p);
string objName;
ItemClass *tempObj;
string v, n ; //version,name
int k, q; //key, quantity
double p; //price

int main() {

    //declare classes for each software item
    ItemClass photoshop;
    ItemClass nortonU;
    ItemClass nSysWorks;
    ItemClass vsPro;

    //load class objects primitively
    nortonU.setItem("Norton Utilities", "n/a", 1, 10, 50);
    vsPro.setItem( "Visual Studio Professional", "2020", 3, 19, 700);
    nSysWorks.setItem("Norton System Works 2009", "", 0, 10, 50);

    //declare a new class to play with file input/output
    ItemClass classObj;

    //declare a vector to hold the objects for
    //later sorting and placing into a tree structure
    vector<ItemClass> classVector;
    vector<ItemClass>fileIO_Vector;
    ifstream file; //create filestream
    file.open("software.txt");

    //make sure the file will read
    if (!file) {
        cerr << "Error reading from file." << endl;
        return EXIT_FAILURE; //system  message
    }
    classObj.readItem(file, classVector);
    file.close();

      for (unsigned int i = 0; i < fileIO_Vector.size(); ++i) {
        fileIO_Vector[i].putItemInFile();
    }
    //  cout << "here is the object we extracted from the IO File': \n" << endl;
  //  printVector(fileIO_Vector);
    for (unsigned int count = fileIO_Vector.size()-1; count >= 0; --count) {
        //this loop compares elements with their neighbor
        for (unsigned int index = 0; index < fileIO_Vector.size()-1; index++) {

            if (fileIO_Vector[index].getName() > fileIO_Vector[index+1].getName()) {
                string temp =  fileIO_Vector[index].getName();
                fileIO_Vector[index].getName() = fileIO_Vector[index+1].getName();
                fileIO_Vector[index+1].getName() = temp;
            }
        }
}
//sort(objs.begin(), objs.end(), [](const MyClass& lhs, const MyClass& rhs){ return lhs.value < rhs.value; });



//    sortVector(fileIO_Vector);
//   sortVector( fileIO_Vector);
//  sort(fileIO_Vector.begin(), fileIO_Vector.end());
    printVector(fileIO_Vector);
    ItemClass tempObj;

    classVector.push_back(pshop);
    classVector.push_back(nortonU);
    classVector.push_back(vsPro);
    classVector.push_back(nSysWorks);

    cout << "again retrieving from file putting into an object: " << endl;


    cout <<"\n\t\tSoftware File System\n\n" << endl;
    cout << "\t   ------------Main Menu-----------------" << endl;
    cout << "\t|  (A)dd Software                      |" << endl;
    cout << "\t|  (U)pdate Software Item              |" << endl;
    cout << "\t|  (D)elete Software Item              |" << endl;
    cout << "\t|  (V)iew Inventory                    |" << endl;
    cout << "\t|  (Q)uit System                       |\n" << endl;
    cout << "\t -------------------------------------" << endl;

    cout << "What is your choice: " ;
    cin >> choice;
    choice = toupper(choice);
    while (!choice) {
        cout << "Error: enter a letter." ;
        cin.clear();
        cin >> choice;
        choice = toupper(choice);
    }
    if (choice == 'A' ) {
        inputItem();
    }
    if(choice == 'V') {

    }
    return 0;
}
//--------------------printVector Function ---------------------------
void printVector(vector<ItemClass> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        v[i].printItem();
    }
}
//--------------------sortVector Function ----------------------------
void sortVector(vector<ItemClass> &v) {

    //start at the end of the array
    for (unsigned int i = v.size()-1; i >= 0; --i) {
        //this loop compares elements with their neighbor
        for (unsigned int index = 0; index < v.size()-1; index++) {

            if (v[index].getName() > v[index+1].getName()) {
                string temp =  v[index].getName();
                v[index].getName() = v[index+1].getName();
                v[index+1].getName() = temp;

            }
        }
    }

}
//----------------------swap Function ------------------------------
void swapItems(string &a, string &b) {
    string temp;
    temp = a;
    a = b;
    b = temp;
}


//--------------------printAll Function ----------------------------
void printAll(vector<ItemClass> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        v[i].printItem();
    }
}
//--------------------resetVars Double Function ----------------------------
void resetVars(string &n, string &v, int &k, int &q, double &p) {
    n = "";
    v = "";
    k +=1;
    q = 0;
    p = 0;
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
void inputItem() {
    cout << "Enter a one-word description for the software: " << endl ;
    cin >> objName ;
    cout << "You entered " << objName << " " ;
    cout << "Is this correct? " ;
    cin >> decision;
    checkChoiceStr(decision, objName);
    cin.clear();
    cout << "Full name of the software: " << endl ;
    cin.ignore();
    getline(cin,n);
    cout << "You entered: " << n << endl;
    cout << "Is this correct? " ;
    cin >> decision;
    checkChoiceStr(decision, n);
    cout << "Enter version Info: " ;
    cin >> v;
    cout << "You entered: " << v << endl ;
    cout << "Is this correct (y/n)" ;
    cin >> decision;
    checkChoiceStr(decision, v);
    cout << "Enter quantity on hand: " ;
    cin >> q;
    cout << "You entered: " << q << endl;
    cout << "Is this correct (y/n)? " ;
    cin >> decision;
    checkChoiceInt(decision, q);
    cout << "Enter the price: " ;
    cin >> p ;
    cout << "You entered: " << p << endl;
    cout << "Is this correct (y/n)? " ;
    cin >> decision;
    checkChoiceDbl(decision, p);
    cout << "\n\nReview the software information before saving." << endl;
    cout << "\tShort Name: \t" << objName << endl;
    cout << "\tFull Name: \t" << n << endl;
    cout << "\tVersion: \t" << v << endl;
    cout <<"\tQuantity: \t" << q << endl;
    cout << "\tPrice: \t\t$" << p << endl << endl;
    cout << "Save to inventory (y/n)? " ;
    cin >> decision;
    decision = toupper(decision);
    if (decision == 'Y') {
        cout << "Are you sure you want to save? " ;
        cin >> decision;
        if (decision == 'N') {
            //  quitProgram();
        }
        decision = toupper(decision);

        if (decision == 'Y') {
            ItemClass objName;
            k++;
            objName.setItem(n, v, k, q, p);
            objName.putItemInFile();
        }
    }
}

//--------------------quitProgram Function ---------------------------

char quitProgram() {
    return 0;
}

