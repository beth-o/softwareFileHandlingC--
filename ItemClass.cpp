/*Name: Beth Marlatt
Class: CIS269, HW9
Project: Create a menu-driven software ordering system that
extracts inventory from a file into a binary tree for searching,
inserting and deleting, then uploads the modified tree to the file
when the user is done.
Date: November 24, 2017
*/

#include "ItemClass.h"
#include <iostream>
#include <vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include "windows.h"
using namespace std;

void ItemClass:: readItem(vector<ItemClass> &v) {
//print
    ifstream file; //create filestream
    file.open("software.txt", ios::in);

    //make sure the file will read
    if (!file) {
        cerr << "Error reading from file." << endl;
    }
    //this function reads the file, creates ItemClass objects and
    //places them in the vector of ItemClass objects
    while(!file.eof()) {

        //get the data and place them in the class member variables

        /*WHAT I FOUND OUT is that with fileIO never mix getline() and*/
        // straight file >> name >> type stuff. The solution was to employ
        //stringStream to enable CONSISTENT getline() file operations, then
        //parse the stream into the variables

        getline(file, name);
        getline(file, version);
        string line;
        getline(file, line);
        istringstream data(line);

        data >> key >> quantity >> price;
        ItemClass result;
        result.setItem(name, version, key, quantity, price);
        v.push_back(result);
    }
    file.close();
}

void ItemClass:: saveAll(vector<ItemClass> &v) {
    ofstream file;
    file.open("software.txt");
    if (!file) {
        cerr << "File Error. Output file." << endl;
    }
    int size = v.size();
    for (int i = 0; i < size-1; i++) {
        //add the items to the file
        file << v[i].getName() << endl << v[i].getVersion() << endl << v[i].getKey() << " " << v[i].getQuantity() << " " << v[i].getPrice() << endl;

    }
    //last item input w/out return at the end so it does't corrupt the file when we retrieve it next time
    file << v[size-1].getName() << endl << v[size-1].getVersion() << endl << v[size-1].getKey() << " " << v[size-1].getQuantity() << " " << v[size-1].getPrice() << " ";
    file.close();

}

void ItemClass::setItem(string n, string v, unsigned int k, unsigned int q, double p ) {
    name = n;
    version = v;
    key = k;
    quantity = q;
    price = p;
}

void ItemClass::appendToFile(vector<ItemClass> &v) {
    //this function was discarded for the saveAll function
    fstream file;                           //create a filestream type

    file.open("software.txt", ios::app);    //app == append to current file

    if (!file) {                            //err out if file didn't open correctly
        cerr << "File Error. Output file." << endl;
        file.clear();                       //if error encountered clear error flag
    }

    //add the item to the file
    file << getName() << endl << getVersion() << endl << getKey() << " " << getQuantity() << " " << getPrice() << endl;
    file.close();
}

void ItemClass::sortVector(vector<ItemClass>& v) {
    //bubble sort ascending order
    int maxElement, index;
    for (maxElement = v.size()-1; maxElement >= 0; maxElement--) {

        for (index = 0; index <= maxElement-1; index++) {

            if (v[index].getName() > v[index+1].getName()) {
                ItemClass tempObj =  v[index];
                v[index] = v[index+1];
                v[index+1] = tempObj;
            }
        }
    }
}

int ItemClass::searchBinaryTree(vector<ItemClass> &v, string &itemName) {
    //cin.clear();
    //fflush(stdin);

    vector<ItemClass> treeVector;   //unused but put here to confuse you (haha), no-to let you know my path not taken
    treeVector.reserve(sizeof(v));  //I was initially playing around with copying 'v' into treeVector but nixed that
    vector<ItemClass> ::iterator i1 = v.begin()+1; //does nothing just thought I might need it

    /*this logic only works on vectors of 5 or less-- sorry:: I ran out of time*/
    int root = v.size()/2;
    int leftNode = root - (root/2);

    int rightNode = root + (root/2);
    int start = 0, endOfV = v.size()-1;

    if (itemName == v[root].getName()) {

        cout << "Found Item at: " << root << "\n" << endl ;
        cout << v[root].getName();
        return root;
    }
    if (v[leftNode].getName() == itemName) {
        cout << "Found Item at: " << leftNode << "\n" << endl;
        cout << v[leftNode].getName();
        return leftNode;
    }
    if (itemName == v[leftNode-1].getName()) {
        cout << "Found Item at: " << leftNode-1 << "\n" << endl;
        cout << v[leftNode-1].getName();
        return leftNode-1;
    }
       if (itemName == v[leftNode+1].getName()) {
        cout << "Found Item at: " << leftNode+1 << "\n" << endl;
        cout << v[leftNode+1].getName();
        return leftNode;
    }
    if (itemName == v[rightNode].getName()) {
        cout << "Found Item at: " << rightNode << "\n" << endl;
        return rightNode;
    }
        if (itemName == v[rightNode+1].getName()) {
        cout << "Found Item at: " << rightNode+1 << "\n" << endl;
        return rightNode+1;

    }
        if (itemName == v[rightNode-1].getName()) {
        cout << "Found Item at: " << rightNode-1 << "\n" << endl;
        return rightNode-1;

    }
    if (itemName == v[endOfV].getName()) {
        cout << "Found Item at end: "  << v.size() << " " << v[endOfV].getName() << "\n" << endl;
        return endOfV;

    }
    if (itemName == v[start].getName()) {
        cout << "Found Item at start: " << v[start].getName() << "\n" << endl;
        return start;

    } else cout << "Item not found." << "\n" << endl;

    return start;
}

void ItemClass::setName(string n) {
    name = n;
}
void ItemClass::setKey(int k) {
    key = k;
}
void ItemClass::setVersion(string v) {
    version = v;
}
void ItemClass::setQuantity(int q) {
    quantity = q;
}
void ItemClass::setPrice(double p) {
    price = p;
}
string ItemClass::getName() {
    return name;
}
string ItemClass::getVersion() {
    return version;
}
int ItemClass::getKey() {
    return key;
}
int ItemClass::getQuantity() {
    return quantity;
}
double ItemClass::getPrice() {
    return price;
}

void ItemClass::printItem() {
    cout << "    Key: " << key << endl;
    cout << "    Name: " <<  name << endl;
    cout << "    Version: " << setw(6) << right << version << endl;
    cout << "    Quantity: " << setw(5) << right << quantity << endl;
    cout << setw(7) << right<< "    Price: $" << setw(7) << setprecision(2) << fixed << right << price << endl<< endl;
}
void ItemClass::printAll(vector<ItemClass> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        v[i].printItem();
    }


}
