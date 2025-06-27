#include <iostream>
#include <fstream>
using namespace std;

int countFrequency(int arr[], int size, int num) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            count++;
    }
    return count;
}

int findMostOccurring(int arr[], int size) {
    int maxCount = 0;
    int mostOccurring = arr[0];

    for (int i = 0; i < size; i++) {
        int count = countFrequency(arr, size, arr[i]);
        if (count > maxCount) {
            maxCount = count;
            mostOccurring = arr[i];
        }
    }

    return mostOccurring;
}

int main() {
    ifstream file("Integer Data.txt");
    int arr[100];
    int size = 0;

    while (file >> arr[size]) {
        size++;
    }

    int result = findMostOccurring(arr, size);
    cout << "Most occurring element is: " << result;

    return 0;
}

