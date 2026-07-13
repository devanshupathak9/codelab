#include <iostream>
using namespace std;

class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
    }
    int Find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = this->Find(parent[node]);
    }
    void Union(int x, int y) {
        int a = this->Find(x);
        int b = this->Find(y);
        parent[b] = a;
    }
};

int main() {
    DisjointSet ds(5);
    ds.Union(1, 2);
    ds.Union(3, 4);
    ds.Union(0, 5);
    ds.Union(4, 0);
    cout << ds.Find(2) << "\n";
    return 0;
}