/*
 * DCL-02. ���� ���������� ���� �̸��� �������� ����.
 *
 * ������ �̸��� ������ ���, �ڵ� �󿡼� ȥ���� ���߽�Ű�� �ȴ�. 
 * ������ ������ ���� ���ؾ� �Ѵ�. 
 * ���� ������ ���� �� �ִ� ���� ������ � ������ �ߺ��ؼ� ���� ���� �̸��� ����ϸ� �ȵȴ�.
 *
 * � ��� �ȿ��� �̹� ���ǰ� �ִ� ������ ������ �̸����� �ٸ� ��Ͽ��� �����ϸ� �ȵȴ�.
 *
 */

#if 0
// ������ �ڵ�
// ���� ������ ���� ������ �̸��� ������ �ǹǷ�, 
// �ڵ�� ���������� ������� �ʴ´�.

#include <stdio.h>
#include <string.h>

char msg[32];

void set_error(const char* error) {
    char msg[32]; // ���������� ������ �̸����� �����ؼ� ���� �߻� ����
    // ...
    strncpy(msg, error, sizeof(msg));
}

int get_fd() {
    // ... 
    return -1;
}

int main() {
    int fd = get_fd();
    if (fd < 0)
        set_error("get_fd error");
    // ...

    printf("error message: %s\n", msg);
    return 0;
}
#endif

#if 1
// �ذ� ���
// ������ �̸��� �����ϰ� �ִٴ� ���� ������ �̸� ��ü�� �ʹ� �Ϲ����̶�� ���� 
// �ǹ��ϱ� ������ ������ �̸��� �� �� ���������� �����Ѵ�.
#include <stdio.h>
#include <string.h>

char system_msg[32];

void set_error(const char* error) {
    char msg[32];
    // ...
    strncpy(system_msg, error, sizeof(system_msg));
}

int get_fd() {
    // ... 
    return -1;
}

int main() {
    int fd = get_fd();
    if (fd < 0)
        set_error("get_fd error");
    // ...

    printf("error message: %s\n", system_msg);
    return 0;
}

#endif

