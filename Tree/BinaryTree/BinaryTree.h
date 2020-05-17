#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _bTreeNode
{
    Data data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

typedef void (*VisitFuncPtr)(Data data);


BTreeNode *MakeTreeNode();
Data GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, Data data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
void DeleteTree(BTreeNode *bt);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

#endif