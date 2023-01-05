/*
 *  INT-02. ���� ��ȯ ��Ģ�� �����϶�
 *
 *  ���� ��ȯ
 *  - ����� ��ȯ(explicit conversion) - ��ȯ �����ڸ� ����� ��ȯ
 *  - ������ ��ȯ(implicit conversion) - Ư�� ���꿡 ���� ��ȯ
 *
 *  ������ �°�(integer Promotion)
 *  - int ���� ���� ���� Ÿ���� ������ ����� ��, int�� unsigned int Ÿ������ ��ȯ�ȴ�.
 *  - �̴� �����÷η� ���� ��� ���� ������ ���ϱ� �����̴�.
 *
 *
 *  ���� ��ȯ ����
 *  - ��Ʈ ���� ���� Ÿ���� ���� ������ ���´�.
 *  - ���� �ٸ� �� ��ȣ�� �ִ� ������ ������ �ٸ���.
 *  - ��ȣ �ִ� ���� Ÿ���� ������ �ڽź��� ���е��� ���� �ٸ� � ��ȣ �ִ� ���� ���� 
 *  ������ ����
 *  - long long int > long int > int > short int > signed char
 *  - unsigned long long int > unsigned long int > unsigned int > unsigned shot int > unsigned char
 *
 *
 *  �Ϲ����� ��� ��ȯ ��Ģ
 *  - ���� ������ ��� �� �ǿ����ڴ� ���� Ÿ������ ��ȯ�ȴ�.
 *  - �� ���� �ǿ����ڰ� ���� Ÿ���̸� ��ȯ���� �ʴ´�.
 *  - �� ���� �ǿ����ڰ� ���� ���� Ÿ���̸� ������ ū Ÿ������ ��ȯ�ȴ�.
 *  - ��ȣ ���� ���� Ÿ���� �ǿ����ڰ� �ٸ� �ǿ������� �������� ũ�ų� ���� ���,
 *  ��ȣ �ִ� ���� Ÿ���� �ǿ����ڴ� ��ȣ ���� Ÿ������ ��ȯ�ȴ�.
 *  - ��ȣ �ִ� ���� Ÿ���� �ǿ����ڰ� ��ȣ ���� Ÿ���� ��� ���� ǥ���� �� �ִ� ���,
 *  ��ȣ ���� ���� Ÿ���� �ǿ����ڴ� ��ȣ �ִ� ���� Ÿ������ ��ȯ�ȴ�.
 *  - ��ȣ �ִ� ���� Ÿ���� �ǿ����ڰ� ��ȣ ���� Ÿ���� ��� ���� ǥ���� �� ���� ���,
 *  ��ȣ �ִ� ���� Ÿ���� �ǿ����ڴ� ���� Ÿ���� ��ȣ ���� Ÿ������ �� �ǿ����� ��� ��ȯ�ȴ�.
 *
 *
 */

#if 0
// ������ �°�
#include <stdio.h>

int main() {
    char c1 = 100;
    char c2 = 3;
    char c3 = 4;

    char result = c1 * c2 / c3;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// ������ �ڵ� 1.
// ���� �ٸ� Ÿ�Կ� ���Ͽ� ������ ������ ��쿡�� �����ؾ� ��.
#include <stdio.h>

int main() {
    int si = -1;
    unsigned int ui = 1;

    if (ui > si)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// �ذ� ���
// Ÿ���� ��ġ ��Ų��.
#include <stdio.h>

int main() {
    int si = -1;
    unsigned int ui = 1;

    if ((int)ui > si)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
// ���� �޸� �Ҵ� �Լ� ���� size_t Ÿ���� ����ϹǷ� ������ ����� ���, 
// �Ҵ��� �� ���� ���� ū ����� ��ȸ�Ǿ� �Ҵ��̽����� �� ����. 
#include <stdlib.h>

int main() {
    int* pArr = (int*)malloc(-1);
    pArr[0] = 0;

    free(pArr);
    return 0;
}
#endif 

#if 0
// �ذ� ��� 
// ������ ������� �ʰų� ��ȯ�� ���� �����ؼ� ���
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pArr = (int*)malloc(-1);
    if (pArr == NULL) {
        perror("malloc");
        exit(-1);
    }
    pArr[0] = 0;

    free(pArr);
    return 0;
}
#endif 
