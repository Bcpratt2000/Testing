//g++ -O3 -std=gnu++11 CalcPi.cpp -I/c/modular-boost -lquadmath -pthread -o CalcPi.o

#include <iostream>
#include <math.h>
#include <future>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#define __float128 long double
#define PLATFORM WIN32
#endif


#ifdef linux
#include <quadmath.h>
#include <unistd.h>
#define PLATFORM LINUX
#define Sleep(x) usleep((x)*1000)
#endif


#define NUM_THREADS 8

#define BATCHSIZE 100000000/NUM_THREADS

using namespace std;

future<__float128> threads[NUM_THREADS] = {};

__float128 piBuffer = 0;
long long i = 1;
__float128 coeff = 6 / sqrt(6);
__float128 printBuffer;

__float128 calcRange(long long start, long long length) {
	__float128 retBuffer=0;
	for (long long i = 0;i < length; i++) {
		retBuffer += (1 / pow(i+start, 2));
	}
	return retBuffer;
}

int main() {

	#ifdef _WIN32
		cout << "Due to some Windows libraries, Pi cannot be accurately calculated" << endl;
	#endif

	cout << "This program is most accurate on Intel x86 based processors" << endl;

	//assign threads
	while (i>0) {
		for (unsigned short t = 0; t < NUM_THREADS; t++) {
			threads[t] = async(calcRange, i, BATCHSIZE);
			i += BATCHSIZE;
		}
		//get thread output
		for (unsigned short t = 0; t < NUM_THREADS; t++) {
			piBuffer+=threads[t].get();
		}
		
		//prints Iterations & Pi
		printBuffer = (coeff*sqrt(piBuffer));
		cout << endl;
		cout << "Billion Iterations: ";
		cout.precision(5);
		cout << (float)(i-1)/1000000000 << endl;
		cout.precision(64);
		cout << "Pi = " << (long double)(printBuffer) << endl;
	}

	printBuffer = (coeff*sqrt(piBuffer));
	cout << "" << endl;
	cout << i - 1 << endl;
	cout << (long double)(printBuffer) << endl;

	cout << "ERROR: long long i has run out of memory space" << endl;
	return 0;
}

