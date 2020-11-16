class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0;
        vector<int> currPosition(2, 0); // [y, x]

        for (char inst: instructions) {
            if (inst == 'L') {
                direction += 1;
            } else if (inst == 'R') {
                direction += 3;
            } else if (inst == 'G') {
                currPosition[0] += -(direction % 4 - 1) * (direction % 2 == 0);
                currPosition[1] += (direction % 4 - 2) * (direction % 2);
            }
        }
        return (currPosition[0] == 0 && currPosition[1] == 0) || (direction % 4 != 0);
    }
};
