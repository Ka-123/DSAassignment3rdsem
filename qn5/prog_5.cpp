#include <iostream>
#include <queue>

using namespace std;

int myMatrix[20][20];
int totalNodes;

void add_link(int u, int v) {
    myMatrix[u][v] = 1;
    myMatrix[v][u] = 1;
}

void do_dfs(int current, bool seenIt[]) {
    cout << current << " ";
    seenIt[current] = true;

    for (int i = 0; i < totalNodes; i++) {
        if (myMatrix[current][i] == 1 && !seenIt[i]) {
            do_dfs(i, seenIt);
        }
    }
}

void do_bfs(int start) {
    bool seenIt[20] = {false};
    queue<int> waitingList;

    seenIt[start] = true;
    waitingList.push(start);

    while (!waitingList.empty()) {
        int current = waitingList.front();
        waitingList.pop();
        cout << current << " ";

        for (int i = 0; i < totalNodes; i++) {
            if (myMatrix[current][i] == 1 && !seenIt[i]) {
                seenIt[i] = true;
                waitingList.push(i);
            }
        }
    }
}

int main() {
    totalNodes = 5; 

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            myMatrix[i][j] = 0;
        }
    }

    add_link(0, 1);
    add_link(0, 2);
    add_link(1, 3);
    add_link(1, 4);
    add_link(2, 4);

    cout << "DFS traversal starting from 0: ";
    bool seenItOnce[20] = {false};
    do_dfs(0, seenItOnce);
    cout << endl;

    cout << "BFS traversal starting from 0: ";
    do_bfs(0);
    cout << endl;

    return 0;
}
