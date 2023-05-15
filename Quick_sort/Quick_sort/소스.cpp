#include <stdio.h>
#include <iostream>
#include <random>
int Array[20] = {};
/*
* �켱 ������ �迭���� ���� ���Ҹ� ���Ѵ�. �� ���� ���Ҹ� �ǹ�(Pivot)�̶�� �Ѵ�. �ƹ� ���Ҹ� ���Ƿ� �����ص� �����ϴ�. 
* ���⼭�� �� ���� ���Ҹ� �ǹ����� �����ϵ��� ����. �ǹ��� �߽����� �� �۰ų� ���� ���� ��������, ū ���� ���� ������ ���ġ�Ѵ�. 
* ���� ���Ҵ� �̷��� ���ҵ� ���� �κ� �迭 ���̿� �ڸ��ϰ� �ȴ�. �̷��� ���ҵ� ���� �κ� �迭�� ���� �����Ѵ�. ���������� ������ 
* �κ� �迭�� ���� �����Ѵ�. ���ؿ��Ҹ� �մ��� ���� ���ڸ��� �״�� �д�. ���ؿ����� ���ʿ� ���ؿ��Һ��� ���� ���ҵ��� ���ĵǾ� �ְ�
, �����ʿ� ������Һ��� ū ���ҵ��� ���ĵǾ� ������ ��ü �迭�� ���ĵ� ���̴�. ���⼭ ���ʰ� ������ �κ� �迭�� ������ �� �� ������ 
��������� ����Ѵ�. 
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
	std::uniform_int_distribution<> dis(1, 100); // 1���� 100������ ���� ����

	// �迭 �ϼ�

	for (int i = 0; i < 20; ++i) {
		Array[i] = dis(gen);
	}

	int a = sizeof(Array) / sizeof(int);
	printf("���� �� �迭�� ÷�� ������� ����մϴ�.\n");
	for (int i = 0; i < a; i++)
	{
		printf(" %d ", Array[i]);
	}
	printf("\n");
	Quick_Sort(Array, 0, a - 1);
	printf("�� ���� �� �迭�� ÷�� ������� ����մϴ�.\n");
	for (int i = 0; i < a; i++)
	{
		printf(" %d ", Array[i]);
	}
	return 0;
}