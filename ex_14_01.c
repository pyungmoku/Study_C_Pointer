// 14-1 전역 구조체 변수 //
#include <stdio.h>

struct _sData
{
    char c;
    int n;
} data1, data2, *pd1;  // 전역 구조체 변수 및 포인터 변수 선언

void printData(struct _sData data)
{
    printf(" member:%c, %d\n", data.c, data.n);
}
void main()
{
    struct _sData data3; // 지역 구조체 변수
    struct _sData *pd2; // 지역 구조체 포인터 변수

    pd1 = &data1;
    pd2 = &data2;

    data1.c = 'A'; data1.n  = 10;
    data2.c = 'B'; data2.n  = 20;
    data3.c = 'C'; data3.n  = 30;

    printData(*pd1);      // 전역 포인터 pd1가 가리키는 구조체(data1)를 역참조(*)하여 값으로 전달(구조체 복사)하고 멤버를 출력
    printData(*pd2);      // 지역 포인터 pd2가 가리키는 구조체(data2)를 역참조(*)하여 값으로 전달(구조체 복사)하고 멤버를 출력
    printData(data1);    // 전역 구조체 변수 data1을 값으로 전달(구조체 복사)하고 멤버를 출력
    printData(data2);    // 전역 구조체 변수 data2을 값으로 전달(구조체 복사)하고 멤버를 출력
    printData(data3);    // 지역 구조체 변수 data3을 값으로 전달(구조체 복사)하고 멤버를 출력
}