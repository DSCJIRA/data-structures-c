#include "linked_list.h"

int main() {
    printf("=== 단일 연결 리스트 테스트 ===\n\n");

    // 리스트 생성
    LinkedList* list = create_list();
    if (list == NULL) {
        printf("리스트 생성 실패\n");
        return -1;
    }
    printf("리스트 생성 완료\n");

    // 초기 상태 확인
    printf("초기 리스트 상태 - 크기: %d, 비어있음: %s\n",
        get_size(list), is_empty(list) ? "예" : "아니오");
    print_list(list);

    // 맨 앞 삽입 테스트
    printf("\n--- 맨 앞 삽입 테스트 ---\n");
    insert_front(list, 10);
    insert_front(list, 20);
    insert_front(list, 30);
    printf("30, 20, 10 순서로 맨 앞 삽입 후:\n");
    print_list(list);
    printf("크기: %d\n", get_size(list));

    // 맨 뒤 삽입 테스트
    printf("\n--- 맨 뒤 삽입 테스트 ---\n");
    insert_back(list, 40);
    insert_back(list, 50);
    printf("40, 50 맨 뒤 삽입 후:\n");
    print_list(list);
    printf("크기: %d\n", get_size(list));

    // 값 탐색 테스트
    printf("\n--- 값 탐색 테스트 ---\n");
    int pos = search(list, 20);
    if (pos != -1) {
        printf("값 20이 인덱스 %d에서 발견됨\n", pos);
    }
    else {
        printf("값 20을 찾을 수 없음\n");
    }

    pos = search(list, 99);
    if (pos != -1) {
        printf("값 99가 인덱스 %d에서 발견됨\n", pos);
    }
    else {
        printf("값 99를 찾을 수 없음 (예상된 결과)\n");
    }

    // 맨 앞 삭제 테스트
    printf("\n--- 맨 앞 삭제 테스트 ---\n");
    int deleted = delete_front(list);
    printf("맨 앞 노드 삭제됨: %d\n", deleted);
    print_list(list);
    printf("크기: %d\n", get_size(list));

    // 맨 뒤 삭제 테스트
    printf("\n--- 맨 뒤 삭제 테스트 ---\n");
    deleted = delete_back(list);
    printf("맨 뒤 노드 삭제됨: %d\n", deleted);
    print_list(list);
    printf("크기: %d\n", get_size(list));

    // 경계 조건 테스트 - 모든 노드 삭제
    printf("\n--- 경계 조건 테스트: 모든 노드 삭제 ---\n");
    while (!is_empty(list)) {
        deleted = delete_front(list);
        printf("삭제된 값: %d, 남은 크기: %d\n", deleted, get_size(list));
    }
    print_list(list);

    // 빈 리스트에서 삭제 시도 (오류 처리 테스트)
    printf("\n--- 오류 처리 테스트: 빈 리스트에서 삭제 ---\n");
    delete_front(list);
    delete_back(list);

    // 메모리 해제
    free_list(list);
    printf("\n메모리 해제 완료\n");
    printf("=== 테스트 종료 ===\n");

    return 0;
}