#include <stdio.h>

int main()
{
	int bal;
	FILE * fp = fopen("hishob.txt","w");
	fprintf(fp,"dd/mm/yy\t\tAmount\t\t%20s\n","Particular\n");
	printf("Balance:");
	scanf("%d",&bal);
	FILE * f = fopen("bal.raw","w");
	fwrite(&bal,sizeof(int),1,f);
	fclose(f);
	fclose(fp);
	return 0;
}
