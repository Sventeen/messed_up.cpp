#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using Vertex = int; // change this as needed
using Edges = std::unordered_set<Vertex>;
using Graph = std::unordered_map<Vertex, Edges>;
using namespace std;

class graph {
    Graph g;
public:
    void addEdge(Vertex from, Vertex to) {
        g[from].insert(to);
        g[to].insert(from);
    }
    void printGraph() {
        for(auto i = g.begin(); i != g.end(); ++i) {
            cout << i->first << " : ";
            for(auto neighbour: i->second)
                cout << neighbour << "->";
            cout << "NULL\n";
        }
    }
    void DFS(Vertex value) {
        stack<Vertex> stk;
        unordered_map<Vertex, bool> isVisited;
        isVisited[value] = true;
        stk.push(value);
        while(!stk.empty()) {
            int v = stk.top();
            stk.pop();
            cout << v << " ";
            for(auto i: g[v]) {
                if (isVisited[i]) continue;
                stk.push(i);
                isVisited[i] = true;
            }
        }
        cout << "\n";
    }
    void recursiveDFS(Vertex value) {
        static unordered_map<Vertex, bool> isVisited;
        isVisited[value] = true;
        cout << value << " ";
        for(auto i: g[value]) {
            if(!isVisited[i])
                recursiveDFS(i);
        }
    }
    void BFS(Vertex value) {
        queue<Vertex> q;
        unordered_map<Vertex, bool> isVisited;
        isVisited[value] = true;
        q.push(value);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for(auto i: g[v]) {
                if (isVisited[i]) continue;
                q.push(i);
                isVisited[i] = true;
            }
        }
        cout << "\n";
    }
};

int main() {
    graph test;
    test.addEdge(1, 7);
    test.addEdge(1,2);
    test.addEdge(1, 8);
    test.addEdge(2,3);
    test.addEdge(2,6);
    test.addEdge(8,9);
    test.addEdge(8,12);
    test.addEdge(3,4);
    test.addEdge(3,5);
    test.addEdge(9,10);
    test.addEdge(9,11);
    test.printGraph();
    test.DFS(1);
    test.BFS(1);
    test.recursiveDFS(1);
    cout << "\n";
    return 0;
}