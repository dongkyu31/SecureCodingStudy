/*
 * EXP-02. �� ������ AND�� OR�� ���� �� ����� �˰� �־��.
 *
 * �� ������ AND�� OR�� ���� �򰡸� �����Ѵ�. ��, ù��° �ǿ����ڷ� �򰡰�
 * �Ϸ�Ǹ� �ι�° �ǿ����ڴ� ������ �ʴ´�.
 *
 *   | ������  |  ù ��° �ǿ����� | �� ��° �ǿ�����  |
 *   | AND(&&) |  ����             |   �� ����       |
 *   | OR(||)  |  ��               |   �� ����       |
 */

#if 0
// ������ �ڵ�
// ���� �ڵ�� �迭���� 0�� �� �������� ���� �ڵ��̴�.
// �׷��� AND �������� ù��° �� �����ڰ� �����̹Ƿ� �ι�° �� �����ڴ�
// �򰡵��� �ʴ´�.

#include <stdio.h>
#define SIZE_MAX    (5)

int main() {
    int arr[SIZE_MAX] = { 0,1,2,3,0 };

    int i = 0;
    int cnt = 0;
    while ((arr[i] == 0) && (++i < SIZE_MAX))
        ++cnt;
    printf("%d\n", cnt);

    return 0;
}
#endif

#if 0
// �ذ� ���
// ���� �򰡰� �̷������ �ʵ��� �Ѵ�.
#include <stdio.h>
#define SIZE_MAX    (5)

int main() {
    int arr[SIZE_MAX] = { 0,2,3,4,0 };

    int cnt = 0;
    for (int i = 0; i < SIZE_MAX; i++) {
        if (arr[i] == 0)
            ++cnt;
    }
    printf("%d\n", cnt);

    return 0;
}
#endif
