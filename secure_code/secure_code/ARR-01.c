/*
 * ARR-01. 배열의 크기를 얻을 때 포인터를 sizeof의 피연산자로 사용하지 마라.
 *
 * sizeof 피 연산자의 크기를 바이트 단위로 계산하는 연산자로 sizeof 연산자로
 * 배열의 크기를 계산할 때는 주의해야 한다.
 *
 */


#if 0
// 위험한 코드
// 배열이 전달된 함수 내에서 배열의 크기를 계산하고 있다.
#include <stdio.h>

void clear(int arr[]) { // void clear(int *arr) -> 즉, 배열의 주소를 가져온 것
	// sizeof(*arr) 는 arr 포인터가 가리키는 int의 크기인  4바이트지만, 
	// 배열 본체가 없는 여기서 sizeof(arr)은 단순 배열의 주소이므로 주소가 가리키는 int의 크기인 4바이트가 된다.
    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        arr[i] = 0;
}

int main() {
    int arr[5];

    clear(arr);
    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        printf("arr[%u] = %d\n", i, arr[i]);

    return 0;
}
#endif 

#if 1
// 해결 방법
// 배열이 선언된 블록 안에서 크기를 계산한 후 이를 함수의 인자로 전달해서 초기화 한다.
#include <stdio.h>

void clear(int arr[], int len) {
    for (size_t i = 0; i < len; i++)
        arr[i] = 0;
}

int main() {
    int arr[5];
    size_t len = sizeof(arr) / sizeof(*arr);

    clear(arr, len);
    for (size_t i = 0; i < len; i++)
        printf("arr[%u] = %d\n", i, arr[i]);

    return 0;
}
#endif
