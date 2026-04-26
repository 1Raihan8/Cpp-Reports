#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(101);
vector<int> Dis(101, -1);
vector<int> Color(101, -1);

void inputList(int n, int e);
void BFS(int s);
void printDistance(int n);

int main(){
    int nodes, edges, source;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    inputList(nodes, edges);

    cout << "Enter the source: ";
    cin >> source;

    cout << "Path difference before BSF" << endl;
    printDistance(nodes);

    BFS(source);

    cout << "Path difference after BSF" << endl;
    printDistance(nodes);

    return 0;
}

void inputList(int n, int e){
    int u, v;
    cout << "Enter edges: " << endl;
    for(int i = 0; i < e; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << "Input complete" << endl;
}

void BFS(int s){
    int u, v;
    queue<int> Q;
    Q.push(s);
    Dis[s] = 0;
    Color[s] = 0;
    
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        
        for(int i = 0; i < G[u].size(); i++){
            v = G[u][i];
            if(Color[v] == -1){
                Q.push(v);
                Color[v] = 0;
                Dis[v] = Dis[u] + 1;
            }
        }
        Color[u] = 1;
    }
}

void printDistance(int n){
    for(int i = 1; i <= n; i++){
        cout << "The distance of " << i << " is " << Dis[i] << endl;
    }
    cout << endl;
}