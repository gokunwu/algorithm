#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ����дһ�����򣬰�һ��������������ŵ���������
����:���⿼������������Ľ����������򵥵ĵݹ�ṹ��
���������㷨���һ��Ҫ���뵽�ݹ飬��Ϊ��������ǵݹ�Ķ��塣
����ѧ��ѵݹ�ĳƷǵݹ�Ҳ��һ�ֱ�Ҫ�ļ�����
�Ͼ����ݹ�����ջ���������ϵͳ�ײ�ĳ����в����ǲ�������ò�Ҫ�á�
���Ƕ�ĳЩ��ѧ���⣬��һ��Ҫѧ���õݹ�ȥ�����
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
