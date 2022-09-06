#define _CRT_SECURE_NO_WARNINGS //scanf() 때문에
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:6031) // scanf 반환값 무시된다는 걸 무시 

int searchMax(int n, int* arr); // 입력된 수들 중에서 최댓값 찾기
int searchMin(int n, int* arr); // 입력된 수들 중에서 최솟값 찾기
void swapOneTwo(int max, int min, int* arr); // 최댓값을 맨 앞으로, 최솟값을 그 다음으로 옮기기
int numbersGcd(int tgcd, int* arr); // 모든 수에 대해 최대공약수 얻기 

int n = 0;

int main() {

	int i, max, min, gcd;
	int* arr = NULL;

	while (n < 2) {
		printf("비교할 양의 정수의 개수를 입력하세요(최소 두 개): ");
		scanf("%d", &n);
	}// 비교할 양의 정수의 개수를 2 이상을 입력할 경우 통과


	arr = (int*)malloc(sizeof(int) * n); // 동적할당배열

	for (i = 0; i < n; i++) {//양수를 올바르게 입력하면 통과 
		printf("양수를 입력하세요: ");
		scanf("%d", arr + i);
		while (*(arr + i) < 0) {
			printf("양수를 입력하세요: ");
			scanf("%d", arr + i);
		}
	}

	max = searchMax(n, arr);
	min = searchMin(n, arr);
	swapOneTwo(max, min, arr);

	while (max != 0 && min != 0) { // 최댓값과 최솟값의 최대공약수 구하기 
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
		if (n > 2) gcd = numbersGcd(min, arr); // 나머지 수들과의 최대공약수 구하기
		printf("최대공약수: %d", gcd);
	}

	else if (min == 0)
	{
		gcd = max;
		if (n > 2) gcd = numbersGcd(max, arr);
		printf("최대공약수: %d", gcd);
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
	for (i = 2; i < n && (tgcd != 1 && arr[i] != 1); i++) { // tgcd가 1이거나 arr[i]가 1이면 끝.
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
			tgcd = gcd; // 새로운 tgcd값
		}
		else if (tgcd == 0) {
			gcd = arr[i];
			tgcd = gcd; //  새로운 tgcd값
		}
	}

	return gcd;
}

/*공약수 구하기
0. 양의 정수만 입력 가능(함수 구현)
   1) 최댓값과 최솟값을 유클리드 알고리즘을 이용한다.
   예: 최댓값이 1015, 최솟값이 25인 경우
   -> 25로 1015를 나눈다. 이때의 나머지 15와 25에 유클리드 알고리즘을 한 번 더
   적용한다. 15로 25를 나눈다. 이때의 나머지 10과 15에 유클리드 알고리즘을 한 번
   더 적용한다. 15를 10으로 나눈다. 이때의 나머지 5와 10에 유클리드 알고리즘을 한 번
   더 적용한다. 10을 5로 나눈다. 나머지가 0이므로 두 수의 최대공약수는
   마지막으로 나누는 수인 5가 된다. 여기서 구해진 5로 나머지 숫자들과도 유클리드
   알고리즘을 적용한다. */