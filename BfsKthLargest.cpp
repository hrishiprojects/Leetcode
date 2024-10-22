#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            ll sum = 0;
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                sum += 1LL*(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.size() < k ? -1 : pq.top();
    }
};