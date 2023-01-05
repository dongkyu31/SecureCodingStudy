/*
 * EXP-04. const�� ĳ��Ʈ�� ������ ����
 *
 * const�� ����� ��ü�� �� ��� ��ü�� ��ȯ�Ͽ� ����� ���, �ǵ����� ���� ����� ��Ÿ�� �� �ִ�.
 *
 */

#if 0
// ������ �ڵ�
// strlen �Լ� ���ο��� ���ڷ� ���޵� ���ڿ��� ���� ������ �� �ִ�.
#include <stdio.h>

int str_len(const char* s) {
    char* p = s;
    while (*p)
        ++p;
    return p - s;
}

int main() {
    char str[] = "hello";
    printf("%d\n", str_len(str));

    return 0;
}
#endif

#if 0
// �ذ� ���
// �� ��� ��ü�� �����ͷ� ĳ���v���� �ʴ´�.
#include <stdio.h>

int str_len(const char* s) {
    const char* p = s;
    while (*p)
        ++p;
    return p - s;
}

int main() {
    char str[] = "hello";
    printf("%d\n", str_len(str));

    return 0;
}
#endif
