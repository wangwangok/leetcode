 #include <iostream>
 #include <vector>
 #include <stack>
 
 using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

 void preorderTree(TreeNode *head) {
     if (head == nullptr)
     {
         return;
     }
     stack<TreeNode *> node_stack;
     TreeNode *lead = head;
     while (lead)
     {
        cout<<lead->val<<endl;

        if (lead->left)
        {
            if (lead->right)
            {
                node_stack.push(lead->right);
            }
            lead = lead->left;
            continue;
        }
        if (lead->right)
        {
            lead = lead->right;
            continue;
        }
        if (node_stack.size() > 0)
        {
            lead = node_stack.top();
            node_stack.pop();
            continue;
        }
        break;
     }
 }

class Solution {
private:
    struct StackRightNode {
        int val;
        vector<int> childs;
        StackRightNode(int val, vector<int> values): val(val), childs(values){}
    };
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t preorder_size = preorder.size();
        size_t inorder_size = inorder.size();
        if (preorder_size <= 0|| inorder_size <= 0 || preorder_size != inorder_size) { return nullptr; }
        stack<StackRightNode *> right_childs_stack;
        stack<TreeNode *> node_stack;
        TreeNode *head = nullptr;
        TreeNode *current = head;
        vector<int> inorder_temp(inorder);
        for (vector<int>::iterator itr = preorder.begin(); itr != preorder.end(); ++itr) 
        {
            size_t index = 0;
            TreeNode **hope;
            if (inorder_temp.size() <= 0)
            {
                break;
            }
            for(vector<int>::iterator in_itr = inorder_temp.begin(); in_itr != inorder_temp.end(); ++in_itr) 
            {
                size_t idx = in_itr - inorder_temp.begin();
                if (*itr == *in_itr)
                {
                    index = idx;
                    break;
                }
            }
            int root_val = inorder_temp[index];
            TreeNode *node = new TreeNode(root_val);
            if (head == nullptr)
            {
                head = node;
                current = head;
            }
            else
            {
                if (hope)
                {
                    *hope = node;
                }
                current = node;
            }
            
            vector<int> left_childs(inorder_temp.begin(), inorder_temp.begin()+index);
            vector<int> right_childs(inorder_temp.begin()+index+1, inorder_temp.end());
            if (left_childs.size() > 0)
            {
                inorder_temp = left_childs;
                hope = &(current->left);
                if (right_childs.size() > 0) {
                    StackRightNode *snode = new StackRightNode(*itr, right_childs);
                    right_childs_stack.push(snode);
                }
                else
                {
                    current->right = nullptr;   
                }
                node_stack.push(node);
                continue;
            }
            if (right_childs.size() > 0)
            {
                current->left = nullptr;
                inorder_temp = right_childs;
                hope = &(current->right);
                node_stack.push(node);
                continue;
            }
            if (right_childs_stack.size() <= 0)
            {
                break; /// 扫描完成
            }
            while(node_stack.size() > 0) {
                TreeNode *t_node = node_stack.top();
                StackRightNode *s_node = right_childs_stack.top();
                current = t_node;
                node_stack.pop();
                if (t_node->val == s_node->val)
                {
                    inorder_temp = (right_childs_stack.top())->childs;
                    hope = &(current->right);
                    right_childs_stack.pop();
                    
                    break;
                }
            }
        }
        return head;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    //vector<int> preorder{3,9,20,15,7};
    //vector<int> inorder{9,3,15,20,7};
    vector<int> preorder{};
    vector<int> inorder{};
    TreeNode *head = s.buildTree(preorder, inorder);
    preorderTree(head);
    return 0;
}