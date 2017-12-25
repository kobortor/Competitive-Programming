#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[10];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }

    set<int> uniq;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < a; b++){
            uniq.insert(arr[a] + arr[b]);
        }
    }
    cout << uniq.size();
}