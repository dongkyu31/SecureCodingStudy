/*
 * INT-05. ���ڿ� ��ū�� ������ ��ȯ�� ���� strtol �Լ��� �ٸ� ���õ� �Լ��� ����϶�.
 *
 * ������ �Լ����� �ٸ� ����麸�� �ŷڼ� �ִ� ���� ó���� �����Ѵ�.
 *
 *   - strtol : long ing ��ȯ
 *   - strtoll : long long int ��ȯ
 *   - strtoul : unsigned long int ��ȯ
 *   - strtoull : unsigned long long int ��ȯ
 *
 *
 *
#if 0
// ������ �ڵ� 1.
// - atoi, atol, atoll �Լ����� ������ ���� ���������� ����
// - ���� �߻� �ÿ� errno �� �������� ����
// - ǥ���� �� ���� ��� ���� ���� ��� ���ǵ��� ���� �ൿ�� ������
// - ���ڿ��� ���� ���� ���� ��� 0�� ��ȯ�ϱ� ������ 0�� �ԷµǾ� ����������
// �ؼ��� ������ �׷��� ������ Ȯ���� �� ����.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    int data = atoi(buff);
    printf("-> %d\n", data);

    return 0;
}
#endif

#if 0
// ������ �ڵ� 2.
// sscanf �Լ��� atoi �Լ��� ������ ������ �����ϰ� ����.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    int data;
    int ret = sscanf(buff, "%d", &data);
    if (ret == 0 || ret == EOF) {
        perror("sscanf");
        exit(-1);
    }

    printf("-> %d\n", data);
    return 0;
}
#endif

#if 0
// �ذ� ���
// strtol, strtoll, strtoul, strtoull �Լ������� ����ϴ� ���� ����.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    errno = 0;
    char* end_ptr;
    long data = strtol(buff, &end_ptr, 10);
    if (errno == ERANGE) {
        perror("strtol");
        exit(-1);
    }
    else if (end_ptr == buff) {
        fprintf(stderr, "not valid numeric input\n");
        exit(-1);
    }
    else if (*end_ptr != '\n' && *end_ptr != '\0') {
        fprintf(stderr, "extra characters on input line\n");
        exit(-1);
    }

    printf("-> %ld\n", data);
    return 0;
}
#endif
