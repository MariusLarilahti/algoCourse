#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Palauttaa kahden luvun suurimman yhteisen tekijän
//HUOM a >= b on vaatimus jotta tämä toimii
int gcd(int a, int b) {
    int r = a % b;  //ensimmäinen jakojäännös
    while (r > 0) { //jatka kunnes jakojäännös = 0
        a = b;
        b = r;
        r = a % b;  //jakojäännös
    }
    return b;
}

//Lesson 1: arrays
int length = 100;
int maxInt;

int arrMixed[100];
//int* arrayAllocate = new int[100];

static long long int* allocateArray(unsigned n) { // add values to p array and allocate memory

    //int _array[100]{};
    //unsigned n = 100;

    cout << "Reserving memory...";
    long long int* arrayAllocate = new long long int[n];
    cout << "Done!" << endl;

    //cout << "Assigning data into array...";
    for (int i = 0; i < n; i++)
        arrayAllocate[i] = i;
    //cout << "Done!" << endl;

    //for (int i = 0; i < length; i++)
    //    cout << "array[" << i << "]: " << arrayAllocate[i] << endl;

    //cout << "Freeing memory...";
    //delete[] arrayAllocate;
    //cout << "Done!" << endl;

    return arrayAllocate;
}

//void freeMemory() {
//    cout << "Freeing memory...";
//    delete[] arrayAllocate;
//    cout << "Done!" << endl;
//}

bool assignArray(int arrayAdd[], unsigned n) { // add values to p array

    cout << "Assigning data into array...";
    for (int i = 0; i < length; i++)
        arrayAdd[i] = i;
    cout << "Done!" << endl;

    for (int i = 0; i < length; i++)
        cout << "array[" << i << "]: " << arrayAdd[i] << endl;

    cout << "Freeing memory...";
    delete[] arrayAdd;
    cout << "Done!" << endl;

    return true;
}

int findMax(int arrayMax[], int size) { //finds the highest array value

    maxInt = arrayMax[0];

    for (int i = 0; i < size; i++) {
        if (arrayMax[i] > maxInt) {
            maxInt = arrayMax[i];
        }
    }
    //cout << "Highest: " << highestInt << endl;
    return maxInt;
}

int randomize(int arrayMix[], int size) { //add random values and randomizes array

    cout << "MIXING!" << endl;
    srand(time(0));


    for (int i = 0; i < size; i++) {
        arrayMix[i] = rand();
        cout << arrayMix[i] << endl;
    }

    return size;
}

//Lesson 1 end
// 



// ---------------------------------------------------------------------------------------------------------------------------------------------
// HUOM TÄSTÄ ALKAA PROGRAMMING TASK KOTILÄKSYÄ VARTEN TEHTY KOODI

//ASSUMES a is in ascending order
long long int linearSearch(long long int* a, long long int x, long long int n) {

    long long int i = 0; //index for going through array

    while (i < n && a[i] <= x) { //i less than size of array
        if (a[i] == x) return i; //found x, return it's index
        i++; // x not yet found, increase index
    }

    return -1; // Not found at all, return -1
}

long long int binarySearch(long long int* a, long long int x, long long int n) {
    long long int left, right, mid; //l and r indices of current search area
    left = 0;
    right =  n - 1;

    while (left != right) {
        mid = (left + right) / 2; //find midpoint
        if (a[mid] == x) return mid;
        if (a[mid] > x) {
            //choose left
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (a[left] == x) return left;
    return -1; // Not found at all, return -1
}

void timeLinear(long long int* a, long long int x, long long int n)
{
    cout << "-------------------------------" << endl;
    cout << "LINEAR" << endl;

    auto linStart = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        cout << "linSearch(a, " << x << "," << n << ")= " << linearSearch(a, x, n) << endl;
    }

    auto linEnd = high_resolution_clock::now();

    auto linDuration = duration_cast<microseconds>(linEnd - linStart);

    cout << "Execution Time: "
        << linDuration.count()
        << " microseconds" << endl;
    cout << "-------------------------------" << endl;
}

void timeBinary(long long int* a, long long int x, long long int n)
{
    cout << "-------------------------------" << endl;
    cout << "BINARY" << endl;

    auto binStart = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        cout << "BinSearch(a, " << x << "," << n << ")= " << binarySearch(a, x, n) << endl;
    }

    auto binEnd = high_resolution_clock::now();

    auto binDuration = duration_cast<microseconds>(binEnd - binStart);

    cout << "Execution Time: "
        << binDuration.count()
        << " microseconds" << endl;
    cout << "-------------------------------" << endl;
}

int main()
{
    auto binStart = high_resolution_clock::now();

    long long int n = 1000000; //array size
    long long int* a = allocateArray(n);
    srand(time(0));
    long long int x = rand() % 1000001; //wanted value
    
    timeLinear(a, x, n);
    cout << "*" << endl;
    timeBinary(a, x, n);
}
// ---------------------------------------------------------------------------------------------------------------------------------------------