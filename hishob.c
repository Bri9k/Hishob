#include <stdio.h> 
#include <time.h>

#define MAX 25

typedef struct
{	
	struct tm t;
	int amount;
	char pari[MAX];
}entry;

int main()
{
	// Read Current Balance
	FILE * f = fopen("bal.raw","r");
	int bal;
	fread(&bal,sizeof(int),1,f);
	fclose(f);
	
	// Get System Time
	entry e;
	time_t t = time(NULL);
	e.t = *localtime(&t);
	e.t.tm_year -= 100;
	
	FILE* fp = fopen("hishob.txt","a");
	fprintf(fp,"%02d/%02d/%02d\t\t%04d\t\t%20s\n\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,bal,"Balance");
	
	char c = 'y';
	while(c == 'y' || c == 'Y')
	{
		// Get Entry
		printf("Particular:");
		fgets(e.pari,MAX,stdin);
		printf("Amount:");
		scanf("%d",&e.amount);
		bal += e.amount;
		fprintf(fp,"%02d/%02d/%02d\t\t%04d\t\t%20s\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,e.amount,e.pari);
		printf("More Entries ?\n");
		fgetc(stdin);
		scanf("%c",&c);
		fgetc(stdin);
	}
	fprintf(fp,"%02d/%02d/%02d\t\t%04d\t\t%20s\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,bal,"Balance");
	
	// Update Balance
	f = fopen("bal.raw","w");
	fwrite(&bal,sizeof(int),1,f);
	fclose(f);
	fclose(fp);
	printf("Exit Code Zero !\n");
	return 0;
}
	
	
