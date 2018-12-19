//Problem        : Base Arithmetic
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int val(char c){
    if(isalpha(c)){
        return 10 + (c - 'A');
    } else {
        return c - '0';
    }
}

int min_base(string s){
    int minb = 0;
    for(char c : s){
        minb = max(minb, val(c));
    }
    return minb + 1;
}

long long conv(string s, int base){
    long long power = 1;
    long long ans = 0;
    while(!s.empty()){
        ans += val(s.back()) * power;
        s.pop_back();
        power *= base;
    }
    return ans;
}

int main() {
    string X, Y;
    cin >> X >> Y;

    cout << conv(X, min_base(X)) + conv(Y, min_base(Y));
}


