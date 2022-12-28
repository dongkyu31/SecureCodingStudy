/*
 * DCL-02. 내부 스코프에서 변수 이름을 재사용하지 마라.
 *
 * 변수의 이름을 재사용할 경우, 코드 상에서 혼란을 가중시키게 된다. 
 * 때문에 다음의 경우는 피해야 한다. 
 * 전역 변수가 사용될 수 있는 범위 내에서 어떤 변수든 중복해서 전역 변수 이름을 사용하면 안된다.
 *
 * 어떤 블록 안에서 이미 사용되고 있는 변수와 동일한 이름으로 다른 블록에서 선언하면 안된다.
 *
 */

#if 0
// 위험한 코드
// 지역 변수가 전역 변수의 이름을 가리게 되므로, 
// 코드는 정상적으로 수행되지 않는다.

#include <stdio.h>
#include <string.h>

char msg[32];

void set_error(const char* error) {
    char msg[32]; // 전역변수와 동일한 이름으로 선언해서 문제 발생 가능
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
// 해결 방법
// 변수의 이름을 재사용하고 있다는 것은 변수의 이름 자체가 너무 일반적이라는 것을 
// 의미하기 때문에 변수의 이름을 좀 더 설명적으로 정의한다.
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

