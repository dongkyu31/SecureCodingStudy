/*
 * INT-07. ������ ����� ������ ������ ���εǵ��� �����϶�
 *
 * C ����� �������� �����ڴ� ���������� ���εȴ�. �Ϲ������� �������� 
 * �� �����ڰ� ���� ������ �����ȴٰ� ���������� ���� ���� ���� ���� 
 * ��Ȯ���� ���� ������ ���� ��������⵵ �Ѵ�.
 *
 */
#if 0
// ������ �ڵ�
// �������� ���� �ߺ��Ǹ� ��ȣ������ ���� ������ �߻��� ���ɼ��� ����.
#include <stdio.h>

enum { DEBUG, WARN, ERROR = 0 };

int main() {
    printf("DEBUG = %d\n", DEBUG);
    printf(" WARN = %d\n", WARN);
    printf("  ERR = %d\n", ERROR);

    if (DEBUG == ERROR)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// �ذ� ���
// ������ ���� ��, �Ʒ��� ����� �������� �ϴ� ���� ����
// ����� ������ ���� �ʴ´�.
// ù ��° �����ڿ� ���ؼ��� ���� �����Ѵ�.
// ��� �����ڿ� ���Ͽ� ��������� ���� �����Ѵ�.

#include <stdio.h>

enum { DEBUG, WARN, ERROR };

int main() {
    printf("DEBUG = %d\n", DEBUG);
    printf(" WARN = %d\n", WARN);
    printf("  ERR = %d\n", ERROR);

    if (DEBUG == ERROR)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 


