#include <bits/stdc++.h>
using namespace std;

/*
Uniform Cost Search (UCS)
Returns:
- Minimum cost
- Optimal path
- Total expanded nodes
*/

struct Result {
    int minCost;
    vector<string> path;
    int expandedNodes;
};

Result uniformCostSearch(
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
    unordered_set<string> visited;

    for (auto &node : graph)
        dist[node.first] = INT_MAX;

    dist[start] = 0;
    pq.push({0, start});

    int expandedCount = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int currentCost = current.first;
        string currentNode = current.second;

        if (visited.count(currentNode))
            continue;

        visited.insert(currentNode);
        expandedCount++;

        if (currentNode == goal)
            break;

        for (auto &neighbor : graph[currentNode]) {
            string nextNode = neighbor.first;
            int edgeCost = neighbor.second;

            if (!visited.count(nextNode) &&
                dist[nextNode] > currentCost + edgeCost) {

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

    return {dist[goal], path, expandedCount};
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

    Result result = uniformCostSearch(graph, start, goal);

    cout << "Minimum Cost: " << result.minCost << " minutes\n\n";

    cout << "Optimal Path:\n";
    for (auto &node : result.path)
        cout << node << " -> ";
    cout << "END\n\n";

    cout << "Total Expanded Nodes: " << result.expandedNodes << endl;

    return 0;
}