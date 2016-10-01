#pragma once

/*
Lucy Tran
9 - 19 - 16
Header File : Case Time Class
PA1 : Bubblesort

*Contains trials and average of a certain case time
*Member Functions: +CalculateAvg, +operator=
*Non-Member Functions: operator<<
*/

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

/* Contains trials and average of a certain case time */
class CaseTime {
public:

	/*Constructors*/

	//Default
	CaseTime();

	//Copy constructor
	/*CaseTime(CaseTime &newCase) {
	_t1 = newCase.getT1();
	_t2 = newCase.getT2();
	_t3 = newCase.getT3();
	_t4 = newCase.getT4();
	_t5 = newCase.getT5();
	_avg = newCase.getAvg();
	}*/

	//Member list initialization: http://www.cplusplus.com/doc/tutorial/classes/
	CaseTime(float &t1, float &t2, float &t3, float &t4, float &t5, float &avg);

	/*Destructor*/
	~CaseTime();

	/*Overloaded Operators*/
	void operator=(const CaseTime newCase);

	/*Getters*/ //Take a look at: https://isocpp.org/wiki/faq/const-correctness#const-ref-alt
	float const & getT1() const;
	float const & getT2() const;
	float const & getT3() const;
	float const & getT4() const;
	float const & getT5() const;
	float const & getAvg() const;

	/*Setters*/
	void setT1(float newT1);
	void setT2(float newT2);
	void setT3(float newT3);
	void setT4(float newT4);
	void setT5(float newT5);
	void setAvg(float newAvg);

	/*Public Functions*/

	//Calculates the average of the 5 trials
	void calculateAvg();

private:
	//5 trials, 1 average
	float _t1;
	float _t2;
	float _t3;
	float _t4;
	float _t5;
	float _avg;

	/*Private Functions*/

	//Calculates the average of the 5 trials
	float const & calculateAvg(float &n, float &n2, float &n3, float &n4, float &n5);
};

ostream & operator<< (ostream &output, const CaseTime & caseObj);