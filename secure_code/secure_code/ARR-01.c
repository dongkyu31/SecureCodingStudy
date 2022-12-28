/*
 * ARR-01. �迭�� ũ�⸦ ���� �� �����͸� sizeof�� �ǿ����ڷ� ������� ����.
 *
 * sizeof �� �������� ũ�⸦ ����Ʈ ������ ����ϴ� �����ڷ� sizeof �����ڷ�
 * �迭�� ũ�⸦ ����� ���� �����ؾ� �Ѵ�.
 *
 */


#if 0
// ������ �ڵ�
// �迭�� ���޵� �Լ� ������ �迭�� ũ�⸦ ����ϰ� �ִ�.
#include <stdio.h>

void clear(int arr[]) { // void clear(int *arr) -> ��, �迭�� �ּҸ� ������ ��
	// sizeof(*arr) �� arr �����Ͱ� ����Ű�� int�� ũ����  4����Ʈ����, 
	// �迭 ��ü�� ���� ���⼭ sizeof(arr)�� �ܼ� �迭�� �ּ��̹Ƿ� �ּҰ� ����Ű�� int�� ũ���� 4����Ʈ�� �ȴ�.
    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        arr[i] = 0;
}

int main() {
    int arr[5];

    clear(arr);
    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        printf("arr[%u] = %d\n", i, arr[i]);

    return 0;
}
#endif 

#if 1
// �ذ� ���
// �迭�� ����� ��� �ȿ��� ũ�⸦ ����� �� �̸� �Լ��� ���ڷ� �����ؼ� �ʱ�ȭ �Ѵ�.
#include <stdio.h>

void clear(int arr[], int len) {
    for (size_t i = 0; i < len; i++)
        arr[i] = 0;
}

int main() {
    int arr[5];
    size_t len = sizeof(arr) / sizeof(*arr);

    clear(arr, len);
    for (size_t i = 0; i < len; i++)
        printf("arr[%u] = %d\n", i, arr[i]);

    return 0;
}
#endif
