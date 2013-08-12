#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：编写一个程序，把一个有序整数数组放到二叉树中
分析:本题考察二叉搜索树的建树方法，简单的递归结构。
关于树的算法设计一定要联想到递归，因为树本身就是递归的定义。
而，学会把递归改称非递归也是一种必要的技术。
毕竟，递归会造成栈溢出，关于系统底层的程序中不到非不得以最好不要用。
但是对某些数学问题，就一定要学会用递归去解决。
*/
#include <cstdlib>
#include <iostream>

struct BTree{
  int value;
  BTree * left;
  BTree * right;
};

void array2tree(int * arr, int len, BTree ** root)
{
  if(arr == NULL || len < 1){
    return;
  }
  *root = new BTree();
  (*root)->value = arr[len/2];
  (*root)->left = NULL;
  (*root)->right = NULL;
  array2tree(arr, len/2, &((*root)->left));
  array2tree(arr+len/2+1, len - len/2 - 1, &((*root)->right));
}

void inorderWalk(BTree ** root){
  if(*root == NULL){
    return;
  }
  inorderWalk(&((*root)->left));
  std::cout<<(*root)->value<<std::endl;
  inorderWalk(&((*root)->right));
}

int main(int argc, char ** argv)
{
  int arr[] = {7,10,2,6,19,22,32};
  int len = sizeof(arr)/sizeof(arr[0]);
  BTree * root = NULL;
  array2tree(arr, len, &root);
  inorderWalk(&root);

  system("pause");
  return 0;
}
#endif
