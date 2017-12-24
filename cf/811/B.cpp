#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//brute force method

const int MAXN = 1e4;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    while(M--){
        int L, R, X;
        cin >> L >> R >> X;
        if(X < L || X > R){
            cout << "Yes\n";
        } else {
            int num_less = 0;

            for(int a = L; a <= R; a++){
                if(arr[a] < arr[X]){
                    num_less++;
                }
            }
            cout << (num_less == X - L ? "Yes\n" : "No\n");
        }
    }
}