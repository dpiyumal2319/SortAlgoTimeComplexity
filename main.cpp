#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;

void printArr(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << ' ';
    }
    cout << endl;
}

void selectionSort(vector<int> &arr, int length)
{
    int minIndex;
    for (int i = 0; i < length; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // doing the swap if only min index is changed
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbeleSortOptimised(vector<int> &arr, int length)
{
    bool swapPerformed; // to store whether swap perfomed or not
    for (int i = length - 1; i > 0; i--)
    {
        swapPerformed = false; //
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // making swaps
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapPerformed = true;
            }
        }
        // end for loop if no swaps done. ie list is already sorted
        if (!swapPerformed)
        {
            break;
        }
    }
}

void bubbleSort(vector<int> &arr, int length)
{
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // making swaps
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(vector<int> &arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            // swapping
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void merge(vector<int> &array, int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[midIndex + 1 + j];

    int i = 0;
    int j = 0;
    int index = leftIndex;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(vector<int> &array, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

void MergeSortInitialised(vector<int> &arr, int length)
{
    int size = length;
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(arr, leftIndex, rightIndex);
    return;
}

vector<int> itrMerge(vector<int> &array, int leftIndex1, int rightIndex1, int leftIndex2, int rightIndex2)
{
    vector<int> temp(rightIndex2 - leftIndex1 + 1);
    int index = 0;
    while ((leftIndex1 <= rightIndex1) && (leftIndex2 <= rightIndex2))
    {
        if (array[leftIndex1] < array[leftIndex2])
        {
            temp[index] = array[leftIndex1];
            index++;
            leftIndex1++;
        }
        else
        {
            temp[index] = array[leftIndex2];
            index++;
            leftIndex2++;
        }
    }
    while (leftIndex1 <= rightIndex1)
    {
        temp[index] = array[leftIndex1];
        index++;
        leftIndex1++;
    }

    while (leftIndex2 <= rightIndex2)
    {
        temp[index] = array[leftIndex2];
        index++;
        leftIndex2++;
    }
    return temp;
}

void itrMergeSort(vector<int> &arr, int n)
{
    int len = 1;
    while (len < n)
    {
        int i = 0;
        while (i < n)
        {
            int l1 = i;
            int r1 = i + len - 1;
            int l2 = i + len;
            int r2 = i + 2 * len - 1;
            if (l2 >= n)
            {
                break;
            }
            if (r2 >= n)
            {
                r2 = n - 1;
            }
            vector<int> temp = itrMerge(arr, l1, r1, l2, r2);
            for (int j = 0; j < (r2 - l1 + 1); j++)
            {
                arr[i + j] = temp[j];
            }
            i = i + 2 * len;
        }
        len = len * 2;
    }
    return;
}

void swap(vector<int> &arr, int firstIndex, int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int replaceNumIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, replaceNumIndex++, i);
        }
    }
    swap(arr, end, replaceNumIndex);

    return replaceNumIndex;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

void quickSortInitialised(vector<int> &arr, int length)
{
    quickSort(arr, 0, length - 1);
}

int main()
{
    vector<int> array[48] = {
        {23, 57, 81},
        {15, 42, 73, 89},
        {2, 49, 68, 91, 34},
        {5, 77, 12, 53, 90, 25},
        {36, 84, 61, 8, 45, 97, 19},
        {14, 58, 72, 7, 33, 96, 51, 68},
        {71, 27, 3, 98, 46, 81, 20, 64, 11},
        {35, 74, 55, 16, 89, 67, 30, 79, 42, 99},
        {9, 52, 83, 38, 65, 22, 59, 76, 29, 70, 87},
        {50, 10, 69, 40, 95, 24, 85, 62, 17, 54, 78, 39},
        {47, 4, 86, 31, 80, 13, 66, 21, 56, 93, 44, 3, 88},
        {75, 18, 63, 32, 82, 41, 94, 60, 5, 37, 92, 28, 48, 6},
        {49, 91, 16, 57, 35, 98, 74, 1, 67, 36, 97, 2, 61, 84, 25},
        {68, 99, 42, 19, 89, 26, 51, 90, 7, 64, 43, 0, 73, 27, 15, 34},
        {96, 45, 72, 23, 58, 12, 55, 30, 70, 46, 75, 13, 86, 63, 31, 99},
        {96, 45, 72, 23, 58, 12, 55, 30, 70, 46, 75, 13, 86, 63, 31, 99, 40},
        {83, 35, 28, 78, 57, 14, 71, 4, 87, 32, 89, 46, 64, 11, 93, 69, 50, 18},
        {98, 59, 25, 52, 91, 5, 36, 80, 15, 81, 47, 12, 92, 67, 21, 74, 33, 84, 3},
        {30, 96, 62, 8, 55, 89, 73, 13, 48, 84, 21, 67, 4, 81, 56, 26, 92, 39, 78, 17},
        {45, 99, 16, 74, 68, 35, 91, 7, 61, 29, 83, 50, 1, 65, 98, 20, 71, 44, 3, 79, 52},
        {46, 75, 40, 97, 11, 57, 28, 94, 6, 85, 22, 51, 87, 2, 76, 18, 53, 89, 31, 80, 5, 36},
        {25, 64, 88, 43, 10, 69, 37, 82, 27, 59, 86, 15, 72, 34, 90, 19, 70, 49, 9, 63, 41, 95, 54},
        {12, 77, 33, 60, 93, 38, 66, 23, 58, 14, 74, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79},
        {40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 92, 23, 81, 66},
        {94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22},
        {56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61},
        {44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60},
        {26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57},
        {48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49},
        {84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53},
        {95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56},
        {95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 76},
        {87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89},
        {37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53},
        {95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 87, 39, 70, 85},
        {12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49},
        {80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 92, 23, 81, 66, 94, 83, 46, 39},
        {29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9},
        {92, 19, 71, 51, 36, 95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57},
        {99, 9, 55, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10},
        {31, 97, 22, 56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49},
        {84, 42, 2, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 92, 23, 81, 66, 94, 83, 46, 39},
        {81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9, 92, 19, 71, 51, 36, 95, 25, 84, 2, 61},
        {44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6},
        {44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53, 95, 6, 78},
        {92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9},
        {95, 25, 84, 2, 61, 44, 75, 30, 64, 92, 21, 53, 89, 37, 82, 12, 49, 84, 82, 49, 80, 96, 17, 51, 98, 95, 1, 55, 61, 79, 40, 3, 76, 60, 26, 57, 99, 9, 82, 29, 90, 15, 80, 20, 62, 34, 70, 86, 53},
        {95, 6, 92, 23, 81, 66, 94, 83, 46, 39, 29, 86, 52, 98, 57, 81, 16, 72, 5, 73, 90, 48, 66, 33, 87, 19, 69, 10, 31, 64, 97, 22, 56, 87, 39, 70, 85, 12, 67, 27, 97, 48, 78, 34, 90, 21, 63, 49, 80, 9},
    };
    void (*functions[])(vector<int> &, int) = {selectionSort, insertionSort, bubbleSort, bubbeleSortOptimised, quickSortInitialised, MergeSortInitialised, itrMergeSort};
    int nuOfFunc = sizeof(functions) / sizeof(functions[0]);
    ofstream file("data.txt");
    int n = 3;
    for (vector<int> &list : array)
    {
        file << n++ << ' ';
        for (int i = 0; i < nuOfFunc; i++)
        {
            double elapsedTime = 0;
            for (int k = 0; k < 10; k++)
            {
                vector<int> unsortedArr = list;
                int length = size(unsortedArr);
                auto start = chrono::high_resolution_clock::now();
                functions[i](unsortedArr, length);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double, nano> elapsed = end - start;
                elapsedTime += elapsed.count();
            }
            file << elapsedTime / 10 << ' ';
        }
        file << endl;
    }
    file.close();
    // system("gnuplot -persist -e \"set term png size 1000,600; set output 'sorting_algorithms.png'; set title 'Sorting Algorithms Performance'; set xlabel 'Number of Elements in Array'; set ylabel 'Time (nanoseconds)'; set key top left; plot 'GraphYValues.txt' using 1:6 with lines title 'Merge Sort', '' using 1:7 with lines title 'Merge Sort(Iterative)'\"");
    return 0;
}