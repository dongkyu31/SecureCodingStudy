/*
 * EXP-03. ����ü�� ũ�Ⱑ ����ü ����� ũ���� ���̶�� �������� ����
 *
 *  ����ü�� ũ��� �׻� ����� ũ���� ���հ� ��ġ���� �ʴ´�. C99 ǥ�ؿ� ���ϸ�
 *  "����ü ��ü���� ������ �ʴ� �е�(padding)�� �� �� ������, ���ʿ��� ��ġ
 *  ���� �ʴ´�"�� ��õǾ� �ִ�. �̴� CPU�� �޸𸮿� ������ ������ �� �ֵ��� �ϱ�
 *  �����̴�. ����ü�� �е��� ��� ���Ե����� �����Ϸ��� ���ǿ� ������.
 *
 *
 *
 */

#if 0
// ������ �ڵ�
// ������ ����ü�� ũ�Ⱑ ������� ���հ� ���ٰ� �����ϰ� �ִ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string {
    char arr[10];
    int len;
} string;

string* make_str(const char* str) {
    string* p = malloc(14);
    strcpy(p->arr, str);
    p->len = strlen(str);

    return p;
}

int main() {
    string* hello = make_str("hello");

    string buf;
    memcpy(&buf, hello, sizeof(string));

    free(hello);
    return 0;
}
#endif

#if 0
// �ذ� ���
// sizeof �����ڸ� �̿��Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string {
    char arr[10];
    int len;
} string;

string* make_str(const char* str) {
    string* p = malloc(sizeof(string));
    strcpy(p->arr, str);
    p->len = strlen(str);

    return p;
}

int main() {
    string* hello = make_str("hello");

    string buf;
    memcpy(&buf, hello, sizeof(string));

    free(hello);
    return 0;
}
#endif
