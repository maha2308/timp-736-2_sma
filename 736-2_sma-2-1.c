#include <stdio.h>
int main()
{
 	int n,x,i,max;
	scanf("%d",&n);
	scanf("%d",&x);
	max=x;
	for(i=1;i<=n-1;i++)
	{	
		scanf("%d",&x);
		if(max<=x)
		{	
		max=x;
		};
	}	
	printf("%d\n",max);
	return 0;
}

