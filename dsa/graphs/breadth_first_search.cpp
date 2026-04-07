#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> & graph, int start_node) {
    int node, nextnode;
    vector<int> res;
    vector<int> visited(graph.size(), 0);
    queue<int> q;
    q.push(start_node);
    visited[start_node] = 1;
    while (q.size()){
        node = q.front();
        res.push_back(node);  q.pop();
        for(int i = 0; i < graph[node].size(); i++){
            nextnode = graph[node][i];
            if (visited[nextnode] == 0){
                visited[nextnode] =1 ;
                q.push(nextnode);
            }
        }
    }
    return res;
};
int main()
{
    vector<vector<int>> graph;
    int node = 7;
    graph.resize(node);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[1].push_back(5);
    graph[2].push_back(3);
    graph[2].push_back(5);
    graph[3].push_back(6);
    vector<int> ans = bfs(graph, 0);
    for (auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}