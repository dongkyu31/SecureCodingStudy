/*
 * DCL-06. ���� ���ڸ� ���� �Լ������� �Լ� �ۼ��ڿ� �Լ� ����ڰ��� ����� �������� �Ѵ�.
 *
 * ���� ���� �Լ��� ���� ���� ���ڸ� ���ϴµ� ������ ������ �ִ�.
 * ������ ���� ���� �Լ��� ��Ȯ�� ��� ����� �����Ͽ� �ǵ����� �ʴ� ����� �߻����� �ʵ��� �ؾ� �Ѵ�.
 *
 */

#if 0
// ������ �ڵ�
// �Ʒ��� �Լ����� ������ ���ڷ� AV_END ���� �Ѱ����� ���� ���,
// �ڵ�� ���������� �������� ���� �� �ִ�. 

#include <stdio.h>
#include <stdarg.h>

enum { VA_END = -1 };
int average(int first, ...) {
    int sum = 0;
    int cnt = 0;

    va_list args; // va_list => typedef char* va_list; �� �������ڸ� ����Ű�� �����Ͷ� �����ϸ� �ȴ�.
					// �׷��� va_list �� char* args; �� �ؼ��ȴ�.
    va_start(args, first);	// va_start(ap, v) =>  ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
							// #define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) -1))
							// _INTSIZEOF() �Լ��� �ǹ̴� � ������ ����� �͵� int�� ��� ���·� ���� �����ϴ°���(��Ʈ ����)
							// �׷���  Ǯ���
							// va_start(args, first) �Լ��� �Ʒ�ó�� �ؼ��ȴ�
							// args = (char*)&first + 4;
							// 
							
    int i = first;
    while (i != VA_END) {
        sum += i;
        ++cnt;
        i = va_arg(args, int);	// va_arg(ap, t)  => (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
								// �� ���ǿ� ���� i = va_arg(args, int) �� 
								// i = *(int*)((args += 4) -4) �� �ؼ��ȴ�.
    }
    va_end(args);			// va_end(ap) => ((void)(ap = (va_list)0))
							// ���� �ش� �ڵ�� args = (char*)0; �� �ؼ��ȴ�.

    return cnt ? sum / cnt : 0;
}

int main() {
    int avg = average(1, 2, 3, 4);
    printf("%d\n", avg);

    return 0;
}
#endif

#if 0
// �ذ� ��� 1.
// ������ ���ڷ� VA_END�� �־� �ذ��Ѵ�.
// �׸��� ����� �ε� �Ҽ������� �����⿡ double ���·� ���.
// �ε� �Ҽ����� float ���� double�� �� ��Ȯ�ϴ�.
#include <stdio.h>
#include <stdarg.h>

enum { VA_END = -1 };
double average(int first, ...) {
    int sum = 0;
    int cnt = 0;

    va_list args;
    va_start(args, first);

    int i = first;
    while (i != VA_END) {
        sum += i;
        ++cnt;
        i = va_arg(args, int);
    }
    va_end(args);

    return cnt ? sum / (double)cnt : 0;
}

int main() {
    double avg = average(1, 2, 3, 4, VA_END);
    printf("%lf\n", avg);

    return 0;
}

#endif

#if 1
// �ذ� ��� 2.
// average �Լ��� �ٽ� �����Ѵ�.
#include <stdio.h>
#include <stdarg.h>

double average(int cnt, ...) {
    if (cnt == 0)
        return 0;

    va_list args;
    va_start(args, cnt);

    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += va_arg(args, int);
    va_end(args);

    return sum / (double)cnt;
}

int main() {
    double avg = average(4, 1, 2, 3, 4);
    printf("%lf\n", avg);

    return 0;
}

#endif
