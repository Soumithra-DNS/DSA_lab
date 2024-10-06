#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int inf = 1e9 + 10;
int dist[N][N];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int val; cin >> val;
            dist[i][j] = val;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                dist[i][j] = 0;
            else if(dist[i][j] == 0)
                dist[i][j] = inf;
        }
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != inf && dist[j][k] != inf)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
}