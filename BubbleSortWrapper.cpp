/*
Lucy Tran
9 - 19 - 16
Function File : Bubble Sort Wrapper Class
PA1 : Bubblesort

+ public
- private

*Contains BubbleSort obj, BubbleSortData obj2
*Member Functions: +run, -setData, -setOptimalData, -setAverageData, -setWorstData
*Non-member Functions: 
*/

#include "BubbleSortWrapper.h"

/*Constructor*/
BubbleSortWrapper::BubbleSortWrapper() {}

//Sets size of vector
BubbleSortWrapper::BubbleSortWrapper(int n) {

	//Set size
	_sort.setN(n);
	_sortData.setN(n);
}

/*Destructor*/
BubbleSortWrapper::~BubbleSortWrapper() {}

/*Public Functions*/

//Wraps everything up for the final result
void BubbleSortWrapper::run() {

	//Open file
	ofstream outputFile;
	outputFile.open("BSStats.csv");

	//Labels
	outputFile << "NSize, OptimalTime, WorstTime, AverageTime, Run1, Run2, Run3, Run4, Run5" << endl;

	//Create BubbleSortWrappers according to all n's needed, output to file
	BubbleSortWrapper _10;
	_10.setData(10);
	outputFile << _10._sortData;
	BubbleSortWrapper _50;
	_50.setData(50);
	outputFile << _50._sortData;
	BubbleSortWrapper _100;
	_100.setData(100);
	outputFile << _100._sortData;
	BubbleSortWrapper _500;
	_500.setData(500);
	outputFile << _500._sortData;
	BubbleSortWrapper _1000;
	_1000.setData(1000);
	outputFile << _1000._sortData;
	BubbleSortWrapper _5000;
	_5000.setData(5000);
	outputFile << _5000._sortData;
	BubbleSortWrapper _10000;
	_10000.setData(10000);
	outputFile << _10000._sortData;

	/*One Run for each case*/
	int _n50000 = 50000; //Set int for n

	BubbleSortWrapper _50000;

	_50000._sort.setN(_n50000); //set vector size
	_50000._sortData.setN(_n50000); //set n for data

	_50000._sort.generateVectors(OPTIMAL); //Create vector
	_50000._sortData.getOptimal().setAvg(_50000._sort.doBubbleSort()); //do one run only
	_50000._sort.removeVectorElements(); //clear vector

	_50000._sort.generateVectors(AVERAGE); //Create vector
	_50000._sortData.getAverage().setAvg(_50000._sort.doBubbleSort()); //do one run only
	_50000._sort.removeVectorElements(); //clear vector

	_50000._sort.generateVectors(WORST); //Create vector
	_50000._sortData.getWorst().setAvg(_50000._sort.doBubbleSort()); //do one run only
	_50000._sort.removeVectorElements(); //clear vector

	outputFile << _50000._sortData;

	//Don't have to do this anymore
	/*BubbleSortWrapper _100000;
	_100000.setData(100000);
	outputFile << _100000._sortData;*/

	outputFile.close();
}

/*Private Functions*/

//*One data line in csv 
void BubbleSortWrapper::setData(int n) {
	setOptimalData(n);
	setAverageData(n);
	setWorstData(n);
}

//Set Optimal Data
void BubbleSortWrapper::setOptimalData(int &n) {
	
	_sort.setN(n);
	_sort.generateVectors(OPTIMAL); //Create vector
	_sortData.setN(n);
	_sortData.getOptimal().setT1(_sort.doBubbleSort()); //Set Trials/Avg
	_sortData.getOptimal().setT2(_sort.doBubbleSort());
	_sortData.getOptimal().setT3(_sort.doBubbleSort());
	_sortData.getOptimal().setT4(_sort.doBubbleSort());
	_sortData.getOptimal().setT5(_sort.doBubbleSort());
	_sortData.getOptimal().calculateAvg();
	_sort.removeVectorElements();
}

//Set Average Data
void BubbleSortWrapper::setAverageData(int &n) {
	_sort.generateVectors(AVERAGE); //Create Vector
	_sortData.getAverage().setT1(_sort.doBubbleSort()); //Set Trials/Avg
	_sort.removeVectorElements();
	_sort.generateVectors(AVERAGE); //Create Vector2
	_sortData.getAverage().setT2(_sort.doBubbleSort());
	_sort.removeVectorElements();
	_sort.generateVectors(AVERAGE); //Create Vector3
	_sortData.getAverage().setT3(_sort.doBubbleSort());
	_sort.removeVectorElements();
	_sort.generateVectors(AVERAGE); //Create Vector4
	_sortData.getAverage().setT4(_sort.doBubbleSort());
	_sort.removeVectorElements();
	_sort.generateVectors(AVERAGE); //Create Vector5
	_sortData.getAverage().setT5(_sort.doBubbleSort());
	_sortData.getAverage().calculateAvg();
	_sort.removeVectorElements();
}

//Set Worst Data
void BubbleSortWrapper::setWorstData(int &n) {
	_sort.generateVectors(WORST); //Create Vector
	_sortData.getWorst().setT1(_sort.doBubbleSort()); //Set Trials/Avg
	_sortData.getWorst().setT2(_sort.doBubbleSort());
	_sortData.getWorst().setT3(_sort.doBubbleSort());
	_sortData.getWorst().setT4(_sort.doBubbleSort());
	_sortData.getWorst().setT5(_sort.doBubbleSort());
	_sortData.getWorst().calculateAvg();
	_sort.removeVectorElements();
}

/*Non-member Functions*/

//*Equivalent to one line in the csv file
//When you write BubbleSortData obj to a file, it will be the same as printing it out to the console.
//ofstream & operator<< (ofstream &outputFile, BubbleSortData dataObj)
//{
//	outputFile << dataObj;
//
//	return outputFile;
//}