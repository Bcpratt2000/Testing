#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	char text[]="Hello, World!\n";

	__asm__("mov %rax, 1");
	__asm__("mov %rdi, 1");
	__asm__("mov %rsi, $text");
	__asm__("mov %rdx, 14");
	__asm__("syscall");			//print $text to screen

	return 0;
}

