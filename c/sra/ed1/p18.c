#include<stdio.h>
int main()
{
struct xx
{
int x;
struct yy
{
char s;
struct xx*p;
};
struct yy *q;
};

}
/*Incompleteness: The struct yy is defined inside struct xx, but you're trying to refer to struct xx inside struct yy as struct xx *p;. Since struct xx is not fully defined until after the nested struct yy, this is problematic and will lead to a compilation error.*/
