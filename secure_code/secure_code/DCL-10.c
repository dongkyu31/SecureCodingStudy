/*
 * DCL-10. ĳ�õǾ�� �ȵǴ� �����Ϳ��� volatile �� ����϶�
 *
 * �Ϲ����׷� CPU�� ���ɻ��� ������ �����͸� �޸𸮿��� ���� �о���� �ʰ�
 * ĳ�ø� ����Ͽ� �о�´�. ���α׷��� �ƴ� �ϵ��� ���� ����Ǵ� �����ʹ�
 * ĳ�ÿ� �ݿ����� �����Ƿ� �޸𸮿��� ���� �о�;� �Ѵ�. 
 * volatile�� �����Ͱ� ���α׷��� �ƴ� �ܺ����� ���ο� ���� �� ���� ����� �� �ִ�
 * �����Ϸ��� �˷� ĳ���� ������ �� ����Ѵ�.
 *
 */

#if 1
// ������ �ڵ�
// ����ȭ�� ���� flag�� ĳ�õǾ��ٸ� SIGINT�� �޾Ƶ� ������� �ʴ´�.
#include <stdio.h>
#include <windows.h>
#include <signal.h>

int flag;

void handler(int signum) {
    printf("\thandler\n");
    flag = 0;
}

int main() {
    flag = 1;
    signal(SIGINT, handler);

    while (flag) {
        printf("do something\n");
        Sleep(1000);
    }

    return 0;
}
#endif

#if 0
// �ذ� ���
// ������ volatile�� �����Ѵ�.
#include <stdio.h>
#include <windows.h>
#include <signal.h>

volatile int flag;

void handler(int signum) {
    printf("\thandler\n");
    flag = 0;
}

int main() {
    flag = 1;
    signal(SIGINT, handler);

    while (flag) {
        printf("do something\n");
        Sleep(1000);
    }

    return 0;
}
#endif

