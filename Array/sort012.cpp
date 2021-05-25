#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
void sort012(int arr[], int n) {
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		switch (arr[mid])
		{
		case 0: swap(arr[low++], arr[mid++]);
			break;
		case 1: mid++;
			break;
		case 2: swap(arr[mid], arr[high--]);
			break;
		}
	}
}

int main()
{
	int n;
	cout << "enter the size of array\n";
	cin >> n;
	int a[n];
	cout << "enter the array\n";
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort012(a, n);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

	return 0;
}