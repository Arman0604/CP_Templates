// function to find Lowest Common Ancestor
Node* LCA(Node* root, int p, int q) {

    // base case
    if(root == NULL)
        return NULL;

    // if current node matches p or q
    if(root->data == p || root->data == q)
        return root;

    // search in left subtree
    Node* left = LCA(root->left, p, q);

    // search in right subtree
    Node* right = LCA(root->right, p, q);

    // if both sides return non-null, current node is LCA
    if(left != NULL && right != NULL)
        return root;

    // otherwise return the non-null child
    if(left != NULL)
        return left;
    else
        return right;
}
