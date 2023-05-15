#include <stdio.h>
#include <iostream>
#include <random>

int Array[20] = {};

void heapify(int A[], int k, int n) {
    int left = 2 * k;
    int right = 2 * k + 1;
    int larger = k;
    if (left <= n && A[left] > A[larger]) {
        larger = left;
    }
    if (right <= n && A[right] > A[larger]) {
        larger = right;
    }
    if (larger != k) {
        int temp = A[k];
        A[k] = A[larger];
        A[larger] = temp;
        heapify(A, larger, n);
    }
}

void buildheap(int A[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

void heapSort(int A[], int n) {
    buildheap(A, n);
    for (int i = n; i > 0; i--) {
        int c = A[i];
        A[i] = A[0];
        A[0] = c;
        heapify(A, 0, i - 1);
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // 1���� 100������ ���� ����

    // �迭 �ϼ�
    int Array[20];
    for (int i = 0; i < 20; ++i) {
        Array[i] = dis(gen);
    }
    int a = sizeof(Array) / sizeof(int);
    printf("���ĵǱ� ������ �迭�� ÷�� ������ ����Ѵ�.\n");
    for (int i = 0; i < a; i++) {
        printf(" %d ", Array[i]);
    }
    printf("\n");
    printf("�� ���ĵǱ� ������ �迭�� ÷�� ������ ����Ѵ�.\n");
    heapSort(Array, a - 1);
    for (int i = 0; i < a; i++) {
        printf(" %d ", Array[i]);
    }
    return 0;
}
