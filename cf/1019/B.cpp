#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int query(int x){
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

void answer(int x){
    cout << "! " << x << endl;
    exit(0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    if(N % 4 == 2){
        answer(-1);
        return 0;
    }

    int va = query(1);
    int vb = query(1 + N / 2);

    if(va == vb){
        answer(1);
    }

    int lo = 1, hi = N / 2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int qa = query(mid);
        int qb = query(mid + N / 2);

        if(qa == qb){
            answer(mid);
        }

        if((va < vb) == (qa < qb)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}
