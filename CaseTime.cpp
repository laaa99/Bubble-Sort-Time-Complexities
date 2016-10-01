/*
Lucy Tran
9 - 19 - 16
Function File : Case Time Class
PA1 : Bubblesort

*Contains trials and average of a certain case time
*Member Functions: CalculateAvg, operator=
*Non-member Functions: operator<<
*/

#include "CaseTime.h"

/*Constructors*/

//Default
CaseTime::CaseTime() {
	_t1 = 0;
	_t2 = 0;
	_t3 = 0;
	_t4 = 0;
	_t5 = 0;
	_avg = 0;
}

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
CaseTime::CaseTime(float &t1, float &t2, float &t3, float &t4, float &t5, float &avg) : _t1(t1), _t2(t2), _t3(t3), _t4(t4), _t5(t5), _avg(avg) {}

/*Destructor*/
CaseTime::~CaseTime() {}

/*Overloaded Operators*/
void CaseTime::operator=(const CaseTime newCase) {
	_t1 = newCase._t1;
	_t2 = newCase._t2;
	_t3 = newCase._t3;
	_t4 = newCase._t4;
	_t5 = newCase._t5;
	_avg = newCase._avg;
}

/*Getters*/ //Take a look at: https://isocpp.org/wiki/faq/const-correctness#const-ref-alt
float const & CaseTime::getT1() const {
	return _t1;
}
float const & CaseTime::getT2() const {
	return _t2;
}
float const & CaseTime::getT3() const {
	return _t3;
}
float const & CaseTime::getT4() const {
	return _t4;
}
float const & CaseTime::getT5() const {
	return _t5;
}
float const & CaseTime::getAvg() const {
	return _avg;
}

/*Setters*/
void CaseTime::setT1(float newT1) {
	_t1 = newT1;
}
void CaseTime::setT2(float newT2) {
	_t2 = newT2;
}
void CaseTime::setT3(float newT3) {
	_t3 = newT3;
}
void CaseTime::setT4(float newT4) {
	_t4 = newT4;
}
void CaseTime::setT5(float newT5) {
	_t5 = newT5;
}
void CaseTime::setAvg(float newAvg) {
	_avg = newAvg;
}

/*Public Functions*/

//Calculates the average of the 5 trials
void CaseTime::calculateAvg() {
	_avg = calculateAvg(_t1, _t2, _t3, _t4, _t5);
}

/*Private Functions*/

//Calculates the average of the 5 trials
float const & CaseTime::calculateAvg(float &n, float &n2, float &n3, float &n4, float &n5) {
	return (n + n2 + n3 + n4 + n5) / 5;
}

/*Non-Member Functions*/

//When you output a CaseTime object, its data members will be outputted this way.
//Avg T1 T2 ... T5
ostream & operator<< (ostream &output, const CaseTime & caseObj)
{
	output << caseObj.getAvg() << ",";
	output << caseObj.getT1() << ",";
	output << caseObj.getT2() << ",";
	output << caseObj.getT3() << ",";
	output << caseObj.getT4() << ",";
	output << caseObj.getT5() << ",";

	return output;
}