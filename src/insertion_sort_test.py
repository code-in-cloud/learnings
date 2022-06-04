from insertion_sort import insertion_sort
from numpy import array_equal


# Expect this to fail as None input list is not accepted
def test_insertion_sort_with_none_input():
    try:
        insertion_sort(None)
    except AssertionError as e:
        print('Test passed')


# Expect this to fail as empty input list is not accepted
def test_insertion_sort_with_empty_input_list():
    try:
        insertion_sort([])
    except AssertionError as e:
        print('Test passed')


# Expect to print key and value
def test_insertion_sort_with_valid_input_list():
    iplist = [2,3,1,7,9,5,6]
    oplist = insertion_sort(iplist)
    iplist.sort()
    assert array_equal(iplist,oplist)

