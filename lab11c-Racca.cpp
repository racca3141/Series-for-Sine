// Emerson Racca
// 12/6/21
// Lab 11c - Series for Sine
/*
Code a regular c - type function that calculates sin(x) near x = 0 (Be careful, users want angles in degrees).
The Taylor(Maclaurin) series expansion(Links to an external site.) is as follows :

Note: this will only work for values of x near 0.

Allow the user to choose the angle in degrees and the number of terms(n) of the approximating function.
Implement the runagain method.You can check your answers using a calculator in degree mode.
*/

#include<iostream>
#include<cmath>
using namespace std;

double factn(int n);
double sinx(double x, int n);

int main(void) {
	double th;
	double x;
	int n;
	char goagain = 'y';

	cout << "Series for Sine" << endl;
	cout << "This app calculates sin(x) using The Taylor(Maclaurin) series expansion." << endl;

	do {
		cout << "\nEnter the angle in degrees (ex. 45.0): ";
		cin >> th;

		cout << "Enter the number of terms: ";
		cin >> n;

		x = th * 3.14159265358979 / 180; // convert degrees to radian.

		cout << "\nsin(" << th << ") = " << sinx(x, n) << endl;

		cout << "\nWould you like to go again (y or n)? ";
		cin >> goagain;

	} while (goagain == 'y');

	return(0);
}

//
double sinx(double x, int n) {
	double fx = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		temp = 2 * i + 1;
		fx = fx + (pow(-1.0, 1.0 * i) * pow(x, 1.0 * temp) / factn(temp));
	}
	return fx;
}


//factorial
double factn(int n) {
	double f = 1.0;
	if(n == 0 || n == 1){
		f = 1.0;
	}
	else {
		for (int i = 2; i <= n; i++)
			f = f * i;
	}
	return f;
}