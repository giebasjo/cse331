//============================================================================
// Name        : Homework 3.cpp
// Author      : Sebnem Onsay
// Version     :
// Copyright   : Your copyright notice
// Description : Binary Search Practice
//============================================================================

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include<random>
#include "SearchSort2.h"
using namespace std;

bool isSorted(vector<int> A);
bool isSortedDec(vector<int> A);
int main() {

	/* read from file
	 *
	 */
	ifstream inClientFile("input_real_small.in",ios::in);
	// check to see if file opening succeeded

	if ( !inClientFile.is_open() ) {
		cout<<"Could not open file\n";
		return 0;
	}
	vector<int> nums;

	int input_t;
	while( inClientFile >> input_t) {
		nums.push_back(input_t);
	}

        std::sort( nums.begin(), nums.end() );

        for ( auto elm : nums ) {

            cout << elm << ", ";

        }

        cout << "SORTED TEST " << endl;
        cout << isSorted(nums) << endl;

    //TESTING BINARY SEARCH ITERATIVE
    cout<<"++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"TESTING BINARY SEARCH ITERATIVE "<< endl;
    int key=11548;
	auto t_bs = std::chrono::high_resolution_clock::now();
	int indexvalue=binarySearch(nums,key);
	auto t_bsend = std::chrono::high_resolution_clock::now();

	if( indexvalue != -1)
		cout<<"The key value --> " << key << " was found" << " at index = " <<indexvalue << endl;
	else
		cout<<"The key value --> " << key << " was not found" <<" index value is "<< indexvalue<< endl;

	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Binary Search iterative version   took "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(t_bsend-t_bs).count()
			<< " nanoseconds \n";
    cout<<"end of binary search test " <<endl;


    //TESTING BINARY SEARCH RECURSIVE
    cout<<"++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"TESTING BINARY SEARCH RECURSIVE "<< endl;

	auto t_bsrec = std::chrono::high_resolution_clock::now();
	recBinSearch(nums,key);
	auto t_bsrecend = std::chrono::high_resolution_clock::now();

	if( indexvalue != -1)
		cout<<"The key value --> " << key << " was found" << " at index = " <<recBinSearch(nums,key) << endl;
	else
		cout<<"The key value --> " << key << " was not found " << recBinSearch(nums,key)<< endl;

	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Binary Search RECURSIVE version   took "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(t_bsrecend-t_bsrec).count()
			<< " nanoseconds \n";
    cout<<"end of binary search test " <<endl;



}
/*
 * @params: vector
 * @return:bool
 */
bool isSorted(vector<int> A)
{
	for(auto i=0; i<A.size()-1; i++)
	{
		if (!(A[i+1] > A[i]))
			return false;

	}
	return true;

}


bool isSortedDec(vector<int> A)
{
	for(auto i=0; i<A.size()-1; i++)
	{
		if (!(A[i+1] < A[i]))
			return false;

	}
	return true;

}
