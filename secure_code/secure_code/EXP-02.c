/*
 * EXP-02. 논리 연산자 AND와 OR의 단축 평가 방식을 알고 있어라.
 *
 * 논리 연산자 AND와 OR은 단축 평가를 수행한다. 즉, 첫번째 피연산자로 평가가
 * 완료되면 두번째 피연산자는 평가하지 않는다.
 *
 *   | 연산자  |  첫 번째 피연산자 | 두 번째 피연산자  |
 *   | AND(&&) |  거짓             |   평가 안함       |
 *   | OR(||)  |  참               |   평가 안함       |
 */

#if 0
// 위험한 코드
// 다음 코드는 배열에서 0이 몇 개인지를 세는 코드이다.
// 그러나 AND 연산자의 첫번째 피 연산자가 거짓이므로 두번째 피 연산자는
// 평가되지 않는다.

#include <stdio.h>
#define SIZE_MAX    (5)

int main() {
    int arr[SIZE_MAX] = { 0,1,2,3,0 };

    int i = 0;
    int cnt = 0;
    while ((arr[i] == 0) && (++i < SIZE_MAX))
        ++cnt;
    printf("%d\n", cnt);

    return 0;
}
#endif

#if 0
// 해결 방법
// 단축 평가가 이루어지지 않도록 한다.
#include <stdio.h>
#define SIZE_MAX    (5)

int main() {
    int arr[SIZE_MAX] = { 0,2,3,4,0 };

    int cnt = 0;
    for (int i = 0; i < SIZE_MAX; i++) {
        if (arr[i] == 0)
            ++cnt;
    }
    printf("%d\n", cnt);

    return 0;
}
#endif
