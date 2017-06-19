//============================================================================
// Name        : main.cpp
// Author      : Sebnem Onsay
// Version     :
// Copyright   : Your copyright notice
// Description : Homework1
//============================================================================

#include <chrono>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include<random>
#include "KthLargest.h"
using namespace std;

void work_smart1 ( int N, ofstream &results_file, vector<int> &vector1, int k ) {

	/* N = 2000 test
    * Read from file of 2000 different randomly generated numbers
    * between [0,20k].
    * Store into vector
    * Run both methods and calculate the times
    * for each pair write to file
    */

	string inputfile = "/Users/GIBZ/N_";

	inputfile += to_string(N) + ".txt";

	results_file << to_string(N) + " ";

	ifstream inClientFile1(inputfile);

	//check to make sure file is open
	if (!inClientFile1.is_open()) {
		cout << "Could not open file\n";
	}

	int buffer1;

	//insert each value from file into vector
	while (inClientFile1 >> buffer1) {
		vector1.push_back(buffer1);
	}

	//Start clock
	auto time1 = std::chrono::high_resolution_clock::now();
	//perform search1 on the vector:
	select1(vector1, k);
	//Start new clock so we can find the time difference
	auto time2 = std::chrono::high_resolution_clock::now();

	float TotalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(time2 - time1).count();


	//print time it took & write to the Sort_Array_TimeResults.txt
	cout << "Bubble Search method took " << TotalTime << " nanoseconds \n";
	results_file << to_string(TotalTime) + " " + "nanoseconds";

	/*
	//calculate time for method2
	srand(static_cast<unsigned int>(time(0)));
	auto time3 = std::chrono::high_resolution_clock::now();
	select2(vector1, k);
	auto time4 = std::chrono::high_resolution_clock::now();

	TotalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(time4 - time3).count();


	//print time it took & write to the Sort_Array_TimeResults.txt
	cout << "Temp Array method took " << TotalTime << " milliseceonds \n";
	results_file << to_string(TotalTime) + " nanoseconds" << endl;
	*/

	inClientFile1.close();

	vector1.clear();

}


void work_smart2 ( int N, ofstream &results_file, vector<int> &vector1, int k ) {

	/* N = 2000 test
    * Read from file of 2000 different randomly generated numbers
    * between [0,20k].
    * Store into vector
    * Run both methods and calculate the times
    * for each pair write to file
    */

	string inputfile = "/Users/GIBZ/N_";

	inputfile += to_string(N) + ".txt";

	//results_file << to_string(N) + " ";

	ifstream inClientFile1(inputfile);

	//check to make sure file is open
	if (!inClientFile1.is_open()) {
		cout << "Could not open file\n";
	}

	int buffer1;

	//insert each value from file into vector
	while (inClientFile1 >> buffer1) {
		vector1.push_back(buffer1);
	}

	//Start clock
	auto time1 = std::chrono::high_resolution_clock::now();
	//perform search1 on the vector:
	select2(vector1, k);
	//Start new clock so we can find the time difference
	auto time2 = std::chrono::high_resolution_clock::now();

	float TotalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(time2 - time1).count();


	//print time it took & write to the Sort_Array_TimeResults.txt
	cout << "Temp Array Search method took " << TotalTime << " nanoseconds \n";
	results_file << to_string(TotalTime) + " nanoseconds" << endl;

	inClientFile1.close();

	vector1.clear();

}

int main()
{
	//cout<<"In"<<endl;
	//ifstream inClientFile("input_real_small",ios::in);
	ifstream inClientFile("input.in",ios::in);
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

	//Testing Hw1 using Bubble sort returning the largest element
	auto t1 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	//sort array in ascending order, return the last element
	//Generate random k values
	int min=1,max=10;

	random_device rd;     // only used once to initialize (seed) engine
	mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> uni(min,2000); // guaranteed unbiased
	auto kthvalue = uni(rng);

	select1(nums,kthvalue);
	auto t2 = std::chrono::high_resolution_clock::now();
	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Bubble Search method  took "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
			<< " milliseconds \n";    inClientFile.close();
	cout<<endl;


	//Testing Hw1 using temparray approach, sort returning the largest element
	auto t3 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	select2(nums,kthvalue);
	auto t4 = std::chrono::high_resolution_clock::now();


	cout << "Size of the vector : "<< nums.size() << endl;
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count()
			<< " nanoseconds \n";    inClientFile.close();

	//Testing for different data sizes...
	//For this part of your hw you are allowed to modify your main method...
	//your code goes here....

	/*

	cout << "-----------------------" << endl;
	cout << "Different sizes test:\n" << endl;

	//vector that elements from txt files will always be stored to
	vector<int> sizeTest_vec;

	//output file: contains the time results of each
	//			   method for each data size
	ofstream results_file;
	results_file.open("Sort_Array_TimeResults.txt");

	for ( int i = 2000; i < 15000; i += 2000 ) {

		work_smart1(i, results_file, sizeTest_vec, 27);
		work_smart2(i, results_file, sizeTest_vec, 27);

	}

	 */

}




