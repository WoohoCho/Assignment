#include <stdio.h>
#include <random>
#include <iostream>
/*InsertSort(삽입 정렬 알고리즘)*/
/*
* 원리가 가장 간단한 정렬 알고리즘 중 하나, 우선 정렬하고자하는 배열에서 가장 큰 원소를 찾아서, 배열의 가장 끝 원소와 
* 자리를 서로 맞바꾼다. 그러면 직전에 자리를 바꾼 맨 끝 원소는 이미 정렬이 된 것임으로 신경쓰지 않아도 된다. 고로 해당 원소는 정렬이 완료되었다고
* 할 수 있기 때문에 나머지 원소들로 같은 과정을 반복하면된다. 
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

    insertSort(Array, size);

    printf("정렬된 배열을 첨자 순으로 출력한다.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}