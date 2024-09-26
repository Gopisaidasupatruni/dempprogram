#include<stdio.h>
int main()
{
	int a=0x1ff;
	int n=0x800000;
	int m=0xa017;
	/* binary */
	int pos;
	for(pos=31;pos>=0;pos--)
		printf("%d",(a>>pos)&1);
	printf("\n");
	printf("0x%X\n",a);
	for(pos=31;pos>=0;pos--)
		printf("%d",(n>>pos)&1);
	printf("\n");
	for(pos=31;pos>=0;pos--)
		printf("%d",(m>>pos)&1);
	printf("\n");
}
