#include<stdio.h>
char *someFun1()
{
char temp[]= "string constant"; 
return temp;
}
char *someFun2()
{
char *temp = {'s','t','r','i','n','g'}; 
return temp;
}

int main()
{
puts(someFun1());
puts(someFun2());
}
