# 단일 연결 리스트 (Singly Linked List)

## 개념

단일 연결 리스트는 선형 자료구조 중 하나로, 각 노드가 데이터와 다음 노드를 가리키는 포인터로 구성되어 있습니다. 배열과 달리 메모리상에서 연속적으로 저장되지 않으며, 포인터를 통해 연결됩니다.

### 주요 특징
- **동적 크기**: 런타임에 크기 조정 가능
- **메모리 효율성**: 필요한 만큼만 메모리 할당
- **삽입/삭제 용이성**: 맨 앞 삽입/삭제는 O(1) 시간복잡도
- **순차 접근**: 특정 위치 접근 시 처음부터 순회 필요 (O(n))

### 구조체 설계
```c
typedef struct Node {
    int data;           // 데이터 저장
    struct Node* next;  // 다음 노드 포인터
} Node;

typedef struct LinkedList {
    Node* head;  // 첫 번째 노드 포인터
    int size;    // 리스트 크기
} LinkedList;
```

## 구현된 기능

### 기본 연산
- `create_list()`: 새로운 연결 리스트 생성
- `free_list()`: 리스트 메모리 해제
- `is_empty()`: 리스트가 비어있는지 확인
- `get_size()`: 리스트 크기 반환

### 삽입 연산
- `insert_front()`: 맨 앞에 노드 삽입 - O(1)
- `insert_back()`: 맨 뒤에 노드 삽입 - O(n)

### 삭제 연산
- `delete_front()`: 맨 앞 노드 삭제 - O(1)
- `delete_back()`: 맨 뒤 노드 삭제 - O(n)

### 탐색 및 출력
- `search()`: 특정 값 탐색 후 인덱스 반환 - O(n)
- `print_list()`: 리스트 전체 출력 - O(n)

## 테스트

### 정상 케이스
- 리스트 생성 및 초기화
- 맨 앞/뒤 삽입 후 순서 확인
- 값 탐색 및 인덱스 반환
- 맨 앞/뒤 삭제 후 크기 변화 확인

### 경계 조건
- 빈 리스트 상태 확인
- 모든 노드 삭제 후 빈 리스트 상태
- 단일 노드 삭제

### 오류 처리
- 빈 리스트에서 삭제 시도
- 메모리 할당 실패 처리
- NULL 포인터 예외 처리

### 시간복잡도 분석
- 삽입(맨 앞): O(1)
- 삽입(맨 뒤): O(n)
- 삭제(맨 앞): O(1)
- 삭제(맨 뒤): O(n)
- 탐색: O(n)
- 출력: O(n)