/*
 * DCL-10. 캐시되어서는 안되는 데이터에는 volatile 을 사용하라
 *
 * 일반저그로 CPU는 성능상의 이유로 데이터를 메모리에서 직접 읽어오지 않고
 * 캐시를 사용하여 읽어온다. 프로그램이 아닌 하드웨어에 의해 변경되는 데이터는
 * 캐시에 반영되지 않으므로 메모리에서 직접 읽어와야 한다. 
 * volatile는 데이터가 프로그램이 아닌 외부저긴 요인에 의해 그 값이 변경될 수 있다
 * 컴파일러에 알려 캐싱을 제한할 때 사용한다.
 *
 */

#if 1
// 위험한 코드
// 최적화에 의해 flag가 캐시되었다면 SIGINT를 받아도 종료되지 않는다.
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
// 해결 방법
// 변수를 volatile로 선언한다.
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

