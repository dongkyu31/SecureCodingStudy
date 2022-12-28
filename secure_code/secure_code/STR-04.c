/*
 * STR-04. 경계가 불분명한 소스로부터 고정된 길이의 배열에 데이터를 복사하지 마라.
 *
 * 별도의 경계 없이 복사를 수행하는 함수들은 종종 외부 입력에서 적절한 크기가 들어올 것이라고 생각한다.
 * 그러나 이러한 가정은 틀릴 수 있고 버퍼 오버플로우를 발생시킬 수 있다.
 *
 */

#if 0
// 위험한 코드 1.
#include <stdio.h>

int main() {
    char buf[32];
    gets(buf);
    printf("%s\n", buf);

    return 0;
}
#endif 

#if 0
// 해결 방법
// fgets() 함수를 사용한다.
#include <stdio.h>

int main() {
    char buf[32];
    fgets(buf, sizeof(buf), stdin);
    printf("[%s]\n", buf);

    return 0;
}
#endif 

#if 0
// 위험한 코드 2.
// 다음의 코드는 버퍼 오버플로우가 발생할 가능성이 있다.
#include <stdio.h>
int main(int argc, char* argv[]) {
    char name[16];
    printf("input name: ");
    scanf("%s", name);
    printf("-> %s\n", name);
    return 0;
}
#endif 

#if 1
// 해결 방법
// 포맷 지정자로 경계를 지정한다.
#include <stdio.h>
#define TO_STR(x) #x 
#define STR_LIMIT(x) TO_STR(x) 
#define INPUT_SIZE 15 
int main(int argc, char* argv[]) {
    char name[INPUT_SIZE + 1];
    printf("input name: ");
    scanf("%"STR_LIMIT(INPUT_SIZE)"s", name);
    printf("-> %s\n", name);
    return 0;
}
#endif 
