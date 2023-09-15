#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <amcl/pf/quickselect.h>

void test(int N, int n) {
    for (int j = 0; j < N; ++j) {
        float *b = new float[n];
        for (int i=0; i<n; i++) {
            b[i] = (float)rand()/(float)(RAND_MAX/5.0);
        }
        int size = n;
        float median = findmedian_quickselect(b, size);

        std::nth_element(b, b + size/2, b + size);
        float median2 = b[size/2];
        if (std::fabs(median - median2) > 0.0001) {
            printf("N %d, n %d, std median: %f\n", N, n, median2);
        }
    }
}


int main(int argc, char **argv) {
    for (int i = 0; i < 100; ++i) {
        printf("Testing for %d\n", i);
        test(100, i);
    }
}
