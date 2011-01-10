#include <stdio.h>

typedef struct {
	int hour;
	int minute;
	int second;
}Clock_t;

void update(Clock_t * t)
{
	t -> second++;
	if(t -> second == 60) {
		t ->second = 0;
		t -> minute++;
	}
	if(t -> minute == 60) {
		t -> minute = 0;
		t -> hour++;
	}
	if(t -> hour == 24) {
		t -> hour = 0;
	}
}
int main(int argc, const char *argv[])
{
	Clock_t myclock;
	myclock.hour = myclock.minute = myclock.second = 0;
	while(1) {
		update(&myclock);
		printf("%02d:%02d:%02d\n",myclock.hour,myclock.minute,myclock.second);
		sleep(1);
		system("clear");
	}
	return 0;
}
