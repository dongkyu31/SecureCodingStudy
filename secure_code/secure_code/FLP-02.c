/*
 * FLP-02. ��Ȯ�� ����� �ʿ��� ���� �ε��Ҽ��� ����
 * ������ �� �ִ��� ����϶�.
 *
 * ��ǻ�ʹ� ������ ������ ���ڸ� ǥ���� �� �ִ�. ���� 1/3�̳� 1/5ó��
 * �ݺ��Ǵ� ���� ǥ�Ⱚ�� ��Ȯ�ϰ� ǥ���ϴ� ���� ��κ��� �ε��Ҽ���ǥ�����δ� �Ұ����ϴ�.
 * ���� ��Ȯ�� ����� �ʿ��� ��쿡�� ���� ǥ���� �� �ִ� �ٸ� ǥ�� ����� 
 * �����ϴ� ���� ����.
 */
#if 0
// ������ �ڵ�
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
// �ذ� ���
// �ε��Ҽ����� ������ �����Ͽ� �ذ��Ѵ�.
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
