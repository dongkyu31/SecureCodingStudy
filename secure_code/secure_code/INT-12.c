/*
 * INT-12. ������ �ǿ������� ��Ʈ���� �� ���� ��Ʈ�� ����Ʈ���� ����
 *
 * ������ �ǿ������� ���� ���� �Ǵ� �°�� ���� �ǿ������� ���� ���ų� 
 * ū ��� ���ǵ��� ���� ������ �Ͼ��.
 */

#if 0
// ������ �ڵ� 1.
// ������ �ǿ������� ���� �����̹Ƿ� ������ �ڵ�� ������ �����̴�.
#include <stdio.h>
#include <limits.h>

int main() {
    signed char sint1, sint2, result = 0;
    sint1 = 1;
    sint2 = -1;

    result = sint1 << sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// �ذ� ���
// ������ �ǿ����ڰ� �������� �˻��Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    signed char sint1, sint2, result = 0;
    sint1 = 1;
    sint2 = -1;

    if (sint2 < 0) {
        fprintf(stderr, "undefined behavior!\n");
        exit(-1);
    }

    result = sint1 << sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
// �ǿ������� ��Ʈ���� �� ���� ��Ʈ�� ����Ʈ�ϴ� ���� ������ �����̴�.
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result;
    uint1 = 1;
    uint2 = 32;

    result = uint1 << uint2;
    printf("result = %u\n", result);

    return 0;
}

#endif 

#if 0
// �ذ� ���
// ����Ʈ ������ �����ϱ� ���� �˻縦 �����Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INT_BIT (sizeof(unsigned int) * CHAR_BIT)

int main() {
    unsigned int uint1, uint2, result;
    uint1 = 1;
    uint2 = 32;

    if (uint2 >= INT_BIT) {
        fprintf(stderr, "undefined behavior!\n");
        exit(-1);
    }

    result = uint1 << uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 



