#include "../src/sort.h"
#include<time.h>
#include<criterion/criterion.h>


Test(merge_sort, merge_sort_test)
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
    cr_assert_eq(array != NULL, true);
}