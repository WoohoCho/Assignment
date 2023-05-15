#include <stdio.h>
#include <iostream>
#include <random>
/*
    ���� ����
    ���� ������ ���� �Է��� ������ ������. �̷��� ���� ���ݺο� �Ĺݺθ� ���� ���������� �����Ѵ�. ���������� ���ĵ� �� �κ��� ���ļ�,
    �� �����Ͽ� ���ĵ� �迭�� ��´�. ���⼭ ���ݺθ� ������ ���� ���� ������ ���� ���� �����ؼ� �ݿ��Ѵ�. ��. ������ ���� ������ 
    ������ �Ȱ��� ���� ũ�⸸ ������ �ٿ��� ���̴�. �Ĺݺο� ���� ���ĵ� ���������̴�. ���� ������ �� �Ȱ��� ���� ũ�⸸ ������ �ٿ��� ���̴�. 
    �Ĺ� �ο� ���� ���ĵ� ���������̴�. ���� ������ �ڽſ� ���� ũ�Ⱑ ���� ������ �� �� Ǭ ����, �̵��� �����ϴ� ���� ��������� �ݺ��Ѵ�. 
*/
int A[20] = {};
void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int* tmp = new int[r - p + 1](); // �迭�� 0���� �ʱ�ȭ

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = A[i++];
    }

    while (j <= r) {
        tmp[t++] = A[j++];
    }

    t = 0;
    for (i = p; i <= r; i++) {
        A[i] = tmp[t++];
    }

    delete[] tmp; // �������� �Ҵ��� �迭�� delete[]�� ���־�� ��
}

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int main() {

    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // 1���� 100������ ���� ����

    // �迭 �ϼ�
  
    for (int i = 0; i < 20; ++i) {
        A[i] = dis(gen);
    }

    int a = sizeof(A) / sizeof(int);
    printf("���ĵ��� ���� �迭�� �ε��� ������ ����մϴ�.\n");
    for (int i = 0; i < a; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");

    mergeSort(A, 0, a - 1);

    printf("���ĵ� �迭�� �ε��� ������ ����մϴ�.\n");
    for (int i = 0; i < a; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");

    return 0;
    
}