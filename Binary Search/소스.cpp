#include <iostream>
using namespace std;
int sequentialSearch(int dataArr[], int length, int findData)
{
	for (int i = 0; i < length; i++)
		if (dataArr[i] == findData) return i;
	return -1;
}
int main()
{
	int arr[] = { 23, 25, 14, 5, 66, 72, 13, 224, 51 };
	int length = sizeof arr / sizeof arr[0];
	int findData = 0;
	int findIndex = 0;
	while (true)
	{
		cout << "ã���ô� �����͸� �Է����ּ���: ";
		cin >> findData;
		findIndex = sequentialSearch(arr, length, findData);
		if (findIndex == -1) cout << "�����͸� ã�� ���߽��ϴ�." << endl;
		else cout << "INDEX : " << findIndex << endl;
	}
	return 0;
}