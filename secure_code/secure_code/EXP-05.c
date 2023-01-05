/*
 * EXP-05. ������ ������ ��Ȯ�ϰ� ����ǰ� �ִ��� �����϶�.
 *
 * ������ ������ ������ �� �����Ϳ� �������� ���� �ڵ������� �����Ͱ� ����Ű�� ��ü��
 * Ÿ������ �����ȴ�. ������ ������ ������ ��� �����ϴ��� �����ϰ� ���� �ʴ´ٸ�
 * �ɰ��� ������ ���� �����÷θ� �ʷ��Ѵ�.
 *
 * � ������ ptr�� ������ ���� n�� ���� ��, ������ ������ ���������� ������ ���� 
 * �����Ѵ�.
 *
 *     - ptr +n == ptr + (sizeof(*ptr) * n)
 *
 */
#if 1
// ������ �ڵ�
// ���� �ڵ�� ���� �����÷ΰ� �߻��Ѵ�.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    int* cur = buf;
    while (cur < (buf + sizeof(buf))) {
		printf("sizeof(buf) is (%ld), cur is (%d)\n", sizeof(buf), cur);
        *cur++ = 0;
	}

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif

#if 0
// �ذ� ��� 1.
// ������ ���� ��, ������ ũ�⸸ŭ ���� �� �ֵ��� char* Ÿ������ ĳ�����Ѵ�.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    int* cur = buf;
    while (cur < ((char*)buf + sizeof(buf))) {
		//printf("sizeof(buf) is (%ld), cur is (%ld)\n", sizeof(buf), cur);
		printf("sizeof(buf) is (%ld), cur is (%ld)\n", sizeof(buf), cur);
        *cur++ = 0;
	}

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif

#if 0
// �ذ� ��� 2.
// ÷�� �����ڸ� ����Ѵ�.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    for (int i = 0; i < BUF_SIZE; i++)
        buf[i] = 0;

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif
