#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <fstream>
#include <random>

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

int partition(vector<int> &array, int pivot_index, int endIndex)
{
    int swap_index = pivot_index;
    for (int i = pivot_index + 1; i <= endIndex; i++)
    {
        if (array[i] < array[pivot_index])
        {
            swap_index++;
            swap(array, swap_index, i);
        }
    }
    swap(array, pivot_index, swap_index);

    return swap_index;
}

int partitionEnd(vector<int> &arr, int start, int end)
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

void quickSortIterative(vector<int> &arr, int low, int high)
{
    vector<int> array2;

    array2.push_back(low);
    array2.push_back(high);

    // popping untill array is emplt
    while (!array2.empty())
    {
        high = array2.back();
        array2.pop_back();
        low = array2.back();
        array2.pop_back();

        // positioning the pivot
        int pivot = partition(arr, low, high);

        if (pivot - 1 > low)
        {
            array2.push_back(low);
            array2.push_back(pivot - 1);
        }

        if (pivot + 1 < high)
        {
            array2.push_back(pivot + 1);
            array2.push_back(high);
        }
    }
}

void quickSortInitialisedItr(vector<int> &arr, int length)
{
    quickSortIterative(arr, 0, length - 1);
}

void quickSortInitialised(vector<int> &arr, int length)
{
    quickSort(arr, 0, length - 1);
}

int main()
{
    // Create a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range of random numbers
    int min = 1;
    int max = 100000;

    int cases = 50;

    vector<int> array[cases];
    for (int i = 0; i < cases; i++)
    {
        for (int j = 0; j < i + 3; j++)
        {
            std::uniform_int_distribution<> dis(min, max);
            int randomNumber = dis(gen);
            array[i].push_back(randomNumber);
        }
    }
    ofstream file("data.txt");
    for (vector<int> arr : array)
    {
        int length = arr.size();
        file << length << " ";
        cout << length << endl;
        //Iterative Quick Sort
        int elapsedtime = 0;
        for (int i = 0; i < 10; i++)
        {
            vector<int> arrCopy = arr;
            auto start = chrono::high_resolution_clock::now();
            quickSortInitialisedItr(arrCopy, length);
            auto end = chrono::high_resolution_clock::now();
            elapsedtime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        }
        file << elapsedtime / 10 << " ";
        //Recursive Quick Sort
        elapsedtime = 0;
        for (int i = 0; i < 10; i++)
        {
            vector<int> arrCopy = arr;
            auto start = chrono::high_resolution_clock::now();
            quickSortInitialised(arrCopy, length);
            auto end = chrono::high_resolution_clock::now();
            elapsedtime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        }
        file << elapsedtime / 10 << " ";
        //end
        file << endl;
    }
    file.close();
    system("gnuplot GnuPlotInitFile.gnu");
    return 0;
}