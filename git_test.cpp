#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        for(int i=0;i<inorder.size();i++)
            index[inorder[i]]=i;
        TreeNode* ans=build(0,0,preorder.size()-1);
        return ans;
    }
private:
    vector<int> preorder;
    map<int,int> index;
    TreeNode *build(int head,int l,int r)
    {
        if(l>r)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[head]);
        int i=index[preorder[head]];
        root->left=build(head+1,l,i-1);
        root->right=build(head+i-l+1,i+1,r);
        return root;
    }
};

int main()
{
    Solution *solve;
    vector<int> arr1={3,9,20,15,7},arr2={9,3,15,20,7};
    solve->buildTree(arr1,arr2);
    for(int i=0;i<5;i++)
        cout<<i<<endl;
    getchar();
    return 0;
}