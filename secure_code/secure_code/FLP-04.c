/*
 * FLP-04. �ε��Ҽ��� ����� ������ ���� �ε��Ҽ������� �ٲ��.
 *
 * ���� ������ ����� �ε��Ҽ��� ������ ���� �Ҵ��ϴ� ��� ������ �սǵ� �� �ִ�.
 * �� ��� ǥ������ ���� �� �ϳ��� �ε� �Ҽ��� Ÿ������ ��ȯ�� ���� �� �ִ�.
 *
 */

#if 1
// ������ �ڵ�
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7;    // d�� 76.0
    printf("d : %f\n", d);

    double e = b / 30;  // e�� 226.0
    printf("d : %f\n", e);

    double f = c * 789; // f�� �����÷ο�Ǿ� ������ �� �ִ�.
    printf("d : %f\n", f);

    return 0;
}
#endif 

#if 0
// �ذ� ��� 1.
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7.0f;
    printf("d : %f\n", d);

    double e = b / 30.0;
    printf("d : %f\n", e);

    double f = (double)c * 789;
    printf("d : %f\n", f);

    return 0;
}
#endif 

#if 0
// �ذ� ��� 2.
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a;
    d /= 7;
    printf("d : %f\n", d);

    double e = b;
    e /= b;
    printf("d : %f\n", e);

    double f = c;
    f *= 789;
    printf("d : %f\n", f);

    return 0;
}
#endif
