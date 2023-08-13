#include "database.h"

struct Sstudent *p_first_student = NULL;

/*  fill function to update the structure of the newly add student node form the AddNode func   */
void fill_record(struct Sstudent *p_new_student)
{
	char temp_text[20];
	printf("\nEnter the ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &(p_new_student->data.ID));
	

	printf("\nEnter the name: ");
	fflush(stdout);fflush(stdin);
	gets(p_new_student->data.name);

	printf("\nEnter the height: ");
	fflush(stdout);fflush(stdin);
	scanf("%f", &(p_new_student->data.height));
	

}

/*  function to make a new node in the linked list structure   */

void AddNode ()
{
	struct Sstudent *p_new_student;  //temporary pointer to contain added student
	struct Sstudent *p_last_student; 

	if(!p_first_student)                                      // this means this is the first record
	{
		 p_new_student = (struct Sstudent *) malloc(sizeof(struct Sstudent));
		 p_first_student  =p_new_student;
	}
	else                                                       // this means it has records so we need to loop until we find the last record
	{
		p_last_student = p_first_student;
		while(p_last_student->next){                             
			p_last_student = p_last_student->next;            // update last student pointer
		}
		p_new_student = (struct Sstudent *) malloc(sizeof(struct Sstudent));
		p_last_student->next = p_new_student;
	}

	//fill newly allocated node with user given data
	fill_record(p_new_student);

	//last next should point to null
	p_new_student->next = NULL;
}




/*  function to delete selected record from the id given by the user   */

int delete_record(){
	//check if the list is empty
	if(p_first_student){

		int selected_ID;
		printf("\nEnter the selected id for deletion: ");
		fflush(stdout);fflush(stdin);
		scanf("%d", &selected_ID);
	


		//keep record of previous and current nodes
		struct Sstudent *p_selected = p_first_student;
		struct Sstudent *p_previous = NULL;

		//loop untill reaching null
		while(p_selected)
		{	
			// found a match
			if(p_selected->data.ID == selected_ID)
			{
				//check if the selected node is first or not
				if(p_previous)
				{
					p_previous->next = p_selected->next;
				}
				else  //first
				{
					p_first_student = p_selected->next;
				}

				free(p_selected);
				return 1; //delete operation done.
			}

			//update loop
			p_previous = p_selected;
			p_selected = p_selected->next;
		}

		printf("\nno match for this ID. "); return 0; //no match

	}
	else{
		printf("\nList is empty.");return 0; //list is empty
	}
}

/*  print data for all nodes  */

void view_students()
{
	struct Sstudent *p_current_student = p_first_student;
	int count= 0;
	if(!p_current_student){
		printf("\nThe list is empty");
	}
	else{
		while(p_current_student){
			printf("\n========Recored number %d ========", count+1);
			printf("\n\tstudent ID is: %d", p_current_student->data.ID);
			printf("\n\tstudent name is: %s", p_current_student->data.name);
			printf("\n\tstudent height is: %f", p_current_student->data.height);
			p_current_student = p_current_student->next;
			count++;
		}
	}
}

/*  delete all nodes if list isnt empty  */

void delete_all()
{
	struct Sstudent *p_current_student = p_first_student;
	if(!p_current_student){
		printf("\nThe list is empty");
	}
	else{
		while(p_current_student){
			struct Sstudent *p_temp_student = p_current_student;
			p_current_student = p_current_student->next;
			free(p_temp_student);
		}
		p_first_student = NULL;
	}
}

/*  function to view data of nth student iterativley  */

int getNth (){
	if(p_first_student){
		int index,count = 0;
		printf("\nEnter index: ");
		fflush(stdout);fflush(stdin);
		scanf("%d", &index);

		struct Sstudent *p_current_student = p_first_student;
		while(p_current_student){
			if(count == index){
				printf("\n====FOUND====");
				printf("\n\tstudent ID is: %d", p_current_student->data.ID);
				printf("\n\tstudent name is: %s", p_current_student->data.name);
				printf("\n\tstudent height is: %f", p_current_student->data.height);
				return 1;
			}
			count++;
			p_current_student = p_current_student->next;
		}
		printf("\nindex is not in bounds");
		return 0;
	}
	else{
		printf("\nThe list is empty."); return 0;
	}
	
}

/* function to find length of the list ---iterative solution*/

int get_count()
{
	int count = 0;

	struct Sstudent *p_current_student = p_first_student;
	while(p_current_student){
		count++;
		p_current_student = p_current_student->next;
	}
	return count;
}

/* get nth from the end*/

int getNth_from_end(){
	int index,count = 0;
	printf("\nEnter index from end: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &index);
	index = get_count() - index;
	struct Sstudent *p_current_student = p_first_student;
	if(index >= 0){
		while(p_current_student){
			if(count == index){
				printf("\n====FOUND====");
				printf("\n\tstudent ID is: %d", p_current_student->data.ID);
				printf("\n\tstudent name is: %s", p_current_student->data.name);
				printf("\n\tstudent height is: %f", p_current_student->data.height);
				return 1;
			}
			count++;
			p_current_student = p_current_student->next;
		}
		printf("\nout of bounds");
		return 0;
	}
	else{
		printf("\nout of bounds");
		return 0;
	}
}

/* get middle of the linked list*/

int get_middle()
{
	if(p_first_student)
	{
		int count =0, index = get_count()/2;
		struct Sstudent *p_current_student = p_first_student;
		while(p_current_student)
		{
			if(count == index)
			{
				printf("\n====FOUND====");
				printf("\n\tstudent ID is: %d", p_current_student->data.ID);
				printf("\n\tstudent name is: %s", p_current_student->data.name);
				printf("\n\tstudent height is: %f", p_current_student->data.height);
				return 1;
			}
			p_current_student = p_current_student->next;
			count++;
		}
		printf("an Error occured, validate input type."); return 0;
	}
	else
	{
		printf("\nList is empty."); return 0;
	}
}

/* reversing a linked list with sliding pointer */

int reverse_links()
{
	if(p_first_student)
	{
		struct Sstudent *p_current_student = p_first_student;
		struct Sstudent *r = NULL;
		struct Sstudent *q = NULL;
		while (p_current_student)
		{
			r = q;
			q = p_current_student;
			p_current_student = p_current_student->next;
			q->next = r;
		}
		p_first_student = q;
		printf("reversing done."); return 1;
	}
	else
	{
		printf("\nList is empty."); return 0;
	}
}
