// 해당 예제는 strtok() 함수를 사용하면 원본 함수가 훼손되기 때문에 
// 복사본을 만들어서 조작하라는 의미 
#if 0
// 위험한 코드
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello, world";
    char* token = strtok(str, ",");
    printf("%s\n", str);

    return 0;
}
#endif

#if 0
// 해결 방법
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "hello, world";

    char* copy = malloc(strlen(str) + 1);
    strncpy(copy, str, strlen(str) + 1);

    char* token = strtok(copy, ",");
    printf("%s\n", str);

    free(copy);
    return 0;
}
#endif
