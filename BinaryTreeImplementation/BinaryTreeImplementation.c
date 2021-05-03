
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data ;
    struct Node * left ;
    struct Node * right;
};

struct Node * CreateNewNode(int data)
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL)
    {
        printf("there is node space to create anew node :");
        return node ;
    }
    node->data = data;
    node->left = node->right=NULL;
    return node ;
}


struct Node * InsertNewNode(int data, struct Node * root)
{
    struct Node * temp = root;
    if(temp == NULL)
    {
    temp=CreateNewNode(data); 
    return temp;
    }
    if(temp->data >= data)
    {
    temp->left=InsertNewNode(data,temp->left);
    }
    else 
    {
    temp->right=InsertNewNode(data,temp->right);
    }
    return temp;

}

void InorderTraversal(struct Node * root)
{
    if(root == NULL)
    return;
    InorderTraversal(root->left);
    printf("%d  ",root->data);
    InorderTraversal(root->right);
    
}

void PreorderTraversal(struct Node * root)
{
    if(root == NULL)
    return;
    printf("%d  ",root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}


void PostorderTraversal(struct Node * root)
{
    if(root == NULL)
    return;
    
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d  ",root->data);
}

bool CheckIsFullBinary(struct Node * root)
{
    if(root==NULL)
    return true;
    if((root->left==NULL)&&(root->right==NULL)) // check zero child 
    return true;
    if((root->left)&&(root->right))
    return (CheckIsFullBinary(root->left)&&CheckIsFullBinary(root->right));
    
    return false;
}
// Check if the tree is a complete binary tree
bool checkComplete(struct Node *root, int index, int numberNodes) {
  // Check if the tree is complete
  if (root == NULL)
    return true;

  if (index >= numberNodes)
    return false;

  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main()
{
    
    

    return 0;
}



