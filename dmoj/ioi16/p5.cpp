#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int* restore_permutation(int n, int w, int r) {
    int bits = log2(n);

    string prvstr = string(n, '0');
    for(int i = 0; i < bits; i++){
        string nxtstr = string(n, '0');
        for(int a = 0; a < n; a++){
            if(a & (1 << i)){
                string str = prvstr;
                if(str[a] == '1'){
                    for(char &c : str){
                        c ^= 1;
                    }
                }
                str[a] ^= 1;
                add_element(str);
                nxtstr[a] = '1';
            }
        }
        prvstr = nxtstr;
    }

    compile_set();
    
    int *res = new int[n];
    fill(res, res + n, 0);

    fill(allof(prvstr), '0');
    for(int i = 0; i < bits; i++){
        string nxtstr = string(n, '0');
        for(int a = 0; a < n; a++){
            string str = prvstr;
            if(str[a] == '1'){
                for(char &c : str){
                    c ^= 1;
                }
            }
            str[a] ^= 1;
            if(check_element(str)){
                nxtstr[a] = '1';
                res[a] |= 1 << i;
            }
        }
        prvstr = nxtstr;
    }

    return res;
}
