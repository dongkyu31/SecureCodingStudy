/*
 * EXP-01. ������ �켱������ ��Ÿ���µ� ��ȣ�� ����϶�
 *
 * ��ȣ�� �����ϰ� ����ϸ� �켱���� ������ �߻��ϴ� �Ǽ��� ���� �� ������
 * ��������� ������ ���� �� �ְ� �ڵ� �������� ��������.
 *
 */

#if 0
// ������ �ڵ� 1.
// ������ �켱������ �߸� �����Ͽ� �ڵ尡 �ǵ���� ������� �ʴ´�.
#include <stdio.h>

int is_even(int x) {
    return x & 1 == 0 ? 1 : 0;
}

int main() {
    int n = 2;

    if (is_even(n))
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}
#endif

#if 0
// �ذ� ���
// ǥ������ �ǵ���� �򰡵ǵ��� ��ȣ�� ����Ѵ�.
#include <stdio.h>

int is_even(int x) {
    return (x & 1) == 0 ? 1 : 0;
}

int main() {
    int n = 2;

    if (is_even(n))
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}
#endif

#if 0
// ������ �ڵ� 2.
// ������ �켱������ �߸� �����Ͽ� �ڵ尡 �ǵ���� ������� �ʴ´�.
#include <stdio.h>

void incr(int* p) {
    *p++;
}

int main() {
    int cnt = 0;

    incr(&cnt);
    printf("cnt = %d\n", cnt);

    return 0;
}
#endif

#if 0
// �ذ� ���
// ǥ������ �ǵ���� �򰡵ǵ��� ��ȣ�� ����Ѵ�.
#include <stdio.h>

void incr(int* p) {
    (*p)++;
}

int main() {
    int cnt = 0;

    incr(&cnt);
    printf("cnt = %d\n", cnt);

    return 0;
}

#endif
