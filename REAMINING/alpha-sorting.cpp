#include <iostream>
#include <cstring>  // for strcmp
using namespace std;

bool compare(const char *a, const char *b) {
    return strcmp(a, b) < 0;
}

void sortStrings(const char *arr[], int size, bool (*cmp)(const char*, const char*)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!cmp(arr[i], arr[j])) {
                // Swap pointers
                const char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    const char *fruits[] = { "banana", "apple", "mango", "grape" };

    int size = sizeof(fruits) / sizeof(fruits[0]);

    cout << "Before sorting:\n";
    for (int i = 0; i < size; ++i) {
        cout << fruits[i] << endl;
    }

    sortStrings(fruits, size, compare);

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < size; ++i) {
        cout << fruits[i] << endl;
    }

    return 0;
}
