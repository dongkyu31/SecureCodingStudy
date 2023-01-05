/*
 *  INT-06. ���� ������ ��������� signed �Ǵ� unsigned ���� ����϶�
 *
 *  char, signed char, unsigned char �� ��Ʋ�� ���� Ÿ��(character type)�̶�� �Ѵ�.
 *  ���� ���� ������ ���, signed char�� unsigned char�� ����ؾ� ���� Ÿ���� ��ȣ�� �������
 *  ȣȯ ������ �ڵ带 ����� ������ ����̴�.
 */

#if 0
// ������ �ڵ�
// ���� Ÿ���� ���� c�� signed char �Ǵ� unsigned char Ÿ���� �� �ִ�.
// ��ȣ�� ������ ���� ���� �޶��� �� �ִ�.
#include <stdio.h>

int main() {
    char c = 200;
    int i = 1000;

    printf("%d / %d = %d\n", i, c, i / c);
    return 0;
}
#endif 

#if 0
// �ذ� ���
// unsigned char�� �����ϸ� char�� ��ȣ�� ������� ������ �� ���� ������ �� �ִ�.
#include <stdio.h>

int main() {
    unsigned char c = 200;
    int i = 1000;

    printf("%d / %d = %d\n", i, c, i / c);
    return 0;
}
#endif 
