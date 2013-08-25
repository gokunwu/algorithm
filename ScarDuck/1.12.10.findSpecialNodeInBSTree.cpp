#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：一棵排序二叉树，令 f=(最大值+最小值)/2， 设计一个算法，找出距离f值最近、大于f值的结点。
*/
#include <cstdlib>
#include <iostream>

struct BSTree{
  int value;
  BSTree * left;
  BSTree * right;
};

void BSTreeInsert(BSTree ** root, int value)
{
  BSTree * newnode = new BSTree();
  newnode->value = value;
  newnode->left = NULL;
  newnode->right = NULL;
  BSTree * pcur = *root;
  BSTree * pparent = NULL;
  if(*root == NULL){//deal with the first node
    *root = newnode;
    return;
  }
  while(pcur != NULL){
    pparent = pcur;
    if(value < pcur->value){
      pcur = pcur->left;
    }
    else{
      pcur = pcur->right;
    }
  }
  if(value < pparent->value){
    pparent->left = newnode;
  }
  else{
    pparent->right = newnode;
  }
}

void createBSTree(int arr[], int len, BSTree ** root)
{
  if(arr == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    BSTreeInsert(root, arr[i]);
  }
}

void inorderWalk(BSTree ** root)
{
  if(*root == NULL){
    return;
  }
  inorderWalk(&((*root)->left));
  std::cout<<(*root)->value<<std::endl;
  inorderWalk(&((*root)->right));
}

int maxInBSTree(BSTree ** root)
{
  if(*root == NULL){
    return -1;
  }
  BSTree * pcur = *root;
  BSTree * pparent = NULL;
  while(pcur != NULL){
    pparent = pcur;
    pcur = pcur->right;
  }
  if(pparent != NULL){
    return pparent->value;
  }
  else{
    return -1;
  }
}

int minInBSTree(BSTree ** root)
{
  if(*root == NULL){
    return -1;
  }
  BSTree * pcur = *root;
  BSTree * pparent = NULL;
  while(pcur != NULL){
    pparent = pcur;
    pcur = pcur->left;
  }
  if(pparent != NULL){
    return pparent->value;
  }
  else{
    return -1;
  }
}

BSTree * findSpecialNode(BSTree ** root)
{
  if(*root == NULL){
    return NULL;
  }
  int min = minInBSTree(root);
  int max = maxInBSTree(root);
  int value = (min+max)/2;
  BSTree * pcur = *root;
  BSTree * pparent = NULL;
  while(pcur != NULL){
    pparent = pcur;
    if(value > pcur->value){
      pcur = pcur->right;
    }
    else if(value < pcur->value){
      if(pcur->left != NULL && pcur->left->value > value){
        pcur = pcur->left;
      }
      else{
        return pcur;
      }
    }
  }
  return NULL;
}

int main(int argc, char ** argv)
{
  int arr[] = {6,4,3,5,10,8,9,11};
  int len = sizeof(arr)/sizeof(int);
  BSTree * root = NULL;
  createBSTree(arr, len, &root);
  inorderWalk(&root);
  int ret = maxInBSTree(&root);
  std::cout<<ret<<std::endl;
  ret = minInBSTree(&root);
  std::cout<<ret<<std::endl;
  BSTree * pnode = findSpecialNode(&root);
  if(pnode == NULL){
    std::cout<<"NULL"<<std::endl;
  }
  else{
    std::cout<<pnode->value<<std::endl;
  }
  system("pause");
  return 0;
}
#endif
