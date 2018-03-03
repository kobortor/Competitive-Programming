#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
class median_queue{
public:
    void push(const T &val){
        if(lower.size() == upper.size()){
            lower.push(val);
        } else {
            upper.push(val);
        }
        while(!upper.empty() && lower.top() > upper.top()){
            upper.push(lower.top());
            lower.push(upper.top());

            upper.pop();
            lower.pop();
        }
    }
    const T& peek_lower(){
        assert(!lower.empty());
        return lower.top();
    }
    const T& peek_upper(){
        assert(!lower.empty());
        if(lower.size() == upper.size()){
            return upper.top();
        } else {
            return lower.top();
        }
    }
    void pop_lower(){
        assert(!lower.empty());
        lower.pop();
        while(upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    void pop_upper(){
        assert(!lower.empty());
        if(lower.size() == upper.size()){
            upper.pop();
        } else {
            lower.pop();
        }
        while(upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    size_t size(){
        return lower.size() + upper.size();
    }
    bool empty(){
        return lower.empty();
    }
    
private:
    priority_queue<T> lower;
    priority_queue<T, vector<T>, greater<T>> upper;
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    //notice that at the end, popping lower gives 3 3 while popping upper gives 1 1

    median_queue<int> mq1;
    mq1.push(1);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    mq1.push(3);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    mq1.push(2);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    
    while(!mq1.empty()){
        cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
        mq1.pop_lower();
    }

    cout << "---" << endl;
    mq1.push(1);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    mq1.push(3);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    mq1.push(2);
    cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
    
    while(!mq1.empty()){
        cout << mq1.peek_lower() << " " << mq1.peek_upper() << endl;
        mq1.pop_upper();
    }
}
