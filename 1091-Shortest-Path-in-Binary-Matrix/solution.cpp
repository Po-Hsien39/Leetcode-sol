// Recursive Solution
// TLE

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int shortestLength;

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        this->shortestLength = INT_MAX;
        travelMatrix(0, 0, 0, grid, -1);
        if (this->shortestLength != INT_MAX)
            return this->shortestLength;
        return -1;
    }
    void travelMatrix(int x, int y, int travelLegnth, vector<vector<int>> &grid, int prevPos)
    {
        if (grid[x][y] == 1)
            return;
        if (x == grid.size() - 1 && y == grid.size() - 1)
        {
            if (travelLegnth + 1 <= this->shortestLength)
                this->shortestLength = travelLegnth + 1;
            return;
        }
        // top
        if (x > 0 && grid[x - 1][y] == 0 && prevPos + 1 != 9)
        {
            grid[x - 1][y] = -1;
            travelMatrix(x - 1, y, travelLegnth + 1, grid, 1);
            grid[x - 1][y] = 0;
        }
        // right & top
        if (x > 0 && y < grid.size() - 1 && grid[x - 1][y + 1] == 0 && prevPos + 2 != 9)
        {
            grid[x - 1][y + 1] = -1;
            travelMatrix(x - 1, y + 1, travelLegnth + 1, grid, 2);
            grid[x - 1][y + 1] = 0;
        }
        // right
        if (y < grid.size() - 1 && grid[x][y + 1] == 0 && prevPos + 3 != 9)
        {
            grid[x][y + 1] = -1;
            travelMatrix(x, y + 1, travelLegnth + 1, grid, 3);
            grid[x][y + 1] = 0;
        }
        // right & bottom
        if (x < grid.size() - 1 && y < grid.size() - 1 && grid[x + 1][y + 1] == 0 && prevPos + 4 != 9)
        {
            grid[x + 1][y + 1] = -1;
            travelMatrix(x + 1, y + 1, travelLegnth + 1, grid, 4);
            grid[x + 1][y + 1] = 0;
        }

        // left & top
        if (x > 0 && y > 0 && grid[x - 1][y - 1] == 0 && prevPos + 5 != 9)
        {
            grid[x - 1][y - 1] = -1;
            travelMatrix(x - 1, y - 1, travelLegnth + 1, grid, 5);
            grid[x - 1][y - 1] = 0;
        }
        // left
        if (y > 0 && grid[x][y - 1] == 0 && prevPos + 6 != 9)
        {
            grid[x][y - 1] = -1;
            travelMatrix(x, y - 1, travelLegnth + 1, grid, 6);
            grid[x][y - 1] = 0;
        }
        // left & bottom
        if (x < grid.size() - 1 && y > 0 && grid[x + 1][y - 1] == 0 && prevPos + 7 != 9)
        {
            grid[x + 1][y - 1] = -1;
            travelMatrix(x + 1, y - 1, travelLegnth + 1, grid, 7);
            grid[x + 1][y - 1] = 0;
        }
        // bottom
        if (x < grid.size() - 1 && grid[x + 1][y] == 0 && prevPos + 8 != 9)
        {
            grid[x + 1][y] = -1;
            travelMatrix(x + 1, y, travelLegnth + 1, grid, 8);
            grid[x + 1][y] = 0;
        }
    }
};
