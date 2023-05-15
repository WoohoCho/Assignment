//Selction Sort
//���� ����
// ������ �迭 ��ü���� ���� ū ���� �����Ѵ�. 
//������ ���� �迭�� ������ ÷�� ���ҷ� �ڸ��� ���� �ٲ۴�.
//�ڸ��� ���ġ�� �������� �����ϰ� ���������� ���ؼ� �ݺ��Ѵ�. 
#include <stdio.h>
#include <iostream>
#include <random>
int theLargest(int A[], int last) {
    int largest = 0; // 0���� �ʱ�ȭ
    for (int i = 1; i <= last; i++) { // i�� ���۰��� 1�� ����
        if (A[i] >= A[largest]) {
            largest = i;
        }
    }
    return largest;
}
void SelectionSort(int A[], int n) {
    for (int last = n; last > 1; last--) {
        int k = theLargest(A, last);
        int temp = A[k]; // �ӽ� �������� temp�� ����
        A[k] = A[last];
        A[last] = temp; // ������ ������ ���� ��ȯ
    }
}
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // 1���� 100������ ���� ����

    int Array[20];
    for (int i = 0; i < 20; ++i) {
        Array[i] = dis(gen);
    }
    int size = sizeof(Array) / sizeof(int);

    printf("���ĵǱ� ������ �迭�� ÷�� ������ ����Ѵ�.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    SelectionSort(Array, size);

    printf("���ĵ� �迭�� ÷�� ������ ����Ѵ�.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}
