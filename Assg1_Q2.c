//2. Modify selection sort, bubble sort and insertion sort functions 
//to return number of passes and number of comparisons and print both in main function. 

#include<stdio.h>
#define size 6
#define SWAP(a,b)  int temp = a; a = b; a = temp;

typedef struct ret
{
    int comparison;
    int iteration;
}ret;

ret r1={0,0},r2={0,0},r3={0,0};
ret bubble_sort(int arr[size]);
ret selection_sort(int arr[size]);
ret insertion_sort(int arr[size]);

//void ret_init(ret *);
int main()
{
    int key;
    ret m1,m2,m3;
    
    int arr[size]={11,22,33,44,55,66};
    //ret_init(&r1);
    m1=selection_sort(arr);
    printf("selction sort : no of comparision = %d\tno of iteration = %d\n",m1.comparison,m1.iteration);
    m2=bubble_sort(arr);
    printf("Bubble sort : no of comparision = %d\tno of iteration = %d\n",m2.comparison,m2.iteration);
    m3=insertion_sort(arr);
    printf("insertion sort : no of comparision = %d\tno of iteration = %d\n",m3.comparison,m3.iteration);


}
ret selection_sort(int arr[size])
{   
    for(int i=0;i<size-1;i++)
    {   
         r1.iteration++;
        for(int j=i+1;j<size;j++)
        {   
            r1.comparison++;
            if(arr[i]>arr[j]){
                SWAP(arr[i],arr[j]);
            }
        
        }
    }
    return r1;
}
ret bubble_sort(int arr[size])
{
    int its,pos,flag=0;
    
    for(its = 0;its < size-1; its++)
    {
        r2.iteration++;

        for(pos=0;pos < size-1-its;pos++)
        {
            r2.comparison++;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    return r2; 
}
ret insertion_sort(int arr[size])
{
    int i,j,temp;

    for(i=1; i< size; i++)
    {
        r3.iteration++;
        temp = arr[i];
        for(j = i-1;j>=0 && temp < arr[j] ;j--)
        {
            r3.comparison++;
            // 1) shift arr[j] to j+1 index
            arr[j+1] = arr[j];
        }

        arr[j+1] = temp;
    }
    return r3;
}

