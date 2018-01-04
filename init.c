#include "entries.h"
int main()
{
	int bal;
	struct tm ini_time;
	FILE * fp = fopen("hishob.txt","w");
	fprintf(fp,"dd/mm/yy\t\tAmount\t\t%20s\n","Particular\n");
	printf("Balance:");
	scanf("%d",&bal);
	gettime(&ini_time);
	FILE * f = fopen("bal.raw","w");
	fwrite(&bal,sizeof(int),1,f);
	fwrite(&ini_time,sizeof(time_t),1,f);
	fclose(f);
	fclose(fp);
	return 0;
}
