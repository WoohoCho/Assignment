#include <stdio.h>
#include <iostream>
#include <random>
int Array[20] = {};
/*
* 우선 정렬한 배열에서 기준 원소를 구한다. 고른 기준 원소를 피벗(Pivot)이라고 한다. 아무 원소리 임의로 선택해도 무관하다. 
* 여기서는 맨 뒤의 원소를 피벗으로 선택하도록 하자. 피벗을 중심으로 더 작거나 같은 수는 왼쪽으로, 큰 수는 오른 쪽으로 재배치한다. 
* 기준 원소는 이렇게 분할된 양쪽 부분 배열 사이에 자리하게 된다. 이렇게 분할된 왼쪽 부분 배열을 따로 정렬한다. 마찬가지로 오른쪽 
* 부분 배열도 따로 정렬한다. 기준원소를 손대지 말고 제자리에 그대로 둔다. 기준원소의 왼쪽에 기준원소보라 작은 원소들이 정렬되어 있고
, 오른쪽에 기쥔원소보다 큰 원소들이 정렬되어 있으면 전체 배열은 정렬된 것이다. 여기서 왼쪽과 오른쪽 부분 배열을 정렬할 때 퀵 정렬을 
재귀적으로 사용한다. 
*/

int partition(int A[], int p, int r) {
	int pivot = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] < pivot) {
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void Quick_Sort(int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		Quick_Sort(A, p, q - 1);
		Quick_Sort(A, q + 1, r);
	}
}

int main() {
	// random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100); // 1부터 100까지의 정수 생성

	// 배열 완성

	for (int i = 0; i < 20; ++i) {
		Array[i] = dis(gen);
	}

	int a = sizeof(Array) / sizeof(int);
	printf("정렬 전 배열을 첨자 순서대로 출력합니다.\n");
	for (int i = 0; i < a; i++)
	{
		printf(" %d ", Array[i]);
	}
	printf("\n");
	Quick_Sort(Array, 0, a - 1);
	printf("퀵 정렬 후 배열을 첨자 순서대로 출력합니다.\n");
	for (int i = 0; i < a; i++)
	{
		printf(" %d ", Array[i]);
	}
	return 0;
}