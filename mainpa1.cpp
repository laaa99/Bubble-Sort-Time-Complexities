/*
Lucy Tran
9-19-16
Main (driver)
PA1: Bubblesort

The primary function will take an input of how many random integers to sort, and return how long it
took to sort the given vector of N randomly generated integers. This function will be called many
times to generate our statistics.
*/

#include "BubbleSortWrapper.h"

int main(void)
{
	
	BubbleSortWrapper _run;

	_run.run(); //Run whole program

	return 0;
}

/*Other Testing for main*/

//vector<int> v = { 8, 3, 100, 5 };
//cout << do_bubblesort(v, 1) << endl;
/*srand(time(NULL));

for (int i = 0; i < 9; i++) {
int x = (rand() % (101));
cout << x << endl;
}*/

//int temp = 0;
//time_point<system_clock> start, end; //start timer
//start = system_clock::now();

//for (int i = 0; i < 4; i++) {
//	for (int j = 0; j < 3 - i; j++) {
//		//Ascending order
//		if (v[j] > v[j + 1]) {
//			//Swap
//			temp = v[j];
//			v[j] = v[j + 1];
//			v[j + 1] = temp;
//		}
//	}
//}

//end = std::chrono::system_clock::now(); //end timer
//duration<float> elapsedSecs = end - start; //Calculate seconds
//cout << elapsedSecs.count() << endl;
/*for (int k = 0; k < 4; k++)
{
cout << v[k] << endl;
}*/
