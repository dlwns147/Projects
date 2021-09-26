#include "queue.h"

int main(){

	int n, m, d;
	int time_value;
	int curent_time = 0;
	int people_limit = 0;
	char queue_input;
	queue_t standard_time;
	queue_t fastpass_time;
	queue_t standard_id;
	queue_t fastpass_id;
	init_queue(&standard_time);
	init_queue(&fastpass_time);
	init_queue(&standard_id);
	init_queue(&fastpass_id);

	scanf("%d %d %d", &n, &m, &d);

	// Input for n guests, capacity m, duration d and guest ID & wating type.
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &time_value, &queue_input);
		if (queue_input == 's') {
			enqueue(&standard_time, time_value);
			enqueue(&standard_id, i + 1);
		}
		else if(queue_input == 'f') {
			enqueue(&fastpass_time, time_value);
			enqueue(&fastpass_id, i + 1);
		} 
	}
	time_value = 0;

	// Output of guest ID's per a ride.  
	while (!is_empty(&standard_time) || !is_empty(&fastpass_time))
	{
		// testcode printf("time : %d, tmp : %d\n", curent_time, time_value);

		// When attraction is empty.
		if (!time_value) 
		{	// Fastpass riding on.
			while (!is_empty(&fastpass_time) && peek(&fastpass_time) <= curent_time && people_limit != m)
			{
				dequeue(&fastpass_time);
				printf("%d ", peek(&fastpass_id));
				dequeue(&fastpass_id);
				people_limit++;
			}

			// Standard line riding on.
			while (!is_empty(&standard_time) &&  peek(&standard_time) <= curent_time && people_limit != m)
			{
				dequeue(&standard_time);
				printf("%d ", peek(&standard_id));
				dequeue(&standard_id);
				people_limit++;
			}
			// Setting for When any person takes on the attraction.
			if (people_limit > 0){
				time_value += d;
				people_limit = 0;
				printf("\n");
			}

		}
		if (time_value > 0) time_value--;
		curent_time++;
	}

	return 0;
}