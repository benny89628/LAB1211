#include <stdlib.h>
#include <stdio.h>
typedef struct clientData
{
	int accNum;
	char lastName[15];
	char firstName[10];
	double balance;
};

int main()
{
	FILE *pRead, *pWrite, *cfPtr;
	int cnt = 0;
	struct  clientData client = { 0,"","",0.0 };
	pRead = fopen("D://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}
	pWrite = fopen("D://credit_bin.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf(pRead, "%d%s%s%lf", &client.accNum, client.lastName, client.firstName, &client.balance);
		fwrite(&client, sizeof(struct  clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);

	}
	fclose(pRead);
	fclose(pWrite);
	printf("OK ACSII\n\n");
	system("PAUSE");
	printf("\nŪ����X�p�U:\n");
	if ((cfPtr = fopen("D://credit_bin.txt", "rb")) == NULL)
	{
		printf("fail\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
		cnt = fread(&client, sizeof(struct  clientData),1, cfPtr);

		while (cnt>0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.accNum,client.lastName,client.firstName,client.balance);
			cnt = fread(&client, sizeof(struct  clientData), 1, cfPtr);

		}
		fclose(cfPtr);
	}
	system("PAUSE");
	return 0;
	
	
	
}