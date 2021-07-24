#include<iostream>
#include<vector>
using namespace std;
// ������ �ǹ��ϴ� �� : 10�� ����
#define INF 1e9 
// ����� �ִ� ���� : 100,000��
#define MAX 100001 

// ����� ����(n), ������ ����(m), ���� ��� ��ȣ(start)
int n, m, start;

// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int> > graph[MAX]; 

// �湮�� ���� �ִ��� üũ�ϴ� ������ �迭 �����
bool visited[MAX]; 

// �ִ� �Ÿ� ���̺� �����
int d[MAX]; 

// �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ.
int getSmallestNode() {
    int min_value = INF;
    // ���� �ִ� �Ÿ��� ª�� ���(�ε���)
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
        // �ִܰŸ� ���̺� �ʱⰪ ����
        d[adjindex] = graph[start][j].second; 
    }

    for (int i = 0; i < n - 1; i++){

        //  �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� Ȯ�� �� �湮 ǥ��.
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

    // ��� ���� ������ �Է¹ޱ�
    for (int i = 0; i < m; i++){
        int a, b, c;
        // a�� ��忡�� b�� ���� ���� ����� c
        cin >> a >> b >> c;  
        graph[a].push_back({ b, c });
    }

    // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
    fill_n(d, 100001, INF);

    dijkstra_list(start);

    // ��� ���� ���� ���� �ִ� �Ÿ��� ���
    for (int i = 1; i <= n; i++){
        // ������ �� ���� ���, ����(INFINITY)�̶�� ���
        if (d[i] == INF){
            cout << "INFINITY" << '\n';
        }
        // ������ �� �ִ� ��� �Ÿ��� ���
        else{
            cout << d[i] << '\n';
        }
    }
    return 0;
}