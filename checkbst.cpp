/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

bool checkBSTleft(Node * root, int star)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right != NULL)
    {
        if (root->right->data > root->data && root->right->data < star)
        {
            return checkBSTleft(root->right,star);
        }
        else
        {
            return false;
        }
    }
    if (root->left != NULL && root->right == NULL)
    {
        if (root->left->data < root->data && root->left->data < star)
        {
            return checkBSTleft(root->left,root->data);
        }
        else
        {
            return false;
        }
    }
    if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
    if (root->left->data < root->data && root->right->data > root->data && root->right->data < star)
    {
        return checkBSTleft(root->left,root->data) && checkBSTleft(root->right,star);
    }
    return false;
    
    
}

bool checkBSTright(Node * root, int star)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right != NULL)
    {
        if (root->right->data > root->data && root->right->data > star)
        {
            return checkBSTright(root->right,root->data);
        }
        else
        {
            return false;
        }
    }
    if (root->left != NULL && root->right == NULL)
    {
        if (root->left->data < root->data && root->left->data > star)
        {
            return checkBSTright(root->left,star);
        }
        else
        {
            return false;
        }
    }
    if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
    if (root->left->data < root->data && root->right->data > root->data && root->left->data > star)
    {
        return checkBSTright(root->left,star) && checkBSTright(root->right,root->data);
    }
    return false;
}

	bool checkBST(Node* root) {
        
        if (root == NULL)
        {
            return true;
        }
        if (root->left == NULL && root->right != NULL)
        {
            if (root->right->data > root->data)
            {
                return checkBSTright(root->right,root->data);
            }
            else
            {
                return false;
            }
        }
        if (root->left != NULL && root->right == NULL)
        {
            if (root->left->data < root->data)
            {
                return checkBSTleft(root->left,root->data);
            }
            else
            {
                return false;
            }
        }
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        if (root->left->data < root->data && root->right->data > root->data)
        {
            return checkBSTleft(root->left,root->data) && checkBSTright(root->right,root->data);
        }
        return false;
		
	}
