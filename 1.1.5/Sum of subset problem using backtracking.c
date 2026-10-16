#include <stdio.h>
#include <stdlib.h>

int a[100];
int subset[100];
int n, target;

int solutions[1000][100];
int sizes[1000];
int count = 0;

void findSubsets(int index, int sum, int size) {
    if (index == n) {
        if (sum == target) {
            for (int i = 0; i < size; i++) {
                solutions[count][i] = subset[i];
            }
            sizes[count] = size;
            count++;
        }
        return;
    }

    // Include current element
    subset[size] = a[index];
    findSubsets(index + 1, sum + a[index], size + 1);

    // Exclude current element
    findSubsets(index + 1, sum, size);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &target);

    findSubsets(0, 0, 0);

    if (count == 0) {
        printf("-1\n");
    } else {
        // Print in reverse order of discovery
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < sizes[i]; j++) {
                printf("%d ", solutions[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
