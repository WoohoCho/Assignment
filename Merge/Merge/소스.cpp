#include <stdio.h>
#include <iostream>
#include <random>
/*
    병합 정렬
    병합 정렬은 먼저 입력을 반으로 나눈다. 이렇게 나눈 전반부와 후반부를 각각 독립적으로 정렬한다. 마지막으로 정렬된 두 부분을 합쳐서,
    즉 병합하여 정렬된 배열을 얻는다. 여기서 전반부를 정렬할 때도 역시 반으로 나눈 다음 정렬해서 반영한다. 즉. 원래의 정렬 문제와 
    성격이 똑같고 단지 크기만 반으로 줄였을 뿐이다. 후반부에 대한 정렬도 마찬가지이다. 병합 정렬은 이 똑같고 단지 크기만 반으로 줄였을 뿐이다. 
    후반 부에 대한 정렬도 마찬가지이다. 병합 정렬은 자신에 비해 크기가 반인 문제를 두 개 푼 다음, 이들을 병합하는 일을 재귀적으로 반복한다. 
*/
int A[20] = {};
void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int* tmp = new int[r - p + 1](); // 배열을 0으로 초기화

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

    delete[] tmp; // 동적으로 할당한 배열은 delete[]를 해주어야 함
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
    std::uniform_int_distribution<> dis(1, 100); // 1부터 100까지의 정수 생성

    // 배열 완성
  
    for (int i = 0; i < 20; ++i) {
        A[i] = dis(gen);
    }

    int a = sizeof(A) / sizeof(int);
    printf("정렬되지 않은 배열을 인덱스 순으로 출력합니다.\n");
    for (int i = 0; i < a; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");

    mergeSort(A, 0, a - 1);

    printf("정렬된 배열을 인덱스 순으로 출력합니다.\n");
    for (int i = 0; i < a; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");

    return 0;
    
}