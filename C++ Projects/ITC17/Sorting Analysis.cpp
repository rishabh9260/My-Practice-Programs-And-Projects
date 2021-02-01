#include <bits/stdc++.h>
#include<chrono>
using namespace std; 
using namespace std::chrono;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {    
        min_idx = i;  
        for (j = i+1; j < n; j++)  
            if (arr[j] < arr[min_idx])  
                min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }  
}

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];  
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}

void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])  
                swap(&arr[j], &arr[j+1]);  
} 

void time_func(int arr[], int n, int x)
{
    cout<< "Array No.: " << x << endl;
    // Get starting timepoint 
	auto start1 = high_resolution_clock::now(); 

	// Calling the function here
    quickSort(arr, 0, n - 1);
    
	// Get ending timepoint 
	auto stop1 = high_resolution_clock::now();

    // Get starting timepoint 
	auto start2 = high_resolution_clock::now(); 

	// Calling the function here
    selectionSort(arr, n);

	// Get ending timepoint 
	auto stop2 = high_resolution_clock::now(); 
    
    // Get starting timepoint 
	auto start3 = high_resolution_clock::now(); 

	// Calling the function here
    mergeSort(arr, 0, n - 1);

	// Get ending timepoint 
	auto stop3 = high_resolution_clock::now(); 
    
    // Get starting timepoint 
	auto start4 = high_resolution_clock::now(); 

	// Calling the function here
    bubbleSort(arr, n);

	// Get ending timepoint 
	auto stop4 = high_resolution_clock::now(); 

	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
	auto duration2 = duration_cast<microseconds>(stop2 - start2); 
	auto duration3 = duration_cast<microseconds>(stop3 - start3); 
	auto duration4 = duration_cast<microseconds>(stop4 - start4); 

	cout << "Time taken by QuickSort: "
		<< duration1.count() << " microseconds" << endl;
	cout << "Time taken by SelectionSort: "
		<< duration2.count() << " microseconds" << endl;
	cout << "Time taken by MergeSort: "
		<< duration3.count() << " microseconds" << endl;
	cout << "Time taken by BubbleSort: "
		<< duration4.count() << " microseconds" << endl;

}

int main() 
{
    int arr1[10000] = {};   //Sorted
    for(int i=1;i<=10000;i++)
        arr1[i-1] = i;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[10000] = {};   //Reverse Sorted
    for(int i=10000;i<=1;i--)
        arr1[10000-i] = i;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[10000] = {};   //Random
    srand(time(0));
    for(int i=0;i<10000;i++)
    {
        arr3[i] = rand()%10000;
    }
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    time_func(arr1, n1, 1);
    time_func(arr2, n2, 2);
    time_func(arr3, n3, 3);

	return 0; 
} 
