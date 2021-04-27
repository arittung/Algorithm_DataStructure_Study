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
<br><br><br>


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
<br><br><br>


## Queue <br>
> - 가장 먼저 들어온 데이터가 가장 먼저 나가는 <br>
> - 선입 선출(FIFO) <br>
> <img src="https://user-images.githubusercontent.com/53934639/116229189-28b55100-a791-11eb-8478-869af6402119.PNG" width="400px"><br><br>
> ### 선형 큐 <br>
> > - 배열을 사용한 선형 큐
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
> > > - int peek(); // 조회 연산<br>
<br><br><br>


