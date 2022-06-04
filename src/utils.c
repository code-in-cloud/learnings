#include "utils.h"

bool isNull(void* obj)
{
	if (obj != NULL)
		return false;
	else
		return true;
}

void print_array(int* input, int size)
{
	assert(input != NULL && size > 0);
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", *(input + i));
	}
	printf("\n");
}

int* get_random_array(int size)
{
    assert(size > 0);
    int* input = (int*) malloc(sizeof(int) * size);
    if (input)
    {
        for (int i = 0; i < size; i++)
        {

            *(input + i) = get_random_number(1, size);
        }
    }
    return input;
}

int get_random_number(int start, int end)
{
    assert(start >= 0 && end >= start);
    return ((rand() % (end - start + 1)) + 1);
}