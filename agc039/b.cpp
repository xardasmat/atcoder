#include <iostream>
#include <queue>
#include <algorithm>
const int N = 200+5;

int n;
bool V[N][N];
bool C[N];
bool P[N];
int G[N];
int D[N];
int R[N];

int BFS(int v, int g)
{
    for (int i=0;i<n;++i)
        P[i] = false;
    std::queue<int> q; q.push(v);
    P[v] = true;
    C[v] = true;
    D[v] = 1;
    int max = 1;
    while (!q.empty())
    {
        int w = q.front();
        max = std::max(max, D[w]);
        G[w] = g;
        q.pop();
        for (int u=0;u<n;++u)
        {
            if (!V[w][u]) continue;
            if (P[u]) {
                if (C[u] == C[w])
                {
                    return -1;
                }
            }
            else {
                P[u] = true;
                C[u] = !C[w];
                D[u] = D[w] + 1;
                q.push(u);
            }
        }
    }
    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin >> n;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            char c;
            std::cin >> c;
            V[i][j] = c == '1';
        }
    }
    int g = 0, gg;
    for (int i=0;i<n;++i)
    {
        if (G[i] == 0) { ++g; gg = g; }
        else gg = G[i];
        int b = BFS(i, gg);
        if (b < 0)
        {
            std::cout << -1;
            return 0;
        }
        R[gg] = std::max(R[gg], b);
    }

    int result = 0;
    for (int i=0;i<n;++i)
        result += R[i];
    std::cout << result;
    return 0;
}
