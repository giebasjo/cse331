/*
 * File   : HashTable.cpp
 * Author : giebasjo (Jordan Giebas)
 * Class  : CSE331
 * Proj   : Hw8
 * Created on December 5, 2016, 5:03 PM
 */

#include <iostream>
#include <functional>
#include <unordered_set>
#include <string>
using std::string;
#include "HashTable.h"

/*
 * @pre    : none
 * @param  : integer- table size
 * @post   : HashTable created
 * @return : none
 */
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize) {

    tableSize = initTableSize;
    dataTable = new BSTree<DataType, KeyType>[tableSize];
    numberElms = 0;

}

/*
 * @pre    : Hash Table
 * @param  : Different Hash Table source of copying
 * @post   : Copies hash table from source to this
 * @return : None
 */
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& source) {

    copyTable(source);

}

/*
 * @pre    : Hash Table to compare
 * @param  : Different Hash Table source of assignment
 * @post   : Assigns one hash table to another
 * @return : none
 */
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>&
HashTable<DataType, KeyType>::operator=(const HashTable& source) {

    if (&source != this) {

        delete[] dataTable;
        copyTable(source);

    }

    return *this;

}

/*
 * @pre    : Hash Table
 * @param  : Different Hash Table source of copying
 * @post   : Copies hash table from source to this
 * @return : None
 */
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {

    BSTree<DataType, KeyType>* temp;
    (*this).dataTable = source.dataTable;
    (*this).numberElms = source.numberElms;

}

/*
 * @pre    : HashTable object needs to exist
 * @param  : none
 * @post   : Deleted HashTable
 * @return : none
 */
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {

    (*this).clear();

    delete[] dataTable;

}

/*
 * @pre    : none
 * @param  : DataType obj
 * @post   : none
 * @return : Unsigned int, address of key
 */
template <typename DataType, typename KeyType>
unsigned HashTable<DataType, KeyType>::getHash( DataType item ) {

    return DataType::hash( item.getKey() ) % tableSize;

}

/*
 * @pre    : Hash Table created
 * @param  : newDataItem
 * @post   : Hash Table Modified, added newDataItem
 * @return : none
 */
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) {

    //need to find where to insert the BST into the Hash Table, use static hash method
    unsigned newIndex = getHash( newDataItem );

    // this thing is a BST -> (*this).dataTable[newIndex]
    (*this).dataTable[newIndex].insert( newDataItem );

}

/*
 * @pre    : Hash Table created
 * @param  : KeyType deleteKey
 * @post   : Hash Table Modified, removed key
 * @return : none
 */
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) {

    unsigned keyIndex = DataType::hash( deleteKey );
    keyIndex = keyIndex % tableSize;

    if ( dataTable[keyIndex].isEmpty() ) {

        return false;

    }

    else {

        dataTable[keyIndex].remove( deleteKey );
        return true;

    }


}

/*
 * @pre    : none
 * @param  : searchKey, returnItem
 * @post   : same
 * @return : boolean, data found
 */
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {

    unsigned keyIndex = DataType::hash( searchKey );
    keyIndex = keyIndex % tableSize;

    return dataTable[keyIndex].retrieve( searchKey, returnItem );

}

/*
 * @pre    : HashTable
 * @param  : none
 * @post   : HashTable cleared, all elms removed
 * @return : none
 */
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {

    for ( auto i = 0; i < tableSize; i++ ) {

        dataTable[i].clear();
        numberElms -= 1;

    }

}

/*
 * @pre    : none
 * @param  : none
 * @post   : none
 * @return : boolean, empty or non-empty
 */
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {

    return ( numberElms == 0 );

}

/*
 * @pre    : none
 * @param  : none
 * @post   : none
 * @return : none
 */
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {

    for (int i = 0; i < tableSize; ++i) {

        cout << i << ": "; dataTable[i].showStructure();

    }

}
