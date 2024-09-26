#include<stdio.h>
 aaa() { printf("hi");
}
 bbb(){ printf("hello");
}
 ccc(){ printf("bye");
}
int main()
{
int (*ptr[3])(); ptr[0]=aaa; ptr[1]=bbb; 
ptr[2]=ccc; ptr[2]();
}

