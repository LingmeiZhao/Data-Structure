#include "BinaryTree.h"
#include "iostream"

using namespace std;

BinaryTree::BinaryTree()
{
    this->root = nullptr;
}

void BinaryTree::Insert(int value)
{
    if (this->root == nullptr)
    {
        this->root = new BinaryTreeNode(value, nullptr, nullptr);
    }
    else
    {
        this->Insert(value, this->root);
    }
}

void BinaryTree::Insert(int value, BinaryTreeNode *current)
{
    if (value < current->value)
    {
        if (current->left == nullptr)
        {
            current->left = new BinaryTreeNode(value, nullptr, nullptr);
        }
        else
        {
            this->Insert(value, current->left);
        }
    }
    else if (value > current->value)
    {
        if (current->right == nullptr)
        {
            current->right = new BinaryTreeNode(value, nullptr, nullptr);
        }
        else
        {
            this->Insert(value, current->right);
        }
    }
    else
    {
        cout << "this value has already exist!";
    }
}

bool BinaryTree::Search(int value, BinaryTreeNode *current)
{
    if (current == nullptr)
    {
        return false;
    }
    else if (current->value > value)
    {
        return Search(value, current->left);
    }
    else if (current->value < value)
    {
        return Search(value, current->right);
    }
    else
    {
        return true;
    }
}

void BinaryTree::PreOrder(BinaryTreeNode *current)
{
    if (current != nullptr)
    {
        cout << current->value << "--";
        PreOrder(current->left);
        PreOrder(current->right);
    }
}

void BinaryTree::InOrder(BinaryTreeNode *current)
{
    if (current != nullptr)
    {
        this->InOrder(current->left);
        cout << current->value << "--";
        this->InOrder(current->right);
    }
}

void BinaryTree::PostOrder(BinaryTreeNode *current)
{
    if (current != nullptr)
    {
        PostOrder(current->left);
        PostOrder(current->right);
        cout << current->value << "--";
    }
}

BinaryTreeNode::BinaryTreeNode(int value, BinaryTreeNode *right,
                               BinaryTreeNode *left)
{
    this->value = value;
    this->right = right;
    this->left  = left;
}
