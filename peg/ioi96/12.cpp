#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXM = 35;

int N, M1, M2;
int A[MAXN], B[MAXN];

int finishA[MAXN * 20];
int finishB[MAXN * 20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    cin >> M1;
    for(int a = 1; a <= M1; a++){
        cin >> A[a];
    }

    cin >> M2;
    for(int a = 1; a <= M2; a++){
        cin >> B[a];
    }

    for(int a = 1; a <= M1; a++){
        for(int b = A[a]; b < MAXN * 20; b += A[a]){
            finishA[b]++;
        }
    }

    int ansA;
    for(int a = 1; a < MAXN * 20; a++){
        N -= finishA[a];
        if(N <= 0){
            finishA[a] += N;
            fill(finishA + a + 1, finishA + MAXN * 20, 0);
            ansA = a;
            break;
        }
    }

    int lo = ansA + 1, hi = MAXN * 20 - 1;
    while(lo <= hi){
        memset(finishB, 0, sizeof finishB);

        int mid = (lo + hi) / 2;
        for(int a = 1; a <= M2; a++){
            for(int b = mid - B[a]; b >= 0; b -= B[a]){
                finishB[b]++;
            }
        }

        bool good = true;
        for(int a = mid, cur = 0; a >= 0; a--){
            cur += finishB[a] - finishA[a];
            if(cur < 0){
                good = false;
                break;
            }
        }

        if(good){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ansA << "\n" << lo << "\n";
}
