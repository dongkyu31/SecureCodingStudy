// �ش� ������ data ������ �ٷ� �ǵ���� �߻��ϴ� ������ ���ؼ� �����Ѵ�.
//
// �Ʒ� �ڵ忡�� "hello"�� data ������ ����ǰ�, main() �Լ� �ڵ�� stack ������ ����Ǵµ� 
// str[0] = 'c' �ڵ�� data ������ �����Ϸ��� �ϴ� ������ �õ��ϱ� ������ ������ �߻��ϴµ� 
// �� ū ������ �ش� �ڵ�� ���� �ÿ��� ������ ���ٰ� ���� �� Segmentation Fault�� �߻���Ų��.
// ���� �ذ��������� const �� �߰��Ͽ� ���� Ÿ�ӿ� ������ �߻��ϵ��� �������.

#if 0
// ������ �ڵ�
// Segmentation Fault �߻�
#include <stdio.h>

int main() {
    char* str = "hello";
    str[0] = 'c'; 

    printf("%s\n", str);
    return 0;
}
#endif 

#if 0
// �ذ� ���1
#include <stdio.h>

int main() {
    const char* str = "hello";
    str[0] = 'c';

    printf("%s\n", str);
    return 0;
}
#endif 

#if 0
// �ذ� ���2
// ���� �޸� �Ҵ��� ���� heap ������ �޸𸮸� �Ҵ� �� data ������ �ִ� "hello" ���ڿ��� heap ������ ���� �Ѵ�. 
// ���� Heap �������� ������ �����ϴ� �������� ����
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
// �ذ� ���3
// �迭�� �����ϸ�, data ������ �ִ� "hello"�� Stack �������� �����ؿ´�.
// ���� Stack ������ ������ ��Ʈ���� �����ϴ� �������� �����ϸ� �ȴ�.
#include <stdio.h>

int main() {
    char str[] = "hello";
    str[0] = 'c';

    printf("%s\n", str);
    return 0;
}
#endif 
