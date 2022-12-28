/*
 * DCL-01. ������ �ʴ� ��ü�� const�� �����صֶ�
 *
 * ������ �ʴ� ��ü�� const�� �����ؾ� �Ѵ�. ��ü�� �Һ����� const�� ����� �����ϸ� 
 * ���ø����̼��� ��Ȯ���� �������� �����ϴµ� ������ �ȴ�.
 *
 */

#if 0
// ������ �ڵ�
// ������ �ڵ�� ��ü�� ���� �ǵ����� �ʰ� ����ǰ� �ִ�.
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
// �ذ� ���
// const Ű���带 ����Ͽ� �ذ��Ѵ�.
// �̷��� �ϸ� ���� Ÿ�ӿ� ������ ��Ƴ� �� �ִ�.
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
