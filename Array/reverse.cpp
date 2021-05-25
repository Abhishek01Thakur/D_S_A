#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void rvereseArray(int arr[], int start, int end) //recursive method
{
    if (start >= end)
    return;
     
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
     
    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}  

int main(){
	int a[]={2,3,4,5,6};
	int b[]={5,9,1,0};
	int i,j,temp;
	
	i=0;
	j=4;
	while(i<j)   //odd size array
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
	i=0;
	j=3;
	while(i<j) //even size array
	{
		temp=b[i];
		b[i]=b[j];
		b[j]=temp;
		i++;
		j--;
	}
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	for(i=0;i<4;i++)
	cout<<b[i]<<" ";
		
	return 0;
}
