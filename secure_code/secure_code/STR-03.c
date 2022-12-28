/*
 * STR-03. ���ڿ��� ���� ������ ���� �����Ϳ� �� ���� ���ڸ� ��⿡ ������� �����϶�
 * 
 * �����͸� ��� ���� ��ŭ ����� ũ�� ���� ���ۿ� �����ϸ� ���� �����÷ο찡 �߻��Ѵ�.
 * Ư��, �� ���ڷ� ����Ǵ� ���ڿ��� ���, �����͸� ������ �� ���ڿ��� ũ�⸦ �������� �ʾ� ���� �����÷ΰ� �߻��Ѵ�. 
 * �����ڴ� �̻��¸� �ǿ��� ����� ���μ����� �������� ���� �ڵ带 ������ �� �ְ� �ȴ�.
 *
 */



#if 0 
// ������ �ڵ� 1.
// ���� �ڵ忡�� �� ���� ���ڸ� �����ϴٰ� ���� �����÷ο찡 �߻��� �� �ִ�.
#include <stdio.h>

enum { ARR_SIZE = 6 };

int main()
{
	char src[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		src[i] = 'A' + i;
	char dst[ARR_SIZE];
	int i;
	for (i = 0; src[i] && i < sizeof(dst); i++)
		dst[i] = src[i];
	dst[i] = '\0';  // <- HERE!! Buffer Overflow
	printf("[%s]\n", dst);
	return 0;
}
#endif 

#if 0
// �ذ� ���
// dst�� �߰��Ǵ� �� ���� ���ڸ� ����Ͽ� ������ ���� ������ �����Ѵ�.
#include <stdio.h>

enum { ARR_SIZE = 6 };

int main()
{
	char src[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		src[i] = 'A' + i;
	char dst[ARR_SIZE];
	int i;
	for (i = 0; src[i] && i < sizeof(dst) - 1; i++) // <-- HERE sizeof(dst) - 1 
		dst[i] = src[i];
	dst[i] = '\0';
	printf("%s\n", dst);
	return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
// ������ �ڵ�� ������� ���ڸ� �����ϱ� ���� ���縦 �����ϰ� �ִ�.
// �� �� �������� ���� ������ �߸� �Ҵ��� ���, ���� �����÷ο츦 ����ų �� �ִ�.
#include <stdio.h>
int main(int argc, char* argv[])
{
	char prog_name[128];
	strcpy(prog_name, argv[0]);
	// ...
	return 0;
}
#endif 

#if 0
// �ذ� ���
// ����Ǵ� ������ ũ�Ⱑ �����ϰ� ������ �� �ֵ��� ���� �޸� �Ҵ��� ����Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	char* prog_name = malloc(strlen(argv[0]) + 1);
	if (prog_name == NULL) {
		perror("malloc");
		return -1;
	}
	strcpy(prog_name, argv[0]);
	// ...
	free(prog_name);
	return 0;
}
#endif 





