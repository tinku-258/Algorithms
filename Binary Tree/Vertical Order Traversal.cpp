// This function return the vertical order traversal from left to right

vector<vector<int>> vertical(TreeNode* root) {
          int mini=0;
          map<int,vector<int>> mp=levelOrder(root);
          vector<vector<int>> ans;
           for(auto& it:mp){
               ans.push_back(it.second);
           }
          return ans;
    } 
map<int,vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> ans;
        if(root==NULL) return ans;
         queue<pair<TreeNode*,int>> q;
         q.push({root,0});
          
         while(!q.empty()){
              int s=q.size();
              unordered_map<int,vector<int>> temp; //to store the vertical orders at current level
             while(s--){
                 TreeNode* node=q.front().first;
                 int col=q.front().second;
                 q.pop();
                 temp[col].push_back(node->val);

                 if(node->left){
                     q.push({node->left,col-1});
                 }

                 if(node->right){
                     q.push({node->right,col+1});
                 }
             }
            
            for(auto& it:temp){
                vector<int>& b=it.second;
                sort(b.begin(),b.end()); //to sort the values occured at same position
                vector<int>& a=ans[it.first];
                a.insert(a.end(),b.begin(),b.end()); //append to final answer
            }
         }
         return ans;
 }
