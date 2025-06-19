#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
int h, w;
vector<int> blocks;

void solution() {
    vector<int> leftMax(w), rightMax(w);

    leftMax[0] = blocks[0];
    for(int i = 1; i < w; i++) {
        leftMax[i] = max(leftMax[i-1], blocks[i]);
    }

    rightMax[w-1] = blocks[w-1];
    for(int i = w-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], blocks[i]);
    }

    for(int i = 0; i < w; i++) {
        int height = min(leftMax[i], rightMax[i]);
        if(blocks[i] < height) {
            ans += height - blocks[i];
        }
    }
}

int main() {
    cin >> h >> w;
    for(int i = 0, num ; i < w ; i++) {
        cin >> num;
        blocks.push_back(num);
    }
    solution();
    cout << ans << '\n';
    return 0;
}