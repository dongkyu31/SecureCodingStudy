/*
 * INT-04. ��� ������ �Է��� ó���� �� ���ٸ� ���� ������ ��ȯ�� ���� �Է� �Լ��� ������� ����
 *
 * scanf, fscanf, vscanf, vfscanf �Լ��� stdin �Ǵ� �ٸ� �Է� ��Ʈ�����κ��� ���ڿ� �����͸�
 * �дµ� ����Ѵ�. �� �Լ����� ��ȿ�� ���� ���� ���� �� ���������� ��ȿ���� �ʴ� ���� ���ؼ��� 
 * �ŷڼ��� �ִ� ó���� ���� ���Ѵ�.
 */

#if 0
// ������ �ڵ�
//  ������ �ε��Ҽ��� ���� �Է� �ޱ� ���� scanf �Ǵ� fscanf �Լ��� ����ϴ� ���,
//  ������ ������ �߻��� ���ɼ��� ����.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int data;
    printf("input integer: ");

    int ret = scanf("%d", &data);
    if (ret != 1 || ret == EOF) {
        perror("scanf");
        exit(-1);
    }
    printf("-> %d\n", data);

    return 0;
}
#endif 

#if 0
// �ذ� ���
// �Է� ���ڿ��� ó���ϴµ� fgets �Լ��� ����ϰ�, ���ڿ��� ������ ��ȯ�ϱ� 
// ���ؼ� strtol �Լ��� ����ϴ� ���� ����. strtol �Լ��� �Է� ���� long ��������
// ��ȿ���� �����ϴ� ���� üũ�� �����Ѵ�.
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


