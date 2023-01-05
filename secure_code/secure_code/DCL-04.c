/*
 * DCL-04. 프로그램 로직 상의 고정적인 값을 나타낼 때는 의미 있는 심볼릭 살수를 사용하라.
 *
 * 코드 상에서 리터럴(literal)을 사용할 경우, 가독성이 떨어질 수 있다. 때문에 가급적
 * 리터럴을 직접 사용하기 보다는 심볼릭(Symbolic) 상수를 통해 적절한 이름을 붙여 코드의 
 * 의도를 명확히 하는 것이 좋다. C 언어에서 심볼릭 상수를 만드는 방법은 다음과 같다.
 *
 * - const로 지정된 객체
 * - 열거형 상수
 * - 객체형 매크로
 *
 * const로 지정된 객체
 *
 * const로 지정된 객체는 특정 스코프 내에서 사용 가능하며 컴파일러가 타입 체크를 해주며
 * 디버깅 도구 사용 시 객체의 이름을 나타낼 수 있다. 대신 각 객체는 메모리를 사용하며
 * 런타임에 약간의 오버헤드가 발생한다. 또한 아래의 경우처럼 컴파일 타임에서 정수형
 * 상수가 필요한 곳에서는 사용할 수 없다.
 *
 * 구조체 내부의 비트 단위로 정의된 멤버의 크기
 * 배열의 크기(가변 배열은 예외)
 * 얼거형 상수의 값
 * case 상수의 값
 *
 *
 * 열거형 상수 
 *
 * 열거형 상수는 정수로 나타낼 수 있는 정수형 상수 표현식을 나타낼 때 사용한다. 
 * const 키워드를 사용한 객체와 달리 메모리를 소모하지 않는다.
 * 다만, 열거형 상수는 값의 타입을 정의할 수 없으며 항상 정수(int)이다.
 *
 *
 * 객체형 매크로
 *
 * 전처리 단계에서 사용되는 객체형 매크로(object-like macro)의 정의는 다음과 같다.
 *
 * #define identifier replacement-list
 * 
 * 객체형 매크로는 전처리기에 의해 치환되는 구조이므로 컴파일 과정에서는 매크로의 심볼을
 * 볼 수 없다. 그래서 대부분의 컴파일러들은 매크로 이름들을 따로 저장하고 디버거에 
 * 전달하기도 한다.
 * 매크로는 다음 이름으로 적용될 수 있는 스코프 규칙들을 고려하지 않았기 때문에 의도하지 않는다
 * 방식으로 치환되어 기대하지 않은 결과를 만들기도 한다. 그리고 객체형 매크로는 메모리를
 * 소비하지 않으며 따라서 포인터로 가리킬 수도 없다. C 프로그래머들은 심볼릭 상수로 
 * 객체형 매크로를 사용하는 편이다.
 *
 * 열거형을 추천...
 *
 *  정리하면 다음과 같다.
 *
 * | 방식     |  평가시점  |메모리 소비|디버깅 시의 심볼|타입 체크|컴파일 타임 상수 표현식|
 * | 열거형   | 컴파일 타임| 없음      | 있음           | 있음    | 있음                  |
 * | const지정| 런타임     | 있음      | 있음           | 있음    | 없음                  |
 * | 매크로   | 전처리     | 없음      | 없음           | 없음    | 있음                  |
 *
 *
 */




#if 0
// 위험한 코드 1.
// 정수 리터럴에 대한 의미가 분명하지 않다.
void draw_color(int color) {
    switch (color) {
    case 0: /* ... */ break;
    case 1: /* ... */ break;
    case 2: /* ... */ break;
    }
}

int main() {
    // ...
    draw_color(0);

    return 0;
}
#endif

#if 0
// 해결 방법
// 심볼릭 상수로 변경하여 의미를 분명하게 한다.
enum { RED, GREEN, BLUE };
void draw_color(int color) {
    switch (color) {
    case RED: /* ... */ break;
    case GREEN: /* ... */ break;
    case BLUE: /* ... */ break;
    }
}

int main() {
    // ...
    draw_color(RED);

    return 0;
}
#endif

#if 0
// 위험한 코드 2.
// 버퍼의 크기가 일치하지 않아 버퍼 오버플로우가 발생할 수 있다.
#include <stdio.h>

int main() {
    char buff[16];

    fgets(buff, 32, stdin);
    printf("%s\n", buff);

    return 0;
}

#endif

#if 0
// 해결 방법 1.
// 열거형을 사용하여 해결한다.
#include <stdio.h>

enum { BUFF_SIZE = 16 };

int main() {
    char buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, stdin);
    printf("%s\n", buff);

    return 0;
}

#endif

#if 0
// 해결 방법 2.
// sizeof() 연산자를 이용하여 해결한다.
#include <stdio.h>

int main() {
    char buff[16];

    fgets(buff, sizeof(buff), stdin);
    printf("%s\n", buff);

    return 0;
}
#endif
