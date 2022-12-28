// 해당 예제는 data 영역을 바로 건드려서 발생하는 문제에 대해서 설명한다.
//
// 아래 코드에서 "hello"는 data 영역에 저장되고, main() 함수 코드는 stack 영역에 저장되는데 
// str[0] = 'c' 코드는 data 영역을 수정하려고 하는 접근을 시도하기 때문에 문제가 발생하는데 
// 더 큰 문제는 해당 코드는 빌드 시에는 문제가 없다가 실행 시 Segmentation Fault를 발생시킨다.
// 따라서 해결방법에서는 const 를 추가하여 빌드 타임에 문제가 발생하도록 만들었다.

#if 0
// 위험한 코드
// Segmentation Fault 발생
#include <stdio.h>

int main() {
    char* str = "hello";
    str[0] = 'c'; 

    printf("%s\n", str);
    return 0;
}
#endif 

#if 0
// 해결 방법1
#include <stdio.h>

int main() {
    const char* str = "hello";
    str[0] = 'c';

    printf("%s\n", str);
    return 0;
}
#endif 

#if 0
// 해결 방법2
// 동적 메모리 할당을 통해 heap 영역에 메모리를 할당 후 data 영역에 있는 "hello" 문자열을 heap 영역에 복사 한다. 
// 이후 Heap 영역에서 내용을 수정하는 방향으로 수정
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = "hello";
	char* p = malloc(sizeof(str));
	strcpy(p, str);

    p[0] = 'c';

    printf("%s\n", p);
    return 0;
}
#endif 



#if 1
// 해결 방법3
// 배열로 선언하면, data 영역에 있는 "hello"를 Stack 영역으로 복사해온다.
// 이후 Stack 영역에 복사한 스트링을 수정하는 방향으로 진행하면 된다.
#include <stdio.h>

int main() {
    char str[] = "hello";
    str[0] = 'c';

    printf("%s\n", str);
    return 0;
}
#endif 
