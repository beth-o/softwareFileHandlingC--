#ifndef ITEMCLASS_H
#define ITEMCLASS_H
using namespace std;
#include <iostream>
#include <vector>
#include<list>
#include<fstream>
#include<string>
#include<sstream>


class ItemClass {
private:
    unsigned int key = 0;
    string name = "";
    string version = "";
    unsigned int quantity = 0; //quantity
    double price = 0; //price

public:

    Item();
    vector<ItemClass> v;
    void setKey(int k);
    void setName(string n);
    void createObj();
    void setVersion(string v);
    void setQuantity(int q);
    void setPrice(double p);
    void setItem(string, string, unsigned int, unsigned int, double  );
    string getName();
    string getVersion();
    int getKey();
    int getQuantity();
    double getPrice();
    void putItemInFile();
    void putVectorInFile(vector<ItemClass> &v);
    void getFromFile(istream& in);
    void printItem();
    void printAll(vector<ItemClass> &v);
    void readItem(std::istream& in, vector<ItemClass> &v);
    friend ostream& operator<<(ostream&, ItemClass&);
    friend istream& operator>>(istream&, ItemClass&);


};

#endif // ITEM_H
