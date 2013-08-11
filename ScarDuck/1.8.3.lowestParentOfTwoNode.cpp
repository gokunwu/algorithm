#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���������Ľ�㶨�����£�
struct TreeNode
{
     int m_nvalue;
     TreeNode* m_pLeft;
     TreeNode* m_pRight;
};
����������е�������㣬��������������������͵Ĺ�ͬ����㡣
����������������������͹�ͬ����������о������ֵ�һ�����⡣�����������������
���֡�
��һ�����Ƕ�������һ������Ķ����������Ҷ�������Ҳ��������������ģ�λ����������
�Ľ�㶼�ȸ����С����λ���������Ľ�㶼�ȸ���������ֻ��Ҫ�Ӹ���㿪ʼ������
�����бȽϡ������ǰ����ֵ��������㶼������͵Ĺ�ͬ�����һ���ڵ�ǰ����
�������С������ǰ����ֵ��������㶼С������͵Ĺ�ͬ�����һ���ڵ�ǰ��������
���С�
�ڶ�������������һ���Ƕ�������ÿ����㶼��һ��ָ��ָ�����ĸ���㡣�������ǿ��Դ�
�κ�һ�����������õ�һ�������������ĵ�����������������ת��Ϊ������������
�ĵ�һ��������㡣
��ν��ͬ�ĸ���㣬����������㶼������������������С�
������ǿ��Զ���һ���������ж�һ�������������ǲ��ǰ���������һ����㡣
���ǿ��ԴӸ���㿪ʼ���ж��Ե�ǰ���Ϊ�����������������ǲ��ǰ�������Ҫ�ҵ�������
�㡣���������㶼�����������������У�����͵Ĺ�ͬ�����Ҳ�����������������С���
��������㶼�����������������У�����͵Ĺ�ͬ�����Ҳ�����������������С��������
���һ���������������У�һ���������������У��ǵ�ǰ�Ľ�������͵Ĺ�ͬ����㡣
*/
#include <cstdlib>
#include <iostream>

struct TreeNode
{
  int value;
  TreeNode * left;
  TreeNode * right;
};

void insertBTNode(TreeNode ** & root, int value)
{
  TreeNode * newnode = new TreeNode;
  newnode->value = value;
  newnode->left = NULL;
  newnode->right = NULL;
  if(*root == NULL){
    *root = newnode;
  }
  else{
    TreeNode * cur = *root;
    TreeNode * parent = *root;
    while(cur != NULL){
      parent = cur;
      if(value < cur->value){
        cur = cur->left;
      }
      else{
        cur = cur->right;
      }
    }
    if(value < parent->value){
      parent->left = newnode;
    }
    else{
      parent->right = newnode;
    }
  }
}

void createBTree(int * arr, int len, TreeNode ** root)
{
  if(arr == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    insertBTNode(root, arr[i]);
  }
}

void inorderTravel(TreeNode ** root){
  if(*root == NULL){
    return;
  }
  else{
    inorderTravel(&((*root)->left));
    std::cout<<(*root)->value<<std::endl;
    inorderTravel((&(*root)->right));
  }
}

TreeNode * findNode(TreeNode ** root, int value)
{
  if(*root == NULL){
    return NULL;
  }
  if((*root)->value == value){
    return *root;
  }
  else if(value > (*root)->value){
    findNode(&(*root)->right, value);
  }
  else{
    findNode(&(*root)->left, value);
  }
}

bool hasNode(TreeNode ** root, TreeNode * pcur){
  if(*root == NULL){
    return false;
  }
  if(pcur == *root){
    return true;
  }
  else if(pcur->value < (*root)->value){
    hasNode(&(*root)->left, pcur);
  }
  else{
    hasNode(&(*root)->right, pcur);
  }
}

TreeNode * lowestParentOfTwoNode(TreeNode ** root, TreeNode * pcur1, TreeNode * pcur2)
{
  if(*root == NULL || pcur1 == NULL || pcur2 == NULL){
    return NULL;
  }
  //judge if the two node all in left
  bool leftHasNode1 = false;
  bool leftHasNode2 = false;
  if((*root)->left != NULL){
    leftHasNode1 = hasNode(&(*root)->left, pcur1);
    leftHasNode2 = hasNode(&(*root)->left, pcur2);
  }
  if(leftHasNode1 == true && leftHasNode2 == true){
    if((*root)->left == pcur1 ||(*root)->right == pcur2){
      return *root;
    }
    return lowestParentOfTwoNode(&(*root)->left, pcur1, pcur2);
  }
  //judge if the two node all in right
  bool rightHasNode1 = false;
  bool rightHasNode2 = false;
  if(&(*root)->right != NULL){
    if(leftHasNode1 == false){
      rightHasNode1 = hasNode(&(*root)->right, pcur1);
    }
    if(leftHasNode2 == false){
      rightHasNode2 = hasNode(&(*root)->right, pcur2);
    }
  }
  if(rightHasNode1 == true && rightHasNode2 == true){
    if((*root)->right == pcur1 || (*root)->right == pcur2){
      return (*root);
    }
    return lowestParentOfTwoNode(&(*root)->right, pcur1, pcur2);
  }
  //the two node one in left one in right
  if((leftHasNode1 && rightHasNode2) || (leftHasNode2 && rightHasNode1)){
    return *root;
  }
  //others
  return NULL;
}

int main(int argc, char ** argv)
{
  int arr[] = {2,4,1,6,9,5,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  TreeNode * root = NULL;
  createBTree(arr, len, &root);
  //inorderTravel(&root);
  TreeNode * node1 = findNode(&root, 7);
  TreeNode * node2 = findNode(&root, 5);
  if(node1 != NULL && node2 != NULL){
    std::cout<<node1->value<<std::endl;
    std::cout<<node2->value<<std::endl;
  }

  TreeNode * res = lowestParentOfTwoNode(&root, node1, node2);
  std::cout<<res->value<<std::endl;

  system("pause");
  return 0;
}
#endif
