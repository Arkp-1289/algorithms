def merge(a):
    if len(a)>1:
        
        mid=len(a)//2
        l=a[:mid]
        r=a[mid:]
        merge(l)
        merge(r)
        
        i=0
        j=0
        k=0
        while(i<len(l) and j<len(r)):
            if l[i]>r[j]:
                a[k]=r[j]
                j+=1
            else:
                a[k]=l[i]
                i+=1
            k+=1
        for i in range(i,len(l)):
            a[k]=l[i]
            k+=1
        for j in range(j,len(r)):
            a[k]=r[j]
            k+=1
def p_list(a):
    for i in range(len(a)):
        print(a[i],end=" ")
    print()
        
if __name__=='__main__':
    a=list(map(int,input().split()))
    print("given array is : ")
    p_list(a)
    merge(a)
    print("sorted array is : ")
    p_list(a)
    
