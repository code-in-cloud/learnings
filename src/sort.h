#ifndef _SORT_H_
#define _SORT_H_
    #include<stdio.h>
    #include<stdlib.h>
    #include<assert.h>
    #include<stdbool.h>
    #include<time.h>
    
    #include "utils.h"

    void insertion_sort(int*, int);
    void merge_sort(int* input, int, int);
    void bubble_sort(int*, const int) ;
#endif