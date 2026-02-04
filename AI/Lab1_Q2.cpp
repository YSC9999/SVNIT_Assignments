#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> network = {
    {"Rahul", {"Arjun_Bottom", "Arjun_Right", "Maya", "Neha_Center", "Pooja", "Sneha"}},
    {"Arjun_Bottom", {"Rahul", "Maya", "Pooja"}},
    {"Arjun_Right", {"Rahul", "Aarav", "Neha_Right"}},
    {"Maya", {"Rahul", "Arjun_Bottom", "Sunil"}},
    {"Neha_Center", {"Rahul", "Akash", "Priya"}},
    {"Pooja", {"Rahul", "Arjun_Bottom", "Aarav", "Neha_Right"}},
    {"Sneha", {"Rahul", "Sunil", "Neha_Center"}},
    {"Aarav", {"Arjun_Right", "Pooja", "Priya", "Neha_Right"}},
    {"Neha_Right", {"Arjun_Right", "Aarav", "Pooja", "Arjun_Right"}},
    {"Sunil", {"Maya", "Sneha", "Raj", "Akash"}},
    {"Akash", {"Neha_Center", "Sunil", "Raj", "Priya"}},
    {"Priya", {"Neha_Center", "Akash", "Aarav", "Raj"}},
    {"Raj", {"Sunil", "Akash", "Priya"}}
};

void printBFSTree(string start) {
    set<string> visited;
    queue<pair<string, string>> q;

    q.push({start, "None"});
    visited.insert(start);

    cout << "--- BFS Tree (Root: " << start << ") ---\n";
    while (!q.empty()) {
        string curr = q.front().first;
        string parent = q.front().second;
        q.pop();

        if (parent != "None") {
            cout << parent << " -> " << curr << endl;
        }

        vector<string> neighbors = network[curr];
        sort(neighbors.begin(), neighbors.end());

        for (string neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, curr});
            }
        }
    }
}

void printDFSTree(string curr, string parent, set<string>& visited) {
    visited.insert(curr);
    if (parent != "None") {
        cout << parent << " -> " << curr << endl;
    }

    vector<string> neighbors = network[curr];
    sort(neighbors.begin(), neighbors.end());

    for (string neighbor : neighbors) {
        if (visited.find(neighbor) == visited.end()) {
            printDFSTree(neighbor, curr, visited);
        }
    }
}

int main() {
    string startNode = "Rahul";

    printBFSTree(startNode);

    cout << "\n--- DFS Tree (Root: " << startNode << ") ---\n";
    set<string> visitedDFS;
    printDFSTree(startNode, "None", visitedDFS);

    return 0;
}