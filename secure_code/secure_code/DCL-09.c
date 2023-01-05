/*
 * DCL-09. �Լ� ���ڿ��� restrict�� ������ �ҽ� �����Ϳ� 
 * ���� �����Ͱ� ������ ��ü�� �������� �ʰ� �϶�
 *
 * restrict Ű����� ���� �����Ϳ��� ����Ǵ� Ű����� �� �����Ͱ� ������
 * ��ü�� ������ �� �ִ� �����ϰ� ���ʰ� �Ǵ� �������� ��Ÿ����.
 * ��, �����Ͱ� restrict�� �����Ǹ� �� �����Ͱ� ����Ű�� ������ �����
 * �� �����͸��� ������ �����ϹǷ� �����Ϸ��� �� ȿ�������� �ڵ带
 * ����ȭ�� �� �ִ�.
 *
 * �׷��� restrict �����ڸ� ����� ���� �����͵��� ���� ������ ��ü�� �������� 
 * ���ƾ� �Ѵ�. �Լ��� �� �����Ͱ� ������ ��ü�� �����ϴ� ��� �� ����� 
 * ������ �����̴�.
 *
 */
 
#if 1
// restrict ������

#include <stdio.h>

void foo(int* a, int* b, int* c)
{
	*a += *c;
	*b += *c;
}

int main() {
	int a = 1;
	foo(&a, &a, &a);
	printf("%d\n", a);
	return 0;
}

#endif




#if 0
// ������ �ڵ�
// memcpy�� restrict �����ڸ� ����� �Լ��� ������ ��ü�� �ּҸ� ���ڷ� �����ϸ� �� ����� �� �� ����.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    --cnt;
    memcpy(arr, arr + 1, sizeof(int) * cnt);
    print_arr(arr, cnt);

    return 0;
}
#endif

#if 0
// �ذ� ��� 1.
// �޸��� ������ ������� �ʴ� �ٸ� ������ ��Ҹ� �� �ʿ� �����Ѵ�.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    arr[0] = arr[--cnt];
    print_arr(arr, cnt);

    return 0;
}

#endif



#if 0
// �ذ� ��� 2.
// memmove �Լ��� ����Ͽ� ó���Ѵ�. memmove �Լ��� ���������� ���۸� ������ �־�
// �����ϰ� ���簡 �����ϴ�.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    --cnt;
    memmove(arr, arr + 1, sizeof(int) * cnt);
    print_arr(arr, cnt);

    return 0;
}


#endif
