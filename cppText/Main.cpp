#include <stdio.h>
#include <iostream>


using namespace std;

int main(){
	char text[] = "Hello, World!";
	//int text = 3;
	#ifdef _WIN32
		_asm{
			mov eax, 1
			mov edi, 1
			mov esi, [$text]
			mov edx, 13
			int 21h			;syscall
		};
	#endif

	#ifdef linux
		__asm__(
			"mov %eax, 1;"
			"mov %edi, 1;"
			"mov %esi, $text;"
			"mov %edx, 13;"
			"syscall;"			//syscall
		);
	#endif
	return 0;
}
