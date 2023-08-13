#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


/*   data and node structures  */

struct Sdata
{
	int ID;
	char name[20];
	float height;
};

struct Sstudent
{
	struct Sdata data;
	struct Sstudent *next;
};    // this is a golobal variable of type pointer to the first element in the list, this wil not change unless we do a special operation

extern struct Sstudent *p_first_student;

/*  fill function to update the structure of the newly add student node form the AddNode func   */

void fill_record(struct Sstudent *p_new_student);

/*  function to make a new node in the linked list structure   */

void AddNode ();

/*  function to delete selected record from the id given by the user   */

int delete_record();

/*  print data for all nodes  */

void view_students();

/*  delete all nodes if list isnt empty  */

void delete_all();

/*  function to view data of nth student iterativley  */

int getNth ();

/* function to find length of the list ---iterative solution*/

int get_count();

/* get nth from the end*/

int getNth_from_end();

/* get middle of the linked list*/

int get_middle();

/* reversing a linked list with sliding pointer */

int reverse_links();