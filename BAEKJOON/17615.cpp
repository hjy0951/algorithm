#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    int totalRed = 0, totalBlue = 0;
    int startRed = 0, startBlue = 0, endRed = 0, endBlue = 0;

    if (str[0] == 'R') {
        totalRed++;
        startRed++;
    } else {
        totalBlue++;
        startBlue++;
    }

    bool isInStartSequence = true;

    for (int i = 1; i < n; i++) {
        if (str[i] == 'R') {
            totalRed++;
        } else {
            totalBlue++;
        }

        if (isInStartSequence) {
            if (str[i] == str[0]) {
                if (str[0] == 'R') {
                    startRed++;
                } else {
                    startBlue++;
                }
            } else {
                isInStartSequence = false;
                if (str[i] == 'R') {
                    endRed++;
                } else {
                    endBlue++;
                }
            }
        } else {
            if (str[i] == 'R') {
                endBlue = 0;
                endRed++;
            } else {
                endRed = 0;
                endBlue++;
            }
        }
    }

    // 최소 이동 횟수 계산
    int minMoves = min({
        totalRed - startRed,
        totalBlue - startBlue,
        totalRed - endRed,
        totalBlue - endBlue
    });

    cout << minMoves << '\n';

    return 0;
}