/*
 * STR-03. 문자열의 위한 공간이 문자 데이터와 널 종료 문자를 담기에 충분함을 보장하라
 * 
 * 데이터를 모두 담을 만큼 충분히 크지 않은 버퍼에 복사하며 버퍼 오버플로우가 발생한다.
 * 특히, 널 문자로 종료되는 문자열의 경우, 데이터를 조작할 때 문자열의 크기를 제한하지 않아 종종 오버플로가 발생한다. 
 * 공격자는 이상태를 악용해 취약한 프로세스의 권한으로 임의 코드를 실행할 수 있게 된다.
 *
 */



#if 0 
// 위험한 코드 1.
// 다음 코드에서 널 종료 문자를 저장하다가 버퍼 오버플로우가 발생할 수 있다.
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
// 해결 방법
// dst에 추가되는 널 종료 문자를 고려하여 루프의 종료 조건을 수정한다.
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
// 위험한 코드 2.
// 다음의 코드는 명령행의 인자를 수정하기 위해 복사를 수행하고 있다.
// 이 때 복사히기 위한 공간을 잘못 할당할 경우, 버퍼 오버플로우를 일으킬 수 있다.
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
// 해결 방법
// 복사되는 공간의 크기가 적절하게 생성될 수 있도록 동적 메모리 할당을 사용한다.
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





