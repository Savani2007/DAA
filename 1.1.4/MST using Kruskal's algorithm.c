#include <stdio.h>
            if (cost[i][j] != 9999) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
	}
 for (int i = 1; i < edgeCount; i++) {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }

    int *parent = (int *)malloc(V * sizeof(int));
    int *rnk = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
int mstEdgeCount = 0;
    int minCost = 0;

    for (int i = 0; i < edgeCount && mstEdgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            printf("Edge %d:(%d, %d) cost:%d\n", mstEdgeCount, u, v, w);
            minCost += w;
            unionSet(parent, rnk, setU, setV);
            mstEdgeCount++;
        }
	}
printf("Minimum cost= %d\n", minCost);

    free(parent);
    free(rnk);
    free(edges);
}
int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
