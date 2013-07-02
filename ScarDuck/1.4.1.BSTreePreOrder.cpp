#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：递归和非递归俩种方法实现二叉树的前序遍历
分析：
按照二叉树前序遍历的定义，无论是访问整棵树还是其子树，均应该遵循先访问根结点，
然后访问根结点的左子树，最后访问根结点的右子树的。
因为对于一棵树（子树）t,如果t 非空，访问完t 的根结点值后，就应该进入t 的左子树，
但此时必须将t 保存起来，以便访问完其左子树后，进入其右子树的访问。
yeah，就是这个意思。
即在t 处设置一个回溯点，并将该回溯点进栈保存。
在整个二叉树前序遍历的过程中，程序始终要做的工作分成俩个部分：
1.当前正在处理的树（子树）
2.保存在栈中等待处理的部分。
注：当栈中元素位于栈顶即将出栈时，意味着其根结点和左子树已访问完成，
出栈后，进入其右子树进行访问。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

struct BSTreeNode{
  int value;
  int flag;
  BSTreeNode * lchild;
  BSTreeNode * rchild;
};

void insertBSTree(BSTreeNode ** root, int value){
  BSTreeNode * newNode = new BSTreeNode();
  newNode->value = value;
  newNode->flag = 0;
  newNode->lchild = NULL;
  newNode->rchild = NULL;

  if((*root) == NULL){
    *root = newNode;
  }
  else{
    BSTreeNode * par = NULL;
    BSTreeNode * cur = *root;
    while(cur != NULL){
      par = cur;
      if(value >= cur->value){
        cur = cur->rchild;
      }
      else{
        cur = cur->lchild;
      }
    }
    if(value >= par->value){
      par->rchild = newNode;
    }
    else{
      par->lchild = newNode;
    }
  }
  return;
}

void createBSTree(BSTreeNode ** root, int * arr, int len){
  if(arr == NULL || len < 1) return;
  for(int i = 0; i < len; ++i){
    insertBSTree(root, arr[i]);
  }
  return;
}

void preOrderRecursion(BSTreeNode *root){
  if(root != NULL){
    std::cout<<root->value<<std::endl;
    preOrderRecursion(root->lchild);
    preOrderRecursion(root->rchild);
  }
  return ;
}

void preOrderNoRecursion(BSTreeNode * root){
  if(root == NULL) return;
  std::stack<BSTreeNode *> BSTreeNodeStack;
  while(root != NULL || !BSTreeNodeStack.empty()){
    while(root != NULL){
      std::cout<<root->value<<std::endl;
      BSTreeNodeStack.push(root);
      root = root->lchild;
    }
    if(!BSTreeNodeStack.empty()){
      root = BSTreeNodeStack.top();
      root = root->rchild;
      BSTreeNodeStack.pop();
    }
  }
  return ;
}

void inOrderRecursion(BSTreeNode * root){
  if(root != NULL){
    inOrderRecursion(root->lchild);
    std::cout<<"*"<<root->value<<std::endl;
    inOrderRecursion(root->rchild);
  }
  return;
}

void inOrderNoRecursion(BSTreeNode * root){
  if(root == NULL) return;
  BSTreeNode * cur = root;
  std::stack<BSTreeNode *> BSTreeNodeStack;
  while(cur != NULL || !BSTreeNodeStack.empty()){
    while(cur != NULL){
      BSTreeNodeStack.push(cur);
      cur = cur->lchild;
    }
    if(!BSTreeNodeStack.empty()){
      cur = BSTreeNodeStack.top();
      BSTreeNodeStack.pop();
      std::cout<<"*"<<cur->value<<std::endl;
      cur = cur->rchild;
    }
  }
  return;
}

void lastOrderRecursion(BSTreeNode * root){
  if(root != NULL){
    lastOrderRecursion(root->lchild);
    lastOrderRecursion(root->rchild);
    std::cout<<"**"<<root->value<<std::endl;
  }
}

void lastOrderNoRecursion(BSTreeNode * root){
  if(root == NULL) return;
  std::stack<BSTreeNode *> BSTreeNodeStack;
  BSTreeNodeStack.push(root);
  BSTreeNode * cur = NULL;
  while(!BSTreeNodeStack.empty()){
    cur = BSTreeNodeStack.top();
    if(cur->flag == 0){
      if(cur->rchild != NULL)
        BSTreeNodeStack.push(cur->rchild);
      if(cur->lchild != NULL)
        BSTreeNodeStack.push(cur->lchild);
      cur->flag = 1;
    }
    else{
      std::cout<<"**"<<cur->value<<std::endl;
      cur->flag = 0;
      BSTreeNodeStack.pop();
    }
  }
  return;
}

int main(int argc, char ** argv){
  int arr[] = {2,4,1,6,9,5,7};
  int len = sizeof(arr)/sizeof(int);
  BSTreeNode * root = NULL;
  createBSTree(&root, arr, len);

  preOrderRecursion(root);
  preOrderNoRecursion(root);

  inOrderRecursion(root);
  inOrderNoRecursion(root);

  lastOrderRecursion(root);
  lastOrderNoRecursion(root);


  system("pause");
  return 0;
}
#endif


















