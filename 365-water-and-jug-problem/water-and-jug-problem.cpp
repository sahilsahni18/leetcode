class Solution {
public:
    bool dfs(int tot, int jug1, int jug2, int jug, int target,vector<int> &vis ){
        if(jug>tot || jug<0 || vis[jug]==1){
            return false;
        }
        vis[jug]=1;
        if(jug==target){
            return true;
        }
         bool a = dfs(tot, jug1, jug2, jug+jug1, target, vis);
        bool b = dfs(tot, jug1, jug2, jug-jug1, target, vis);
        bool c = dfs(tot, jug1, jug2, jug+jug2, target, vis);
        bool d = dfs(tot, jug1, jug2, jug-jug2, target, vis);
        return a||b||c||d;
            }
    bool canMeasureWater(int x, int y, int target) {
        int tot = x+y;
        vector<int>vis(tot+1, 0);
        return dfs(tot, x,y, 0, target, vis);
    }
};