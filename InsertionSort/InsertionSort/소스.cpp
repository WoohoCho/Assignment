#include <stdio.h>
#include <random>
#include <iostream>
/*InsertSort(���� ���� �˰���)*/
/*
* ������ ���� ������ ���� �˰��� �� �ϳ�, �켱 �����ϰ����ϴ� �迭���� ���� ū ���Ҹ� ã�Ƽ�, �迭�� ���� �� ���ҿ� 
* �ڸ��� ���� �¹ٲ۴�. �׷��� ������ �ڸ��� �ٲ� �� �� ���Ҵ� �̹� ������ �� �������� �Ű澲�� �ʾƵ� �ȴ�. ��� �ش� ���Ҵ� ������ �Ϸ�Ǿ��ٰ�
* �� �� �ֱ� ������ ������ ���ҵ�� ���� ������ �ݺ��ϸ�ȴ�. 
* 
*/
int A[20] = { 2, 55, 4, 78, 90, 100, 123, 321, 98, 99, 5, 6, 89, 198, 200, 203, 555, 1, 6, 97 };

void insertSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int loc = i - 1;
        int newItem = A[i];
        while (loc >= 0 and newItem < A[loc]) {
            A[loc + 1] = A[loc];
            loc--;
        }
        A[loc + 1] = newItem;
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

    insertSort(Array, size);

    printf("���ĵ� �迭�� ÷�� ������ ����Ѵ�.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}