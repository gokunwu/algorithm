
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
  if(root == NULL){
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

int main(int argc, char ** argv)
{
  int arr[] = {2,4,1,6,9,5,7};
  int len = sizeof(arr)/sizeof(arr[0]);


  system("pause");
  return 0;
}
