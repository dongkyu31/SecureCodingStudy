/*
 * DCL-07. �Լ��� ���� �ٲ��� ���� ���� ���� �����͸�
 * �Լ��ǸŰ������� ����� ���� const�� �����϶�.
 *
 * �����͸� �Ű� ������ �ϴ� �ϼ��� ���������� ���ü�� ���� �����ϴ� ������ �����Ѵ�.
 * ������ �ǵ����� �ʴ� ������ �������� const Ű���带 ����ؾ� �Ѵ�.
 */

#if 0
// ������ �ڵ�
// ������ �ڵ�� ���ڷ� ���޵� �迭�� ���� ���Ƿ� �����ϰ� �ִ�.
#include <stdio.h>

int sum_arr(int* arr, int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += arr[i];
    *arr = 0;
    return sum;
}

int main() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", sum_arr(arr, 10));
	for (int i =0; i<10; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

    return 0;
}
#endif

#if 1
// �ذ� ���
// ��� ��ü�� ����Ű�� �����ͷ� �����Ѵ�.
#include <stdio.h>

int sum_arr(const int* arr, int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += arr[i];
    *arr = 0;
    return sum;
}

int main() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", sum_arr(arr, 10));

    return 0;
}
#endif
