/*
 * EXP-07. �Լ��� ���� ��ȯ�Ǵ� ���� �������� ����.
 *
 * �Ϲ������� �Լ��� ��ȯ �� ������ ���� �����ϴµ� �밳 �� ���� �Լ��� �۾���
 * ���������� �����ߴ��� Ȥ�� ������ �߻��ߴ����� Ȯ���ϴµ� ����Ѵ�.
 *
 */

#if 0
// ������ �ڵ�
// ���� �ڵ�� ������ �Է� �ޱ� ���� scanf �Լ��� ���������
// ������ �߻��ϴ����� üũ���� �ʴ´�.
#include <stdio.h>

int main() {
    int num;

    printf("input number: ");
    scanf("%d", &num);
    printf("-> %d\n", num);

    return 0;
}
#endif


#if 0
// �ذ� ���
// �Է� ������ �߻��ߴ����� üũ�Ѵ�. 
#include <stdio.h>

int main() {
    int num;

    printf("input number: ");
    int ret = scanf("%d", &num);
    if (ret == 0 || ret == EOF)
        printf("input error\n");
    else
        printf("-> %d\n", num);

    return 0;
}
#endif
