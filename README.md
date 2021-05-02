# 자료구조<br><br>

## linked List<br>
> ### 구조<br>
> > 1. 노드<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116224092-31a32400-a78b-11eb-9497-6d1e3f90a11b.PNG" width="500px"><br>
> > 2. 포인터
> > > - 헤드 포인터(Head) : 리스트의 첫 번째 노드<br>
> > > - 테일 포인터(Tail) : 리스트의 마지막 노드<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116224142-3f58a980-a78b-11eb-9d78-9711b70b7b82.PNG" width="500px"><br><br>

> ### 장점<br>
> > - 노드를 추가, 삭제 용이.<br>
> > - 불연속적인 메모리 공간에 저장 가능.<br>
> > - 크기를 가변적으로 쓸 수 있음.<br><br>

> ### 종류<br>
> > 1. 단순(단방향) 연결 리스트(singly linked list)<br>
> > <img src="https://user-images.githubusercontent.com/53934639/116212669-06ff9e00-a780-11eb-8b47-aa4b904e8164.PNG" width="500px"><br>
> > 2. 원형 연결 리스트(circular linked list)<br>
> > <img src = "https://user-images.githubusercontent.com/53934639/116223979-0caeb100-a78b-11eb-9407-3062873a640e.PNG" width="500px">br>
> > 3. 이중 연결 리스트(double linked list)<br>
> > <img src ="https://user-images.githubusercontent.com/53934639/116224047-23ed9e80-a78b-11eb-823f-b542e496dd64.PNG" width="500px"><br><br>

> ### 연산<br>
> > 1. 삽입 연산 <br>
> > > - void push_front(int n); // 노드를 맨 앞에 한 개 추가<br>
> > > - void push_back(int n);  // 노드를 끝에 한 개 추가<br>
> > > - void insert_node_at(int idx, int n);  // 정해진 위치에 노드를 추가<br>
> > 2. 삭제 연산 <br>
> > > - int pop_front();  // 맨 앞의 노드를 지우고 지운 노드의 값을 리턴<br>
> > > - int pop_back(); // 끝 노드를 지우고 지운 노드 값을 리턴<br>
> > > - int pop_node_at(int idx); // 원하는 위치의 노드를 지우고 지운 노드의 값을 리턴<br>
> > > - void remove_node(int n);  // 원하는 값과 같은 노드를 한 개 지움<br>
> > > - void delete_list(); // linked list 전체를 지움<br>
> > 3. 대입 연산 및 기타 연산 <br>
> > > - void replace_value_at(int idx, int n);  // 원하는 위치의 값을 입력 받은 값으로 바꿈<br>
> > > - int size(); // 연결리스트의 총 길이를 리턴<br>
> > > - void display_contents();  // 연결리스트의 현재 구조를 보여줌<br>
> > > - int search_value(int n);  // 연결릴스트에서 원하는 값을 찾아서 그 값의 인덱스를 리턴<br>
<br><br><br><br>


## Stack<br>
> - 가장 나중에 들어온 데이터가 가장 먼저 나가는 자료형<br>
> - 후입 선출(LIFO)<br>
> <img src="https://user-images.githubusercontent.com/53934639/116227582-44b7f300-a78f-11eb-80c6-c8eba8a604d9.PNG" height="300px"><br><br>
> ### 연산<br>
> > 1. 삽입 연산<br>
> > > - void push(int e); // 스택에 요소 추가<br>
> > 2. 삭제 연산<br>
> > > - int pop(); // 스택에 요소 제거하고 지운 요소 값 리턴<br>
> > 3. 기타 연산<br>
> > > - bool isEmpty(); // 스택이 비어있는지 확인<br>
> > > - bool isFull();  // 스택이 가득 차있는지 확인<br>
> > > - int peek(); // 맨 위의 요소 출력<br>
<br><br><br><br>


## Queue <br>
> - 가장 먼저 들어온 데이터가 가장 먼저 나가는 자료형 <br>
> - 선입 선출(FIFO) <br>
> <img src="https://user-images.githubusercontent.com/53934639/116229189-28b55100-a791-11eb-8478-869af6402119.PNG" width="400px"><br><br>
> ### 선형 큐 <br>
> > - 배열을 사용한 선형 큐<br>
> ><img src="https://user-images.githubusercontent.com/53934639/116229921-fd7f3180-a791-11eb-9c1d-fd183a2558ec.PNG" width="400px"><br><br>
> ### 원형 큐 <br>
> > <img src="https://user-images.githubusercontent.com/53934639/116231658-20124a00-a794-11eb-9f70-320aba61c493.PNG" width="500px"><br><br>
> ### 연산<br>
> > 1. 삽입 연산<br>
> > > - void enqueue(int val);  // 큐 맨 뒤에 데이터를 추가<br>
> > 2. 삭제 연산<br>
> > > - int dequeue();  // 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴<br>
> > 3. 기타 연산<br>
> > > - bool isEmpty();  // 큐가 비었는지 확인<br>
> > > - bool isFull();  // 큐가 꽉 찼는지 확인<br>
> > > - int peek(); // 맨 앞의 데이터 리턴<br>
<br><br><br><br>


## Deque <br>
> - Double-Ended Queue<br>
> - 양쪽에서 연산이 가능한 큐<br>
> <img src="https://user-images.githubusercontent.com/53934639/116235281-9fa21800-a798-11eb-9c7c-ecce17562b31.PNG" width="500px"><br>
> <img src="https://user-images.githubusercontent.com/53934639/116236075-92395d80-a799-11eb-97d8-b94b4143f30d.PNG" width="500px"><br><br>
> ### 연산<br>
> > 1. 삽입 연산<br>
> > > - void addRear(int n);  // 큐 맨 뒤에 데이터를 추가<br>
> > > - void addFront(int n); // 큐 맨 앞에 데이터를 추가<br>
> > 2. 삭제 연산<br>
> > > - int deleteFront();  // 큐 맨 앞에서 데이터를 꺼내고 꺼낸 값 리턴<br>
> > > - int deleteRear(); // 큐 맨 뒤에서 데이터를 꺼내고 꺼낸 값 리턴<br>
> > 3. 기타 연산<br>
> > > - bool isEmpty();  // 큐가 비었는지 확인<br>
> > > - bool isFull();  // 큐가 꽉 찼는지 확인<br>
> > > - int getFront(); // 맨 앞의 데이터 리턴<br>
> > > - int getRear();  // 맨 뒤 요소를 삭제하지 않고 리턴<br>
<br><br><br><br>

## List<br>
> - 순서를 가진 데이터들의 모임 <br>
> <img src="https://user-images.githubusercontent.com/53934639/116814620-d612d500-ab94-11eb-8795-41966bfdf747.PNG" width="400px"><br>
> ### 연결리스트와 리스트의 차이 <br>
> > 1. 리스트 <br>
> > > - 특정한 "자료구조"를 의미<br>
> > > - Abstract Data Type(ADT) - 실제 구현은 다양하게 할 수 있음 (ex. 스택, 큐, 리스트..)<br>
> > 2. 연결리스트 <br>
> > > - 실제 구현된 구현체<br>
> > > - 포인터와 데이터로 구성된 노드를 이용한 구현(Implementation) (ex. 배열, 연결리스트..)<br>
> ### 구현 방법 <br>
> <img src="https://user-images.githubusercontent.com/53934639/116814870-cb0c7480-ab95-11eb-99ad-e475bec4c426.PNG" width="400px"><br>
> > 1. 배열 이용 <br>
> > > - 구현 간단, 삽입과 삭제 시 오버헤드, 항목의 수가 제한됨 <br>
> > > - 공백과 포화 상태가 존재<br>
> > > - 삽입, 삭제 위치 다음의 항목들을 이동 - O(N): 평균적으로 N/2개의 항목을 이동해야 함.<br>
> > 2. 연결리스트 이용 <br>
> > > - 구현이 복잡, 삽입과 삭제가 효율적이고 크기의 제한이 없음, 조회가 느림 <br>
> > > - O(1) - 다만 조회 연산이 느림.<br>

> ### 연산 <br>
> <img src="https://user-images.githubusercontent.com/53934639/116816129-a915f080-ab9b-11eb-9d28-86519649a723.PNG" width="400px"><br>
> > 1. 배열 통해 리스트 구현<br>
> > > - Array_List.cpp<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116815131-17a47f80-ab97-11eb-8ea2-ff1e00227e5f.PNG" width="250px" height="250px">
> > > <img src="https://user-images.githubusercontent.com/53934639/116815135-1b380680-ab97-11eb-8f4c-358fda297b27.PNG" width="250px" height = "250px"><br>
> > 2. 연결리스트 통해 리스트 구현<br>
> > > - Linkedlist_List.cpp<br>
> > > <img src ="https://user-images.githubusercontent.com/53934639/116816131-ad420e00-ab9b-11eb-8bdc-a692ae078771.PNG" width="350px" height="250px">
> > > <img src ="https://user-images.githubusercontent.com/53934639/116816133-afa46800-ab9b-11eb-816e-67b68d82fa20.PNG" width="250px" height="250px"><br>
> > > - 헤드 노드란..?<br>
> > > : 포인터 변수 head가 아닌 node 객체인 head를 사용<br>
> > > : 가상의 노드 head가 앞에 추가로 존재<br>
> > > : 맨 앞 노드의 삽입이나 삭제 연산을 단순화 할 수 있음<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116816234-08740080-ab9c-11eb-9116-e58ca9b4dca8.PNG" width="400px"><br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116816244-11fd6880-ab9c-11eb-9a9a-6f8fe9a37e7d.PNG" width="400px"><br>
<br><br><br><br>
