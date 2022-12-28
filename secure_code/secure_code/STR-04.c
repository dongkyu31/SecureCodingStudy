/*
 * STR-04. ��谡 �Һи��� �ҽ��κ��� ������ ������ �迭�� �����͸� �������� ����.
 *
 * ������ ��� ���� ���縦 �����ϴ� �Լ����� ���� �ܺ� �Է¿��� ������ ũ�Ⱑ ���� ���̶�� �����Ѵ�.
 * �׷��� �̷��� ������ Ʋ�� �� �ְ� ���� �����÷ο츦 �߻���ų �� �ִ�.
 *
 */

#if 0
// ������ �ڵ� 1.
#include <stdio.h>

int main() {
    char buf[32];
    gets(buf);
    printf("%s\n", buf);

    return 0;
}
#endif 

#if 0
// �ذ� ���
// fgets() �Լ��� ����Ѵ�.
#include <stdio.h>

int main() {
    char buf[32];
    fgets(buf, sizeof(buf), stdin);
    printf("[%s]\n", buf);

    return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
// ������ �ڵ�� ���� �����÷ο찡 �߻��� ���ɼ��� �ִ�.
#include <stdio.h>
int main(int argc, char* argv[]) {
    char name[16];
    printf("input name: ");
    scanf("%s", name);
    printf("-> %s\n", name);
    return 0;
}
#endif 

#if 1
// �ذ� ���
// ���� �����ڷ� ��踦 �����Ѵ�.
#include <stdio.h>
#define TO_STR(x) #x 
#define STR_LIMIT(x) TO_STR(x) 
#define INPUT_SIZE 15 
int main(int argc, char* argv[]) {
    char name[INPUT_SIZE + 1];
    printf("input name: ");
    scanf("%"STR_LIMIT(INPUT_SIZE)"s", name);
    printf("-> %s\n", name);
    return 0;
}
#endif 
