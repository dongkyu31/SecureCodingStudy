/*
 * DCL-09. 함수 인자에서 restrict로 지정된 소스 포인터와 
 * 목적 포인터가 동일한 객체를 참조하지 않게 하라
 *
 * restrict 키워드는 오직 포인터에만 적용되는 키워드로 그 포인터가 데이터
 * 객체에 접근할 수 있는 유일하고도 최초가 되는 수단임을 나타낸다.
 * 즉, 포인터가 restrict로 한정되면 그 포인터가 가리키는 데이터 블록은
 * 그 포인터만이 접근이 가능하므로 컴파일러가 더 효율적으로 코드를
 * 최적화할 수 있다.
 *
 * 그러나 restrict 지정자를 사용할 때는 포인터들이 서로 동일한 객체를 참조하지 
 * 말아야 한다. 함수의 두 포인터가 동일한 객체를 참조하는 경우 그 결과는 
 * 미정의 동작이다.
 *
 */
 
#if 1
// restrict 한정자

#include <stdio.h>

void foo(int* a, int* b, int* c)
{
	*a += *c;
	*b += *c;
}

int main() {
	int a = 1;
	foo(&a, &a, &a);
	printf("%d\n", a);
	return 0;
}

#endif




#if 0
// 위험한 코드
// memcpy는 restrict 지정자를 사용한 함수로 동일한 객체의 주소를 인자로 전달하면 그 결과는 알 수 없다.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    --cnt;
    memcpy(arr, arr + 1, sizeof(int) * cnt);
    print_arr(arr, cnt);

    return 0;
}
#endif

#if 0
// 해결 방법 1.
// 메모리의 순서를 고려하지 않는 다면 마지막 요소를 앞 쪽에 복사한다.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    arr[0] = arr[--cnt];
    print_arr(arr, cnt);

    return 0;
}

#endif



#if 0
// 해결 방법 2.
// memmove 함수를 사용하여 처리한다. memmove 함수는 내부적으로 버퍼를 가지고 있어
// 안전하게 복사가 가능하다.
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    getchar();
}

int main() {
    int cnt = 10;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    print_arr(arr, cnt);

    --cnt;
    memmove(arr, arr + 1, sizeof(int) * cnt);
    print_arr(arr, cnt);

    return 0;
}


#endif
