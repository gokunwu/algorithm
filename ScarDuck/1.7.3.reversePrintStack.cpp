
#if 0
/*
copyright@nciaebupt ת����ע������
��Ŀ���õݹ�ߵ�һ��ջ����������ջ{1, 2, 3, 4, 5}��1��ջ�����ߵ�֮���ջΪ{5, 4, 3, 2, 1}��5����ջ����
���������ǰ�ջ{1, 2, 3, 4, 5}��������������ɣ�ջ��Ԫ��1��ʣ�µĲ�
��{2, 3, 4, 5}����������ܰ�{2, 3, 4, 5}�ߵ����������{5, 4, 3, 2}��Ȼ���ڰ�ԭ����ջ��Ԫ
��1�ŵ��ײ�����ô������ջ�͵ߵ������ˣ����{5, 4, 3, 2, 1}��
������������Ҫ�����������飺һ����ΰ�{2, 3, 4, 5}�ߵ��������{5, 4, 3, 2}������ֻҪ��
{2, 3, 4, 5}��������������ɣ�ջ��Ԫ��2��ʣ�µĲ���{3, 4, 5}������ֻҪ��{3, 4, 5}�ȵ�
���������{5, 4, 3}��Ȼ���ٰ�֮ǰ��ջ��Ԫ��2�ŵ���ײ���Ҳ�ͱ����{5, 4, 3, 2}��
������ô��{3, 4, 5}�ߵ����������ܶ���߿��ܶ��뵽����ǵݹ顣Ҳ����ÿһ����ͼ�ߵ�
һ��ջ��ʱ������ջ��Ԫ��pop�������ٵߵ�ʣ�µ�Ԫ����ɵ�ջ������֮ǰ��ջ��Ԫ
�طŵ�ʣ��Ԫ����ɵ�ջ�ĵײ����ݹ������������ʣ�µ�ջ�Ѿ����ˡ�
*/
#include <cstdlib>
#include <iostream>
#include <stack>

void initStack(int * arr, int len, std::stack<int> & istack){
  if(arr == NULL || len < 0){
    return;
  }
  for(int i = 0; i < len; ++i){
    istack.push(arr[i]);
  }
  return;
}

void reversePrintStack(std::stack<int> & istack){
  if(istack.empty()){
    return;
  }
  int top = istack.top();
  istack.pop();
  reversePrintStack(istack);
  std::cout<<top<<std::endl;
}

int main(int argc, char ** argv){
  int arr[] = {1, 2, 3, 4, 5};
  int len = sizeof(arr)/sizeof(arr[0]);
  std::stack<int> istack;
  initStack(arr, len, istack);
  reversePrintStack(istack);
  system("pause");
  return 0;
}
#endif
