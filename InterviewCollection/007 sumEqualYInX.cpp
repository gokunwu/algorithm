#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：有一个整数数组，然后有一个数m，要找到整数数组中，所有和等于m的组合，并输出。
    比如有数组｛1,5,3,7,6,4,2｝,m = 7,
    输出：1 6
          3 4
          7
          1 2 4
          2 5
*/

#include <cstdlib>
#include <iostream>
#include <vector>

void exchange(int * arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
  return;
}

int partition(int * arr, int l, int u){
  if(arr == NULL || l > u)  return -1;
  int mid = l-1;
  int key = arr[u];
  for(int cur = l; cur < u; ++cur){
    if(arr[cur] < key){
      mid = mid + 1;
      exchange(arr, cur, mid);
    }
  }
  exchange(arr, mid+1, u);
  return mid+1;
}

void quickSort(int * arr, int l, int u){
  if(arr == NULL || l > u)  return;
  int mid = partition(arr, l, u);
  quickSort(arr, l, mid-1);
  quickSort(arr, mid+1, u);
  return;
}

void quickSort(int * arr, int len){
  if(arr == NULL || len < 1){
    return ;
  }
  quickSort(arr, 0, len-1);
}

int binSearch(int * arr, int len, int Y){
  if(arr == NULL || len < 1)  return -1;
  int l = 0;
  int u = len-1;
  int mid;
  while(l <= u){
    mid = (l+u)/2;
    if(Y > arr[mid]){
      l = mid+1;
    }
    else if(Y < arr[mid]){
      u = mid -1;
    }else{
      return mid;
    }
  }
  return -1;
}

void sumEqualYinX(int * arr, int len, int Y, std::vector<int> & vec){
  if(arr == NULL || len < 1) return;
  if(arr[len-1] <= Y){
    int pos = binSearch(arr, len, Y);
    if(pos != -1){
      vec.push_back(Y);
      for(int i = vec.size()-1; i >=0; --i){
        std::cout<<"**"<<vec[i]<<" ";
      }
      std::cout<<std::endl;
      vec.pop_back();
    }
    vec.push_back(arr[len-1]);
    sumEqualYinX(arr,len-1,Y-arr[len-1],vec);
    vec.pop_back();
    sumEqualYinX(arr,len-1,Y,vec);


  }
  else{
    sumEqualYinX(arr, len-1, Y, vec);
  }

}

int main(int argc, char ** argv){
  int arr[] = {1,5,3,7,6,4,2};
  int len = sizeof(arr)/sizeof(int);

  quickSort(arr,len);

  std::vector<int> vec;
  sumEqualYinX(arr, len, 7, vec);

  system("pause");
  return 0;
}

#endif
