#include <stdio.h>
#include <malloc.h>
#include <string.h>


struct stu{
	int id;
	int chinese;
	int math;
	int average;
	char name[128];
	struct stu * next;
};
typedef struct stu stu_t;
stu_t * head;

stu_t * creat_node(stu_t * last, int id, int chinese, int math,char * name)
{
	stu_t * p;

	p = (stu_t *)malloc(sizeof(stu_t));
	p -> next = last;
	p -> id = id;
	p -> chinese = chinese;
	p -> math = math;
	p -> average = (chinese + math)/2;
	strcpy(p -> name,name);

	return p;
}

stu_t * creat_link(void)
{
	stu_t * q;

	q = (stu_t*)malloc(sizeof(stu_t));
	q -> next = NULL;
	q -> id = 6;
	q -> chinese = 90;
	q -> math = 80;
	q -> average = 85;
	strcpy(q -> name,"liuliu");

	q = creat_node(q,5,95,95,"weiwei");
	q = creat_node(q,4,98,98,"xiaoming");
	q = creat_node(q,3,55,50,"liangliang");
	q = creat_node(q,2,86,55,"tongtong");
	q = creat_node(q,1,83,76,"xixi");

	return q;
}

void print_l(stu_t * p)
{
	stu_t * k = p;
		printf("-----------------------------------------------\n");
		printf("  ID      Name       Chinese    Math    Average  \n");
	while(k != NULL) {
		printf("  %d     %-10s    %d        %d       %d      \n",k -> id,
				k -> name,k -> chinese,k -> math,k -> average);
		k = k-> next;
	}
	printf("-----------------------------------------------\n");
}

stu_t * sort_l(stu_t * k)
{
	stu_t * h, * q, * ht,* t = k, *pp;

	q = t -> next;
	t -> next = NULL;
	h = t;
	t = q;
	while(t != NULL) {
		q = t -> next;
		t -> next = NULL;
		ht = h;
		while(ht -> next != NULL)
			ht = ht -> next;
		if(t -> average >= h -> average) {    //max
			t -> next = h;
			h = t;
		}
		else {
			if(t -> average < ht -> average)   //min
				ht -> next = t;
			else {                             //mid 
				ht = h;
				while(ht -> next -> average > t -> average) 
					ht = ht -> next;
				t -> next = ht -> next;
				ht -> next = t;
			}
		}
		t = q;
	}

	return h;
}

stu_t * add_node(stu_t * h,int i,char * s,int c,int m)
{
	stu_t * p, * t;
	p = h;
	t = (stu_t *)malloc(sizeof(stu_t));
	t -> id = i;
	t -> chinese = c;
	t -> math = m;
	t -> average = (c + m)/2;
	strcpy(t -> name,s);
	t -> next = p;
	p = t;

	return p;
}

stu_t * deleter_node(stu_t * h)
{
	stu_t * p = h, * q = h, * t;
	int k;

	printf("Plese input ID:");
	scanf("%d",&k);
	if(h -> id == k){   //the first one is what we seek.
		p = h -> next;
		h -> next = NULL;
		free(h); h = NULL;
		return p;
	} 
	else {
		p = h; q = h;
		while(q ->next != NULL && q -> next -> id != k)
			q = q -> next;
		if(q -> next == NULL) {
			printf("No ID %d exist!\n",k);
			return p;
		}
		else {
		t = q -> next;
		q -> next = t -> next;
		t -> next = NULL;
		free(t); t = NULL;
		}
    }

	return p;
}

stu_t * deleter_by_name(stu_t * h)
{
	stu_t * p = h, * t = h;
	char s[128];

	printf("Please input your choice(name):");
	scanf("%s",s);
	printf("%s\n",s);
	if(!strcmp(h -> name,s)) {
		p = h -> next;
		t -> next = NULL;
		free(t); t = NULL;
		return p;
	}
	else {
		while(t -> next != NULL && strcmp(t -> next -> name,s) != 0)
			t = t -> next;
		if(t -> next == NULL) {
			printf("No the name %s exist\n",s);
			return p;
		}
		else {
			h = t -> next;
			t -> next = t -> next -> next;
			free(h); h = NULL;
		}
	}
	return p;
}

int main(int argc, const char *argv[])
{
	int chinese = 0, math = 0, id = 0, i = 0, j = 0;
	char n[128];
	head = creat_link();
kk:	
	printf("Please select the option:\n1.Display all student's info\n2.Sort by average\n\
3.Insert a new info\n4.Deleter a recored\n5.Quit\nPlease input your choice:");
	scanf("%d",&i);
	switch(i){
		case 1:
			print_l(head);
			goto kk;
			break;
		case 2:
			head = sort_l(head);
			print_l(head);
			goto kk;
			break;
		case 3:
			printf("Please info the new info(ID Name Chinese Math)\n");
			scanf("%d %s %d %d",&id,n,&chinese,&math);
			head = add_node(head,id,n,chinese,math);
		//	print_l(head);
			goto kk;
			break;
		case 4:
			printf("Plese choose the way:\n1.Deleter by ID\n2.Deleter by name\n\
3.Exit\nyour choice:");
			scanf("%d",&j);
			if(j == 1) 
				head = deleter_node(head);
			if(j == 2){
				head = deleter_by_name(head);
			}
			goto kk;
			break;
		case 5:
			return 0;
			break;
	}
	return 0;
}
