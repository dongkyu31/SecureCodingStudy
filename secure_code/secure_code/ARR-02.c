/*
 * ARR-02. 배열의 인덱스가 유효한 범위 안에 있음을 보장하라.
 *
 * 배열의 참조가 배열의 경계 안에서 일어나게 하는 일은 전적으로 프로그래머의 책임이다.
 *
 */


#if 0
// 위험한 코드
// insert_in_table() 함수는 배열의 위쪽 경계를 넘지 않도록 보장하고 있지만, 아래쪽 경계를 체크하고 있지 않다.

#include <stdio.h>
#include <stdlib.h>

enum { TABLESIZE = 10 };
int* table = NULL;

int insert_in_table(int pos, int value) {
    if (!table) {
        table = (int*)malloc(sizeof(int) * TABLESIZE);
        if (table == NULL) {
            perror("malloc");
            exit(-1);
        }
    }

    if (pos >= TABLESIZE) {
		free(table);
        return -1;
	}

    table[pos] = value;
	printf("table[%d] is %d\n", pos, value);
	free(table);
    return 0;
}

int main() {
    if (insert_in_table(-5, 100) < 0)
        printf("insert_in_table error\n");

    return 0;
}
#endif 

#if 1
// 해결 방법
// pos 변수를 size_t로 선언하여 음수의 전달을 막는다.
// 음수가 size_t 인 unsigned int 형태로 변환 되면 매우 큰 값이 되는 것을 이용하는 방식.

#include <stdio.h>
#include <stdlib.h>

enum { TABLESIZE = 10 };
int* table = NULL;

int insert_in_table(size_t pos, int value) {
    if (!table) {
        table = (int*)malloc(sizeof(int) * TABLESIZE);
        if (table == NULL) {
            perror("malloc");
            exit(-1);
        }
    }

    if (pos >= TABLESIZE) {
		free(table);
        return -1;
	}

    table[pos] = value;
	printf("table[%d] is %d\n", pos, value);
	free(table);
    return 0;
}

int main() {
    if (insert_in_table(-5, 100) < 0)
        printf("insert_in_table error\n");

    return 0;
}
#endif 


