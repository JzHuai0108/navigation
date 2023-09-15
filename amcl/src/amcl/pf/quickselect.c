#include <amcl/pf/quickselect.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void quickselect(float arr[], int k, int size) {
    int i, j, l, m;
    float x;

    l=0; m=size-1;
    while (l<m) {
        x = arr[k];
        i = l;
        j = m;
        do {
            while (arr[i] < x) i++;
            while (x < arr[j]) j--;
            if (i<=j) {
                swap(&arr[i], &arr[j]);
                i++; j--;
            }
        } while (i<=j);
        if (j<k) l=i;
        if (k<i) m=j;
    }
}

float findmedian_quickselect(float arr[], int size) {
    int halfsize = size/2;
    quickselect(arr, halfsize, size);
    return arr[halfsize];
}

float findmax(float arr[], int size) {
    float max = -100000;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}