#pragma once

/*
Lucy Tran
9 - 19 - 16
Header File : Bubble Sort Wrapper Class
PA1 : Bubblesort

+ public
- private

*Contains ofstream obj, BubbleSort objs + BubbleSortData dataObj for each n
*Member Functions: +run, -setData, -setOptimalData, -setAverageData, -setWorstData
*Non-member Functions:
*/

#include "BubbleSort.h"
#include "BubbleSortData.h"

#include <fstream>

using std::ofstream;

class BubbleSortWrapper {
public:

	/*Constructor*/

	BubbleSortWrapper();

	//Sets size of vector
	BubbleSortWrapper(int n);

	/*Destructor*/
	~BubbleSortWrapper();

	/*Public Functions*/

	//Wraps everything up for the final result
	void static run();

private:
	BubbleSort _sort;
	BubbleSortData _sortData;

	/*Private Functions*/

	//*One data line in csv 
	void setData(int n);

	//Set Optimal Data
	void setOptimalData(int &n);

	//Set Average Data
	void setAverageData(int &n);

	//Set Worst Data
	void setWorstData(int &n);
};

//*Equivalent to one line in the csv file
//When you write BubbleSortData obj to a file, it will be the same as printing it out to the console.
//ofstream & operator<< (ofstream &outputFile, BubbleSortData dataObj);