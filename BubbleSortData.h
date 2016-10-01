#pragma once

/*
Lucy Tran
9 - 19 - 16
Header File : Bubble Sort Data Class
PA1 : Bubblesort

*Data that is to be printed to the csv file
*Includes optimal, worst, and avg case data
*Includes the number of inputs (size of array): n
*Member Functions: 
*Non-member Functions: operator<<
*/

#include "CaseTime.h" //Contains a CaseTime object

class BubbleSortData {

public:

	/*Constructors*/
	BubbleSortData();
	BubbleSortData(int &n, CaseTime &optimal, CaseTime &worst, CaseTime &average);

	/*Destructor*/
	~BubbleSortData();

	/*Getters*/
	int getN() const;
	CaseTime & getOptimal();
	CaseTime & getWorst();
	CaseTime & getAverage();

	/*Setters*/
	void setN(int & newN);
	void setOptimal(CaseTime newOptimal);
	void setWorst(CaseTime newWorst);
	void setAverage(CaseTime newAverage);


private:
	int _n; // size of the list (# of items)
	CaseTime _optimal;
	CaseTime _worst;
	CaseTime _average;
};

ostream & operator<< (ostream &output, BubbleSortData & dataObj);