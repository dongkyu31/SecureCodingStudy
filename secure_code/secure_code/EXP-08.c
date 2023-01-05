/*
 * EXP-08. ������ �μ� ȿ���� ���϶�
 *
 * assert �� �Բ� ���Ǵ� ǥ������ �μ� ȿ���� ������ �ȵȴ�. 
 * �̴� assert �Լ��� ��ũ���̱� �����̰� ��ũ�� �Լ� ������
 * ���� �Ҵ�, ����, ����, �޸� ������ ����, �Լ� ȣ�� ����
 * ������ �����̴�.
 */

#if 0
// ������ �ڵ�
// assert �Լ����� ���� ������Ű�� �ִ�. 
#include <stdio.h>
#include <assert.h>

int process(int i) {
    assert(i++ > 0);
    printf("%d\n", i);
}

int main() {
    int num;

    printf("input size: ");
    int ret = scanf("%d", &num);
    if (ret != 1)
        printf("scanf error\n");
    else
        process(num);

    return 0;
}
#endif

#if 0
// �ذ� ���
// assert �Լ����� ���� �����ڸ� �����Ѵ�.
#include <stdio.h>
#include <assert.h>

int process(int i) {
    assert(i > 0);
    ++i;
    printf("%d\n", i);
}

int main() {
    int num;

    printf("input size: ");
    int ret = scanf("%d", &num);
    if (ret != 1)
        printf("scanf error\n");
    else
        process(num);

    return 0;
}

#endif
