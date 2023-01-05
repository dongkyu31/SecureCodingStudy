/*
 * FLP-02. 정확한 계산이 필요할 때는 부동소수점 수를
 * 재제할 수 있는지 고려하라.
 *
 * 컴퓨터는 유한한 개수의 숫자를 표현할 수 있다. 따라서 1/3이나 1/5처럼
 * 반복되는 이진 표기값을 정확하게 표현하는 것은 대부분의 부동소수점표현으로는 불가능하다.
 * 따라서 정확한 계산이 필요한 경우에는 값을 표현할 수 있는 다른 표현 방법을 
 * 생각하는 편이 좋다.
 */
#if 0
// 위험한 코드
#include <stdio.h>

float mean(float* arr, size_t len) {
    float total = 0.0f;
    for (int i = 0; i < len; i++) {
        total += arr[i];
        printf("arr[%d]: %f\ttotal = %f\n", i, arr[i], total);
    }

    if (len != 0)
        return total / len;
    else
        return 0.0F;
}

#define ARR_SIZE    (10)
int main() {
    float array[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
        array[i] = 10.1F;

    float total = mean(array, ARR_SIZE);
    printf("total = %.10f\n", total);
    return 0;

}
#endif

#if 1
// 해결 방법
// 부동소수점을 정수로 변경하여 해결한다.
#include <stdio.h>

float mean(float* arr, size_t len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += arr[i];
        printf("arr[%d]: %f\ttotal = %f\n", i, arr[i], (float)total);
    }

    if (len != 0)
        return (float)total / len;
    else
        return 0.0F;
}

#define ARR_SIZE    (10)
int main() {
    float array[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
        array[i] = 1010;

    float total = mean(array, ARR_SIZE);
    printf("total = %.10f\n", total / 100.0);
    return 0;

}
#endif
