// Linear Search

#include<stdio.h>
#define SIZE 9

int linear_search(int arr[SIZE],int key);
int Rec_linear_search(int arr[SIZE],int key,int pos);
int comparisons;

int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    int key;
    // 1.Get the key from the user.

    printf("Enter the Key to Search :");
    scanf("%d",&key);

    int result = linear_search(arr,key);

    if(result == -1)
        printf("Key not found !\n");
    else
        printf("Key found at index = %d\n",result);
       
        printf("comparisons = %d\n",comparisons);

    int res=Rec_linear_search(arr,key,0);

    if(res == -1)
        printf("by recursion \nKey not found !\n");
    else
        printf("by recursion \nKey found at index = %d\n",res);

    return 0;
}

int linear_search(int arr[SIZE],int key)
{

   //2) Start traversal from the 1st element(0th index).
        for(int index = 0; index < SIZE; index++)
        {
            // 	3) Compare the key with each element.
            comparisons++; 
            if(key == arr[index])
            {
                //a. If the key is found, return the index.
                return index;
            }
            // b. Else, continue the search till the last element.
        }

    return -1; // return false -> key not found


}


int Rec_linear_search(int arr[SIZE],int key,int i)
{
int res;

if(i==SIZE)
 return -1;

if(arr[i]==key)
{
	return i;
}
else{
    ++i;
    res=Rec_linear_search(arr,key,i);

}
return res;

}