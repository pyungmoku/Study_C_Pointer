// 10-11 첫번째 매개변수가 int형인 가변 인자 사용자 함수 //
// 플랫폼/컴파일러 차이 - &n + 1 방식은 비표준이라 불안정할 수 있음 //
/*예상 출력
10
10 20
10 20 30
*/ 
/* 실제 출력
0
0 10
0 10 0
*/

#include <stdio.h>

void print(int n, ...)
{
    if (n ==1)
        printf(" %d\n", *(&n+1));
    else if (n ==2)
        printf(" %d %d\n", *(&n+1), *(&n+2));
    else if (n ==3)
        printf(" %d %d %d\n", *(&n+1), *(&n+2), *(&n+3));
    else
        printf("Invalid input\n");
}

void main()
{
    int a = 10, b = 20, c = 30;

    print(1, a);               // 첫번째 매개변수가 1일 때
    print(2, a, b);           // 첫번째 매개변수가 2일 때
    print(3, a, b, c);       // 첫번째 매개변수가 3일 때
}