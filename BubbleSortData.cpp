/*
Lucy Tran
9 - 19 - 16
Function File : Bubble Sort Data Class
PA1 : Bubblesort

*Data that is to be printed to the csv file
*Includes optimal, worst, and avg case data
*Includes the number of inputs (size of array): n
*Member Functions:
*Non-member Functions: operator<<
*/

#include "BubbleSortData.h"

/*Constructors*/
BubbleSortData::BubbleSortData() {
	_n = 0;
}
BubbleSortData::BubbleSortData(int &n, CaseTime &optimal, CaseTime &worst, CaseTime &average) {
	_n = n;
	_optimal = optimal;
	_worst = worst;
	_average = average;
}

/*Destructor*/
BubbleSortData::~BubbleSortData() {}

/*Getters*/
int BubbleSortData::getN() const {
	return _n;
}
CaseTime & BubbleSortData::getOptimal()  {
	return _optimal;
}
CaseTime & BubbleSortData::getWorst()  {
	return _worst;
}
CaseTime & BubbleSortData::getAverage()  {
	return _average;
}

/*Setters*/
void BubbleSortData::setN(int & newN) {
	_n = newN;
}
void BubbleSortData::setOptimal(CaseTime newOptimal) {
	_optimal = newOptimal; //calls overloaded assignment operator
}
void BubbleSortData::setWorst(CaseTime newWorst) {
	_worst = newWorst;
}
void BubbleSortData::setAverage(CaseTime newAverage) {
	_average = newAverage;
}

/*Non-Member Functions*/

//*Equivalent to one line in the csv file
//When you output a BubbleSortData object, the data will be outputted this way.
//N Optimal Worst Average Avg(1) Avg(2) ... Avg(5) 
//The last part are the 5 trials for the average case
ostream & operator<< (ostream &output, BubbleSortData & dataObj)
{
	output << dataObj.getN() << ",";
	output << dataObj.getOptimal().getAvg() << ",";
	output << dataObj.getWorst().getAvg() << ",";
	output << dataObj.getAverage() << endl; //Ultilizing the overloaded << function for CaseTime

	return output;
}