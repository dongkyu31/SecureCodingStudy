/*
 * INT-04. 모든 가능한 입력을 처리할 수 없다면 문자 데이터 변환을 위해 입력 함수를 사용하지 마라
 *
 * scanf, fscanf, vscanf, vfscanf 함수는 stdin 또는 다른 입력 스트림으로부터 문자열 데이터를
 * 읽는데 사용한다. 이 함수들은 유효한 정수 값에 대해 잘 동작하지만 유효하지 않는 값에 대해서는 
 * 신뢰성이 있는 처리를 하지 못한다.
 */

#if 0
// 위험한 코드
//  정수나 부동소수점 수를 입력 받기 위해 scanf 또는 fscanf 함수를 사용하는 경우,
//  미정의 동작이 발생할 가능성이 있음.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int data;
    printf("input integer: ");

    int ret = scanf("%d", &data);
    if (ret != 1 || ret == EOF) {
        perror("scanf");
        exit(-1);
    }
    printf("-> %d\n", data);

    return 0;
}
#endif 

#if 0
// 해결 방법
// 입력 문자열을 처리하는데 fgets 함수를 사용하고, 문자열을 정수로 변환하기 
// 위해서 strtol 함수를 사용하는 것이 좋다. strtol 함수는 입력 값이 long 영역에서
// 유효한지 점검하는 에러 체크를 제공한다.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    errno = 0;
    char* end_ptr;
    long data = strtol(buff, &end_ptr, 10);
    if (errno == ERANGE) {
        perror("strtol");
        exit(-1);
    }
    else if (end_ptr == buff) {
        fprintf(stderr, "not valid numeric input\n");
        exit(-1);
    }
    else if (*end_ptr != '\n' && *end_ptr != '\0') {
        fprintf(stderr, "extra characters on input line\n");
        exit(-1);
    }

    printf("-> %ld\n", data);
    return 0;
}
#endif 


