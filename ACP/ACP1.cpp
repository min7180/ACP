#define _CRT_SECURE_NO_WARNINGS //scanf() ������
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:6031) // scanf ��ȯ�� ���õȴٴ� �� ���� 

int searchMax(int n, int* arr); // �Էµ� ���� �߿��� �ִ� ã��
int searchMin(int n, int* arr); // �Էµ� ���� �߿��� �ּڰ� ã��
void swapOneTwo(int max, int min, int* arr); // �ִ��� �� ������, �ּڰ��� �� �������� �ű��
int numbersGcd(int tgcd, int* arr); // ��� ���� ���� �ִ����� ��� 

int n = 0;

int main() {

	int i, max, min, gcd;
	int* arr = NULL;

	while (n < 2) {
		printf("���� ���� ������ ������ �Է��ϼ���(�ּ� �� ��): ");
		scanf("%d", &n);
	}// ���� ���� ������ ������ 2 �̻��� �Է��� ��� ���


	arr = (int*)malloc(sizeof(int) * n); // �����Ҵ�迭

	for (i = 0; i < n; i++) {//����� �ùٸ��� �Է��ϸ� ��� 
		printf("����� �Է��ϼ���: ");
		scanf("%d", arr + i);
		while (*(arr + i) < 0) {
			printf("����� �Է��ϼ���: ");
			scanf("%d", arr + i);
		}
	}

	max = searchMax(n, arr);
	min = searchMin(n, arr);
	swapOneTwo(max, min, arr);

	while (max != 0 && min != 0) { // �ִ񰪰� �ּڰ��� �ִ����� ���ϱ� 
		if (max >= min) {
			max = max % min;
		}
		else if (max <= min) {
			min = min % max;
		}
	}

	if (max == 0)
	{
		gcd = min;
		if (n > 2) gcd = numbersGcd(min, arr); // ������ ������� �ִ����� ���ϱ�
		printf("�ִ�����: %d", gcd);
	}

	else if (min == 0)
	{
		gcd = max;
		if (n > 2) gcd = numbersGcd(max, arr);
		printf("�ִ�����: %d", gcd);
	}

	free(arr);
}

int searchMax(int n, int* arr) {
	int i;
	int temp;
	int max = arr[0];
	for (i = 1; i < n; i++) {
		if (max < arr[i]) {
			temp = max;
			max = arr[i];
			arr[i] = temp;
		}
	}

	return max;
}

int searchMin(int n, int* arr) {
	int i;
	int temp;
	int min = arr[0];
	for (i = 1; i < n; i++) {
		if (min > arr[i]) {
			temp = min;
			min = arr[i];
			arr[i] = temp;
		}
	}

	return min;
}

void swapOneTwo(int max, int min, int* arr) {
	int temp1 = max;
	int temp2 = min;
	max = arr[0];
	min = arr[1];
	arr[0] = temp1;
	arr[1] = temp2;
}

int numbersGcd(int tgcd, int* arr) {
	int i;
	int gcd;
	for (i = 2; i < n && (tgcd != 1 && arr[i] != 1); i++) { // tgcd�� 1�̰ų� arr[i]�� 1�̸� ��.
		while (arr[i] != 0 && tgcd != 0) {
			if (arr[i] >= tgcd) {
				arr[i] = arr[i] % tgcd;
			}
			else if (arr[i] <= tgcd) {
				tgcd = tgcd % arr[i];
			}
		}

		if (arr[i] == 0) {
			gcd = tgcd;
			tgcd = gcd; // ���ο� tgcd��
		}
		else if (tgcd == 0) {
			gcd = arr[i];
			tgcd = gcd; //  ���ο� tgcd��
		}
	}

	return gcd;
}

/*����� ���ϱ�
0. ���� ������ �Է� ����(�Լ� ����)
   1) �ִ񰪰� �ּڰ��� ��Ŭ���� �˰����� �̿��Ѵ�.
   ��: �ִ��� 1015, �ּڰ��� 25�� ���
   -> 25�� 1015�� ������. �̶��� ������ 15�� 25�� ��Ŭ���� �˰����� �� �� ��
   �����Ѵ�. 15�� 25�� ������. �̶��� ������ 10�� 15�� ��Ŭ���� �˰����� �� ��
   �� �����Ѵ�. 15�� 10���� ������. �̶��� ������ 5�� 10�� ��Ŭ���� �˰����� �� ��
   �� �����Ѵ�. 10�� 5�� ������. �������� 0�̹Ƿ� �� ���� �ִ�������
   ���������� ������ ���� 5�� �ȴ�. ���⼭ ������ 5�� ������ ���ڵ���� ��Ŭ����
   �˰����� �����Ѵ�. */