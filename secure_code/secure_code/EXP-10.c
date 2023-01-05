/*
 * EXP-10. �� �����Ͱ� ������ ���� ������ �����϶�
 *
 * �� �����͸� ������ �ϸ� ���α׷��� �� �� ���� ���°� �Ǹ�
 * ������ ����ȴ�. ������ �� �����ʹ� ������ ���� �ʴ� ���� ����.
 *
 */

#if 0
// ������ �ڵ�
// malloc �Լ� ȣ�� ��, ���� ���� �������� �ʰ� �ִ�.
// ���⼭ ���� �� �����Ͱ� ��ȯ�� ���, ���α׷��� ������ ����ȴ�.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = malloc(-1);

    for (int i = 0; i < 10; i++)
        pArr[i] = 0;

    // ...

    free(pArr);
    return 0;
}
#endif 

#if 0
// �ذ� ���
// malloc �Լ��� ��ȯ ���� �����Ѵ�.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = malloc(-1);
    if (pArr == NULL) {
        printf("malloc error\n");
        exit(-1);
    }

    for (int i = 0; i < 10; i++)
        pArr[i] = 0;

    // ...

    free(pArr);
    return 0;
}
#endif 

