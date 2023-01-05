/*
 *  INT-02. 정수 변환 규칙을 이해하라
 *
 *  정수 변환
 *  - 명시적 변환(explicit conversion) - 변환 연산자를 사용한 변환
 *  - 묵시적 변환(implicit conversion) - 특정 연산에 의한 변환
 *
 *  정수의 승계(integer Promotion)
 *  - int 보다 작은 정수 타입은 연산이 수행될 때, int나 unsigned int 타입으로 변환된다.
 *  - 이는 오버플로로 인한 산술 연산 에러를 피하기 위함이다.
 *
 *
 *  정수 변환 순위
 *  - 비트 수가 많은 타입이 높은 순위를 갖는다.
 *  - 각기 다른 두 부호에 있는 정수는 순위가 다르다.
 *  - 부호 있는 정수 타입의 순위는 자신보다 정밀도가 낮은 다른 어떤 부호 있는 정수 보다 
 *  순위가 높다
 *  - long long int > long int > int > short int > signed char
 *  - unsigned long long int > unsigned long int > unsigned int > unsigned shot int > unsigned char
 *
 *
 *  일반적인 산술 변환 규칙
 *  - 이항 연산의 경우 두 피연산자는 같은 타입으로 변환된다.
 *  - 두 개의 피연산자가 같은 타입이면 변환하지 않는다.
 *  - 두 개의 피연산자가 같은 정수 타입이면 범위가 큰 타입으로 변환된다.
 *  - 부호 없는 정수 타입의 피연산자가 다른 피연산자의 순위보다 크거나 같은 경우,
 *  부호 있는 정수 타입의 피연산자는 부호 없는 타입으로 변환된다.
 *  - 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을 표현할 수 있는 경우,
 *  부호 없는 정수 타입의 피연산자는 부호 있는 정수 타입으로 변환된다.
 *  - 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을 표현할 수 없는 경우,
 *  부호 있는 정수 타입의 피연산자는 동일 타입의 부호 없는 타입으로 두 피연산자 모두 변환된다.
 *
 *
 */

#if 0
// 정수의 승계
#include <stdio.h>

int main() {
    char c1 = 100;
    char c2 = 3;
    char c3 = 4;

    char result = c1 * c2 / c3;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// 위험한 코드 1.
// 서로 다른 타입에 대하여 연산을 수행할 경우에는 주의해야 함.
#include <stdio.h>

int main() {
    int si = -1;
    unsigned int ui = 1;

    if (ui > si)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// 해결 방법
// 타입을 일치 시킨다.
#include <stdio.h>

int main() {
    int si = -1;
    unsigned int ui = 1;

    if ((int)ui > si)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// 위험한 코드 2.
// 동적 메모리 할당 함수 들은 size_t 타입을 사용하므로 음수를 사용할 경우, 
// 할당할 수 없는 아주 큰 양수로 변회되어 할당이실패할 수 있음. 
#include <stdlib.h>

int main() {
    int* pArr = (int*)malloc(-1);
    pArr[0] = 0;

    free(pArr);
    return 0;
}
#endif 

#if 0
// 해결 방법 
// 음수를 사용하지 않거나 반환된 값을 조사해서 사용
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = (int*)malloc(-1);
    if (pArr == NULL) {
        perror("malloc");
        exit(-1);
    }
    pArr[0] = 0;

    free(pArr);
    return 0;
}
#endif 
