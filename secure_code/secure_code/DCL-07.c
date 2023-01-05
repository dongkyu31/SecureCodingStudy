/*
 * DCL-07. 함수에 의해 바뀌지 않을 값에 대한 포인터를
 * 함수의매개변수로 사용할 때는 const로 정의하라.
 *
 * 포인터를 매개 변수로 하는 하수는 내부적으로 대상체의 값을 변경하는 위힘이 존재한다.
 * 때문에 의도하지 않는 변경을 막으려면 const 키워드를 사용해야 한다.
 */

#if 0
// 위험한 코드
// 다음의 코드는 인자로 전달된 배열의 값을 임의로 변경하고 있다.
#include <stdio.h>

int sum_arr(int* arr, int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += arr[i];
    *arr = 0;
    return sum;
}

int main() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", sum_arr(arr, 10));
	for (int i =0; i<10; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

    return 0;
}
#endif

#if 1
// 해결 방법
// 상수 객체를 가리키는 포인터로 변경한다.
#include <stdio.h>

int sum_arr(const int* arr, int cnt) {
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += arr[i];
    *arr = 0;
    return sum;
}

int main() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", sum_arr(arr, 10));

    return 0;
}
#endif
