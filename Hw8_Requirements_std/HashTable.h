// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

using namespace std;

#include "BSTree.cpp"

template <typename DataType, typename KeyType>
class HashTable {

  public:

    //rule of 5
    HashTable(int initTableSize);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();

    //additional methods

    unsigned int hash( KeyType kt );

    //============
    // MUTATORS
    //============
    void insert(const DataType& newDataItem);
    bool remove(const KeyType& deleteKey);
    void clear();

    //============
    // ACCESSORS
    //============
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    bool isEmpty() const;
    bool search( const KeyType &searchKey );

    //============
    // DISPLAY
    //============
    void showStructure() const;

  private:

    //private member methods
    void copyTable(const HashTable& source);
    BSTree<DataType, KeyType>* dataTable;
    unsigned int getHash( DataType item );

    //member vars
    int tableSize;
    int numberElms;

};

#endif	// ifndef HASHTABLE_H
