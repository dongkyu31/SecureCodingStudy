/* 
 * DCL-05. 함수 선언 시 적절한 타입 정보를 포함시켜라
 *
 * 함수 호출 전 반드시 함수의 선언 정보가 반드시 존재해야 한다. 
 * 이는 함수 선언 정보가 없을 경우, 컴파일러는 타입 정보를 정확하게 
 * 체크할 수 없기 때문이다. 표준 라이브러리의 함수를 사용할 함수 선언 정보를 
 * 삽입하는 방법은 적절한 헤더 파일을 삽입하는 것이다. 
 * 함수의 선언 정보가 없는 상태로 함수를 호출할 경우, 컴파일러는 경고를 내지만
 * 에러는 발생하지 않는다.
 */

#if 0
// 위험한 코드 1.
// 함수의 선언 정보 없이 함수를 호출하면 잘못된 값이 함수의 인자로 전달될 수 있다.
// 아래 코드는 컴파일 타임에서 에러로 잡히지 않는다. Warning 만 발생한다.
// 그리고 실제 런타임 시에 쓰레기 값이 인자로 전달된다.
#include <stdio.h>

int main() {
    func(1, 2);
    return 0;
}

int func(int a, int b, int c) {
    printf("func(%d, %d, %d)\n", a, b, c);
    return 0;
}
#endif

#if 0
// 해결 방법
// 함수의 선언 정보를 정확하게 기술한다.
// 아래의 코드처럼 함수를 미리 선언해놓으면 컴파일 타임에서 에러를 잡을 수 있다.
#include <stdio.h>

int func(int a, int b, int c);

int main() {
    func(1, 2); // error 발생. 위 함수 형태를 선언해놓았기에 컴파일러에서 에러 처리
    return 0;
}

int func(int a, int b, int c) {
    printf("func(%d, %d, %d)\n", a, b, c);
    return 0;
}

#endif

#if 1
// 위험한 코드 2.
// 잘못된 함수 포인터를 선언해서 사용하면 의도하지 않는 결과가 나타날 수 있다.
// 첫번째 코드 예제 처럼... 
// 컴파일러가 에러로 잡지 않고 warning으로 잡아 처리하기에 원치 않는 결과를 초래한다.
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int(*fp)(int); // 매개변수가 하나뿐인 함수 포인터 선언

    fp = add; // 매개변수가 2개인 함수를 복사하고 있다. 
    printf("%d\n", fp(1));

    return 0;
}

#endif

#if 0
// 해결 방법
// 함수 포인터를 정확하게 정의해야 한다.
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int(*fp)(int, int);

    fp = add;
    printf("%d\n", fp(1, 1));

    return 0;
}


#endif

