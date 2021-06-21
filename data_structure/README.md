# 자료구조<br><br>

## 목차
- [1. linked List](#01-linked-list)
- [2. Stack](#02-stack)
- [3. Queue](#03-queue-)
- [4. Deque](#04-deque-)
- [5. List](#05-list)
- [이미지 출처](#이미지-출처)
 <br><br>
 ---
 <br><br>
## 01. linked List
<br>

### 01-1. 구조<br>
1. 노드<br>
> <img src="https://mblogthumb-phinf.pstatic.net/MjAxOTA1MDdfMTEg/MDAxNTU3MjA0OTUwMDA1.DSJlwlTNm2iXdPUkzSrIkz58Q-6C2WKfFi0Tq7KlZVwg.uGAPoVzrcjQv58CzjdZ0Fz1u0BWZoA0rOWT6YUQ2Hacg.PNG.std_34/image.png?type=w800" width="500px"><br>
2. 포인터
> - 헤드 포인터(Head) : 리스트의 첫 번째 노드<br>
> - 테일 포인터(Tail) : 리스트의 마지막 노드<br>
> <img src="https://media.vlpt.us/images/sangh00n/post/bfa73611-96a7-450a-9974-4b40fb70c2fd/linkedLIst.png" width="500px">

<br>

### 01-2. 장점<br>
 - 노드를 추가, 삭제 용이.<br>
 - 불연속적인 메모리 공간에 저장 가능.<br>
 - 크기를 가변적으로 쓸 수 있음.

<br>

### 01-3. 종류<br>
1. 단순(단방향) 연결 리스트(singly linked list)<br>
2. 원형 연결 리스트(circular linked list)<br>
3. 이중 연결 리스트(double linked list)<br>
<img src="https://mblogthumb-phinf.pstatic.net/MjAxOTA1MDdfMTc4/MDAxNTU3MjA2NzUwNTA2.zFSk59o7XoiUEv20e73r1Qh0csm7PfHL2zgpK0B9NZEg.vDG82wpGHzBLaRyrSP41E6EVIjjdzsszeoWY8mIBOqAg.PNG.std_34/image.png?type=w800" width="500px"><br>


<br>

### 01-4. 연산<br>
1. 삽입 연산 <br>
> - void push_front(int n); // 노드를 맨 앞에 한 개 추가<br>
> - void push_back(int n);  // 노드를 끝에 한 개 추가<br>
> - void insert_node_at(int idx, int n);  // 정해진 위치에 노드를 추가<br>
2. 삭제 연산 <br>
> - int pop_front();  // 맨 앞의 노드를 지우고 지운 노드의 값을 리턴<br>
> - int pop_back(); // 끝 노드를 지우고 지운 노드 값을 리턴<br>
> - int pop_node_at(int idx); // 원하는 위치의 노드를 지우고 지운 노드의 값을 리턴<br>
> - void remove_node(int n);  // 원하는 값과 같은 노드를 한 개 지움<br>
> - void delete_list(); // linked list 전체를 지움<br>
3. 대입 연산 및 기타 연산 <br>
> - void replace_value_at(int idx, int n);  // 원하는 위치의 값을 입력 받은 값으로 바꿈<br>
> - int size(); // 연결리스트의 총 길이를 리턴<br>
> - void display_contents();  // 연결리스트의 현재 구조를 보여줌<br>
> - int search_value(int n);  // 연결릴스트에서 원하는 값을 찾아서 그 값의 인덱스를 리턴<br>

<br><br><br><br>

## 02. Stack<br>
- 가장 나중에 들어온 데이터가 가장 먼저 나가는 자료형<br>
- 후입 선출(LIFO)<br><br>

<img src="https://cdn.codingworldnews.com/news/photo/202104/img_3407_1.png" height="300px">

<br>

### 02-1. 연산<br>
1. 삽입 연산<br>
> - void push(int e); // 스택에 요소 추가<br>
2. 삭제 연산<br>
> - int pop(); // 스택에 요소 제거하고 지운 요소 값 리턴<br>
3. 기타 연산<br>
> - bool isEmpty(); // 스택이 비어있는지 확인<br>
> - bool isFull();  // 스택이 가득 차있는지 확인<br>
> - int peek(); // 맨 위의 요소 출력<br>

<br><br><br><br>


## 03. Queue <br>
- 가장 먼저 들어온 데이터가 가장 먼저 나가는 자료형 <br>
- 선입 선출(FIFO) <br>
<img src="https://cdn.codingworldnews.com/news/photo/202104/img_3407_2.png" width="400px"><br><br>
<br>

### 03-1. 선형 큐 <br>
- 배열을 사용한 선형 큐<br>
- 삽입을 계속하기 위해서는 요소들을 이동시켜야 함. 번거로움 <br>
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbgqC9I%2Fbtq2Tci68iW%2Fv1tkHzmWfFp3yjUpE1bHOK%2Fimg.png" width="700px"><br><br>
<br>

### 03-2. 원형 큐 <br>
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbxYKyl%2Fbtq2NdjvNAk%2F67qIyyADkTzqGHenQagcVk%2Fimg.png" width="700px"><br>
&<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbD3xhh%2Fbtq2MzUGuNA%2FjkJKZlmUVXFqICJHeclEp0%2Fimg.png" width="700px"><br><br>
<br>

### 03-3. 연산<br>
1. 삽입 연산<br>
> - void enqueue(int val);  // 큐 맨 뒤에 데이터를 추가<br>
2. 삭제 연산<br>
> - int dequeue();  // 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴<br>
3. 기타 연산<br>
> - bool isEmpty();  // 큐가 비었는지 확인<br>
> - bool isFull();  // 큐가 꽉 찼는지 확인<br>
> - int peek(); // 맨 앞의 데이터 리턴<br>

<br><br><br><br>


## 04. Deque <br>
- Double-Ended Queue<br>
- 양쪽에서 연산이 가능한 큐<br>
<img src="https://t1.daumcdn.net/cfile/blog/99861B345CA99E3717" width="600px" height="150px"><br>
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FXykii%2Fbtq2N0Kxzrv%2F3M3N4IHQsGPZzddr5AJa50%2Fimg.png" width="700px"><br><br>
<br>

### 04-1. 연산<br>
1. 삽입 연산<br>
> - void addRear(int n);  // 큐 맨 뒤에 데이터를 추가<br>
> - void addFront(int n); // 큐 맨 앞에 데이터를 추가<br>
2. 삭제 연산<br>
> - int deleteFront();  // 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴<br>
> - int deleteRear(); // 큐 맨 뒤에서 데이터를 꺼내고 꺼낸 값 리턴<br>
3. 기타 연산<br>
> - bool isEmpty();  // 큐가 비었는지 확인<br>
> - bool isFull();  // 큐가 꽉 찼는지 확인<br>
> - int getFront(); // 맨 앞의 데이터 리턴<br>
> - int getRear();  // 맨 뒤 요소를 삭제하지 않고 리턴<br>

<br><br><br><br>

## 05. List<br>
- 순서를 가진 데이터들의 모임 <br>

<br>

### 05-1. 연결리스트와 리스트의 차이 <br>
1. 리스트 <br>
> - 특정한 "자료구조"를 의미<br>
> - Abstract Data Type(ADT) - 실제 구현은 다양하게 할 수 있음 (ex. 스택, 큐, 리스트..)<br>
2. 연결리스트 <br>
> - 실제 구현된 구현체<br>
> - 포인터와 데이터로 구성된 노드를 이용한 구현(Implementation) (ex. 배열, 연결리스트..)<br>
<Br>

### 05-2. 구현 방법 <br>
<img src="https://blog.kakaocdn.net/dn/cIuYyU/btq2SL7kX7y/kPu4Lyf1CIk4PmhdVu5yMk/img.png" width="600px"><br>
1. 배열 이용 <br>
> - 구현 간단, 삽입과 삭제 시 오버헤드, 항목의 수가 제한됨 <br>
> - 공백과 포화 상태가 존재<br>
> - 삽입, 삭제 위치 다음의 항목들을 이동 - O(N): 평균적으로 N/2개의 항목을 이동해야 함.<br>
2. 연결리스트 이용 <br>
> - 구현이 복잡, 삽입과 삭제가 효율적이고 크기의 제한이 없음, 조회가 느림 <br>
> - O(1) - 다만 조회 연산이 느림.<br>
<br>
 
### 05-3. 연산 <br>
1. 배열 통해 리스트 구현<br>
> - Array_List.cpp<br>
> - DArray_List.cpp : 가변 길이 리스트(동적할당)<br>
> <img src="https://user-images.githubusercontent.com/53934639/122797952-ffc9bc00-d2fa-11eb-86e4-adc935654e68.png" width="300px">
> <img src="https://user-images.githubusercontent.com/53934639/122797877-e7f23800-d2fa-11eb-9b3e-a0690e81bde0.png" width="300px"><br>

2. 연결리스트 통해 리스트 구현<br>
> - Linkedlist_List.cpp<br>
> <img src="https://user-images.githubusercontent.com/53934639/122798296-5fc06280-d2fb-11eb-9576-53a4162bef6a.png" width="400px">
> <img src="https://user-images.githubusercontent.com/53934639/122798352-74045f80-d2fb-11eb-93b0-3e896a5bad43.png" width="250px"><br>

 
>  - 헤드 노드란..?<br>
>  : 포인터 변수 head가 아닌 node 객체인 head를 사용<br>
>  : 가상의 노드 head가 앞에 추가로 존재<br>
>  : 맨 앞 노드의 삽입이나 삭제 연산을 단순화 할 수 있음<br>
> <img src="https://user-images.githubusercontent.com/53934639/122798469-98f8d280-d2fb-11eb-9a26-17eb2536a4b9.png" width="500px"><br>

 
 
<br><br><br><br>
------------
 ## 이미지 출처
 - https://m.blog.naver.com/std_34/221532135313
 - https://velog.io/@sangh00n/%EB%A6%AC%EC%8A%A4%ED%8A%B8List%EC%9D%98-%EC%9D%B4%ED%95%B4-%EB%A7%81%ED%81%AC%EB%93%9C%EB%A6%AC%EC%8A%A4%ED%8A%B8
 - http://www.codingworldnews.com/news/articleView.html?idxno=3407
 - https://yjg-lab.tistory.com/category/%EC%BB%B4%ED%93%A8%ED%84%B0%EA%B3%B5%ED%95%99%EB%B6%80/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0
