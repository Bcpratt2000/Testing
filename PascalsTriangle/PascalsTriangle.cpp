//g++ PascalsTriangle.cpp -std=gnu++11 -lpthread -o PascalsTriangle.o

#include "stdio.h"
#include "iostream"
#include "thread"
#include "time.h"
#include "sstream"

#define NUM_THREADS 128

#define ITERATIONS 1024

using namespace std;

unsigned long long getPascal(unsigned int row, unsigned int col) {
	if (col == 0 || col == row) {
		return 1;
	}
	else {
		return getPascal(row - 1, col - 1) + getPascal(row - 1, col);
	}
}

int printBufferedRow(unsigned int row) {
	stringstream outBuffer;
	outBuffer << (row);
	outBuffer << ": ";
	for (unsigned int x = 0; x <= row; x++) {
		outBuffer << getPascal(row, x);
		outBuffer << " ";
	}
	cout << outBuffer.str() << endl;
	return true;
}

int main(){
	thread threads[NUM_THREADS] = {};

	unsigned int y=0;

	while (y <= ITERATIONS) {
		//assign threads
		//don't start multithreading until after line 25
		if (y <= 25) {
			printBufferedRow(y);
			y++;
		}
		else {
			for (unsigned short t = 0; t < NUM_THREADS; t++) {
				threads[t] = thread(printBufferedRow, y);
				y++;
			}
			//tell main to wait until all threads execute
			for (unsigned short t = 0; t < NUM_THREADS; t++) {
				threads[t].join();
			}
		}
	}
	cout << "Success! Press Q and enter to quit: ";
	unsigned char temp;
	cin >> temp;

    return 0;
}
