#include <iostream>
#include <utility>
#include <chrono>
#include <random>
#include <iomanip>
#include <vector>

using namespace std;
using namespace std::chrono;

void simpleSort(vector<float>& a, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] > a[i])
                swap(a[j], a[i]);
}

int main()
{
    const int minValue = 0;
    const int maxValue = 10;
    const int size = 100000;


    std::vector<float> myArray(size);

    std::mt19937 prng(std::random_device{}());
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (auto& i : myArray) {
        i = dist(prng);
    }

    //cout array
    //for (auto i : myArray) {
    //    std::cout << i << ' ';
    //}
    //std::cout << '\n';


    auto linStart = high_resolution_clock::now();

    simpleSort(myArray, size);

    auto linEnd = high_resolution_clock::now();
    auto linDuration = duration_cast<microseconds>(linEnd - linStart);
    cout << "Execution Time: "
        << linDuration.count() / 1000
        << " ms" << endl;
    cout << "-------------------------------" << endl;

    //cout sorted array
    //for (auto i : myArray) {
    //    std::cout << i << ' ';
    //}
    //std::cout << '\n';
}
