/*
 * INT-05. 문자열 토큰을 정수로 변환할 때는 strtol 함수나 다른 관련된 함수를 사용하라.
 *
 * 다음의 함수들은 다른 방법들보다 신뢰성 있는 에러 처리를 제공한다.
 *
 *   - strtol : long ing 반환
 *   - strtoll : long long int 반환
 *   - strtoul : unsigned long int 반환
 *   - strtoull : unsigned long long int 반환
 *
 *
 *
#if 0
// 위험한 코드 1.
// - atoi, atol, atoll 함수들은 다음에 대한 문제점들이 존재
// - 에러 발생 시에 errno 를 설정하지 않음
// - 표시할 수 없는 결과 값을 얻은 경우 정의되지 않은 행동을 유발함
// - 문자열에 정수 값이 없는 경우 0을 반환하기 때문에 0이 입력되어 정상적으로
// 해석된 값인지 그렇지 않은지 확인할 수 없음.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    int data = atoi(buff);
    printf("-> %d\n", data);

    return 0;
}
#endif

#if 0
// 위험한 코드 2.
// sscanf 함수는 atoi 함수와 동일한 문제를 내포하고 있음.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char buff[32];
    printf("input integer: ");
    fgets(buff, sizeof(buff), stdin);

    int data;
    int ret = sscanf(buff, "%d", &data);
    if (ret == 0 || ret == EOF) {
        perror("sscanf");
        exit(-1);
    }

    printf("-> %d\n", data);
    return 0;
}
#endif

#if 0
// 해결 방법
// strtol, strtoll, strtoul, strtoull 함수군들을 사용하는 것이 좋음.
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
