/*
 * DCL-01. 변하지 않는 객체는 const로 보장해둬라
 *
 * 변하지 않는 객체는 const로 보장해야 한다. 객체의 불변성을 const를 사용해 보장하며 
 * 어플리케이션의 정확성과 안전성을 보장하는데 도움이 된다.
 *
 */

#if 0
// 위험한 코드
// 다음의 코드는 객체의 값이 의도하지 않게 변경되고 있다.
#include <stdio.h>

typedef struct {
    int x, y;
} Point;

void print_point(Point* p) {
    printf("x = %d, y = %d\n", p->x, p->y);
    p->x = -1;
	printf("x is (%d)\n", p->x);
}

int main() {
    Point p = { 0, };
    print_point(&p);

    return 0;
}
#endif

#if 1
// 해결 방법
// const 키워드를 사용하여 해결한다.
// 이렇게 하면 빌드 타임에 에러를 잡아낼 수 있다.
#include <stdio.h>

typedef struct {
    int x, y;
} Point;

void print_point(const Point* p) {
    printf("x = %d, y = %d\n", p->x, p->y);
    p->x = -1;
	printf("x is (%d)\n", p->x);
}

int main() {
    Point p = { 0, };
    print_point(&p);

    return 0;
}

#endif
