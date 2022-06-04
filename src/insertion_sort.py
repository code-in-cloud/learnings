def insertion_sort(iplist):
    assert iplist and len(iplist) > 0
    print("\n")
    i = 1
    while i < len(iplist):
        j = i - 1
        key = iplist[i]
        while j >= 0 and iplist[j] > key:
            iplist[j+1] = iplist[j]
            j-=1
        iplist[j+1] = key
        i+=1
    return iplist