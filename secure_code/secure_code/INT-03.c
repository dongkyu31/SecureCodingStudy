/*
 * INT-03. �Һи��� �ҽ����� ������� ���� ���� ������ �����϶�
 *
 * �ŷ��� �� ���� �ҽ��κ��� ������� ���� ���� �ĺ��� �� �ִ� ���� ���� ���� ���� �ִ�����
 * Ȯ���ϱ� ���� �ݵ�� �򰡵Ǿ�� �Ѵ�.
 *
 */

#if 1
// ������ �ڵ�
// �޸𸮸� �������� �Ҵ��ϴ� �ڵ忡�� ũ�� ���� �˻����� ���� ���, �޸� �Ҵ��� ������ �� ������
// ���� ó���� ������ ���� ���� �ź�(denial of server) ���°� �� �� ����.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* create_buff(size_t len) {
    return malloc(sizeof(char) * len);
}

int main() {
    char buff[24];

    printf("input string: ");
    scanf("%s", buff);

    int len = strlen(buff);
    char* str = create_buff(len + 1);
    strcpy(str, buff);

    printf("-> %s\n", str);
    free(str);

    return 0;
}
#endif

#if 0
// �ذ� ���
// ���� ������ ���� ������ �˻������ν� �ذ� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { MAX_STRING_LEN = 1024 };

char* create_buff(size_t len) {
    if (len == 0 || len > MAX_STRING_LEN)
        return NULL;
    return malloc(sizeof(char) * len);
}

int main() {
    char buff[MAX_STRING_LEN];
    printf("input string: ");
    scanf("%s", buff);

    int len = strlen(buff);
    char* str = create_buff(len + 1);
    if (str == NULL) {
        fprintf(stderr, "create_buff error\n");
        exit(-1);
    }
    strcpy(str, buff);

    printf("-> %s\n", str);
    free(str);

    return 0;
}
#endif


