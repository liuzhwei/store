
// oprating about linked list.
#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct stu {	
	int id;
	int chinese;
	char name[256];
	struct stu * next;
};
struct stu *head, * a;

/** 
* @brief :creat a node for linked_list.
* 
* @param last : pointer ,pointing to the last node.
* @param id :       member of struct stu
* @param chinese :  member of struct stu
* @param name :     member of struct stu
* 
* @return : return the new node pointer.
*/
struct stu * creat_node(struct stu * last, int id, int chinese, char * name)
{
	struct stu * p = (struct stu *)malloc(sizeof(struct stu));
	p -> id = id;
	p -> chinese = chinese;
	strcpy(p -> name,name);
	p -> next = NULL;
	last -> next = p;
	return p;
}

/** 
* @brief : ergodic(bian li) and print linked_list(lian biao).
* 
* @param p: recieve linked_list's head point to save the point don't be modified.
*/
void print_n(struct stu * p)
{
	struct stu * t = p;
	while(t != NULL) {           //ergodic(bian li) /traveral
		printf("ID: %d\tChinese: %d\tName: %s\n",t -> id,t -> chinese,t -> name);
		t = t -> next;
	}
}

/** 
* @brief :creat and init linked list.
*/
void init(void)
{
	head = (struct stu *)malloc(sizeof(struct stu));
	head -> id = 0;
	head -> chinese = 99;
	strcpy(head -> name,"AAAAA");
	head -> next = NULL;
	a = creat_node(head,1,81,"BBBBB");
	a = creat_node(a,2,82,"CCCCC");
	a = creat_node(a,3,83,"DDDDD");
	a = creat_node(a,4,84,"EEEEE");
	a = creat_node(a,5,85,"FFFFF");
	a = creat_node(a,6,86,"GGGGG");
	a = creat_node(a,7,87,"HHHHH");

}

/** 
* @brief : Delete a node in linked_list as it's id is 3.
* 
* @param t: head pointer of linked_list.
*/
void delete_node(struct stu * t)
{
	struct stu * del, * p;
	p = t;
	while (p -> next -> id != 3) {    //traveral
		p = p -> next;
	}
	del = p -> next;
	p -> next = p -> next -> next;
	free(del);
}

/** 
* @brief :added a node in linked list at next of it's id is 2.
* 
* @param t : head pointer of linked list.
*/
void add_node(struct stu * t)
{
	struct stu *p, *add;
	add = (struct stu * )malloc(sizeof(struct stu));
	add -> id = 3;
	add -> chinese = 100;
	strcpy(add -> name,"added one");
	p = t;
	while (p -> id != 2) {      //traveral
		p = p -> next;
	}
	add ->next = p -> next;
	p -> next = add;
}

int main(int argc, const char *argv[])
{
	init();                //init and print
	print_n(head);
	printf("\n");

	delete_node(head);     //delete and print
	print_n(head);
	printf("\n");

	add_node(head);        //added and print
	print_n(head);
	printf("\n");

	return 0;
}
