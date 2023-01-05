/* 
 * EXP-11. �Լ��� ��ȯ ���� ������ ���� ������ �����Ϳ���
 * �����ϰų� �������� ����.
 *
 * C99������ ������ ���� ����ϰ� �ִ�
 *
 * �Լ� ȣ�� ��� ���� ���� ������ ����Ʈ���� �����Ϸ��� �Ѵٸ�,
 * ���ǵ��� ���� ����� ��� �Ѵ�. 
 *
 * C �Լ��� �迭�� ��ȯ�� �� ������ �迭�� ���� ����ü�� ����ü�� ��ȯ�� �� �ִ�.
 * ����, �Լ� ȣ�� �� ���� ��ȯ ���� �迭�� �ִٸ� �� �迭�� ǥ���� ������
 * ���ٵǰų� �����Ǹ� �ȵȴ�.
 */

#if 0
// ������ �ڵ�
// ������ �ڵ�� �Լ� ȣ�� �� ���� ����ü�κ��� �迭�� ������ �ϰ� �ִ�. 
// �Լ� ��ȯ ���� ������ ���� ������ ����Ʈ ���� ������ �ǹǷ� �Լ��� ���� ��ȯ�� ����ü��
// �� �̻� ��ȿ���� �ʰų� �ٸ� ������ ����� ���ɼ��� ũ��. 

#include <stdio.h>
#include <string.h>

typedef struct {
    char buf[32];
} String;

String make_str(const char* s) {
    String str;
    strcpy(str.buf, s);
    return str;
}

int main() {
    printf("%s\n", make_str("hello").buf);
    return 0;
}
#endif 

#if 0
// �ذ� ���
// ��ȯ�Ǵ� ����ü�� ���� �� ����Ѵ�.
#include <stdio.h>
#include <string.h>

typedef struct {
    char buf[32];
} String;

String make_str(const char* s) {
    String str;
    strcpy(str.buf, s);
    return str;
}

int main() {
    String str = make_str("hello");
    printf("%s\n", str.buf);

    return 0;
}
#endif 

