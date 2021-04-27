# 자료구조

## linked List<br>
> - 구조<br>
> > 1. 노드<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116224092-31a32400-a78b-11eb-9497-6d1e3f90a11b.PNG" width="500px")<br>
> > 2. 포인터
> > > - 헤드 포인터(Head) : 리스트의 첫 번째 노드<br>
> > > - 테일 포인터(Tail) : 리스트의 마지막 노드<br>
> > > <img src="https://user-images.githubusercontent.com/53934639/116224142-3f58a980-a78b-11eb-9d78-9711b70b7b82.PNG" width="500px")<br><br>

> - 장점<br>
> > 노드를 추가, 삭제 용이.<br>
> > 불연속적인 메모리 공간에 저장 가능.<br>
> > 크기를 가변적으로 쓸 수 있음.<br><br>

> - 종류<br>
> > 1. 단순(단방향) 연결 리스트(singly linked list)<br>
> > <img src="https://user-images.githubusercontent.com/53934639/116212669-06ff9e00-a780-11eb-8b47-aa4b904e8164.PNG" width="500px"><br>
> > 2. 원형 연결 리스트(circular linked list)<br>
> > <img src = "https://user-images.githubusercontent.com/53934639/116223979-0caeb100-a78b-11eb-9407-3062873a640e.PNG" width="500px">
> > 3. 이중 연결 리스트(double linked list)<br>
> > <img src ="https://user-images.githubusercontent.com/53934639/116224047-23ed9e80-a78b-11eb-823f-b542e496dd64.PNG" width="500px">
<br><br>

> - 연산<br>
> > 1. 삽입 연산 <br>
> > > void push_front(int n); // 노드를 맨 앞에 한 개 추가<br>
> > > void push_back(int n);  // 노드를 끝에 한 개 추가<br>
> > > void insert_node_at(int idx, int n);  // 정해진 위치에 노드를 추가<br>
> > 2. 삭제 연산 <br>
> > > int pop_front();  // 맨 앞의 노드를 지우고 지운 노드의 값을 리턴<br>
> > > int pop_back(); // 끝 노드를 지우고 지운 노드 값을 리턴<br>
> > > int pop_node_at(int idx); // 원하는 위치의 노드를 지우고 지운 노드의 값을 리턴<br>
> > > void remove_node(int n);  // 원하는 값과 같은 노드를 한 개 지움<br>
> > > void delete_list(); // linked list 전체를 지움<br>
> > 3. 대입 연산 및 기타 연산 <br>
> > > void replace_value_at(int idx, int n);  // 원하는 위치의 값을 입력 받은 값으로 바꿈<br>
> > > int size(); // 연결리스트의 총 길이를 리턴<br>
> > > void display_contents();  // 연결리스트의 현재 구조를 보여줌<br>
> > > int search_value(int n);  // 연결릴스트에서 원하는 값을 찾아서 그 값의 인덱스를 리턴<br>
<br><br><br>


## Stack<br>

