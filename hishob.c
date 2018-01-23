#define MAX 25

#include "entries.h"



int main()
{
	// Read Current Balance
	FILE * f = fopen("bal.raw","r");
	int bal;
	time_t prev_entry;
	fread(&bal,sizeof(int),1,f);
	fread(&prev_entry,sizeof(time_t),1,f);
	fclose(f);
	
	// Get System Time
	entry e;
	gettime(&e.t);
	FILE* fp = fopen("hishob.txt","a");
	fprintf(fp,"%02d/%02d/%02d\t\t%04d\t\t%20s\n\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,bal,"Balance");
	
	char c = 'y';
	while(c == 'y' || c == 'Y')
	{
		// Get Entry
		getentry(&e,fp,&c);
		bal += e.amount;
	}
	fprintf(fp,"%02d/%02d/%02d\t\t%04d\t\t%20s\n\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,bal,"Balance");
	
	// Update Balance
	f = fopen("bal.raw","w");
	fwrite(&bal,sizeof(int),1,f);
	fwrite(&e.t,sizeof(time_t),1,f);
	fclose(f);
	fclose(fp);
	printf("Exit Code Zero !\n");
	return 0;
}
	
	
