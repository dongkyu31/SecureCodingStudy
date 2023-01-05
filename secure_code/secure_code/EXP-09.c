/*
 * EXP-09. 초기화되지 않는 메모리를 참조하지 마라
 *
 * 함수 내에 선언된 자동 변수 (auto variable)는 초기화하지 않으면
 * 쓰레기(garbage) 값으로 설정된다. C99 표준에서는 자동 변수에 대해
 * 다음과 같이 정의하고 있다. 
 *
 * 객체가 자동 변수 저장 공간에 있는 경우, 초기화되지 않았다면
 * 변수의 값은 정의되어 있지 않다. 
 *
 * 따라서 초기화되지 않는 변수를 사용하면 프로그램은 제대로 동작
 * 하지 않을 수 있다.
 *
 */

#if 0
// 위험한 코드
// sum_to() 함수 내에서 변수 sum 의 값을 제대로 초기화하지 않아 프로그램은
// 의도하지 않게 실행된다.
#include <stdio.h>

int sum_to(int num) {
    int sum;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}

int main() {
    int input;
    printf("input number: ");
    scanf("%d", &input);
    printf("sum 1 to %d: %d\n", input, sum_to(input));

    return 0;
}
#endif


#if 0
// 해결 방법
// 지역 변수 sum을 적절한 값으로 초기화해준다.
#include <stdio.h>

int sum_to(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}

int main() {
    int input;
    printf("input number: ");
    scanf("%d", &input);
    printf("sum 1 to %d: %d\n", input, sum_to(input));

    return 0;
}

#endif
