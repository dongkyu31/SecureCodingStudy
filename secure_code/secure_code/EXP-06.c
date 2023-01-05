/*
 * EXP-06. Ÿ���̳� ������ ũ�⸦ ������ ���� sizeof�� ����϶�
 *
 * ���ø����̼ǿ��� Ÿ�� ũ�⸦ �ϵ� �ڵ����� �ʴ� ���� ����. 
 * ��κ� Ÿ���� ũ�Ⱑ �����Ϸ����� �ٸ��� ������ �����Ϸ� �������� ������ ���� �ٸ� �� �ִ�.
 */

#if 0
// ������ �ڵ�
// ������ �ڵ�� �����Ϳ� ������ 4����Ʈ�� �����ϰ� �ִ�. �ý��ۿ� ���� 
// ������ ũ��� �޶��� �� �����Ƿ� �ǵ����� ���� ����� �ʷ��� �� �ִ�.
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE    (10)

int main() {
    int** pArr = (int**)malloc(4 * ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
        pArr[i] = (int*)malloc(4 * ARR_SIZE);

    // ...

    for (int i = 0; i < ARR_SIZE; i++)
        free(pArr[i]);
    free(pArr);

    return 0;
}
#endif

#if 0
// �ذ� ���
// sizeof �����ڸ� ����Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE    (10)

int main() {
    int** pArr = (int**)malloc(sizeof(int*) * ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
        pArr[i] = (int*)malloc(sizeof(int) * ARR_SIZE);

    // ...

    for (int i = 0; i < ARR_SIZE; i++)
        free(pArr[i]);
    free(pArr);

    return 0;
}
#endif
