// ex 14-2 typedef를 사용한 전역 구조체 변수 //
#include <stdio.h>
struct _sData
{
    char c;
    int n;
};
typedef struct _sData SDATA, *PSDATA; // typedef를 사용한 구조체 및 구조체 포인터 별칭 선언
SDATA data1, data2, *pd1; // "SDATA *pd1" = "PSDATA pd1"

void printData(SDATA data)
{
    printf(" member:%c, %d\n", data.c, data.n);
}

/* 포인터로 받는 경우 예시:
void printData(PSDATA data)  // 또는 void printData(SDATA *data)
{
    printf(" member:%c, %d\n", data->c, data->n);  // . 대신 -> 사용
}

main()에서 호출 시:
    printData(pd1);       // 포인터 그대로 전달 (*pd1 → pd1로 변경)
    printData(pd2);       // 포인터 그대로 전달 (*pd2 → pd2로 변경)
    printData(&data1);    // 주소 전달 (data1 → &data1로 변경)
    printData(&data2);    // 주소 전달 (data2 → &data2로 변경)
    printData(&data3);    // 주소 전달 (data3 → &data3로 변경)
*/

void main()
{
    SDATA data3; // 지역 구조체 변수
    PSDATA pd2; // 지역 구조체 포인터 변수

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
