#ifndef __PRINTING_H__
#define __PRINTING_H__

void bangCuuChuong()
{
	int i;
	int j;
	
	for (i = 1; i < 10; i++)
	{
		j = 1;
		
		do
		{
			printf("    %dx%d = %d    ",j,i,i*j);
			j++;
		}while(j < 10);
		
		printf("\n");
	}
}



#endif // __PRINTING_H__
