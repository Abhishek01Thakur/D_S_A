#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <bits/stdc++.h>

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

	return i;

}



int main()
{
	int arr[] = {2, 7, 8, 6, 1, 5, 4};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;
	int p = partition(arr, 0, n - 1);
	while (p != k) {
		if (p > k)
			p = partition(arr, 0, p - 1);
		else
			p = partition(arr, p + 1, n - 1);
	}
	cout << "kth smallest element is" << arr[p];

	return 0;
}