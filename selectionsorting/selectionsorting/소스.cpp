//Selction Sort
//선택 정렬
// 정렬할 배열 전체에서 가장 큰 수를 선택한다. 
//선택한 수를 배열의 마지막 첨자 원소로 자리를 서로 바꾼다.
//자리가 재배치된 마지작을 제외하고 나머지들을 한해서 반복한다. 
#include <stdio.h>
#include <iostream>
#include <random>
int theLargest(int A[], int last) {
    int largest = 0; // 0으로 초기화
    for (int i = 1; i <= last; i++) { // i의 시작값을 1로 변경
        if (A[i] >= A[largest]) {
            largest = i;
        }
    }
    return largest;
}
void SelectionSort(int A[], int n) {
    for (int last = n; last > 1; last--) {
        int k = theLargest(A, last);
        int temp = A[k]; // 임시 변수명을 temp로 변경
        A[k] = A[last];
        A[last] = temp; // 원소의 값들을 직접 교환
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

    SelectionSort(Array, size);

    printf("정렬된 배열을 첨자 순으로 출력한다.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}
