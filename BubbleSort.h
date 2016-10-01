#pragma once

/*
Lucy Tran
9 - 19 - 16
Header File : Bubble Sort Class
PA1 : Bubblesort

+ public
- private

*Contains vector, size of vector = n
*Member Functions: +removeVectorElements, +generateVectors, -generateVectorsHelper, -generateInorder, -generateReverse, -generateRandom, -randomGenerator
*Non-member Functions: 
*/

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <ctime>
#include <vector>

#define OPTIMAL 0
#define AVERAGE 1
#define WORST 2

using std::vector;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;

class BubbleSort {

public:
	
	/*Constructors*/
	BubbleSort();
	//N = size of vector
	BubbleSort(const int & n);

	/*Destructor*/
	~BubbleSort();

	/*Getters*/
	int const & getN() const;

	/*Setters*/
	void setN(int & newN);


	/*Public Functions*/

	//Fills vector with values according to the indicator 
	void generateVectors(int vectorIndicator);

	// sorts the vector of n elements passed in
	// returns # of seconds to accomplish the sorting
	float doBubbleSort();

	//Removes all vector elements
	void removeVectorElements();

private:
	vector<int> _v; //Vector to be sorted
	int _n; //size of vector

	/*Private Functions*/

	//Fills vector with values according to the indicator 
	void generateVectorsHelper(int vectorIndicator);

	//Fills a vector with values in order
	void generateInorder();

	//Fills a vector with values in reverse order
	void generateReverse();

	//Fills a vector with random values [0, N]
	void generateRandom();

	//Generates a random number from 0 - 100
	int randomGenerator();
};