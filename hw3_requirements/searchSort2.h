/*
 * SearchSort2.h
 *
 *  Created on: Aug 3, 2016
 *      Author: giebasjo
 *      Class : CSSE331
 *      Due   : 9/29/2016
 */

#ifndef SEARCHSORT2_H_
#define SEARCHSORT2_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Description: Iterative Binary Search
 * Pre:
 * Params:
 * Post:
 */
template <typename Comparable>
Comparable binarySearch ( vector<Comparable> &items, const int key  ) {

    sort(items.begin(), items.end());

    //Declare left and right hand side vars
    int left = 1;
    int right = items.size();

    //Looping through, checking against key and cutting array in half
    while ( left <= right ) {

        //define midpoint and check to see if key is at midpoint
        int midp = left + ((right - left)/2);
        if ( items.at(midp) == key ) {

            return midp;

        }

        //if not, check value at midpoint is less than key 
        else if ( items.at(midp) < key) {

            left = midp + 1;

        }

        //if neither, must be above or not there
        else {

            right = midp - 1;

        }

    }

   // cout << "Not in the list" << endl;
   // return -1;

}

template <typename Comparable>
int recDriver ( vector<Comparable> &items, const int key, int l, int r ) {

    sort(items.begin(), items.end());

    int vec_size = items.size();

    //check to see if the key is even within range of the vector
    if ( items.at(l) > key || items.at(r-1) < key ) {

        return -1; //Item not found

    }

    else if ( items.at(l) == key ) { 
    
        return l; 
    
    }

    else if ( items.at(r-1) == key ) {

        return r-1;

    }

    //assign the midpoint value
    int midp = ( l + r) / 2;
    //cout << "midp, key: " << midp << ", : " << key << endl;
    if ( items.at(midp) == key ) {

        return midp; //found the value at exactly the midpoint woop!

    }

    //if neither case above is hit, need to search lower and upper half
    else {

        //lower half search
        if ( key < items.at(midp) ) {

            //make a recursive call
            recDriver ( items, key, l, midp-1 );

        }

        else {

            //make a recursive call
            recDriver ( items, key, midp+1, r );

        }

    }

}



/*
 * Description: Recursive Binary Search
 * Pre:
 * Params:
 * Post:
 */
template <typename Comparable>
Comparable recBinSearch ( vector<Comparable> &items, const int key) {

    //define the bounds of the vector
    int left = 0;
    int right = items.size();
        //call the driver function
    return recDriver ( items, key, left, right  );

}



#endif /* SEARCHSORT2_H_ */
