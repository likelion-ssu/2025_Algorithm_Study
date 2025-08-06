# 개념
Map, Set, Priority Queue(우선순위 큐)

## 1. map
https://velog.io/@ymj7250/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-map

각 노드가 key와 value 쌍으로 이루어진 트리로, 중복을 허용하지 않는다.
중복을 허용하지 않으므로 key값이 겹치는 값이 들어왔을 때에는 갱신되는 것이 아니라 아예 삽입되지 않는다.
key 값으로 value에 접근하고자 할 때 사용된다.

`정렬`
- 내부에서 key 값을 기준으로 자동 정렬된다. 오름차순이 기본이다.
- 내림차순 정렬을 원한다면 `map<string, int, greater<string>> mp`과 같이 선언하면 된다.

`검색`: find()
- iterator을 사용하며, 데이터를 끝까지 찾지 못했을 경우 iterator은 `map.end()`를 반환한다. map의 끝과 비교하여 발견 여부를 확인하면 된다.

`삽입`: insert() 혹은 key값을 사용한 삽입

`접근`
- key값을 가지고 배열을 사용하듯 value에 접근한다. 즉, index 대신 key를 사용하는 느낌이다.

### 내부 구현
- map
내부적으로 Red-Black Tree로 구현된다. 따라서 탐색, 삭제 전부 O(log N) 내로 실행된다.

- unordered_map
정렬 없이 저장되지만, 저장 순서대로 데이터가 삽입되는 것은 아니다.
내부적으로는 해시테이블로 구현된다.

## 2. Set
### 1. set
중복을 비허용하며, 기본적으로 오름차순 정렬된다.
집합의 특성상, 구분하지 않는다.

### 2. multi set
중복이 불가한 일반 set과는 달리 key값이 중복될 수 있다.
기본 오름차순 자동 정렬된다.
내부적으로 이진 검색 트리를 사용하여 접근/검색/삽입/삭제의 시간복잡도는 O(log N)이다.

## 3. Priority queue(우선순위 큐)
내부적으로는 Heap 자료구조를 사용하며, 모든 원소 중 가장 큰 값이 Top을 유지하도록 설계되어 있다. 최대/최소만 그때그때 필요한 경우 사용하면 좋은 자료구조이다.

우선순위 큐를 사용하다보면, 정렬 기준을 직접 만들어야 하는 경우가 발생한다. 이때, struct를 직접 정의하여 선언시 인자로 넘겨줘야 한다.

```
// pair의 second 값을 기준으로 정렬하는 예시
struct cmp{ bool operator()(pair<int,char> &a, pair<int,char> &b) {
    return a.second > b.second; // second가 크면 true => 더 크다 => 더 밑에 (heap의 구조 생각하기)
}};
```

# 문제 풀이
14425 -> 21939 -> 2696

