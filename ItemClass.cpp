#include <iostream>
#include<ostream>
#include <vector>
#include<list>
#include<fstream>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include "ItemClass.h"
using namespace std;

void ItemClass:: readItem(std::istream& in, vector<ItemClass> &v){

    while(!in.eof()){
    getline(in, name);
    getline(in, version);
    string line;
    getline(in, line);
    istringstream data(line);

    data >> key >> quantity >> price;
    ItemClass result;
    result.setItem(name, version, key, quantity, price);
    result.printItem();
    v.push_back(result);
    }
}

void ItemClass::setItem(string n, string v, unsigned int k, unsigned int q, double p ) {
    name = n;
    version = v;
    key = k;
    quantity = q;
    price = p;
}

void ItemClass::getFromFile(istream &file){

    getline(file, name);
    getline(file, version);
    string line;
    getline(file, line);
    istringstream myStream(line) ;
    myStream >> key >> quantity >> price;
//    std::istringstream data(line);
   // getline(line);
   // in >> key;
    //in >> quantity;
    //in >> price;

    setItem(name, version, key, quantity, price);
  //  cin.ignore();
}


void ItemClass::putItemInFile(){
    fstream fileIO;
    fileIO.open("fileIO.txt", ios::app);
        if (!fileIO) {
        cerr << "File Error. Output file." << endl;
      //  fileIO.close();
    }
    fileIO << getName() << endl << getVersion() << endl << getKey() << " " << getQuantity() << " " << getPrice() << endl;
 //   fileIO.close();
}

void ItemClass::putVectorInFile(vector<ItemClass> &v){

//did not get to this
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
ostream& operator<<(ostream& o, ItemClass& c) {
    o << c.getName();
    return o;
}

void ItemClass::printItem() {
    cout << "Key: " << key << endl;
    cout << "Name: " << name << endl;
    cout << "Version: " << version << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: $" << price << endl<< endl;
}
void ItemClass::printAll(vector<ItemClass> &v){
    for (unsigned int i = 0; i < v.size(); ++i){
        v[i].printItem();

    }


}
