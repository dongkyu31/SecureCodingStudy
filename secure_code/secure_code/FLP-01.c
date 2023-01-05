/*
 * Chapter 6. Float Point
 *
 * FLP-01. 부동소수점의 제한을 이해하라.
 *
 * C 프로그래밍 언어는 계산을 위해 부동 소수점 수를 사용할 수 
 * 있도록 지원한다. C99에서는 부동 소수점 수에 대한 요구 사항을 플랫폼에서 
 * 어떻게 지원해야 하는지 명시하고 있지만, 부동소수점을 구현한 시스템들 간의
 * 경쟁 때문에 특정 부동소수점 표현 방식을 보장하지 않는다.
 */

#if 0
// 아래의 코드는 시스템에 따라 다른 결과를 출력할 수 있다.
#include <stdio.h>

int main() {
    float f = 1.0f / 3.0f;
    printf("Float is %.40f\n", f);

    return 0;
}
#endif 

#if 1
// 아래 코드는 컴파일러 최적화 레벨에 따라 다른 결과를 출력할 수 있다.
// 따라서 각 시스템에 따라 부동소수점 수에 대한 제한을 잘 알고 있어야
// 데이터에 대한 무결성이 보장될 수 있다.
#include <stdio.h>

int main() {
    double a = 3.0;
    double b = 7.0;
    double c = a / b;

    if (c == (a / b))
        printf("same\n");
    else
        printf("not same\n");

    return 0;
}
#endif 
