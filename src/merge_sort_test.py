from merge_sort import merge_sort
from numpy import array_equal

# Expect this to fail as None input list is not accepted
def test_insertion_sort_with_none_input():
    try:
        merge_sort(None)
    except AssertionError as e:
        print('Test passed')


# Expect this to fail as empty input list is not accepted
def test_insertion_sort_with_empty_input_list():
    try:
        merge_sort([])
    except AssertionError as e:
        print('Test passed')


# Run pytest
def test_merge_sort_with_valid_input():
    iplist = [2,3,1,7,9,5,6]
    merge_sort(iplist)
    assert array_equal(iplist, [1,2,3,5,6,7,9])
    