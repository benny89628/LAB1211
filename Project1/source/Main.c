#include <stdlib.h>
#include <stdio.h>
typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;

int main()
{
	student data[5];
	FILE *stream1, *stream2;
	stream1 = fopen("D://gradedata.txt", "r");
	stream2 = fopen("D://gradeoutput.txt", "w");

	if (stream1 == NULL || stream2==NULL)
	{
		printf("fail");
	}
	else
	{
		fprintf(stream2, "name\t國\t英\t數\t綜\t平均\n");
		for (int i = 0; i < 5; i++)
		{
			fscanf(stream1, "%s", data[i].name);
			fscanf(stream1, "\t%d", &data[i].chinese);
			fscanf(stream1, "\t%d", &data[i].english);
			fscanf(stream1, "\t%d", &data[i].math);
			data[i].sum = data[i].chinese + data[i].math + data[i].english;
			data[i].avg = data[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", data[i].name,
				data[i].chinese, data[i].english, data[i].math, data[i].sum, data[i].avg);
		}
		fclose(stream1);
		fclose(stream2);
	}
	system("PAUSE");
	return 0;
}