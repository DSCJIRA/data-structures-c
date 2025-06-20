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

// ���� �Լ�: �迭 ���� ��� �׽�Ʈ
int main() {
    printf("=== �迭 ���� �׽�Ʈ ===\n");

    // �׽�Ʈ 1: ���� ����
    printf("\n�׽�Ʈ 1: �뷮 3���� ���� ����\n");
    ArrayStack* stack = createArrayStack(3);
    if (stack) {
        printf("������ ���������� �����Ǿ����ϴ�, �뷮: %d\n", stack->capacity);
    }
    else {
        printf("���� ���� ����\n");
        return 1;
    }

    // �׽�Ʈ 2: �� ���� Ȯ��
    printf("\n�׽�Ʈ 2: �� ���� Ȯ��\n");
    printf("��� ����? %d (����: 1)\n", isArrayStackEmpty(stack));

    // �׽�Ʈ 3: ������ ����
    printf("\n�׽�Ʈ 3: 10, 20, 30 ����\n");
    if (pushArrayStack(stack, 10)) {
        printf("10 ���� ����, �ֻ��: %d\n", peekArrayStack(stack));
    }
    else {
        printf("10 ���� ����\n");
    }

    if (pushArrayStack(stack, 20)) {
        printf("20 ���� ����, �ֻ��: %d\n", peekArrayStack(stack));
    }
    else {
        printf("20 ���� ����\n");
    }

    if (pushArrayStack(stack, 30)) {
        printf("30 ���� ����, �ֻ��: %d\n", peekArrayStack(stack));
    }
    else {
        printf("30 ���� ����\n");
    }

    // �׽�Ʈ 4: ���� ���� �� Ȯ��
    printf("\n�׽�Ʈ 4: ���� ���� �� Ȯ��\n");
    printf("���� ��? %d (����: 1)\n", isArrayStackFull(stack));

    // �׽�Ʈ 5: ���� �����÷ο� �׽�Ʈ
    printf("\n�׽�Ʈ 5: ���� �� ���ÿ� 40 ����\n");
    if (pushArrayStack(stack, 40)) {
        printf("40 ���� ���� (�������� ����)\n");
    }
    else {
        printf("40 ���� ���� (����� - ������ ���� ��)\n");
    }

    // �׽�Ʈ 6: ������ ����
    printf("\n�׽�Ʈ 6: ������ ����\n");
    printf("����: %d (����: 30)\n", popArrayStack(stack));
    printf("����: %d (����: 20)\n", popArrayStack(stack));
    printf("���� �� �ֻ��: %d (����: 10)\n", peekArrayStack(stack));

    // �׽�Ʈ 7: �� ���ÿ��� ���� �׽�Ʈ
    printf("\n�׽�Ʈ 7: ���� �� ���ÿ��� ����\n");
    printf("����: %d (����: 10)\n", popArrayStack(stack));
    printf("�� ���ÿ��� ����: %d (����: -1)\n", popArrayStack(stack));

    // �׽�Ʈ 8: NULL ���� �׽�Ʈ
    printf("\n�׽�Ʈ 8: NULL ���� ����\n");
    ArrayStack* nullStack = NULL;
    if (pushArrayStack(nullStack, 50)) {
        printf("NULL ���ÿ� 50 ���� ���� (�������� ����)\n");
    }
    else {
        printf("NULL ���ÿ� 50 ���� ���� (�����)\n");
    }
    printf("NULL ���� �ֻ��: %d (����: -1)\n", peekArrayStack(nullStack));
    printf("NULL ���� ����: %d (����: -1)\n", popArrayStack(nullStack));

    // �׽�Ʈ 9: �޸� ����
    printf("\n�׽�Ʈ 9: ���� ����\n");
    freeArrayStack(stack);
    printf("���� ���� �Ϸ�\n");

    // �׽�Ʈ 10: �߸��� �뷮 �׽�Ʈ
    printf("\n�׽�Ʈ 10: �߸��� �뷮���� ���� ����\n");
    ArrayStack* invalidStack = createArrayStack(0);
    if (invalidStack == NULL) {
        printf("�뷮 0���� ���� ���� ���� (����)\n");
    }
    else {
        printf("����ġ �ʰ� ���� ������\n");
        freeArrayStack(invalidStack);
    }

    // �׽�Ʈ 11: �뷮 ������ �׽�Ʈ
    printf("\n�׽�Ʈ 11: �뷮 ������ ���� �� ����\n");
    stack = createArrayStack(1000);
    if (stack) {
        int successCount = 0;
        for (int i = 0; i < 1000; i++) {
            if (pushArrayStack(stack, i)) {
                successCount++;
            }
        }
        printf("%d�� ��� ���� ����, �ֻ��: %d (����: 999)\n", successCount, peekArrayStack(stack));
        printf("���� ��? %d (����: 1)\n", isArrayStackFull(stack));

        for (int i = 0; i < 1000; i++) {
            popArrayStack(stack);
        }
        printf("1000�� ��� ����, ��� ����? %d (����: 1)\n", isArrayStackEmpty(stack));
        freeArrayStack(stack);
    }
    else {
        printf("�뷮 ���� ���� ����\n");
    }

    // �׽�Ʈ 12: �߰����� ��ȯ�� �׽�Ʈ
    printf("\n�׽�Ʈ 12: ��ȯ�� ��� ���� ���� �׽�Ʈ\n");
    stack = createArrayStack(5);
    if (stack) {
        int values[] = { 100, 200, 300, 400, 500, 600 }; // 6�� (�뷮 �ʰ�)
        int size = sizeof(values) / sizeof(values[0]);

        for (int i = 0; i < size; i++) {
            if (pushArrayStack(stack, values[i])) {
                printf("�� %d ���� ����\n", values[i]);
            }
            else {
                printf("�� %d ���� ���� - ������ ���� ��\n", values[i]);
            }
        }

        printf("���� ���� ���� - ���� ��? %d, �ֻ��: %d\n",
            isArrayStackFull(stack), peekArrayStack(stack));

        freeArrayStack(stack);
    }

    printf("\n=== �׽�Ʈ �Ϸ� ===\n");
    return 0;
}