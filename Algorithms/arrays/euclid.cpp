#include <iostream>
using namespace std;

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
int highestInt;

int arrayMixed[100];
//int* arrayAllocate = new int[100];

static int* allocateArray(unsigned n) { // add values to p array and allocate memory

    //int _array[100]{};
    //unsigned n = 100;

    cout << "Reserving memory...";
    int* arrayAllocate = new int[n];
    cout << "Done!" << endl;

    cout << "Assigning data into array...";
    for (int i = 0; i < length; i++)
        arrayAllocate[i] = i;
    cout << "Done!" << endl;

    for (int i = 0; i < length; i++)
        cout << "array[" << i << "]: " << arrayAllocate[i] << endl;

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

    highestInt = arrayMax[0];

    for (int i = 0; i < size; i++) {
        if (arrayMax[i] > highestInt) {
            highestInt = arrayMax[i];
        }
    }
    //cout << "Highest: " << highestInt << endl;
    return highestInt;
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
//ASSUMES a is in ascending order
int linearSearch(int* a, int x, int n) {

    int i = 0; //index for going through array

    while (i < n && a[i] <= x) { //i less than size of array
        if (a[i] == x) return i; //found x, return it's index
        i++; // x not yet found, increase index
    }

    return -1; // Not found at all, return -1
}

int main()
{
    int n = 100;
    int* a = allocateArray(n);
    int x = 42;
    cout << "linSearch(a, " << x << "," << n << ")=" << linearSearch(a, x, n);

    //freeMemory();
    // 
    //AllocateArray(length);
    //AssignArray(arrayAllocate, length);
    //Randomize(arrayMixed, length);

    //int max = FindMax(arrayMixed, length);

    //cout << "Max in arrayMixed: " << FindMax(arrayMixed, length) << endl;

    //int a = 42; int b = 35;
    //cout << "gcd( " << a << " , " << b << " )= " << (a, b) << endl;
    //return EXIT_SUCCESS;
}

