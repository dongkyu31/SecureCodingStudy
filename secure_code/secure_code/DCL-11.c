/*
 * DCL-11. �Լ� ���ǿ� ���� �ʴ� Ÿ������ �Լ��� ��ȯ���� ����.
 *
 * ������ Ÿ�԰� �ٸ� Ÿ���� �Լ��� �����ϵ��� �Լ� �����͸� ����ϸ� ���ǵ��� ����
 * ����� �ʷ��Ѵ�. ������ �Լ� �����͸� ����� ���, ��Ȯ�� Ÿ���� �����ؼ� ����ؾ� 
 * �Ѵ�. C99������ ������ ���� ����ϰ� �ִ�.
 *
 * Ư�� Ÿ�Կ� ���� �Լ��� �����ʹ� �ٸ� Ÿ���� �Լ� �����ͷ� ��ȯ�� �� �ְ� �����
 * ������ �����Ϳ� ��������. ȣȯ���� �ʴ� Ÿ���� �Լ��� ȣ���ϴµ� �Լ� �����Ͱ�
 * ���Ǹ� �� �� ���� �ൿ�� �ʷ��Ѵ�.
 *
 */
#if 0
// ������ �ڵ�
// �Լ� �����Ϳ� �Լ��� Ÿ���� ��ġ���� �ʾ� ���ǵ��� ���� ����� �ʷ��Ѵ�.
#include <stdio.h>
#include <signal.h>

int square(int a) { return a * a; }
int cube(int a) { return a * a * a; }
int add(int a, int b) { return a + b; }

int main() {
    int(*fp)(int);
    // ...

    fp = add;
    printf("%d\n", fp(1));

    return 0;
}
#endif

#if 0
// �ذ� ���
// ��Ȯ�� Ÿ���� ������ ������ �����Ѵ�.
#include <stdio.h>
#include <signal.h>

int square(int a) { return a * a; }
int cube(int a) { return a * a * a; }
int add(int a, int b) { return a + b; }

int main() {
    int(*fp)(int);
    // ...

    fp = add;
    printf("%d\n", fp(1,1));

    return 0;
}
#endif

