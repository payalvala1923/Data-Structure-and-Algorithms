int finddiameter(TreeNode* root, int &d) {

        if(root == NULL) return 0; 

        int lh = finddiameter(root->left,d); 
        int rh = finddiameter(root->right,d); 

		d=max(d,lh+rh);

        return 1 + max(lh, rh); 
    }
public:

    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        finddiameter(root,d);
        return d;
    }
