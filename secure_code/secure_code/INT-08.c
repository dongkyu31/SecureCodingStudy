/* 
 * INT-08. ǥ���Ŀ��� signed, unsigned ǥ�ð� ���� int ��Ʈ �ʵ��� Ÿ���� �������� ����.
 *
 * ��Ʈ �ʵ忡�� ���� Ÿ���� ��ȣ�� �ִ� ���� Ÿ������ �ƴ����� �������� �ٸ���. 
 * C99 ǥ�ؿ� ������ "���� int Ÿ������ �°�� ��, ���� Ÿ���� ��� ���� ǥ���� �� �ִٸ� 
 * ���� int�� ��ȯ�Ǹ� �׷��� ���� ��� unsigned int �� ��ȯ�ȴ�"��� �Ǿ� �ִ�.
 */
#if 1
// ������ �ڵ�
// ��Ʈ �ʵ忡�� int ��Ʈ �ʵ带 �����ϸ� ������ ���� �� ��(-1 �Ǵ� 255)�� �޶��� �� �ִ�.

#include <stdio.h>

struct {
    int a : 8;
} bits = { 255 };

int main() {
    printf("bits.a = %d\n", bits.a);
    return 0;
}
#endif 

#if 0
// �ذ� ���
// ��ȣ�� ������ ��������� �����ϸ� �ǵ��� ��Ȯ������.
#include <stdio.h>

struct {
    unsigned int a : 8;
} bits = { 255 };

int main() {
    printf("bits.a = %d\n", bits.a);
    return 0;
}
#endif 
