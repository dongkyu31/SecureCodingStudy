/*
 * ARR-03. 충분한 크기의 공간에서 복사가 진행됨을 보장하라.
 *
 * 모들 데이터를 담을 수 있을 만큼 크지 않은 배열에 데이터를 복사하면 
 * 버퍼 오버 플로우가 발생할 수 있다.
 *
 */


#if 0
// 위험한 코드
// memcpy 함수처럼 크기를 지정해 제한된 복사를 수행하는 함수를 부적절하게 사용하면 
// 버퍼 오버 플로우가 발생할 수 있다.
#include <stdio.h>
//enum { BUF_SIZE = 1024 };
enum { BUF_SIZE = 4 }; // 테스트를 위해 범위 수정

void func(const char src[], size_t len) {
    char dest[BUF_SIZE];
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
}

int main() {
    char str[] = "hello, world";
    func(str, strlen(str) + 1);

    return 0;
}
#endif 

#if 0
// 해결 방법 1.
// 배열의 경계를 체크한다.
#include <stdio.h>
//enum { BUF_SIZE = 1024 };
enum { BUF_SIZE = 4 }; // 테스트를 위해 범위 수정

void func(const char src[], size_t len) {
    if (len >= BUF_SIZE) { // 배열의 경계 체크
		printf("Error. It makes Buffer(stack) Overflow \n");
        return;
	}

    char dest[BUF_SIZE];
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
}

int main() {
    char str[] = "hello, world";

    func(str, strlen(str) + 1);
    return 0;
}
#endif 

#if 1
// 해결 방법 2.
// 버퍼의 사이즈를 고정하지 않고 동적 메모리 할당을 수행한다.
#include <stdio.h>
#include <stdlib.h>

void func(const char src[], size_t len) {
    char* dest = (char*)malloc(sizeof(char) * len);
    memcpy(dest, src, len * sizeof(char));
    printf("%s\n", dest);
    free(dest);
}

int main() {
    char str[] = "hello, world";

    func(str, strlen(str) + 1);
    return 0;
}
#endif 
