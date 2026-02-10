#include <iostream>

using namespace std;


#define VERY_FAR 9999
#define NODES 6


int findNextNode(int howFar[], bool visitedNodes[]) {
    int minVal = VERY_FAR;
    int index = -1;

    for (int i = 0; i < NODES; i++) {
        if (!visitedNodes[i] && howFar[i] <= minVal) {
            minVal = howFar[i];
            index = i;
        }
    }
    return index;
}


void myDijkstra(int graphMap[NODES][NODES], int startNode) {
    int shortDist[NODES];     
    bool done[NODES];      

    
    for (int i = 0; i < NODES; i++) {
        shortDist[i] = VERY_FAR;
        done[i] = false;
    }

    
    shortDist[startNode] = 0;

    for (int count = 0; count < NODES - 1; count++) {
        
        int u = findNextNode(shortDist, done);

        
        done[u] = true;


        for (int v = 0; v < NODES; v++) {
            
            if (!done[v] && graphMap[u][v] != 0 && shortDist[u] != VERY_FAR) {
                int newWeight = shortDist[u] + graphMap[u][v];
                if (newWeight < shortDist[v]) {
                    shortDist[v] = newWeight;
                }
            }
        }
    }

    
    cout << "Shortest distances from starting point (Node " << startNode << "):" << endl;
    for (int i = 0; i < NODES; i++) {
        cout << "Distance to Node " << i << " is: " << shortDist[i] << endl;
    }
}

int main() {
    
    
    int graphMap[NODES][NODES] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    myDijkstra(graphMap, 0);

    return 0;
}
