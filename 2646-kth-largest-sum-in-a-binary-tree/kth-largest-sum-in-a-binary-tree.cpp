/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    #define ll long long
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Initialize a queue for BFS
        queue<TreeNode*> q;
        q.push(root);
        
        // Priority queue to store the sums of levels in decreasing order
        priority_queue<ll> sums;
        
        // Perform BFS to compute the sum of nodes at each level
        while(!q.empty()) {
            int size = q.size();
            ll sum = 0;
            
            // Traverse each node at the current level
            while(size--) {
                auto it = q.front();
                q.pop();
                
                // Add the node's value to the current level's sum
                sum += it->val;
                
                // Push the left and right children to the queue for the next level
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            
            // Push the current level's sum to the priority queue
            sums.push(sum);
        }
        
        // Check if k is valid (k should not exceed the number of levels)
        k--;
        if(k >= sums.size()) return -1;
        
        // Pop k-1 largest sums from the priority queue to get the k-th largest
        while(k-- && !sums.empty()) {
            sums.pop();
        }
        
        // The top of the priority queue is now the k-th largest sum
        return sums.top();
    }
};