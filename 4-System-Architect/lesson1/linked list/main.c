#include "database.h"


void main()
{

	int choice;
	while(1)
	{
		printf("\n ===================================");
		printf("\n\t choose one option: \n");
		printf("\n 1:Add Student        ");
		printf("\n 2:Delete Student     ");
		printf("\n 3:View Students      ");
		printf("\n 4:Delete All         ");
		printf("\n 5:Get nth student    ");
		printf("\n 6:Length of the list ");
		printf("\n 7:get nth from last  ");
		printf("\n 8:get middle of list ");
		printf("\n 9:reverse the list   ");
		printf("\n Enter option number: ");
		fflush(stdout);fflush(stdin);
		scanf("%d", &choice);
		

		printf("\n ===================================");
		switch(choice)
		{
			case 1:
				AddNode();
				break;
			case 2:
				delete_record();
				break;
			case 3:
				view_students();
				break;
			case 4:
				delete_all();
				break;
			case 5:
				getNth();
				break;
			case 6:
				printf("\ncurrent length is: %d", get_count());
				break;
			case 7:
				getNth_from_end();
				break;
			case 8:
				get_middle();
				break;
			case 9:
				reverse_links();
				break;
			default:
				printf("\n Wrong option");
				break;
		}

	}
	
}