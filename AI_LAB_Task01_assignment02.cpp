#include <bits/stdc++.h>
using namespace std;

/*
Uniform Cost Search to find minimum cost path
from Main Gate to IICT
*/

vector<string> uniformCostSearch(
    unordered_map<string, vector<pair<string, int>>> &graph,
    string start,
    string goal
) {
    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > pq;

    unordered_map<string, int> dist;        
    unordered_map<string, string> parent;   

    for (auto &node : graph)
        dist[node.first] = INT_MAX;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int currentCost = current.first;
        string currentNode = current.second;

        if (currentNode == goal)
            break;

        for (auto &neighbor : graph[currentNode]) {
            string nextNode = neighbor.first;
            int edgeCost = neighbor.second;

            if (dist[nextNode] > currentCost + edgeCost) {
                dist[nextNode] = currentCost + edgeCost;
                parent[nextNode] = currentNode;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    vector<string> path;
    string node = goal;

    while (node != start) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graph;

    // edges
    graph["Main Gate"].push_back({"Library", 4});
    graph["Library"].push_back({"Main Gate", 4});

    graph["Main Gate"].push_back({"Cafeteria", 2});
    graph["Cafeteria"].push_back({"Main Gate", 2});

    graph["Library"].push_back({"Academic Building A", 5});
    graph["Academic Building A"].push_back({"Library", 5});

    graph["Cafeteria"].push_back({"Academic Building A", 8});
    graph["Academic Building A"].push_back({"Cafeteria", 8});

    graph["Cafeteria"].push_back({"Central Field", 10});
    graph["Central Field"].push_back({"Cafeteria", 10});

    graph["Academic Building A"].push_back({"IICT", 6});
    graph["IICT"].push_back({"Academic Building A", 6});

    graph["Central Field"].push_back({"IICT", 3});
    graph["IICT"].push_back({"Central Field", 3});

    graph["Library"].push_back({"Central Field", 7});
    graph["Central Field"].push_back({"Library", 7});

    string start = "Main Gate";
    string goal = "IICT";

    vector<string> resultPath = uniformCostSearch(graph, start, goal);

    cout << "Minimum Cost Path using UCS:\n";
    for (auto &node : resultPath)
        cout << node << " -> ";

    cout << "END\n";

    return 0;
}