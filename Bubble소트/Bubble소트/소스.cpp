#include <stdio.h>
#include <random>

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // 1부터 100까지의 정수 생성

    int Array[20];
    for (int i = 0; i < 20; ++i) {
        Array[i] = dis(gen);
    }
    int size = sizeof(Array) / sizeof(int);

    printf("정렬되기 이전의 배열을 첨자 순으로 출력한다.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    BubbleSort(Array, size);

    printf("정렬된 배열을 첨자 순으로 출력한다.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}