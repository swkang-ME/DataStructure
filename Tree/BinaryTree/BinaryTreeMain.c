#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
    BTreeNode *bt1 = MakeTreeNode();
    BTreeNode *bt2 = MakeTreeNode();
    BTreeNode *bt3 = MakeTreeNode();
    BTreeNode *bt4 = MakeTreeNode();
    BTreeNode *bt5 = MakeTreeNode();
    BTreeNode *bt6 = MakeTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);

    printf("Binary Tree Data 확인\n");
    printf("%d \n", GetData(GetLeftSubTree(bt1)));
    printf("%d \n",GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    printf("Binary Tree Inorder Traversal\n");
    PreorderTraverse(bt1, ShowIntData);
    printf("\n");
    InorderTraverse(bt1, ShowIntData);
    printf("\n");
    PostorderTraverse(bt1, ShowIntData);
    printf("\n");

    DeleteTree(bt1);

    return 0;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}