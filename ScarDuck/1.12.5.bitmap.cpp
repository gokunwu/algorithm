
#if 0
主要讨论了一个对一个包含1000万条的整数文件排序问题，  很有baidu面试题的风格。
主要思想是hash来解决排序问题，但是hash的空间复杂度又相对比较大，所以用bitmap
来减少hash算法所需的空间。
一般的hash，例如对数组[2, 3, 5, 10]  运用桶排序算法，需要声明10个整数的bucket,如下图
所示：
0  1  1  0  1  0  0  0  0  1
1  2  3  4  5  6  7  8  9  10
但是如果用bitmap的话，只需一个整数，因为一个整数(32位机)的话有32bit，每个bit都
能map一个整数，如下图所示：
                           1        1     1  1
31  30  …  3  2  1  0  31  …  9  …  5  4  3  2  1  0
数组元素1              数组元素0
所以关键就是位操作set, clear, test:
01#define BITSPERWO RD 32
02#define SHIFT 5
03#define MASK 0x1f


04
05typedef long long int64;
06
07int array[100000];
08
09/**
10*
11*    i  / 32    对应具体数组元素
12
13*    i % 32  对应具体数组元素的bit位
14*    i >> SHIFT  == i /  32
15*    i &  MASK    == i  % 32
16*    (32) = (100000)
17*
18**/
19
20void set(int64 i)
21{
22    array[ i >> SHIFT]  |= ( 1 << ( i  &  MAS K));
23}
24
25void clear(int64 i)
26{
27    array[ i >> SHIFT]  &= ~( 1 << ( i  & MASK));
28}
29
30int  test(int64 i)
31{
32    return array[ i >> SHIFT]  & ( 1 << ( i  &  MAS K));
33}

在一个文件中有  10G 个整数，乱序排列，要求找出中位数。内存限制为  2G。只写出思路
即可。
10G整数做bitmap需要10G/32 = 0.3G 个整数（< 32位机器总共可以的2^31-1 = 2G个整数），
0.3G个整数只需要0.3G*4=1.2G的存储空间，故可以只扫描一遍，就可以求出中位数。
#endif
