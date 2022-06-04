#include "../src/sort.h"
#include<criterion/criterion.h>

Test(insertion_sort, sort_test)
{
    int array[] = {5, 4, 3, 2, 1};
    int array_size = 5;
    merge_sort(array, 0,array_size);
    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < array_size; i++) {
        cr_assert_eq(array[i], expected[i]);
    }
}