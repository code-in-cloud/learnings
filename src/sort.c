#include "sort.h"

void insertion_sort(int input[], int size) {
    clock_t start;
    clock_t end;
    assert(input != NULL && size > 0);
    start = clock();
    int i = 1;
    while(i<size)
    {
        int j = i-1;
        int key = input[i];
        while(j>=0 && key < input[j]) {
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = key;
        i++;
    }
    end = clock();
    double time_taken = (double)((end - start) / (double)CLOCKS_PER_SEC);
    printf("Execution time => %f seconds",time_taken);
}

void __merge(int* input, int l, int mid, int r) {
    int ls = (mid - l) + 1;
    int rs = (r - mid);

    int* li = (int*)malloc(sizeof(int) * ls);
    int* ri = (int*)malloc(sizeof(int) * rs);

    int i = 0;

    if (li != NULL) {
        while (i < ls)
        {
            *(li + i) = *(input + l + i);
            i++;
        }
    }

    if (ri != NULL) {
        for (int j = 0; j < rs; j++) {
            *(ri + j) = *(input + mid + j + 1);
        }
    }

    int x = 0, y = 0, z = l;

    while (x < ls && y < rs)
    {
        if (li[x] < ri[y])
        {
            input[z] = li[x];
            x++;
        }
        else
        {
            input[z] = ri[y];
            y++;
        }
        z++;
    }

    while (x < ls)
    {
        input[z] = li[x];
        x++;
        z++;
    }

    while (y < rs)
    {
        input[z] = ri[y];
        y++;
        z++;
    }
    free(li);
    free(ri);
}

void merge_sort(int* input, int p, int r) {
    if ((r - p) > 1)
    {
        int q = (p + r) / 2;
        merge_sort(input, p, q);
        merge_sort(input, q + 1, r);
        __merge(input, p, q, r);
    }
}

void bubble_sort(int *list, const int size) 
{
    for(int i=0;i<size;i++)
    {
        for(int j= i + 1; j < size; j++)
        {
            if(list[j] < list[i])
            {
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }
}

/*
int main(int argc, char const *argv[])
{
    const int array_size = 1000000;
    int *array = get_random_array(array_size);
    clock_t begin = clock();
    merge_sort(array, 0,array_size);
    clock_t end = clock();
    //int expected[] = {1, 2, 3, 4, 5};
    // for (int i = 0; i < array_size; i++) {
    //     cr_assert_eq(array[i], expected[i]);
    // }
    printf("%f\n", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}
*/
