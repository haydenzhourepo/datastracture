#include <stdio.h>

int sort1(const int a[], int n) {
    int max = a[0];

    for (int i = 1; i <n ; ++i) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

int sort2(int a[], int n) {
    int i, j, temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}