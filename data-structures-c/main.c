#include "linked_list.h"

int main() {
    printf("=== ���� ���� ����Ʈ �׽�Ʈ ===\n\n");

    // ����Ʈ ����
    LinkedList* list = create_list();
    if (list == NULL) {
        printf("����Ʈ ���� ����\n");
        return -1;
    }
    printf("����Ʈ ���� �Ϸ�\n");

    // �ʱ� ���� Ȯ��
    printf("�ʱ� ����Ʈ ���� - ũ��: %d, �������: %s\n",
        get_size(list), is_empty(list) ? "��" : "�ƴϿ�");
    print_list(list);

    // �� �� ���� �׽�Ʈ
    printf("\n--- �� �� ���� �׽�Ʈ ---\n");
    insert_front(list, 10);
    insert_front(list, 20);
    insert_front(list, 30);
    printf("30, 20, 10 ������ �� �� ���� ��:\n");
    print_list(list);
    printf("ũ��: %d\n", get_size(list));

    // �� �� ���� �׽�Ʈ
    printf("\n--- �� �� ���� �׽�Ʈ ---\n");
    insert_back(list, 40);
    insert_back(list, 50);
    printf("40, 50 �� �� ���� ��:\n");
    print_list(list);
    printf("ũ��: %d\n", get_size(list));

    // �� Ž�� �׽�Ʈ
    printf("\n--- �� Ž�� �׽�Ʈ ---\n");
    int pos = search(list, 20);
    if (pos != -1) {
        printf("�� 20�� �ε��� %d���� �߰ߵ�\n", pos);
    }
    else {
        printf("�� 20�� ã�� �� ����\n");
    }

    pos = search(list, 99);
    if (pos != -1) {
        printf("�� 99�� �ε��� %d���� �߰ߵ�\n", pos);
    }
    else {
        printf("�� 99�� ã�� �� ���� (����� ���)\n");
    }

    // �� �� ���� �׽�Ʈ
    printf("\n--- �� �� ���� �׽�Ʈ ---\n");
    int deleted = delete_front(list);
    printf("�� �� ��� ������: %d\n", deleted);
    print_list(list);
    printf("ũ��: %d\n", get_size(list));

    // �� �� ���� �׽�Ʈ
    printf("\n--- �� �� ���� �׽�Ʈ ---\n");
    deleted = delete_back(list);
    printf("�� �� ��� ������: %d\n", deleted);
    print_list(list);
    printf("ũ��: %d\n", get_size(list));

    // ��� ���� �׽�Ʈ - ��� ��� ����
    printf("\n--- ��� ���� �׽�Ʈ: ��� ��� ���� ---\n");
    while (!is_empty(list)) {
        deleted = delete_front(list);
        printf("������ ��: %d, ���� ũ��: %d\n", deleted, get_size(list));
    }
    print_list(list);

    // �� ����Ʈ���� ���� �õ� (���� ó�� �׽�Ʈ)
    printf("\n--- ���� ó�� �׽�Ʈ: �� ����Ʈ���� ���� ---\n");
    delete_front(list);
    delete_back(list);

    // �޸� ����
    free_list(list);
    printf("\n�޸� ���� �Ϸ�\n");
    printf("=== �׽�Ʈ ���� ===\n");

    return 0;
}