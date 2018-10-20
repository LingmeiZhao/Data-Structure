#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTreeNode
{
  public:
    int value;
    BinaryTreeNode *right;
    BinaryTreeNode *left;
    BinaryTreeNode(int value, BinaryTreeNode *right, BinaryTreeNode *left);
};

class BinaryTree
{
  public:
    BinaryTreeNode *root;
    BinaryTree();
    ~BinaryTree();

    void Insert(int value);

    void Insert(int value, BinaryTreeNode *current);
    bool Search(int value, BinaryTreeNode *current);
    void PreOrder(BinaryTreeNode *current);
    void InOrder(BinaryTreeNode *current);
    void PostOrder(BinaryTreeNode *current);
};

#endif
// BINARYTREE_H
