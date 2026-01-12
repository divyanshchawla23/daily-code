class Solution {
public:
    bool isRobotBounded(string instructions) {
        char currDir = 'N';
        pair<int, int> start = {0, 0}; // x-axis, y-axis

        for (char& ch : instructions) {

            if (ch == 'G') {

                if (currDir == 'N') {
                    start.second = start.second + 1;
                } else if (currDir == 'S') {
                    start.second = start.second - 1;
                } else if (currDir == 'E') {
                    start.first = start.first + 1;
                } else {
                    start.first = start.first - 1;
                }

            } else {

                if (ch == 'L') {
                    if (currDir == 'N') {
                        currDir = 'W';
                    } else if (currDir == 'S') {
                        currDir = 'E';
                    } else if (currDir == 'E') {
                        currDir = 'N';
                    } else {
                        currDir = 'S';
                    }
                } else {
                    if (currDir == 'N') {
                        currDir = 'E';
                    } else if (currDir == 'S') {
                        currDir = 'W';
                    } else if (currDir == 'E') {
                        currDir = 'S';
                    } else {
                        currDir = 'N';
                    }
                }
            }
        }
        if (start == pair<int, int>{0, 0} || currDir != 'N') {
            return true;
        }
        return false;
    }
};