//g++ PascalsTriangle.cpp -std=gnu++11 -lpthread -o PascalsTriangle

#include "stdio.h"
#include "iostream"
#include "thread"
#include "time.h"
#include "sstream"
#include <future>

#define NUM_THREADS 4

#define ITERATIONS 40

using namespace std;

unsigned long getPascal(unsigned int row, unsigned int col) {
	if (col == 0 || col == row) {
		return 1;
	}
	else {
		return getPascal(row - 1, col - 1) + getPascal(row - 1, col);
	}
}

string getBufferedRow(unsigned int row) {
	stringstream outBuffer;
//	outBuffer << (row);
//	outBuffer << ": ";
	for (unsigned int x = 0; x <= row; x++) {
		outBuffer << getPascal(row, x);
		outBuffer << " ";
	}
	return outBuffer.str();
}

int main(){
	future<string> threads[NUM_THREADS];

	unsigned int y=0;

	for (unsigned short t = 0; t < NUM_THREADS; t++) {
		threads[t] = async(launch::async, getBufferedRow, y);
		y++;
	}
	bool loop = true;
	while(loop){
		for (unsigned short t=0; t < NUM_THREADS; t++) {
			cout << threads[t].get() << endl;
			threads[t] = async(launch::async, getBufferedRow, y);
			y++;
			if(y>=ITERATIONS){
				loop = false;
			}
		}
	}
	for (unsigned short t=0; t < NUM_THREADS; t++) {
		cout << threads[t].get() << endl;
		y++;
	}
	return 0;
}

