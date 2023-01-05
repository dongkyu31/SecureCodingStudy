/*
 * EXP-09. �ʱ�ȭ���� �ʴ� �޸𸮸� �������� ����
 *
 * �Լ� ���� ����� �ڵ� ���� (auto variable)�� �ʱ�ȭ���� ������
 * ������(garbage) ������ �����ȴ�. C99 ǥ�ؿ����� �ڵ� ������ ����
 * ������ ���� �����ϰ� �ִ�. 
 *
 * ��ü�� �ڵ� ���� ���� ������ �ִ� ���, �ʱ�ȭ���� �ʾҴٸ�
 * ������ ���� ���ǵǾ� ���� �ʴ�. 
 *
 * ���� �ʱ�ȭ���� �ʴ� ������ ����ϸ� ���α׷��� ����� ����
 * ���� ���� �� �ִ�.
 *
 */

#if 0
// ������ �ڵ�
// sum_to() �Լ� ������ ���� sum �� ���� ����� �ʱ�ȭ���� �ʾ� ���α׷���
// �ǵ����� �ʰ� ����ȴ�.
#include <stdio.h>

int sum_to(int num) {
    int sum;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}

int main() {
    int input;
    printf("input number: ");
    scanf("%d", &input);
    printf("sum 1 to %d: %d\n", input, sum_to(input));

    return 0;
}
#endif


#if 0
// �ذ� ���
// ���� ���� sum�� ������ ������ �ʱ�ȭ���ش�.
#include <stdio.h>

int sum_to(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}

int main() {
    int input;
    printf("input number: ");
    scanf("%d", &input);
    printf("sum 1 to %d: %d\n", input, sum_to(input));

    return 0;
}

#endif
