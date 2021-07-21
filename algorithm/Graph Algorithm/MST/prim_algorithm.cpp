#include <iostream>
#include <vector>

using namespace std;


const int MAX_V = 100;
const int INF = 987654321;

int V = 6;



int prim(vector<pair<int, int> >& selected, vector<pair<int, int> > adj[MAX_V]) {
    //selected.clear();

    vector<bool> added(V, false);   // 현재 트리에 어떤 정점이 있는지 체크
    vector<int> minWeight(V, INF);  // 트리에 붙어있는 정점중 가장 가까운 정점
    vector<int> parent(V, -1);  // 정점의 부모

    int ret = 0;    // 최소 스패닝 트리의 모든 간선 값.
    minWeight[0] = parent[0] = 0;

    // 모든 정점까지 반복하는 roop
    for (int i = 0; i < V; i++) {
        int u = -1;
        // u 부모가 u가 아니라면 u의 부모와 u로 구성된 정점 쌍을 selected에 저장.
        for (int v = 0; v < V; v++) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        }

        if (parent[u] != u)
            selected.push_back(make_pair(parent[u], u));

        ret += minWeight[u];
        added[u] = true;

        for (int j = 0; j < adj[u].size(); j++) {

            int v = adj[u][j].first;
            int weight = adj[u][j].second;

            if (!added[v] && minWeight[v] > weight) {

                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}

int main() {
    vector<pair<int, int> > adj[MAX_V];

    // 0-1 연결시 weight 5
    adj[0].push_back(make_pair(1, 5));
    adj[1].push_back(make_pair(0, 5));

    adj[1].push_back(make_pair(2, 3));
    adj[2].push_back(make_pair(1, 3));

    adj[2].push_back(make_pair(3, 4));
    adj[3].push_back(make_pair(2, 4));

    adj[1].push_back(make_pair(4, 3));
    adj[4].push_back(make_pair(1, 3));

    adj[0].push_back(make_pair(3, 7));
    adj[3].push_back(make_pair(0, 7));

    adj[2].push_back(make_pair(4, 2));
    adj[4].push_back(make_pair(2, 2));

    adj[3].push_back(make_pair(5, 1));
    adj[5].push_back(make_pair(3, 1));

    adj[4].push_back(make_pair(5, 4));
    adj[5].push_back(make_pair(4, 4));

    vector<pair<int, int> > selected;

    int mst = prim(selected, adj);

    cout << "mst : " << mst << endl;

    for (int i = 0; i < selected.size(); i++) {

        cout << selected[i].first << " - " << selected[i].second << endl;
    }
    cout << endl;
    
    return 0;
}