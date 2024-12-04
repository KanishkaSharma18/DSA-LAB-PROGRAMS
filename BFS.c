#include <stdio.h>

int a[10][10], vis[10], parent[10], n;
char nodes[10];

void bfs(int v) {
    int q[10], f = 0, r = 0, u, i;
    q[r] = v;
    vis[v] = 1;
    parent[v] = -1;

    printf("%c ", nodes[v]);

    while (f <= r) {
        u = q[f];
        f++;

        for (i = 0; i < n; i++) {

            if (a[u][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                r++;
                q[r] = i;
                parent[i] = u;
                printf("%c ", nodes[i]);
            }

            else if (a[u][i] == 1 && vis[i] == 1 && parent[u] != i) {
                printf("\nCycle detected!\n");
                return;
            }
        }
    }
    printf("\n");
}

int isConnected() {
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter node labels (characters) for each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf(" %c", &nodes[i]);
    }

    printf("Enter adjacency matrix (0 or 1) :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
        parent[i] = -1;
    }

    printf("Enter source vertex (by label): ");
    char src_label;
    scanf(" %c", &src_label);

    int src_index = -1;
    for (int i = 0; i < n; i++) {
        if (nodes[i] == src_label) {
            src_index = i;
            break;
        }
    }

    if (src_index == -1) {
        printf("Invalid source vertex.\n");
        return 0;
    }

    printf("BFS Traversal starting from vertex '%c':\n", src_label);
    bfs(src_index);

    if (isConnected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }


    return 0;
}
