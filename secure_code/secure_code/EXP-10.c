/*
 * EXP-10. 널 포인터가 역참조 되지 않음을 보장하라
 *
 * 널 포인터를 역참조 하면 프로그램은 알 수 없는 상태가 되면
 * 보통은 종료된다. 때문에 널 포인터는 역참조 하지 않는 것이 좋다.
 *
 */

#if 0
// 위험한 코드
// malloc 함수 호출 후, 리턴 값을 조사히지 않고 있다.
// 여기서 만약 널 포인터가 반환될 경우, 프로그램은 비정상 종료된다.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = malloc(-1);

    for (int i = 0; i < 10; i++)
        pArr[i] = 0;

    // ...

    free(pArr);
    return 0;
}
#endif 

#if 0
// 해결 방법
// malloc 함수의 반환 값을 조사한다.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = malloc(-1);
    if (pArr == NULL) {
        printf("malloc error\n");
        exit(-1);
    }

    for (int i = 0; i < 10; i++)
        pArr[i] = 0;

    // ...

    free(pArr);
    return 0;
}
#endif 

