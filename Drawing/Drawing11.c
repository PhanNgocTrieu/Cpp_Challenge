#include <stdio.h>

int main(void) {
	// remove this for running testcase
	int testcase = 1; 
	int r = 4,c = 4,w = 2,h = 1;

    // uncomment this following statment for running testcase
	// scanf("%d",&testcase);
	
	for (int i = 0; i < testcase; i++)
	{
        // uncomment this following statment for running testcase:
		// scanf("%d",&r);scanf("%d",&c);
		// scanf("%d",&h);scanf("%d",&w);
		
		int count_height = 0;
		int count_width = 0;
		int count_row = 0;
		int count_col = 0;
		
		while (count_row < r)
		{
            // Drawing A Shape before Line
			while(count_height < h)
			{
				while (count_col < c)
				{
					while (count_width < w)
					{
						printf(".");
						count_width++;
					}
					printf("|");
					if (count_col == c - 1)
					{
						count_width = 0;
						while (count_width < w)
						{
							printf(".");
							count_width++;
						}
					}
					count_col++;
					count_width = 0;
				}
				printf("\n");
				count_col = 0;
				count_height++;
			}
			
            // Drawing Line
			while (count_col < c)
			{
				while (count_width < w)
				{
					printf("-");
					count_width++;
				}
				printf("+");
				if (count_col == c - 1)
				{
					count_width = 0;
					while (count_width < w)
					{
						printf("-");
						count_width++;
					}
				}
				count_col++;
				count_width = 0;
			}
			printf("\n");
			count_col = 0;
			count_height = 0;
			count_row++;
		}

        // Drawing last part of Shape belowest of shape
		while(count_height < h)
		{
			while (count_col < c)
			{
				while (count_width < w)
				{
					printf(".");
					count_width++;
				}
				printf("|");
				if (count_col == c - 1)
				{
					count_width = 0;
					while (count_width < w)
					{
						printf(".");
						count_width++;
					}
				}
				count_col++;
				count_width = 0;
			}
			printf("\n");
			count_col = 0;
			count_height++;
		}
	}
	
	
	return 0;
}
