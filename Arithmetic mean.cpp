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
int arithmetic(int* arr, int size) {
    int middle = 0;
    for (int i = 0; i < size; i++) {
        middle = middle + arr[i];
    }
    middle = middle / size;
    return middle;
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
    int midarr = arithmetic(arr, size);
    cout << "The arithmetic mean is " << midarr;

}

