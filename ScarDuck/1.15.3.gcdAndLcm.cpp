
/*
copyright@nciaebupt 转载请注明出处
题目:求两个或N个数的最大公约数(gcd)和最小公倍数(lcm)的较优算法

求两个或N个数的最大公约数(gcd)和最小公倍数(lcm)的较优算法
两个数的最大公约数--欧几里得算法
int gcd(int a, int b)
{
      if (a < b)
         swap(a, b);
      if (b == 0)
         return a;
       else
         return gcd(b, a%b);
}

n 个数的最大公约数算法
说明:
把n个数保存为一个数组
参数为数组的指针和数组的大小(需要计算的数的个数)
然后先求出gcd(a[0],a[1]), 然后将所求的gcd与数组的下一个元素作为gcd的参数继续求gcd
这样就产生一个递归的求ngcd的算法

int ngcd(int *a, int n)
{
     if (n == 1)
         return *a;
     return gcd(a[n-1], ngcd(a, n-1));
}

两个数的最小公倍数(lcm)算法
//lcm(a, b) = a*b/gcd(a, b)
int lcm(int a, int b)
{
     return a*b/gcd(a, b);
}

n 个数的最小公倍数算法
算法过程和n个数的最大公约数求法类似
求出头两个的最小公倍数,再将欺和大三个数求最小公倍数直到数组末尾
这样产生一个递归的求nlcm的算法
int nlcm(int *a, int n)
{
       if (n == 1)
         return *a;
       else
         return lcm(a[n-1], nlcm(a, n-1));
}
*/
