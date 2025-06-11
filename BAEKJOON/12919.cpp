#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int answer;

void solution(string cur) {
    if(cur.length() < s.length() || answer) return;
    if(cur.length() == s.length()) {
        if(cur.compare(s) == 0) {
            answer = 1;
        }
        return;
    }

    int len = cur.length();

    if(cur[len-1] == 'A') {
        solution(cur.substr(0, len-1));
    }

    if(cur[0] == 'B') {
        string str = cur.substr(1);
        reverse(str.begin(), str.end());
        solution(str);
    }
}

int main() {
    cin >> s;
    cin >> t;

    solution(t);

    cout << answer << '\n';

    return 0;
}