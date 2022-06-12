from generator import get_random_list
from timeit import timeit

def merge_sort(iplist):
    size = len(iplist) if iplist else -1
    if size > 1:
        mid = size//2 # Get integer middle i.e., 7//2 = 3, 7/2 is 3.5 which is not wanted
        left = iplist[0:mid]
        right = iplist[mid:]
        merge_sort(left)
        merge_sort(right)
        merge(iplist, left, right)

def merge(iplist, l, r):
    lp = len(l)
    rp = len(r)

    m =0
    n = 0
    o = 0

    while m < lp and n < rp:
        if l[m] < r[n]:
            iplist[o] = l[m]
            m += 1
        else:
            iplist[o] = r[n]
            n += 1
        o += 1
    
    while m < lp:
        iplist[o] = l[m]
        m += 1
        o += 1

    while n < rp:
        iplist[o] = r[n]
        n += 1
        o += 1

"""
def merge_sort(inp_arr):
    size = len(inp_arr)
    if size > 1:
        middle = size // 2
        left_arr = inp_arr[:middle]
        right_arr = inp_arr[middle:]
 
        merge_sort(left_arr)
        merge_sort(right_arr)
 
        p = 0
        q = 0
        r = 0
 
        left_size = len(left_arr)
        right_size = len(right_arr)
        while p < left_size and q < right_size:
            if left_arr[p] < right_arr[q]:
              inp_arr[r] = left_arr[p]
              p += 1
            else:
                inp_arr[r] = right_arr[q]
                q += 1
             
            r += 1
 
        
        while p < left_size:
            inp_arr[r] = left_arr[p]
            p += 1
            r += 1
 
        while q < right_size:
            inp_arr[r]=right_arr[q]
            q += 1
            r += 1

"""


if __name__ == "__main__":
    
    iplist = get_random_list(1000000)
    
    #merge_sort(iplist)
    print("Execution time = ", timeit(lambda: merge_sort(iplist), number=1))
