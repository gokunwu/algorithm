
#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：输入一棵二元树的根结点，求该树的深度。从根结点到叶结点依次经过的
结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
例如：输入二元树：
                                                                  10
                                                               /        /
                                                            6           14
                                                         /              /     /
                                                      4             12       16
输出该树的深度  3。
分析：这道题本质上还是考查二元树的遍历。
题目给出了一种树的深度的定义。当然，我们可以按照这种定义去得到树的所有
路径，也就能得到最长路径以及它的长度。只是这种思路用来写程序有点麻烦。
我们还可以从另外一个角度来理解树的深度。如果一棵树只有一个结点，它的深
度为1。如果根结点只有左子树而没有右子树，那么树的深度应该是其左子树的
深度加  1；同样如果根结点只有右子树而没有左子树，那么树的深度应该是其右
子树的深度加  1。如果既有右子树又有左子树呢？那该树的深度就是其左、右子
树深度的较大值再加  1。
上面的这个思路用递归的方法很容易实现，只需要对遍历的代码稍作修改即可。
*/
#include <cstdlib>
#include <iostream>

struct bTree{
  int value;
  bTree * left;
  bTree * right;
};

void createBTree(bTree * &root){
  root = new bTree;
  root->left = NULL;
  root->right = NULL;
  std::cout<<"please input the node value : "<<std::endl;
  std::cin>>root->value;
  root->value;
  if(root->value == -1){
    root = NULL;
  }
  if(root){
    createBTree(root->left);
    createBTree(root->right);
  }
}

void inorderBTree(bTree * &root){
  if(root == NULL){
    return;
  }
  inorderBTree(root->left);
  std::cout<<root->value<<std::endl;
  inorderBTree(root->right);
}

int btreeDepth(bTree * &root){
  if(root == NULL){
    return 0;
  }
  int leftDepth = 0;
  int rightDepth = 0;
  leftDepth = btreeDepth(root->left);
  rightDepth = btreeDepth(root->right);
  return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}

int main(int argc, char ** argv){
  //int arr[] = {10,6,4,-1,-1,-1,14,12,-1,-1,16,-1,-1};

  bTree * root;
  createBTree(root);
  //inorderBTree(root);
  int treeDepth = btreeDepth(root);
  std::cout<<"TreeDepth : "<<treeDepth<<std::endl;

  system("pause");
  return 0;
}

#endif
