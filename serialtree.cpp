class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
			if (!root) {
				return result;
			}
            queue<TreeNode*> queue({ root });
			while (!queue.empty()) {
                
				TreeNode *front = queue.front();
				queue.pop();
				if (front) {
                    
					result += to_string(front->val) + ",";
                    
					queue.push(front->left);
					queue.push(front->right);
				} else {
                   
					result += "#,";
				}
			}
			return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) {
			return NULL;
		}
        
		stringstream stream(data);
		getline(stream, data, ',');
        
		TreeNode *root = new TreeNode(stoi(data));
		queue<TreeNode*> queue({ root });
		while (!queue.empty()) {
            
			TreeNode *front = queue.front();
			queue.pop();
          
			string left, right;
			getline(stream, left, ',');
			getline(stream, right, ',');
			if (left == "#") {
               
				front->left = NULL;
			} else {
                
				front->left = new TreeNode(stoi(left));
				queue.push(front->left);
			}
			if (right == "#") {
                
				front->right = NULL;
			} else {
                
				front->right = new TreeNode(stoi(right));
				queue.push(front->right);
			}
		}
		return root;
    }
};