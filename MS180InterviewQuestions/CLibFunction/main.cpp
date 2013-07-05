

/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memset(void *ptr, int c, size_t count);
*用法：#include <string.h>
*功能：把ptr所指内存区域的前count个字节设置成字符c。
*说明：返回指向buffer的指针。
*自己实现memset
*/
#include <cstdio>

void * _memset(void *ptr,int c,size_t count)
{
    void * start = ptr;
    while(count--)
    {
        *(char *)ptr = (char)c;
        ptr = (char *)ptr + 1;
    }
    return start;
}

int main(int args,char ** argv)
{
    char str[] = "almost every programmer should know memset!";
    _memset(str,'-',6);
    printf("%s\n",str);
    getchar();
    return 0;
}

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memset(void *ptr, int c, size_t count);
*用法：#include <string.h>
*功能：把ptr所指内存区域的前count个字节设置成字符c。
*说明：返回指向buffer的指针。
*使用C函数库中的memset
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "almost every programmer should know memset!";
    memset(str,'-',6);
    printf("%s\n",str);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strtok(char *str, char *delimiters);
*用法：#include <string.h>
*功能：分解字符串为一组标记串。s为要分解的字符串，delim为分隔符字符串。
*说明：首次调用时，s必须指向要分解的字符串，随后调用要把s设成NULL。
*   strtok在s中查找包含在delim中的字符并用NULL('\0')来替换，
*   直到找遍整个字符串。返回指向下一个标记串。当没有标记串时则返回空字符NULL。
*自己实现strtok
*/
#include <cstdio>
#include <cstring>

char * _strtok(char * string,const char * control)
{
    unsigned char * str = NULL;
    const unsigned char * ctrl = (const unsigned char *)control;
    unsigned char map[32];
    int count;
    static char * nextoken;
    /*clear the control map*/
    memset(map,0,32*sizeof(unsigned char));
    /*set bits in control map*/
    while(*ctrl)
    {
        map[*ctrl >> 3] |= (0x01 << (*ctrl & 7));
        ctrl++;
    }
    /*set the str if string is NULL the str = nextoken else str = string*/
    if(string)
        str = (unsigned char *)string;
    else
        str = (unsigned char *)nextoken;
    /*find beginning of token*/
    while((map[*str >> 3] & (0x01 << (*str & 7))) && *str)
        str++;
    /*remember the beginning of the token*/
    string = (char *)str;
    /*find the end of the token,set the last of the token '\0'*/
    for(;*str;str++)
    {
        if(map[*str >> 3] & (0x01 << (*str & 7)))
        {
            *str++ = '\0';
            break;
        }
    }
    /*remember the rest of the string*/
    nextoken = (char *)str;
    /*return the result*/
    if((unsigned char *)string == str)
        return NULL;
    else
        return string;
}

int main(int args,char ** argv)
{
    char str[] = "- This, is a sample string.";
    char *pch;
    printf("split sentence '%s' into tokens : \n",str);
    pch = _strtok(str,"-,. ");
    while(pch != NULL)
    {
        printf("%s\n",pch);
        pch = _strtok(NULL,"-,. ");
    }
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strtok(char *str, char *delimiters);
*用法：#include <string.h>
*功能：分解字符串为一组标记串。s为要分解的字符串，delim为分隔符字符串。
*说明：首次调用时，s必须指向要分解的字符串，随后调用要把s设成NULL。
*   strtok在s中查找包含在delim中的字符并用NULL('\0')来替换，
*   直到找遍整个字符串。返回指向下一个标记串。当没有标记串时则返回空字符NULL。
*使用C函数库中的strtok
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "- This, is a sample string.";
    char *pch;
    printf("split sentence '%s' into tokens : \n",str);
    pch = strtok(str,"-,. ");
    while(pch != NULL)
    {
        printf("%s\n",pch);
        pch = strtok(NULL,"-,. ");
    }
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strstr(const char *haystack, const char *needle);
*用法：#include <string.h>
*功能：从字符串haystack中寻找needle第一次出现的位置（不比较结束符NULL)。
*说明：返回指向第一次出现needle位置的指针，如果没找到则返回NULL。
*自己实现strstr
*/
#include <cstdio>
#include <cstring>

char * _strstr(const char * str1,const char * str2)
{
    char * cp = (char *)str1;
    char * s1;
    char * s2;
    if(!*str2)
        return ((char *)str1);
    while(*cp)
    {
        s1 = cp;
        s2 = (char *)str2;
        while(*s1 && *s2 && !(*s2 - *s1))
        {
            s1++;
            s2++;
        }
        if(!*s2)
            return (cp);
        cp++;
    }
    return NULL;
}

int main(int args,char ** argv)
{
    char str[] = "This is a simple string";
    char * pch = _strstr(str,"simple");
    strncpy(pch,"sample",6);
    printf("%s\n",str);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strstr(const char *haystack, const char *needle);
*用法：#include <string.h>
*功能：从字符串haystack中寻找needle第一次出现的位置（不比较结束符NULL)。
*说明：返回指向第一次出现needle位置的指针，如果没找到则返回NULL。
*使用C函数库中的strstr
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "This is a simple string";
    char * pch = _strstr(str,"simple");
    strncpy(pch,"sample",6);
    printf("%s\n",str);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：size_t strspn(const char * str1,const char * str2);
*用法：#include <string.h>
*功能：若strspn()返回的数值为n,
*       则代表字符串str1开头连续有n个字符都是属于字符串str2内的字符.
*说明：返回字符串str1开头连续包含字符串str2内的字符数目.
*自己实现strspn
*/
#include <cstdio>
#include <cstring>

size_t _strspn(const char * string,const char * control)
{
    const char * str = (const char *)string;
    const char * ctrl = (const char *)control;
    unsigned char map[32];
    int count = 0;
    /*clear the map*/
    memset(map,0,32*sizeof(unsigned char));
    //memset(map,0,32);
    /*set bits in control map*/
    while(*ctrl)
    {
        map[*ctrl >> 3] |= (0x01 << (*ctrl & 7));
        ctrl++;
    }
    /*count the str's char num in control*/
    if(*str)
    {
        count = 0;

        while((map[*str >> 3] & (0x01 << (*str & 7))))
        {
            count++;
            str++;
        }
        return count;
    }
    return 0;
}

int main(int args,char ** argv)
{
    char str[] = "129th";
    char keys[] = "1234567890";

    int i = _strspn(str,keys);

    printf("the initial string has %d numbers\n",i);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：size_t strspn(const char * str1,const char * str2);
*用法：#include <string.h>
*功能：若strspn()返回的数值为n,
*       则代表字符串str1开头连续有n个字符都是属于字符串str2内的字符.
*说明：返回字符串str1开头连续包含字符串str2内的字符数目.
*使用C函数库中的strspn
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "12999th";
    char keys[] = "1234567890";

    int i = strspn(str,keys);

    printf("the initial string has %d numbers\n",i);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strrchr(const char *s,int ch);
*用法：#include <string.h>
*功能：查找字符串s中最后一次出现字符c的位置
*说明：返回最后一次出现c的位置的指针，如果s中不存在c则返回NULL。
*自己实现strrchr
*/
#include <cstdio>

char * _strrchr(const char * str,int ch)
{
    char * start = (char *)str;
    while(*str++)/*get the end of the string*/
        ;
    while(--str != start && *str != (char)ch)
        ;
    if(*str == (char)ch)
        return((char *)str);
    return NULL;

}

int main(int args,char ** argv)
{
    char str[] = "This is a sample string";
    char *pch;
    pch = _strrchr(str,'s');
    printf("The last occurence of 's' found at : %d",pch - str + 1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：extern char *strrchr(char *s,char c);
*用法：#include <string.h>
*功能：查找字符串s中最后一次出现字符c的位置
*说明：返回最后一次出现c的位置的指针，如果s中不存在c则返回NULL。
*使用C函数库中的strrchr
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "This is a sample string";
    char *pch;
    pch = strrchr(str,'s');
    printf("The last occurence of 's' found at : %d",pch - str + 1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strpbrk(const char *s1, const char *s2);
*用法：#include <string.h>
*功能：在字符串s1中寻找字符串s2中任何一个字符相匹配的第一个字符的位置，
*   空字符NULL不包括在内。
*说明：返回指向s1中第一个相匹配的字符的指针，如果没有匹配字符则返回空指针NULL。
*自己实现strpbrk
*/
#include <cstdio>
#include <cstring>

char * _strpbrk(const char * string,const char * control)
{
    const unsigned char *str = (const unsigned char *)string;
    const unsigned char *ctrl = (const unsigned char *)control;
    unsigned char map[32];
    int count;
    /*clear the map*/
    memset(map,0,32*sizeof(unsigned char));
    /*set bit in the control map*/
    while(*ctrl)
    {
        map[*ctrl >> 3] |= (0x01 << (*ctrl & 7));
        ctrl++;
    }
    /*search control in str*/
    while(*str)
    {
        if((map[*str >> 3] & (1 << (*str & 7))))
            return((char *)str);
        str++;
    }
    return NULL;

}

int main(int args,char ** argv)
{
    char str[] = "This is a sample string";
    char keys[] = "aeiou";
    printf("Vowels in '%s' : ",str);
    char * pch;
    pch = _strpbrk(str,keys);
    while(pch != NULL)
    {
        printf("%c ",*pch);
        pch = _strpbrk(pch + 1,keys);
    }
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strpbrk(const char *s1, const char *s2);
*用法：#include <string.h>
*功能：在字符串s1中寻找字符串s2中任何一个字符相匹配的第一个字符的位置，
*   空字符NULL不包括在内。
*说明：返回指向s1中第一个相匹配的字符的指针，如果没有匹配字符则返回空指针NULL。
*使用C函数库中的strpbrk
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "This is a sample string";
    char keys[] = "aeiou";
    printf("Vowels in '%s' : ",str);
    char * pch;
    pch = strpbrk(str,keys);
    while(pch != NULL)
    {
        printf("%c ",*pch);
        pch = strpbrk(pch + 1,keys);
    }
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：size_t strcspn(const char *s1,const char *s2);
*用法：#include <string.h>
*功能：在字符串s1中搜寻s2中所出现的字符。
*说明：返回第一个出现的字符在s1中的下标值，
*   亦即在s1中出现而s2中没有出现的子串的长度。
*自己实现strcspn
*/
#include <cstdio>

size_t _strcspn(const char * string,const char * control)
{
    const unsigned char * str = (const unsigned char *)string;
    const unsigned char * ctrl = (const unsigned char *)control;

    unsigned char map[32];
    int count = 0;

    //clear the bit map
    for(count = 0;count < 32;count++)
    {
        map[count] = 0;
    }
    //set bit in control map
    while(*ctrl)
    {
        map[*ctrl >> 3] |= (0x01 << (*ctrl & 7));
        ctrl++;
    }

    count = 0;
    map[0] |= 1;/*null chars not considered*/
    while(!(map[*str >> 3] & (0x01 << (*str & 7))))
    {
        count++;
        str++;
    }
    return count;
}

int main(int args,char ** argv)
{
    char str[] = "fcb373";
    char keys[] = "1234567890";

    int i = _strcspn(str,keys);

    printf("The first number in str is in position : %d",i +1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：size_t strcspn(const char *s1,const char *s2);
*用法：#include <string.h>
*功能：在字符串s1中搜寻s2中所出现的字符。
*说明：返回第一个出现的字符在s1中的下标值，
*   亦即在s1中出现而s2中没有出现的子串的长度。
*使用C函数库中的strcspn
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str[] = "fcb373";
    char keys[] = "1234567890";

    int i = strcspn(str,keys);

    printf("The first number in str is in position : %d",i +1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strchr(const char *s,int c);
*用法：#include <string.h>
*功能：查找字符串s中首次出现字符c的位置
*说明：返回首次出现c的位置的指针，如果s中不存在c则返回NULL。
*自己实现strchr
*/
#include <cstdio>

char * _strchr(const char * s,int ch)
{
    while(*s && (*s != (char)ch))
    {
        s++;
    }
    if(*s == (char)ch)  return (char *)s;
    return NULL;
}

int main(int args,char ** argv)
{
    char s[] = "This sample string";
    char *p = _strchr(s,'p');
    if(p != NULL)
    {
        printf("find the char in : %d\n",p - s + 1);
    }
    else    printf("could not find the char\n");

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strchr(const char *s,int c);
*用法：#include <string.h>
*功能：查找字符串s中首次出现字符c的位置
*说明：返回首次出现c的位置的指针，如果s中不存在c则返回NULL。
*使用C函数库中的strchr
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char s[] = "This sample string";
    char *p = strchr(s,'p');
    if(p != NULL)
    {
        printf("find the char in : %d\n",p - s + 1);
    }
    else    printf("could not find the char\n");

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memchr(const void *buf, int ch, size_t count);
*用法：#include <string.h>
*功能：从buf所指内存区域的前count个字节查找字符ch。
*说明：当第一次遇到字符ch时停止查找。
*      如果成功，返回指向字符ch的指针；否则返回NULL。
*自己实现memchr
*/
#include <cstdio>

void * _memchr(const void *buf,int ch,size_t count)
{
    while(count && (*(unsigned char *)buf != (unsigned char )ch))
    {
        buf = (unsigned char *)buf + 1;
        count--;
    }
    return (count ? (void *)buf : NULL);
}

int main(int args,char ** argv)
{
    char s[] = "simple string";
    char *p = (char *)_memchr(s,'n',sizeof(s));

    if(p != NULL)
        printf("find the ch in position : %d\n",p - s + 1);
    else    printf("not find the ch!\n");

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memchr(const void *buf, int ch, size_t count);
*用法：#include <string.h>
*功能：从buf所指内存区域的前count个字节查找字符ch。
*说明：当第一次遇到字符ch时停止查找。
*      如果成功，返回指向字符ch的指针；否则返回NULL。
*使用C函数库中的memchr
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char s[] = "simple string";
    char *p = (char *)memchr(s,'n',strlen(s));

    if(p != NULL)
        printf("find the ch in position : %d\n",p - s + 1);
    else    printf("not find the ch!\n");

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int strcmp(const char *s1,const char * s2，size_t n);
*用法：#include <string.h>
*功能：比较字符串s1和s2的前n个字符。
*说明：
*   当s1<s2时，返回值<0
*   当s1=s2时，返回值=0
*   当s1>s2时，返回值>0
*自己实现strncmp
*/
#include <cstdio>

int _strncmp(const char *src,const char *dest,size_t count)
{
    if(count == 0)
        return 0;
    while(count-- && *src && *src == *dest)
    {
        src++;
        dest++;
    }
    return (*(unsigned char *)src - *(unsigned char *)dest);
}

int main(int args,char ** argv)
{
    char s1[] = "Hello world!";
    char s2[] = "Hello World!";

    int flag = _strncmp(s1,s2,7);

    if(flag < 0)    printf("%s is less than %s\n",s1,s2);
    else if(flag == 0)  printf("%s is equal %s\n",s1,s2);
    else    printf("%s is larger than %s",s1,s2);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int strcmp(const char *s1,const char * s2，size_t n);
*用法：#include <string.h>
*功能：比较字符串s1和s2的前n个字符。
*说明：
*   当s1<s2时，返回值<0
*   当s1=s2时，返回值=0
*   当s1>s2时，返回值>0
*使用C函数库中的strncmp
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char s1[] = "Hello world!";
    char s2[] = "Hello World!";

    int flag = strncmp(s1,s2,7);

    if(flag < 0)    printf("%s is less than %s\n",s1,s2);
    else if(flag == 0)  printf("%s is equal %s\n",s1,s2);
    else    printf("%s is larger than %s",s1,s2);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int strcmp(const char *s1,const char * s2);
*用法：#include <string.h>
*功能：比较字符串s1和s2。
*说明：
*   当s1<s2时，返回值<0
*   当s1=s2时，返回值=0
*   当s1>s2时，返回值>0
*自己是实现strcmp
*/
#include <cstdio>

int _strcmp(const char * src,const char * dest)
{
    int ret = 0;
    while(!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest)
    {
        src++;
        dest++;
    }
    if(ret < 0) ret = -1;
    else if(ret > 0) ret = 1;

    return ret;
}

int main(int args,char ** argv)
{
    char str1[] = "apPle";
    char *str2 = "apple";

    int flag = _strcmp(str1,str2);

    if(flag < 0)    printf("%s is less than %s\n",str1,str2);
    else if(flag == 0)  printf("%s is equal %s\n",str1,str2);
    else    printf("%s is larger than %s\n",str1,str2);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int strcmp(const char *s1,const char * s2);
*用法：#include <string.h>
*功能：比较字符串s1和s2。
*说明：
*   当s1<s2时，返回值<0
*   当s1=s2时，返回值=0
*   当s1>s2时，返回值>0
*使用C函数库中的strcmp
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str1[] = "apple";
    char *str2 = "apple";

    int flag = strcmp(str1,str2);

    if(flag < 0)    printf("%s is less than %s\n",str1,str2);
    else if(flag == 0)  printf("%s is equal %s\n",str1,str2);
    else    printf("%s is larger than %s\n",str1,str2);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int memcmp(const void *buf1, const void *buf2, size_t count);
*用法：#include <string.h>
*功能：比较内存区域buf1和buf2的前count个字节。
*说明：
*   当buf1<buf2时，返回值<0
*   当buf1=buf2时，返回值=0
*   当buf1>buf2时，返回值>0
*自己实现memcmp
*/
#include <cstdio>

int _memcmp(const void * buf1,const void * buf2,size_t count)
{
    if(!count)
        return 0;
    while(count-- && *((char *)buf1) == *((char *)buf2))
    {
        buf1 = (char *)buf1 + 1;
        buf2 = (char *)buf2 + 1;
    }
    return (*((char *)buf1)-*((char *)buf2));
}

int main(int args,char ** argv)
{
    char str1[] = "Hello World!";
    char str2[] = "Hello world!";

    int flag = _memcmp(str1,str2,sizeof(str1));

    if(flag < 0)    printf("%s is less than %s\n",str1,str2);
    else if(flag == 0)  printf("%s is equal %s",str1,str2);
    else    printf("%s is larger than %s",str1,str2);

    getchar();
    return 0;

}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：int memcmp(const void *buf1, const void *buf2, size_t count);
*用法：#include <string.h>
*功能：比较内存区域buf1和buf2的前count个字节。
*说明：
*   当buf1<buf2时，返回值<0
*   当buf1=buf2时，返回值=0
*   当buf1>buf2时，返回值>0
*使用C函数库中的memcmp
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str1[] = "Hello World!";
    char str2[] = "Hello world!";

    int flag = memcmp(str1,str2,sizeof(str1));

    if(flag < 0)    printf("%s is less than %s\n",str1,str2);
    else if(flag == 0)  printf("%s is equal %s",str1,str2);
    else    printf("%s is larger than %s",str1,str2);

    getchar();
    return 0;

}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strncat(char *dest,const char *src,size_t n);
*用法：#include <string.h>
*功能：把src所指字符串的前n个字符添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*      返回指向dest的指针。
*自己实现strncat
*/
#include <cstdio>

char * _strncat(char * dest,const char * src,size_t count)
{
    char * ret = dest;
    while(*dest != '\0')
       dest++;
    while(count--)
    {
        if((*dest++ = *src ++) == '\0')
            return ret;
    }

    *dest = '\0';
    return ret;
}

int main(int args,char ** argv)
{
    char str1[20] = "to be ";
    char str2[20] = "or not to be";

    _strncat(str1,str2,6);

    printf("%s\n",str1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strncat(char *dest,const char *src,size_t n);
*用法：#include <string.h>
*功能：把src所指字符串的前n个字符添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*      返回指向dest的指针。
*使用C函数库中的strncat
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str1[20] = "to be ";
    char str2[20] = "or not to be";

    strncat(str1,str2,6);

    printf("%s\n",str1);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strcat(char *dest,const char *src);
*用法：#include <string.h>
*功能：把src所指字符串添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*      返回指向dest的指针。
*自己实现strcat
*/
#include <cstdio>

char * _strcat(char * dest,const char * src)
{
    char * ret = dest;
    while(*dest != '\0')
        dest++;
    while((*dest++ = *src++) != '\0')
        ;
    return ret;
}

int main(int args,char ** argv)
{
    char *str1 = "strings ";
    char *str2 = "are ";
    char *str3 = "concatenated";
    char p[100] = "These ";

    _strcat(p,str1);
    _strcat(p,str2);
    _strcat(p,str3);

    printf("%s\n",p);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：char *strcat(char *dest,const char *src);
*用法：#include <string.h>
*功能：把src所指字符串添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*      返回指向dest的指针。
*使用C函数库中的strcat
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char *str1 = "strings ";
    char *str2 = "are ";
    char *str3 = "concatenated";
    char p[100] = "These ";

    strcat(p,str1);
    strcat(p,str2);
    strcat(p,str3);

    printf("%s\n",p);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：extern char *strncpy(char *dest, char *src, int n);
*用法：#include <string.h>
*功能：把src所指由NULL结束的字符串的前n个字节复制到dest所指的数组中。
*说明：
*   如果src的前n个字节不含NULL字符，则结果不会以NULL字符结束。
*   如果src的长度小于n个字节，则以NULL填充dest直到复制完n个字节。
*   src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*   返回指向dest的指针。
*自己实现strncpy
*/
#include <cstdio>

char * _strncpy(char * dest,const char * src,size_t count)
{
    char * ret = dest;
    while(count && (*dest++ = *src++))
        count--;
    if(count)
    {
        while(--count)
        {
            *(dest++) = '\0';
        }
    }
    return ret;
}

int main(int args,char ** argv)
{
    char str1[] = "To be or not to be";
    char str2[40];
    char str3[40];

    _strncpy(str2,str1,sizeof(str1));
    _strncpy(str3,str1,5);
    str3[5] = '\0';

    printf("str2 : %s\nstr3 : %s",str2,str3);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：extern char *strncpy(char *dest, char *src, int n);
*用法：#include <string.h>
*功能：把src所指由NULL结束的字符串的前n个字节复制到dest所指的数组中。
*说明：
*   如果src的前n个字节不含NULL字符，则结果不会以NULL字符结束。
*   如果src的长度小于n个字节，则以NULL填充dest直到复制完n个字节。
*   src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*   返回指向dest的指针。
*使用C函数库中的strncpy
*/
#include <cstdio>
#include <cstring>

int main(int args,char **argv)
{
    char str1[] = "To be or not to be";
    char str2[40];
    char str3[40];

    strncpy(str2,str1,sizeof(str1));
    strncpy(str3,str1,5);
    str3[5] = '\0';

    printf("str2 : %s\nstr3 : %s\n",str2,str3);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：extern char *strcpy(char *dest,char *src);
*用法：#include <string.h>
*功能：把src所指由NULL结束的字符串复制到dest所指的数组中。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*返回指向dest的指针。
*编程范式
*自己实现strcpy
*/
#include <cstdio>
#include <cassert>

char * _strcpy(char * dest,const char * src)
{
    //assert((dest != NULL)&&(src != NULL));
    char * ret = dest;
    while((*(dest++) = *(src++)) != '\0')
        ;

    return ret;
}

int main(int args,char ** argv)
{
    char str1[] = "Sample string!";
    char str2[40];
    char str3[40];

    _strcpy(str2,str1);
    _strcpy(str3,"Hello World!");

    printf("str2 : %s\nstr3 : %s\n",str2,str3);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：extern char *strcpy(char *dest,char *src);
*用法：#include <string.h>
*功能：把src所指由NULL结束的字符串复制到dest所指的数组中。
*说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*返回指向dest的指针。
*使用C函数库中的strcpy
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char str1[] = "Sample string!";
    char str2[40];
    char str3[40];

    strcpy(str2,str1);
    strcpy(str3,"Hello World!");
    printf("str2 : %s\nstr3 : %s\n",str2,str3);

    getchar();
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memmove(void *dest, const void *src, size_t count);
*用法：#include <string.h>
*功能：由src所指内存区域复制count个字节到dest所指内存区域。
*说明：src和dest所指内存区域可以重叠，但复制后src内容会被更改。函数返回指向dest的指针。
*自己实现memmove
*
*/
#include <cstdio>
#include <cstring>

void * _memmove(void * dest, const void * src, size_t count)
{
    void * ret = dest;
    if((char *)dest <= (char *)src ||(char *)dest >= ((char *)src) + count)
    {//如果数据区没有重合，则从低地址向高地址复制
        while(count--)
        {
            *((char *)dest) = *((char *)src);
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else//如果数据区有重合，则从高地址向低地址复制
    {
        dest = (char *)dest + count - 1;
        src = (char *)src + count - 1;
        while(count--)
        {
            *((char *)dest) = *((char *)src);
            dest = (char *)dest - 1;
            src = (char *)src -1;
        }
    }
    return ret;
}

int main(int args,char ** argv)
{
    char src[] = "memmove can be very useful......";
    char dest[40] ={""};
    _memmove(src + 20,src + 15,11);

    printf("%s\n",src);
    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memmove(void *dest, const void *src, size_t count);
*用法：#include <string.h>
*功能：由src所指内存区域复制count个字节到dest所指内存区域。
*说明：src和dest所指内存区域可以重叠，但复制后src内容会被更改。函数返回指向dest的指针。
*使用C函数库中的memmove
*
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char src[] = "memmove can be very useful......";
    char dest[40] ={""};
    memmove(src + 20,src + 15,11);

    printf("%s\n",src);
    getchar();
    return 0;
}

#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memcpy(void *dest, const void *src, size_t count);
*用法：#include <cstring>
*功能：由src所指内存区域复制count个字节到dest所指内存区域。
*说明：src和dest所指内存区域不能重叠，函数返回指向dest的指针。
*自己实现memcpy
*/
#include <cstdio>
#include <cstring>

void * _memcpy(void *dest,const void * src,size_t count)
{
    while(count--)
    {
        *((char *)dest) = *((char *)src);
        (char *)(dest = (char *)dest + 1);
        (char *)(src =(char *)src + 1);
    }
}

int main(int args,char ** argv)
{
    char * src = "Hello World!";
    char dest[20];
    /*这里使用strlen(src)+1是因为strlen(src)返回的是src的字符的个数，不包括结束符\0
    *而我们复制时希望将\0一起复制，故需要将strlen(src)加1
    */
    _memcpy(dest,src,strlen(src) + 1);
    printf("The length is : %d",strlen(src));
    printf("The dest is : %s",dest);

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*原型：void *memcpy(void *dest, const void *src, size_t count);
*用法：#include <cstring>
*功能：由src所指内存区域复制count个字节到dest所指内存区域。
*说明：src和dest所指内存区域不能重叠，函数返回指向dest的指针。
*使用C函数库中的memcpy
*
*/
#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{
    char * src = "Hello world!";
    char dest[20];
    /*这里使用strlen(src)+1是因为strlen(src)返回的是src的字符的个数，不包括结束符\0
    *而我们复制时希望将\0一起复制，故需要将strlen(src)加1
    */
    memcpy(dest,src,strlen(src)+1);
    printf("The dest is : %s\n",dest);

    getchar();
    return 0;
}
#endif


#if 0
/*
*copyright@nciaebupt 转载请注明出处
*c标准库中的函数memccpy
*原型：extern void *memccpy(void * dest,const void * src,int c,unsigned count);
*用法：#include <string.h>
*功能：由src所指内存区域复制不多于count个字节到dest所指内存区域，如果遇到字符ch则停止复制。
*说明：返回指向字符ch后的第一个字符的指针，如果src前n个字节中不存在ch则返回NULL。ch被复制。
*自己重写memccpy
*/
#include <cstdio>
#include <cstring>

void * _memccpy(void * dest, const void * src, int c,unsigned count)
{

    while(count && (*((char *)(dest = (char *)dest + 1) - 1) =
                    *((char *)(src = (char *)src + 1) -1)) != (char)c)
    {
        count--;
    }

    return (count ? dest : NULL);
}

int main(int args,char ** argv)
{
    char * src = "Golden Global View";
    char dest[20],*p;
    p = (char *)memccpy(dest,src,'d',strlen(src));
    if(p)
    {
        *p = '\0';
        printf("Char found: %s\n",dest);
    }
    else
    {
        printf("Char not found.\n");
    }

    getchar();
    return 0;
}
#endif

#if 0
/*
*copyright@nciaebupt 转载请注明出处
*c标准库中的函数memccpy
*原型：extern void *memccpy(void *dest, void *src, unsigned char ch, unsigned int count);
*用法：#include <string.h>
*功能：由src所指内存区域复制不多于count个字节到dest所指内存区域，如果遇到字符ch则停止复制。
*说明：返回指向字符ch后的第一个字符的指针，如果src前n个字节中不存在ch则返回NULL。ch被复制。
*使用C函数库中的memccpy
*/

#include <cstdio>
#include <cstring>

int main(int args,char ** argv)
{

    char *s="Golden Global View";
    char d[20],*p;

    p = (char *)memccpy(d,s,'e',strlen(s));
    if(p)
    {
        *p='\0';      //给d添加一个结束符\0
        printf("Char found: %s\n",d);
    }
    else
        printf("Char not found.\n");


    getchar();
    return 0;
}
#endif







