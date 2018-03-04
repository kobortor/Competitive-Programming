#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    
    int mn = *min_element(arr, arr + N);
    int mx = *max_element(arr, arr + N);
    if (mn + 2 == mx){
        int dist[3] = {0, 0, 0};
        int sum = 0;
        for(int a = 0; a < N; a++){
            dist[arr[a] - mn]++;
            sum += arr[a] - mn;
        }

        pii best = pii(N + 1, 0);
        for(int ones = 0; ones <= N; ones++){
            if((sum - ones) % 2){
                continue;
            }
            int twos = (sum - ones) / 2;
            if(twos < 0 || ones + twos > N){
                continue;
            }
            int cost = min(N - ones - twos, dist[0]) + min(ones, dist[1]) + min(twos, dist[2]);
            best = min(best, pii(cost, ones));
        }
        cout << best.first << "\n";
        int ones = best.second;
        int twos = (sum - ones) / 2;
        int zeros = N - ones - twos;
        while(zeros--){
            cout << mn << " ";
        }
        while(ones--){
            cout << mn + 1 << " ";
        }
        while(twos--){
            cout << mn + 2 << " ";
        }
    } else {
        cout << N << "\n";
        for(int a = 0; a < N; a++){
            cout << arr[a] << " ";
        }       
    }
}
