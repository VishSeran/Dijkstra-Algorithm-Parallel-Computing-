#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX
// maximum number of vertices

using namespace std;

int v;
int src;
int parent[100];
int cost[100][100];
int distance_array[100];
bool visited[100] = {0};

// initializing the distance for all vertices from the source vertex
void init_distanceArray()
{
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        distance_array[i] = INF;
    }
    distance_array[src] = 0;
}

int getCloseNode()
{
    // get minimum node is 0th node and all distances are INF
    int minimumVal = INF;
    int minimumNode = 0;

    for (int i = 0; i < v; i++)
    {
        if (distance_array[i] < minimumVal && visited[i] == false)
        {
            minimumVal = distance_array[i];
            minimumNode = i;
        }
    }
    return minimumNode;
}

// initializing the dijkstra algorithm function
void dijkstra()
{
    for (int i = 0; i < v; i++)
    {
        int closet_node = getCloseNode();
        visited[closet_node] = true;

        for (int ad = 0; ad < v; ad++)
        {
            if ((cost[closet_node][ad] != INF) && (distance_array[ad] > distance_array[closet_node] + cost[closet_node][ad]))
            {
                distance_array[ad] = distance_array[closet_node] + cost[closet_node][ad];
                parent[ad] = closet_node;
            }
        }
    }
}

int main()
{
    printf("Input the number of vertices: ");
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("\nPlease input cost[%d][%d]: ", i, j);
            cin >> cost[i][j];
        }
    }

    printf("\nInput the source node numebr: ");
    cin >> src;
}
