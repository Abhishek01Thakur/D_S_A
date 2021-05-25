#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int partition(int *a, int s, int e) {
	//Inplace cannot take extra array
	int i = s - 1;
	int j = s;

	int pivot = a[e];

	for (; j <= e - 1; j++) {
		if (a[j] <= pivot) {
			//merge the smaler element in region 1
			i = i + 1;
			swap(a[i], a[j]);
		}
		//expand the larger region
	}

	//place the pivot element in the correct index
	swap(a[i + 1], a[e]);
	return i + 1;

}



int main()
{	
	int arr[] = {2, 7, 8, 6, 1, 5, 4};
	int n = sizeof(arr) / sizeof(int);
	int k;
	cin>>k;
	int p=partition(arr,0,n-1);
	while(p!=k){
		if(p>k)
		partition(arr,0,p-1);
		else
		partition(arr,p+1,n-1);
	}
	cout<<"kth smallest element is"<<arr[p];
	
	return 0;
}
