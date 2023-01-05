/*
 * FLP-03. 부동소수점 변수를 루프 카운터로 사용하지 마라.
 *
 * 큰 부동 소수점 값에 증가 연산을 적용하면 경우에 따라서 가능한
 * 정밀도의 한계 때문에 값이 전혀 변하지 않을 수 있다. 
 * 또한 플랫폼마다 정밀도의 한계 값이 다르므로 이식 가능한 코드를
 * 구련하려면 부동소수점을 루프 카운터로 사용해선 안된다.
 *
 */

#if 0
// 위험한 코드
// 다음의 코드는 경우에 따라서 9번만 실행될 수 있다.
#include <stdio.h>

int main() {
    int cnt = 0;
    for (float i = 0.1f; i <= 1.0f; i += 0.1f)
        ++cnt;

    printf("cnt = %d\n", cnt);
    return 0;
}
#endif 

#if 0
// 해결 방법
// 루프 카운터는 정수를 사용한다.
#include <stdio.h>

int main() {
    int cnt = 0;
    for (size_t i = 0; i < 10; i++)
        ++cnt;

    printf("cnt = %d\n", cnt);
    return 0;
}
#endif 
