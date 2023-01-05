/*
 * INT-03. 불분명한 소스에서 얻어지는 정수 값은 제한을 강제하라
 *
 * 신뢰할 수 없는 소스로부터 얻어지는 정수 값은 식별할 수 있는 상한 값과 하한 값이 있는지를
 * 확인하기 위해 반드시 평가되어야 한다.
 *
 */

#if 1
// 위험한 코드
// 메모리를 동적으로 할당하는 코드에서 크기 값을 검사하지 않을 경우, 메모리 할당이 실패할 수 있으며
// 에러 처리의 구현에 따라 서비스 거부(denial of server) 상태가 될 수 있음.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* create_buff(size_t len) {
    return malloc(sizeof(char) * len);
}

int main() {
    char buff[24];

    printf("input string: ");
    scanf("%s", buff);

    int len = strlen(buff);
    char* str = create_buff(len + 1);
    strcpy(str, buff);

    printf("-> %s\n", str);
    free(str);

    return 0;
}
#endif

#if 0
// 해결 방법
// 적용 가능한 값의 범위를 검사함으로써 해결 가능
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { MAX_STRING_LEN = 1024 };

char* create_buff(size_t len) {
    if (len == 0 || len > MAX_STRING_LEN)
        return NULL;
    return malloc(sizeof(char) * len);
}

int main() {
    char buff[MAX_STRING_LEN];
    printf("input string: ");
    scanf("%s", buff);

    int len = strlen(buff);
    char* str = create_buff(len + 1);
    if (str == NULL) {
        fprintf(stderr, "create_buff error\n");
        exit(-1);
    }
    strcpy(str, buff);

    printf("-> %s\n", str);
    free(str);

    return 0;
}
#endif


