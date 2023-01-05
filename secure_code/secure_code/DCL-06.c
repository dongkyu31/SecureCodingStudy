/*
 * DCL-06. 가변 인자를 가진 함수에서는 함수 작성자와 함수 사용자간의 약속이 지켜져야 한다.
 *
 * 가변 인자 함수는 여러 개의 인자를 취하는데 문제의 소지가 있다.
 * 때문에 가변 인자 함수의 정확한 사용 방법을 인지하여 의도하지 않는 결과가 발생하지 않도록 해야 한다.
 *
 */

#if 0
// 위험한 코드
// 아래의 함수에서 마지막 인자로 AV_END 값을 넘겨주지 않을 경우,
// 코드는 정상적으로 동작하지 않을 수 있다. 

#include <stdio.h>
#include <stdarg.h>

enum { VA_END = -1 };
int average(int first, ...) {
    int sum = 0;
    int cnt = 0;

    va_list args; // va_list => typedef char* va_list; 로 가변인자를 가리키는 포인터라 생각하면 된다.
					// 그래서 va_list 는 char* args; 로 해석된다.
    va_start(args, first);	// va_start(ap, v) =>  ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
							// #define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) -1))
							// _INTSIZEOF() 함수의 의미는 어떤 형태의 사이즈가 와도 int의 배수 형태로 값을 리턴하는개념(비트 연산)
							// 그래서  풀어쓰면
							// va_start(args, first) 함수는 아래처럼 해석된다
							// args = (char*)&first + 4;
							// 
							
    int i = first;
    while (i != VA_END) {
        sum += i;
        ++cnt;
        i = va_arg(args, int);	// va_arg(ap, t)  => (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
								// 위 정의에 따라 i = va_arg(args, int) 는 
								// i = *(int*)((args += 4) -4) 로 해석된다.
    }
    va_end(args);			// va_end(ap) => ((void)(ap = (va_list)0))
							// 따라서 해당 코드는 args = (char*)0; 로 해석된다.

    return cnt ? sum / cnt : 0;
}

int main() {
    int avg = average(1, 2, 3, 4);
    printf("%d\n", avg);

    return 0;
}
#endif

#if 0
// 해결 방법 1.
// 마지막 인자로 VA_END를 넣어 해결한다.
// 그리고 평균은 부동 소수점으로 나오기에 double 형태로 써라.
// 부동 소수점은 float 보다 double이 더 정확하다.
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
// 해결 방법 2.
// average 함수를 다시 설계한다.
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
