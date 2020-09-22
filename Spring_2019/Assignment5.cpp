#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    int ans;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v),ans(0),left(nullptr),right(nullptr){};
};

void traversal(TreeNode *root,int& sum){
    if(!root) return;
    if(root->ans==0){
        sum += root->val;
    }
    else{
        sum += root->ans;
        return;
    }
    traversal(root->left,sum);
    traversal(root->right,sum);
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    TreeNode *root = new TreeNode(0);
    while(n--){
        string tmp;
        cin >> tmp;
        TreeNode *cur = root;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='0'){
                if(cur->left==nullptr){
                    cur->left = (i==tmp.size()-1) ?  new TreeNode(1) : new TreeNode(0);
                    cur = cur->left;
                }
                else{
                    cur->left->val += (i==tmp.size()-1 ) ?  1 : 0;
                    cur = cur->left;
                }
            }
            else if(tmp[i]=='1'){
                if(cur->right==nullptr){
                    cur->right = (i==tmp.size()-1) ?  new TreeNode(1) : new TreeNode(0);
                    cur = cur->right;
                }
                else{
                    cur->right->val += (i==tmp.size()-1) ?  1 : 0;
                    cur = cur->right;
                }
            }
        }
    }
    //traversal(root);

    cin >> n;
    while(n--){
        string tmp;
        cin >> tmp;
        TreeNode *cur = root;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='0'){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
        int res=0;
        TreeNode *t = cur;
        traversal(t,res);
        cur->ans = res;
        cout << cur->ans << "\n";
    }
    return 0;
}
