/*
 * EXP-06. 타입이나 변수의 크기를 결정할 때는 sizeof를 사용하라
 *
 * 애플리케이션에서 타입 크기를 하드 코딩하지 않는 것이 좋다. 
 * 대부분 타입의 크기가 컴파일러마다 다르고 동일한 컴파일러 내에서도 버전에 따라 다를 수 있다.
 */

#if 0
// 위험한 코드
// 다음의 코드는 포인터와 정수를 4바이트로 가정하고 있다. 시스템에 따라 
// 정수의 크기는 달라질 수 있으므로 의도하지 않은 결과를 초래할 수 있다.
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE    (10)

int main() {
    int** pArr = (int**)malloc(4 * ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
        pArr[i] = (int*)malloc(4 * ARR_SIZE);

    // ...

    for (int i = 0; i < ARR_SIZE; i++)
        free(pArr[i]);
    free(pArr);

    return 0;
}
#endif

#if 0
// 해결 방법
// sizeof 연산자를 사용한다.
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE    (10)

int main() {
    int** pArr = (int**)malloc(sizeof(int*) * ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
        pArr[i] = (int*)malloc(sizeof(int) * ARR_SIZE);

    // ...

    for (int i = 0; i < ARR_SIZE; i++)
        free(pArr[i]);
    free(pArr);

    return 0;
}
#endif
