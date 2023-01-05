/*
 * DCL-08. 객체를 선언할 때 적절한 지속공간을 지정하라.
 *
 * 객체가 자신의 수명을 다한 후에도 참조된다면 정의되지 않은 행동을 유발할 수 있다.
 * 예를 들어 수명을 다한 객체를 참조하는 포인터는 정의되지 않을 값을 갖게 된다.
 * 수명을 다한 객체에 접슥하는 것은 매우 위험하고 취약성을 만드는 결과를 초래하기도 한다.
 *
 */

#if 0
// 위험한 코드 1.
// 수명을 다한 지역 객체를 전역 변수가 참조함으로 임의의 코드를 수행할 수 있는 위험성이 존재한다.
#include <stdio.h>
const char* path;

void open_path() {
    const char str[] = "c:\\a.txt";
    path = str;
    printf("path = %s\n", path);
}

void hack() {
    const char st11r[] = "d:\\a.exe";
    printf("path = %s\n", path);
}

int main() {
    open_path();
    hack();

    printf("path = %s\n", path);
    return 0;
}
#endif

#if 0
// 해결 방법
// 전역 포인터가 유효한 객체를 가리키도록 한다.
// 동적 메모리 할당을 통해 Heap 영역을 가리키도록 만든다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* path;

void open_path() {
    const char str[] = "c:\\a.txt";
    path = calloc(1, strlen(str) + 1);
    strncpy(path, str, strlen(str) + 1);
}

void hack() {
    const char str[] = "d:\\a.exe";
    printf("path = %s\n", path);
}

int main() {
    open_path();
    hack();
    printf("path = %s\n", path);
    return 0;
}

#endif


#if 1
// 위험한 코드 2.
// 다음 코드는 지역 객체의 주소를 반환하고 있다.

#include <stdio.h>

char* init_array() {
    char arr[10] = { 0, };
    return arr;
}

int main() {
    char* pArr = init_array();

    for (int i = 0; i < 10; i++)
        printf("%d ", pArr[i]);
    printf("\n");
    return 0;
}

#endif

#if 0
// 해결 방법
// 초기화할 배열을 함수의 인자로 받아 처리한다.

#include <stdio.h>

void init_array(char arr[]) {
    for (int i = 0; i < 10; i++)
        arr[i] = 0;
}

int main() {
    char arr[10];
    init_array(arr);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

#endif
