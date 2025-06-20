/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

void main()
{
    ArrayStack* stack = createArrayStack(3);

    pushArrayStack(stack, 1);
    pushArrayStack(stack, 2);
    pushArrayStack(stack, 3);
    pushArrayStack(stack, 4);

    printf("%d poped from stack\n", popArrayStack(stack));

}*/

#include<stdio.h>
#include "stack_linkedlist.h"

// 메인 함수: 배열 스택 기능 테스트
int main() {
    printf("=== 배열 스택 테스트 ===\n");

    // 테스트 1: 스택 생성
    printf("\n테스트 1: 용량 3으로 스택 생성\n");
    ArrayStack* stack = createArrayStack(3);
    if (stack) {
        printf("스택이 성공적으로 생성되었습니다, 용량: %d\n", stack->capacity);
    }
    else {
        printf("스택 생성 실패\n");
        return 1;
    }

    // 테스트 2: 빈 스택 확인
    printf("\n테스트 2: 빈 스택 확인\n");
    printf("비어 있음? %d (예상: 1)\n", isArrayStackEmpty(stack));

    // 테스트 3: 데이터 삽입
    printf("\n테스트 3: 10, 20, 30 삽입\n");
    if (pushArrayStack(stack, 10)) {
        printf("10 삽입 성공, 최상단: %d\n", peekArrayStack(stack));
    }
    else {
        printf("10 삽입 실패\n");
    }

    if (pushArrayStack(stack, 20)) {
        printf("20 삽입 성공, 최상단: %d\n", peekArrayStack(stack));
    }
    else {
        printf("20 삽입 실패\n");
    }

    if (pushArrayStack(stack, 30)) {
        printf("30 삽입 성공, 최상단: %d\n", peekArrayStack(stack));
    }
    else {
        printf("30 삽입 실패\n");
    }

    // 테스트 4: 스택 가득 참 확인
    printf("\n테스트 4: 스택 가득 참 확인\n");
    printf("가득 참? %d (예상: 1)\n", isArrayStackFull(stack));

    // 테스트 5: 스택 오버플로우 테스트
    printf("\n테스트 5: 가득 찬 스택에 40 삽입\n");
    if (pushArrayStack(stack, 40)) {
        printf("40 삽입 성공 (예상하지 않음)\n");
    }
    else {
        printf("40 삽입 실패 (예상됨 - 스택이 가득 참)\n");
    }

    // 테스트 6: 데이터 제거
    printf("\n테스트 6: 데이터 제거\n");
    printf("제거: %d (예상: 30)\n", popArrayStack(stack));
    printf("제거: %d (예상: 20)\n", popArrayStack(stack));
    printf("제거 후 최상단: %d (예상: 10)\n", peekArrayStack(stack));

    // 테스트 7: 빈 스택에서 제거 테스트
    printf("\n테스트 7: 거의 빈 스택에서 제거\n");
    printf("제거: %d (예상: 10)\n", popArrayStack(stack));
    printf("빈 스택에서 제거: %d (예상: -1)\n", popArrayStack(stack));

    // 테스트 8: NULL 스택 테스트
    printf("\n테스트 8: NULL 스택 연산\n");
    ArrayStack* nullStack = NULL;
    if (pushArrayStack(nullStack, 50)) {
        printf("NULL 스택에 50 삽입 성공 (예상하지 않음)\n");
    }
    else {
        printf("NULL 스택에 50 삽입 실패 (예상됨)\n");
    }
    printf("NULL 스택 최상단: %d (예상: -1)\n", peekArrayStack(nullStack));
    printf("NULL 스택 제거: %d (예상: -1)\n", popArrayStack(nullStack));

    // 테스트 9: 메모리 해제
    printf("\n테스트 9: 스택 해제\n");
    freeArrayStack(stack);
    printf("스택 해제 완료\n");

    // 테스트 10: 잘못된 용량 테스트
    printf("\n테스트 10: 잘못된 용량으로 스택 생성\n");
    ArrayStack* invalidStack = createArrayStack(0);
    if (invalidStack == NULL) {
        printf("용량 0으로 스택 생성 실패 (정상)\n");
    }
    else {
        printf("예기치 않게 스택 생성됨\n");
        freeArrayStack(invalidStack);
    }

    // 테스트 11: 대량 데이터 테스트
    printf("\n테스트 11: 대량 데이터 삽입 및 제거\n");
    stack = createArrayStack(1000);
    if (stack) {
        int successCount = 0;
        for (int i = 0; i < 1000; i++) {
            if (pushArrayStack(stack, i)) {
                successCount++;
            }
        }
        printf("%d개 요소 삽입 성공, 최상단: %d (예상: 999)\n", successCount, peekArrayStack(stack));
        printf("가득 참? %d (예상: 1)\n", isArrayStackFull(stack));

        for (int i = 0; i < 1000; i++) {
            popArrayStack(stack);
        }
        printf("1000개 요소 제거, 비어 있음? %d (예상: 1)\n", isArrayStackEmpty(stack));
        freeArrayStack(stack);
    }
    else {
        printf("대량 스택 생성 실패\n");
    }

    // 테스트 12: 추가적인 반환값 테스트
    printf("\n테스트 12: 반환값 기반 연속 삽입 테스트\n");
    stack = createArrayStack(5);
    if (stack) {
        int values[] = { 100, 200, 300, 400, 500, 600 }; // 6개 (용량 초과)
        int size = sizeof(values) / sizeof(values[0]);

        for (int i = 0; i < size; i++) {
            if (pushArrayStack(stack, values[i])) {
                printf("값 %d 삽입 성공\n", values[i]);
            }
            else {
                printf("값 %d 삽입 실패 - 스택이 가득 참\n", values[i]);
            }
        }

        printf("최종 스택 상태 - 가득 참? %d, 최상단: %d\n",
            isArrayStackFull(stack), peekArrayStack(stack));

        freeArrayStack(stack);
    }

    printf("\n=== 테스트 완료 ===\n");
    return 0;
}