/*
 * C++ Program To Implement BST
 * Insert
 * Check BST or Not
 * Preorder, Postorder and Inorder Traversal
 * Author: Saroj Panda (Masters Students, University of Texas, Arlington
 */

# include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/*
 * Class Declaration
 */
class BST
{

    public:

        node * insert(node *tree, int info);
        void preorder(node *tree);
        void inorder(node *tree);
        void postorder(node *tree);
        bool checkBST(node* tree);
        void display(node *, int);
        BST()
        {

        }
};
/*
 * Main Contains Menu
 */
int main()
{
    int choice;
    BST bst;

    node *root = NULL;

    cout<<"-----------------"<<endl;
    cout<<"Operations on BST"<<endl;
    cout<<"-----------------"<<endl;

    while (1)
    {

        cout<<"\n1.Insert Element "<<endl;
        cout<<"2.Inorder Traversal"<<endl;
        cout<<"3.Preorder Traversal"<<endl;
        cout<<"4.Postorder Traversal"<<endl;
        cout<<"5.IsBST"<<endl;
        cout<<"6.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            int data;
            cout<<"Enter the number to be inserted : ";
            cin>>data;
            root = bst.insert(root, data);
            break;
        case 2:
            cout<<"Inorder Traversal of BST is:"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Checking IsBST:"<<endl;
            {
                bool isBst = bst.checkBST(root);
            if(isBst == 1)
                cout<<"Yes, Its BST "<<endl;
            else
                cout<<"No, Its not BST "<<endl;
            }

            break;

        case 6:
            return 0;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}


/*
 * Utility function to store inorder traversal of Tree data in a queue
 */
void inOrderUtil(node *tree, queue<int> &q) {

    if (tree == NULL)
    {
        return;
    }
    if (tree != NULL)
    {
        inOrderUtil(tree->left, q);
        q.push(tree->data);
        inOrderUtil(tree->right, q);
    }

}

/*
 * Checks if the tree passed is BST or not
 */
 bool BST::checkBST(node* root) {

       if(root == NULL)
           return 1;

       queue<int> myqueue;


    inOrderUtil(root, myqueue);

    int curData = myqueue.front();
    myqueue.pop();


    while (!myqueue.empty())
    {
        int nxtData = myqueue.front();
        myqueue.pop();
        cout<<"nxtData "<<nxtData<<endl;
        cout<<"curData "<<curData<<endl;

            if (nxtData <= curData)
            {
                cout<<"As nxtData >=curData rturning false "<<endl;
                return 0;
            }

            else
                curData = nxtData;
      }
    return 1;
}

/*
 * Inserting Element into the BST
 */

node * BST::insert(node *root, int info)
{
    node *newnode = new node();
    newnode->data = info;

    if (root == NULL)
    {
        root = newnode;
//        tree->info = info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added \n"<<endl;
        return root;
    }
    if (root->data == info)
    {
        cout<<"Element already in the tree \n"<<endl;
        return root;
    }
    if (root->data > info)
    {
        if (root->left != NULL)
        {
            insert(root->left, info);
	}
	else
	{
            root->left = newnode;

            (root->left)->left = NULL;
            (root->left)->right = NULL;
            cout<<"Node Added To Left \n"<<endl;
            return root;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            insert(root->right, info);
        }
        else
        {
            root->right = newnode;
            (root->right)->left = NULL;
            (root->right)->right = NULL;
            cout<<"Node Added To Right \n"<<endl;
            return root;
        }
    }
}

/*
 * Pre Order Traversal
 */
void BST::preorder(node *root)
{
    if (root == NULL)
    {
 //       cout<<"Tree is empty"<<endl;
        return;
    }
    if (root != NULL)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}
/*
 * In Order Traversal
 */
void BST::inorder(node *root)
{
    if (root == NULL)
    {
//        cout<<"Tree is empty"<<endl;
        return;
    }
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

/*
 * Postorder Traversal
 */
void BST::postorder(node *root)
{
    if (root == NULL)
    {
 //       cout<<"Tree is empty"<<endl;
        return;
    }
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}




