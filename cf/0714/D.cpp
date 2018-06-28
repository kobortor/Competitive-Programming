#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int ask(int x1, int y1, int x2, int y2){
    cout << "? ";
    cout << x1 << " ";
    cout << y1 << " ";
    cout << x2 << " ";
    cout << y2 << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector<int> output;

void solve1(int x1, int y1, int x2, int y2){
    int lo, hi;
    lo = x1, hi = x2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(mid, y1, x2, y2);
        if(ans == 1){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    x1 = lo - 1;

    lo = x1, hi = x2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(x1, y1, mid, y2);
        if(ans == 1){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    x2 = hi + 1;

    lo = y1, hi = y2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(x1, mid, x2, y2);
        if(ans == 1){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    y1 = lo - 1;

    lo = y1, hi = y2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(x1, y1, x2, mid);
        if(ans == 1){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    y2 = hi + 1;
    output.push_back(x1);
    output.push_back(y1);
    output.push_back(x2);
    output.push_back(y2);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    int lo = 1, hi = N;
    //search top-down first
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(1, 1, N, mid);
        
        if (ans == 0){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int v0 = lo;

    lo = lo + 1, hi = N;
    //search top-down first
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(1, mid, N, N);
        
        if (ans == 0){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int v1 = hi;

    if(v0 < v1){
        solve1(1, 1, N, v0);
        solve1(1, v1, N, N);
        cout << "! ";
        for(int i : output){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }

    lo = 1, hi = N;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ans = ask(1, 1, mid, N);

        if (ans == 0){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    solve1(1, 1, lo, N);
    solve1(lo + 1, 1, N, N);
    cout << "! ";
    for(int i : output){
        cout << i << " ";
    }
    cout << endl;
}
