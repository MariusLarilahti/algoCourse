#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Utility function to print array
void printArray(const std::vector<int>& arr) 
{
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

void shellSort(std::vector<int>& arr, int n)
{
    //gap is initialized as half the arr length, and is halved each loop
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void merge(std::vector<int>& arr, int l, int mid, int r) {

    int n1 = mid - l + 1;
    int n2 = r - mid;
    std::vector<int> tempL(n1), tempR(n2);

    //Left half
    for (int i = 0; i < n1; i++)
        tempL[i] = arr[l + i];

    //Right half
    for (int j = 0; j < n2; j++)
        tempR[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    // Merge halves
    while (i < n1 && j < n2) 
    {
        if (tempL[i] <= tempR[j]) 
        {
            arr[k] = tempL[i];
            i++;
        }
        else 
        {
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = tempL[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = tempR[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {

    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arrSize = 1000000;
    std::vector<int> arr(arrSize);
    int n = arr.size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    for (int i = 0; i < arrSize; ++i)
        arr[i] = dis(gen);
    //printArray(arr);

        auto sortStart = std::chrono::high_resolution_clock::now();
        //mergeSort(arr, 0, n - 1);
        //shellSort(arr, n);
        std::sort(arr.begin(), arr.end());
        auto sortStop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = sortStop - sortStart;
        std::cout << "sort took: " << duration.count() / 1000 << " seconds\n" << std::endl;
        std::cout << "Time per data item: " << (duration.count() / 1000) / arrSize << " seconds\n" << std::endl;

    return EXIT_SUCCESS;

}

