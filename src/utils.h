#ifndef _UTILS_H_
#define _UTILS_H_
	#include<stdio.h>
	#include<assert.h>
	#include<stdbool.h>
	#include<stdlib.h>
	
	bool isNull(void*);
	void print_array(int* input, int size);
    int get_random_number(int, int);
	int* get_random_array(int);
#endif // !_UTILS_H_
