#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

static int iMap[101][101] = { 0, };
static int dist[101][101];
static int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (iMap[a][b] == 0 || iMap[a][b] > c)
        {
            iMap[a][b] = c;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (iMap[i][j])
            {
                dist[i][j] = iMap[i][j];
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}