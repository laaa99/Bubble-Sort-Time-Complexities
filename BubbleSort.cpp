/*
Lucy Tran
9 - 19 - 16
Function File : Bubble Sort Class
PA1 : Bubblesort

+ public
- private

*Contains vector, size of vector = n
*Member Functions: +removeVectorElements, +generateVectors, -generateVectorsHelper, -generateInorder, -generateReverse, -generateRandom, -randomGenerator
*Non-member Functions:
*/

#include "BubbleSort.h"

/*Constructors*/
BubbleSort::BubbleSort() {
	_n = 0;
}

//N = size of vector
BubbleSort::BubbleSort(const int & n) {

	////http://www.cplusplus.com/reference/vector/vector/vector/
	//vector<int> v(n); //N ints with the value 0
	//_v = v;
	_n = n;
}

/*Destructor*/
BubbleSort::~BubbleSort() {}

/*Getters*/
int const & BubbleSort::getN() const {
	return _n;
}

/*Setters*/
void BubbleSort::setN(int & newN) {
	_n = newN;
}

/*Public Functions*/

//Fills vector with values according to the indicator 
void BubbleSort::generateVectors(int vectorIndicator) {
	
	generateVectorsHelper(vectorIndicator);
}

// sorts the vector of n elements passed in
// returns # of seconds to accomplish the sorting
float BubbleSort::doBubbleSort() {

	int temp = 0; //temporary variable for swapping

	//BubbleSort
	//Refer to: http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm, http://www.algolist.net/Algorithms/Sorting/Bubble_sort

	//Measuring time
	//Refer to: http://en.cppreference.com/w/cpp/chrono

	time_point<system_clock> start, end; //start timer
	start = system_clock::now();

	if (!_v.empty()) //Check if vector is empty
	{
		for (int i = 0; i < _n; i++) {
			for (int j = 0; j < _n - i - 1; j++) {
				//Ascending order
				if (_v[j] > _v[j + 1]) {
					//Swap
					temp = _v[j];
					_v[j] = _v[j + 1];
					_v[j + 1] = temp;
				}
			}
		}

		end = std::chrono::system_clock::now(); //end timer

		duration<float> elapsedSecs = end - start; //Calculate seconds

		return elapsedSecs.count();
	}

	else
	{
		return -1;
	}
}

//Removes all vector elements
void BubbleSort::removeVectorElements() {
	//Refer to: http://www.cplusplus.com/reference/vector/vector/pop_back/
	while (!_v.empty()) {
		_v.pop_back();
	}
}

/*Private Functions*/

//Fills vector with values according to the indicator 
void BubbleSort::generateVectorsHelper(int vectorIndicator) {

	//Vector that is ordered
	if (vectorIndicator == OPTIMAL) {
		generateInorder();
	}

	//Vector in reverse order
	else if (vectorIndicator == AVERAGE) {
		generateRandom();
	}

	else {
		generateReverse();
	}
}

//Fills a vector with values in order
void BubbleSort::generateInorder() {

	for (int i = 0; i < _n; i++) {
		_v.push_back(i); //Adds a new value (i)
	}
}

//Fills a vector with values in reverse order
void BubbleSort::generateReverse() {

	for (int i = _n; i > 0; i--) {
		_v.push_back(i); //Adds a new value (i)
	}
}

//Fills a vector with random values [0, 100]
void BubbleSort::generateRandom() {

	//Generate N random values
	for (int i = 0; i < _n; i++)
	{
		_v.push_back(randomGenerator()); //Adds a new random value
	}
}

//Generates a random number from 0 - 100
int BubbleSort::randomGenerator() {

	//Refer to: http://www.cplusplus.com/reference/cstdlib/rand/ , http://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range

	//initialize random seed: 
	srand(time(NULL));

	//generate number between 0 and 100:
	int x = (rand() % (101));

	return x;
}