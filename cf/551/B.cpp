#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string A, B, C;
int cntA[26];
int cntB[26];
int cntC[26];

int tmp[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B >> C;
    for(char c : A) cntA[c - 'a']++;
    for(char c : B) cntB[c - 'a']++;
    for(char c : C) cntC[c - 'a']++;

    int best = 0;
    pii bestp = pii(0, 0);

    for(int numB = 0;; numB++){
        int numC = 1e9;
        for(int i = 0; i < 26; i++){
            int rem = cntA[i] - numB * cntB[i];
            if(rem < 0){
                numC = -1;
            } else if (cntC[i] != 0){
                numC = min(numC, rem / cntC[i]);
            }
        }
        if(numC < 0){
            break;
        }
        if(numB + numC > best){
            best = numB + numC;
            bestp = pii(numB, numC);
        }
    }

    string ans;
    for(int a = 0; a < bestp.first; a++){
        for(char c : B){
            ans += c;
            cntA[c - 'a']--;
        }
    }
    for(int a = 0; a < bestp.second; a++){
        for(char c : C){
            ans += c;
            cntA[c - 'a']--;
        }
    }

    for(int a = 0; a < 26; a++){
        while(cntA[a]--){
            ans += char(a + 'a');
        }
    }
    cout << ans;
}
