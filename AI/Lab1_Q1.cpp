#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    string to;
    int weight;
};

// Graph represented as an adjacency list
map<string, vector<Edge>> graph = {
    {"Syracuse", {{"Buffalo", 150}, {"Philadelphia", 253}, {"Boston", 312}}},
    {"Buffalo", {{"Syracuse", 150}, {"Detroit", 256}, {"Cleveland", 189}, {"Pittsburgh", 215}}},
    {"Detroit", {{"Buffalo", 256}, {"Chicago", 283}, {"Cleveland", 169}}},
    {"Cleveland", {{"Detroit", 169}, {"Buffalo", 189}, {"Chicago", 345}, {"Columbus", 144}, {"Pittsburgh", 134}}},
    {"Chicago", {{"Detroit", 283}, {"Cleveland", 345}, {"Indianapolis", 182}}},
    {"Indianapolis", {{"Chicago", 182}, {"Columbus", 176}}},
    {"Columbus", {{"Indianapolis", 176}, {"Cleveland", 144}, {"Pittsburgh", 185}}},
    {"Pittsburgh", {{"Cleveland", 134}, {"Buffalo", 215}, {"Columbus", 185}, {"Baltimore", 247}, {"Philadelphia", 305}}},
    {"Philadelphia", {{"Syracuse", 253}, {"Pittsburgh", 305}, {"Baltimore", 101}, {"New York", 97}}},
    {"Baltimore", {{"Pittsburgh", 247}, {"Philadelphia", 101}}},
    {"New York", {{"Philadelphia", 97}, {"Providence", 181}, {"Boston", 215}}},
    {"Boston", {{"Syracuse", 312}, {"Portland", 107}, {"Providence", 50}, {"New York", 215}}},
    {"Portland", {{"Boston", 107}}},
    {"Providence", {{"Boston", 50}, {"New York", 181}}}};

void findPathsDFS(string current, string target, vector<string> &path, int cost, map<string, bool> &visited)
{
    visited[current] = true;
    path.push_back(current);

    if (current == target)
    {
        cout << "  Path: ";
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
        cout << "  |  Total Distance: " << cost << " miles" << endl;
    }
    else
    {
        for (auto &edge : graph[current])
        {
            if (!visited[edge.to])
            {
                findPathsDFS(edge.to, target, path, cost + edge.weight, visited);
            }
        }
    }

    path.pop_back();
    visited[current] = false;
}

void findPathsBFS(string start, string target)
{
    queue<pair<vector<string>, int>> q;
    q.push({{start}, 0});

    while (!q.empty())
    {
        vector<string> path = q.front().first;
        int cost = q.front().second;
        string last = path.back();
        q.pop();

        if (last == target)
        {
            cout << "  Path: ";
            for (int i = 0; i < path.size(); ++i)
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            cout << "  |  Total Distance: " << cost << " miles" << endl;
            continue;
        }

        for (auto &edge : graph[last])
        {
            if (find(path.begin(), path.end(), edge.to) == path.end())
            {
                vector<string> newPath = path;
                newPath.push_back(edge.to);
                q.push({newPath, cost + edge.weight});
            }
        }
    }
}

int main()
{
    string start = "Syracuse";
    string end = "Chicago";

    cout << "==============================\n";
    cout << "Finding all possible paths between cities" << endl;
    cout << "From: " << start << "\nTo:   " << end << endl;
    cout << "==============================\n";
    cout << "\n[DFS] Depth-First Search Results:\n";
    vector<string> path;
    map<string, bool> visited;
    findPathsDFS(start, end, path, 0, visited);
    cout << "\n[Explanation] DFS explores as far as possible along each branch before backtracking.\n";
    cout << "\n[---]-----------------------------------\n";
    cout << "[BFS] Breadth-First Search Results:\n";
    findPathsBFS(start, end);
    cout << "\n[Explanation] BFS explores all neighbors at the present depth prior to moving on to nodes at the next depth level.\n";
    cout << "==============================\n";
    return 0;
}