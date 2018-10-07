#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>

int numberOfSwaps = 0;
using namespace std;
void heapify(int arr[], int n, int i)
{

	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}


	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}


	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		numberOfSwaps++;
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
		
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);
		numberOfSwaps++;
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
		
	}
}

/*
void printArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}*/


int main() {
	vector<int> v;
	vector <int> ::iterator i;
	int* arr;
	int x = 1;
	ifstream InFile("unsorted.txt");
	cin.rdbuf(InFile.rdbuf());
	while (x) {
		x = 0;
		cin >> x;
		if (x != 0) {
			v.push_back(x);
		}

	}

	InFile.close();
	int size = v.size();
	arr = new int[size - 1];
	int j = 0;
	for (i = v.begin(); i != v.end(); ++i) {
		arr[j] = *i;
		j++;
	}
	heapSort(arr, size);

	
	/*int givenArray[] = {4,10,3,5,1};
	cout << "given array is \n";
	printArray(givenArray, 5);
	heapSort(givenArray, 5);

	cout << "Sorted array is \n";
	printArray(givenArray, 5);
	
	cout << numberOfSwaps << " //this is the number of up/down swaps" << endl;*/


	ofstream OutFile;
	OutFile.open("x.txt");
	for (int j = 0; j < size; j++)
		OutFile << arr[j] << endl;
	OutFile << numberOfSwaps << " //this is the number of up/down swaps" << endl;
	OutFile.close();

	cout << numberOfSwaps;
	ofstream OutputFile("x.csv");
	for (int j = 0; j < size; j++) {
		OutputFile << arr[j] << endl;
	}
	OutputFile << numberOfSwaps<< ","<<" //this is the number of up/down swaps";
	OutputFile.close();

	_getch();
	return 0;
}
