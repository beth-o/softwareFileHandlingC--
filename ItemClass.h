/*Name: Beth Marlatt
Class: CIS269, HW9
Project: Create a menu-driven software ordering system that
extracts inventory from a file into a binary tree for searching,
inserting and deleting, then uploads the modified tree to the file
when the user is done.
Date: November 24, 2017
*/


#ifndef ITEMCLASS_H
#define ITEMCLASS_H
#include <iostream>
#include <vector>
#include<fstream>
#include<string>
using namespace std;

class ItemClass {
private:
    unsigned int key = 0;
    string name = "";
    string version = "";
    unsigned int quantity = 0; //quantity
    double price = 0; //price

public:
    Item();

    //HTML functions
    void writeRow(ostream &out, string tag, vector<ItemClass> row);

    void setKey(int k);
    void setName(string n);
    void setVersion(string v);
    void setQuantity(int q);
    void setPrice(double p);
    void setItem(string, string, unsigned int, unsigned int, double);
    string getName();
    string getVersion();
    int getKey();
    int getQuantity();
    double getPrice();
    void appendToFile(vector<ItemClass> &v);    //not used
    void sortVector(vector<ItemClass>& v);
    void saveAll(vector<ItemClass>& v);
    int searchBinaryTree(vector<ItemClass> &v, string &itemName);
    void printItem();
    void printAll(vector<ItemClass> &v);
    void readItem(vector<ItemClass> &v);
    friend ostream& operator<<(ostream&, ItemClass&);
    friend istream& operator>>(istream&, ItemClass&);


};

#endif // ITEM_H
