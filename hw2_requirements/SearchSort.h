/* 
 * File:   SearchSort.h
 * Author: giebasjo (Jordan Giebas)
 * Class:  CSE331 
 * Created on September 15, 2016, 9:38 AM
 */

#ifndef SEARCHSORT_H_
#define SEARCHSORT_H_

#include <iostream>
#include <vector>

using namespace std;

//simpleprint function to print vectors easily
template <typename T>
void simpleprint( vector<T> &vec ){

    for ( unsigned long i = 0; i < vec.size(); i++  ) {

        cout << vec.at(i) << endl;

    }

}

//insertion sort ascending
template <typename T> 
void insertion_sort( vector<T> &vec ) {

    unsigned long i, j, sub;

    for ( j = 1; j < vec.size(); j++ ) {

        i = j;

        while ( ( i > 0 ) && ( vec.at(i-1) > vec.at(i) ) ) {

            sub = vec.at(i);
            vec.at(i) = vec.at(i-1);
            vec.at(i-1) = sub;
            i--;

        }

    }

}

//insertion sort descending
template <typename T>
void insert_sort_dec( vector<T> &vec ) {

    unsigned long i, j, sub;

    for ( j = 1; j < vec.size(); j++ ) {

        i = j;

        while ( ( i > 0 ) && ( vec.at(i-1) < vec.at(i) ) ) {

            sub = vec.at(i);
            vec.at(i) = vec.at(i-1);
            vec.at(i-1) = sub;
            i--;

        }

    }

}



#endif /* SEARCHSORT_H_ */
