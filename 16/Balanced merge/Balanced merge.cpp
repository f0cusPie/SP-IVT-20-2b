#include <iostream>
using namespace std;

int n;
int* temporaryArray;

void Merge(int* array, int start, int middle, int end)
{
    int leftPtr = start;
    int rightPtr = middle + 1;
    int length = end - start + 1;
    for (int i = 0; i < length; i++)
    {
        if (rightPtr > end || (leftPtr <= middle && array[leftPtr] < array[rightPtr]))
        {
            temporaryArray[i] = array[leftPtr];
            leftPtr++;                                                                
        }
        else
        {
            temporaryArray[i] = array[rightPtr];
            rightPtr++;
        }
    }
    for (int i = 0; i < length; i++)
        array[i + start] = temporaryArray[i];
}

void MergeSort(int* array, int start, int end)
{
    if (start == end) return;

    int middle = (start + end) / 2;
    MergeSort(array, start, middle);
    MergeSort(array, middle + 1, end);
    Merge(array, start, middle, end);

}

void MergeSort(int* array)
{
    temporaryArray = new int[n];
    MergeSort(array, 0, n - 1);
}


int* GenerateArray()
{
    int* array = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = rand() % 10 + 1;
    return array;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите размер массива: ";
    for (size_t i = 0; i < n; i++)
    {

    }
    cin >> n;
    int* array = GenerateArray();
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    MergeSort(array);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}