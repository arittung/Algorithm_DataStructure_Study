# 자료구조<br><br>

<br>

## 목차
- [1. linked List](#01-linked-list)
- [2. Stack](#02-stack)
- [3. Queue](#03-queue-)
- [4. Deque](#04-deque-)
- [5. List](#05-list)
- [이미지 출처](#이미지-출처)
 <br>
 
 ---
 <br><br>
 
## 01. linked List
<br>

#### 01-1. 삽입 연산 

- void push_front(int n); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 노드를 맨 앞에 한 개 추가* <br>
- void push_back(int n);  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 노드를 끝에 한 개 추가* <br>
- void insert_node_at(int idx, int n); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 정해진 위치에 노드를 추가* 

#### 01-2. 삭제 연산 <br>
- int pop_front();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; *// 맨 앞의 노드를 지우고 지운 노드의 값을 리턴*<br>
- int pop_back(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 끝 노드를 지우고 지운 노드 값을 리턴* <br>
- int pop_node_at(int idx); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 원하는 위치의 노드를 지우고 지운 노드의 값을 리턴* <br>
- void remove_node(int n);  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 원하는 값과 같은 노드를 한 개 지움* <br>
- void delete_list(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// linked list 전체를 지움* <br>

#### 01-3. 대입 연산 및 기타 연산 <br>
- void replace_value_at(int idx, int n);  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 원하는 위치의 값을 입력 받은 값으로 바꿈* <br>
- int size(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 연결리스트의 총 길이를 리턴* <br>
- void display_contents();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 연결리스트의 현재 구조를 보여줌* <br>
- int search_value(int n);  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 연결리스트에서 원하는 값을 찾아서 그 값의 인덱스를 리턴* <br>
  
<br>

  ---
  
#### [arittung.log - Linked List](https://velog.io/@arittung/datastructure01Linked-List)

<br><br><br>

## 02. Stack<br>

#### 02-1. 삽입 연산<br>
- void push(int e); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 스택에 요소 추가* <br>
#### 02-2. 삭제 연산<br>
- int pop(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 스택에 요소 제거하고 지운 요소 값 리턴* <br>
#### 02-3. 기타 연산<br>
- bool isEmpty(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 스택이 비어있는지 확인* <br>
- bool isFull();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 스택이 가득 차있는지 확인* <br>
- int peek(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 맨 위의 요소 출력* <br>

  
<br>

  ---
  
#### [arittung.log - Stack](https://velog.io/@arittung/datastructure02.Stack)

<br><br><br>

## 03. Queue <br>

### 03-3. 연산<br>
1. 삽입 연산<br>
- void enqueue(int val); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 뒤에 데이터를 추가* <br>
2. 삭제 연산<br>
- int dequeue();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴* <br>
3. 기타 연산<br>
- bool isEmpty();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐가 비었는지 확인* <br>
- bool isFull(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐가 꽉 찼는지 확인* <br>
- int peek(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 맨 앞의 데이터 리턴* <br>

  
<br>

  ---
  
#### [arittung.log - Queue](https://velog.io/@arittung/datastructure03.Queue)

<br><br><br>



## 04. Deque <br>

#### 04-1. 삽입 연산<br>
- void addRear(int n);  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 뒤에 데이터를 추가* <br>
- void addFront(int n); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 앞에 데이터를 추가* <br>
#### 04-2. 삭제 연산<br>
- int deleteFront();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴* <br>
- int deleteRear(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐 맨 뒤에서 데이터를 꺼내고 꺼낸 값 리턴* <br>
#### 04-3. 기타 연산<br>
- bool isEmpty();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐가 비었는지 확인* <br>
- bool isFull();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 큐가 꽉 찼는지 확인* <br>
- int getFront(); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 맨 앞의 데이터 리턴* <br>
- int getRear();  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  *// 맨 뒤 요소를 삭제하지 않고 리턴* <br>

  
<br>

  ---
  
#### [arittung.log - Deque](https://velog.io/@arittung/datastructure04.Deque)

<br><br><br>

## 05. List<br>

#### 05-1. 배열 통해 리스트 구현<br>
- [Array_List.cpp](https://github.com/arittung/Algorithm_DataStructure_Study/blob/main/data_structure/List/Array_List.cpp)<br>
- [DArray_List.cpp](https://github.com/arittung/Algorithm_DataStructure_Study/blob/main/data_structure/List/DArray_List.cpp) 
: 가변 길이 리스트(동적할당)<br>

<img src="https://user-images.githubusercontent.com/53934639/126075604-37d798b8-f592-499e-8888-11b3ba0979db.png" width="450px" float="left">

<br>

#### 05-2. 연결리스트 통해 리스트 구현<br>
- [Linkedlist_List.cpp](https://github.com/arittung/Algorithm_DataStructure_Study/blob/main/data_structure/List/Linkedlist_List.cpp)<br>

<img src="https://user-images.githubusercontent.com/53934639/126075637-f3b9b5c0-f31b-4298-9b56-27d77823941b.png" width="500px" float="left">

<br>


  ---
  
#### [arittung.log - List](https://velog.io/@arittung/datastructure05.List)

<br><br><br>






<br><br>

 ## 이미지 출처
 - https://yjg-lab.tistory.com/category/%EC%BB%B4%ED%93%A8%ED%84%B0%EA%B3%B5%ED%95%99%EB%B6%80/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0
 - https://www.flaticon.com/kr/
