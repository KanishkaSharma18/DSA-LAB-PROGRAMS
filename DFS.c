#include <stdio.h>

int a[10][10], vis[10], parent[10], n;
char nodes[10];


int dfs(int v)
{
    vis[v] = 1;
    printf("%c ", nodes[v]);

    for (int j = 0; j < n; j++)
    {

        if (a[v][j] == 1 && vis[j] == 0)
        {
            parent[j] = v;
            if (dfs(j))
                return 1;
        }

        else if (a[v][j] == 1 && vis[j] == 1 && parent[v] != j)
        {
            printf("\nCycle detected!\n");
            return 1;
        }
    }
    return 0;
}


int isConnected()
{
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the characters for the nodes (e.g., A, B, C, etc.):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf(" %c", &nodes[i]);
    }

    printf("Enter adjacency matrix (0 or 1) :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
        parent[i] = -1;
    }

    printf("DFS Traversal: ");


    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i))
            {
                break;
            }
        }
    }


    if (isConnected())
    {
        printf("\nThe graph is connected.\n");
    }
    else
    {
        printf("\nThe graph is not connected.\n");
    }

    return 0;
}

