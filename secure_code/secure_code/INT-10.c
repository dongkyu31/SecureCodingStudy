/*
 * INT-10. unsigned ���� ������ ���ε��� �ʵ��� �����϶�.
 *
 * C99 ǥ�ؿ� ������ unsigned �ǿ����ڸ� ����� ����� ���� �����÷ΰ�
 * �߻����� �ʴ´�. ������� ����� ���� Ÿ������ ǥ���� �� ���� ���
 * ������ �������� ���� �ٿ�(wrap around) ǥ���ϱ� �����̴�. �̸� 
 * ���� ����(wrapping) �̶�� �Ѵ�. ������ �ŷ��� �� ���� �ҽ��� ����
 * ����� ���� ���� �Ʒ��� ���� ���� ���ȴٸ� ���� ������ ����ؼ��� �ȵȴ�.
 *
 *	- �迭�� �ε���
 *	- ������ ������ �Ϻ�
 *	- ���� ī����
 *	- �޸� �Ҵ� �Լ��� ����
 *	- �� ���� ���ȿ� �ΰ��� �ڵ�
 *
 *
 */

#if 0
// ������ �ڵ� 1.
// ��ȣ ���� ������ ���� ������ ���� ������ �Ͼ �� �ֱ� ������
// ������ �ڵ�� �ǵ����� �ʴ� ����� �ʷ��� �� �ִ�.

#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, sum = 0;
    uint1 = UINT_MAX;
    uint2 = 1;

    sum = uint1 + uint2;
    printf("sum : %u\n", sum);

    return 0;
}
#endif 

#if 0
// �ذ� ���
// ���� ������ �߻��ϱ� ���� �̸� �׽�Ʈ�Ѵ�. 
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 1;

    if (uint1 > UINT_MAX - uint2) {
		// ���ǹ��� ������ �״�� ������ �̹� ������ �� �� �ֱ⿡ �캯���� �����ؼ� üũ�ؾ� �Ѵ�.
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }
    result = uint1 + uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
// ��ȣ ���� ������ ���� ������ ���� ������ �Ͼ �� �ֱ� ������ 
// ������ �ڵ�� �ǵ����� �ʴ� ����� �ʷ��� �� �ִ�.
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = 0;
    uint2 = 1;

    result = uint1 - uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 0
// �ذ� ���
// ���� ������ �߻��ϱ� ���� �̸� �׽�Ʈ�Ѵ�.
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = 0;
    uint2 = 1;

    if (uint1 < uint2) {
		// ���ǹ��� ������ �״�� ������ �̹� ������ �� �� �ֱ⿡ �캯���� �����ؼ� üũ�ؾ� �Ѵ�.
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }

    result = uint1 - uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif

#if 0
// ������ �ڵ� 3.
// ��ȣ ���� �����ǰ��� ������ ���� ������ �Ͼ �� �ֱ� ������ ������ �ڵ��
// �ǵ����� �ʴ� ����� �ʷ��� �� �ִ�.
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 2;

    result = uint1 * uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 1
// �ذ� ���
// ���� ������ �߻��ϱ� ���� �̸� �׽�Ʈ�Ѵ�. 
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 2;

    if (uint1 > UINT_MAX / uint2) {
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }

    result = uint1 * uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 
