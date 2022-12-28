/*
 * ARR-02. �迭�� �ε����� ��ȿ�� ���� �ȿ� ������ �����϶�.
 *
 * �迭�� ������ �迭�� ��� �ȿ��� �Ͼ�� �ϴ� ���� �������� ���α׷����� å���̴�.
 *
 */


#if 0
// ������ �ڵ�
// insert_in_table() �Լ��� �迭�� ���� ��踦 ���� �ʵ��� �����ϰ� ������, �Ʒ��� ��踦 üũ�ϰ� ���� �ʴ�.

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
// �ذ� ���
// pos ������ size_t�� �����Ͽ� ������ ������ ���´�.
// ������ size_t �� unsigned int ���·� ��ȯ �Ǹ� �ſ� ū ���� �Ǵ� ���� �̿��ϴ� ���.

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


