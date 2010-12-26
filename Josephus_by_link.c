
//Josephus achieved by linked list.
#include <stdio.h>
#include <malloc.h>
#define M 3           //when say M be killed.
#define N 10          //number of all people.

struct peop {
	int id;
	struct peop * next;
};
struct peop * head;   //head pointer for struct linked list.

/** 
* @brief : creat a new node for linked list.
* 
* @param last: last node member pointer.
* @param id: the new node's id.
* 
* @return :return a pointer that pointed address of the new node.
*/
struct peop * creat_node(struct peop * last, int id)
{
	struct peop * new;
	new = (struct peop *)malloc(sizeof(struct peop));
	new -> id = id;
	new -> next = NULL;
	last -> next = new;
	return new;
}

/** 
* @brief : init the linked list. sure what number be for every node's member.
* 
* @param h_id: head node's id.
*/
void init_linked_list(int h_id)
{
	int i = 3;
	struct peop * a;
	head = (struct peop *)malloc(sizeof(struct peop));
	head -> id = h_id;
	head -> next = NULL;
	a = creat_node(head, h_id + 1);
	for(; i < N + 1; i++) {
		a = creat_node(a, h_id + i - 1);
	}
	a -> next = head;
}

/** 
* @brief : print the linked list every node's member for test.
* 
* @param h:head pointer of a linked list
*/
void print_linked_list(struct peop * h)
{
	struct peop * t = h;
	while (t -> next != head) {
		printf("ID: %d\n",t -> id);
		t = t -> next;
	}
	printf("ID: %d\n",t -> id);
}

/** 
* @brief :live one soldier from N soldiers. killed all say M.
*/
void kill_soldiers(void)
{
	int say = 1;
	struct peop * p, *t;

	p = head;
	while (p -> next != p) {
		if(say%(M - 1) == 0) {
			if (p -> next == head) {
				head = head -> next;
			}
			say = 0;
			printf("Killed: %d\n",p ->next -> id);
			t = p -> next;
			p -> next = p -> next -> next;
			free(t); t = NULL;
		}
		say++;
		p = p -> next;
	}
	printf("The last one: %d\n",head -> id);
	return;
}

int main(int argc, const char *argv[])
{
	init_linked_list(1);
	//print_linked_list (head);
	kill_soldiers();
	return 0;
}
