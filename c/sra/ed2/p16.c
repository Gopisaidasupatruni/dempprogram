#include<stdio.h>
int _l_abc(int);
int main()
{
int i=_l_abc(10); printf("%d\n",--i);
}
int _l_abc(int i)
{
return(i++);

}
