/*
 * EXP-07. 함수에 의해 반환되는 값을 무시하지 마라.
 *
 * 일반적으로 함수는 반환 시 유용한 값을 전달하는데 대개 이 값은 함수가 작업을
 * 성공적으로 수행했는지 혹은 에러가 발생했는지를 확인하는데 사용한다.
 *
 */

#if 0
// 위험한 코드
// 다음 코드는 정수를 입력 받기 위해 scanf 함수를 사용하지만
// 에러가 발생하는지를 체크하지 않는다.
#include <stdio.h>

int main() {
    int num;

    printf("input number: ");
    scanf("%d", &num);
    printf("-> %d\n", num);

    return 0;
}
#endif


#if 0
// 해결 방법
// 입력 에러가 발생했는지를 체크한다. 
#include <stdio.h>

int main() {
    int num;

    printf("input number: ");
    int ret = scanf("%d", &num);
    if (ret == 0 || ret == EOF)
        printf("input error\n");
    else
        printf("-> %d\n", num);

    return 0;
}
#endif
