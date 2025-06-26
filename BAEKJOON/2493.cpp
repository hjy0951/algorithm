#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> towers(n);
    for(int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && towers[s.top()] < towers[i]) {
            s.pop();
        }
        if(!s.empty()) {
            cout << s.top() + 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
        s.push(i);
    }
    cout << '\n';
}