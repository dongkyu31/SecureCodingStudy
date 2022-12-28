/*
 * ARR-03. ����� ũ���� �������� ���簡 ������� �����϶�.
 *
 * ��� �����͸� ���� �� ���� ��ŭ ũ�� ���� �迭�� �����͸� �����ϸ� 
 * ���� ���� �÷ο찡 �߻��� �� �ִ�.
 *
 */


#if 0
// ������ �ڵ�
// memcpy �Լ�ó�� ũ�⸦ ������ ���ѵ� ���縦 �����ϴ� �Լ��� �������ϰ� ����ϸ� 
// ���� ���� �÷ο찡 �߻��� �� �ִ�.
#include <stdio.h>
//enum { BUF_SIZE = 1024 };
enum { BUF_SIZE = 4 }; // �׽�Ʈ�� ���� ���� ����

void func(const char src[], size_t len) {
    char dest[BUF_SIZE];
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
}

int main() {
    char str[] = "hello, world";
    func(str, strlen(str) + 1);

    return 0;
}
#endif 

#if 0
// �ذ� ��� 1.
// �迭�� ��踦 üũ�Ѵ�.
#include <stdio.h>
//enum { BUF_SIZE = 1024 };
enum { BUF_SIZE = 4 }; // �׽�Ʈ�� ���� ���� ����

void func(const char src[], size_t len) {
    if (len >= BUF_SIZE) { // �迭�� ��� üũ
		printf("Error. It makes Buffer(stack) Overflow \n");
        return;
	}

    char dest[BUF_SIZE];
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
}

int main() {
    char str[] = "hello, world";

    func(str, strlen(str) + 1);
    return 0;
}
#endif 

#if 1
// �ذ� ��� 2.
// ������ ����� �������� �ʰ� ���� �޸� �Ҵ��� �����Ѵ�.
#include <stdio.h>
#include <stdlib.h>

void func(const char src[], size_t len) {
    char* dest = (char*)malloc(sizeof(char) * len);
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
    free(dest);
}

int main() {
    char str[] = "hello, world";

    func(str, strlen(str) + 1);
    return 0;
}
#endif 
