#include<iostream>
#include<vector>
using namespace std;
// 무한을 의미하는 값 : 10억 설정
#define INF 1e9 
// 노드의 최대 개수 : 100,000개
#define MAX 100001 

// 노드의 개수(n), 간선의 개수(m), 시작 노드 번호(start)
int n, m, start;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[MAX]; 

// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[MAX]; 

// 최단 거리 테이블 만들기
int d[MAX]; 

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환.
int getSmallestNode() {
    int min_value = INF;
    // 가장 최단 거리가 짧은 노드(인덱스)
    int index = 0; 

    for (int i = 1; i <= n; i++)
    {
        if (d[i] < min_value && !visited[i])
        {
            min_value = d[i];
            index = i;
        }
    }

    return index;
}

void dijkstra_list(int start){
    d[start] = 0;
    visited[start] = true;

    for (int j = 0; j < graph[start].size(); j++){
        int adjindex = graph[start][j].first;
        // 최단거리 테이블에 초기값 세팅
        d[adjindex] = graph[start][j].second; 
    }

    for (int i = 0; i < n - 1; i++){

        //  방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 확인 후 방문 표시.
        int now = getSmallestNode();
        visited[now] = true;

        for (int j = 0; j < graph[now].size(); j++)
        {
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first])
            {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main(){
    cin >> n >> m >> start;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++){
        int a, b, c;
        // a번 노드에서 b번 노드로 가는 비용이 c
        cin >> a >> b >> c;  
        graph[a].push_back({ b, c });
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 100001, INF);

    dijkstra_list(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; i++){
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF){
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else{
            cout << d[i] << '\n';
        }
    }
    return 0;
}