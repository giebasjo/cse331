/*
 * KthLargest.h
 *
 *  Created on: 9/8/2016
 *      Author: Jordan Giebas
 *      Homework 1
 *      Due: 9/15/2016
 */

#ifndef KTHLARGEST_H_
#define KTHLARGEST_H_


#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Find the minimum of a vector
 */
template <typename Comparable>
long min_index ( vector<Comparable> &vec ) {

    // need to find MIN : WON'T WORK Comparable minimum = std::min(tempVec);
    typename std::vector<Comparable>::iterator minLocation = std::min_element(std::begin(vec), std::end(vec));
    //long minimum = std::distance(std::begin(vec), minLocation);

    long minimum = minLocation - vec.begin();

    return minimum;

}

/*
 * Use bubble sort to sort vector in
 * increasing order
 */
template <typename Comparable>
void sort ( vector<Comparable> &vec  ) {

    //bubble sort
    unsigned long size = vec.size();

    for ( unsigned i = 0; i < (size - 2); i++  ) {

        for ( unsigned j = 0; j < (size - 2 - i); j++ ) {

            if ( vec.at(j) > vec.at(j+1) ) {

                Comparable temp = vec.at(j);
                vec.at(j) = vec.at(j+1);
                vec.at(j+1) = temp;

            }

        }

    }

}

/*
 * Use bubble sort to sort vector in
 * decreasing order
 */
template <typename Comparable>
void sortDec ( vector <Comparable> &vec ) {

    //bubble sort
    unsigned long size = vec.size();

    for ( unsigned i = 0; i < (size - 2); i++  ) {

        for ( unsigned j = 0; j < (size - 2 - i); j++ ) {

            if ( vec.at(j) < vec.at(j+1) ) {

                Comparable temp = vec.at(j);
                vec.at(j) = vec.at(j+1);
                vec.at(j+1) = temp;

            }
        }
    }
}

/*
 * Use sort method for finding kth largest value
 */
template <typename Comparable>
void select1 ( vector<Comparable> nums, int kthval ) {

    cout << "Approach 1: Using Bubble Sort (decreasing)" << endl;
    cout << "Print the kth largest element" << endl;

    sortDec(nums);

    cout << to_string(kthval) << " th largest element in array --> " << nums.at(kthval) << endl;

}

/*
 * Use temp array for finding kth largest value
 */
template <typename Comparable>
void select2 ( const vector<Comparable> &nums, int kthvalue ) {

    cout << "Approach 2: Using Temporary Vector" << endl;
    cout << "Print the kth largest element" << endl;

    vector<Comparable> tempVec;

    //1: Make a temp array of first k-vals (tempVec)
    for ( unsigned j = 0; j <= kthvalue; j++ ) {

        tempVec.push_back(nums.at(j));

    }

    //find minimum location of tempVec
    long minimumLoc = min_index(tempVec);

    for ( unsigned i = (kthvalue+1); i < nums.size(); i++ ) {

        if ( tempVec.at(minimumLoc) < nums.at(i) ) {

            tempVec.at(minimumLoc) = nums.at(i);

            minimumLoc = min_index(tempVec);

        }

    }

    sortDec(tempVec);

    Comparable minimum = tempVec.at( (kthvalue - 1) );

    cout << to_string(kthvalue) << " th largest element in the array --> " << minimum << endl;

}

#endif /* KTHLARGEST_H_ */
