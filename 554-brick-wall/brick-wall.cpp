class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        unordered_map<long long, int> edge_frequency; // Use long long for large edge positions
        int max_frequency = 0;

        for(int row = 0; row < wall.size(); row++) {
            long long edge_postion = 0; // Use long long to avoid overflow
            
            // Don't include the last brick to avoid the edge at the end of the wall
            for(int brick_no = 0; brick_no < wall[row].size() - 1; brick_no++) {
                edge_postion += wall[row][brick_no];
                edge_frequency[edge_postion]++;
                max_frequency = max(max_frequency, edge_frequency[edge_postion]);
            }
        }
        return wall.size() - max_frequency;
    }
};
