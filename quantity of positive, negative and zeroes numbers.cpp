using namespace std;
#include <iostream>
void inputing(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Input " << i + 1 << " element  ";
        cin >> arr[i];
    }
    cout << "You have got this array of numbers:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void mathing(int* arr, int size, int& positive, int& negative, int& zero) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] == 0) {
            zero++;
        }
        else {
            negative++;
        }
    }
}

int main()
{
    int size;
start:
    cout << "Input number of elements \n";
    cin >> size;
    if (size > 0);
    else {
        cout << "Wrong inputting\nTry again\n";
        goto start;
    }
    int* arr = new int[size];
    inputing(arr, size);
    int positive = 0;
    int negative = 0;
    int zero = 0;
    mathing(arr, size, positive, negative, zero);
    cout << "Positive elements = " << positive << endl;
    cout << "Negative elements = " << negative << endl;
    cout << "Zeroes elements = " << zero << endl;
}

