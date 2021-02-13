# include <stdio.h>
# include <stdlib.h>


// 프로그램 5.2에서 다음과 같은 부분을 복사한다. 
// ================ 원형큐 코드 시작 =================
typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
} element;			// 교체!
// ================ 원형큐 코드 종료 =================
// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 60
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main(void)
{
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int cur_wait = 0;
	int service_time1 = 0;
	int service_time2 = 0;
	int service_customer = 0;
	int service_customer1 = 0;
	int service_customer2 = 0;
	int arrv_rate = 4;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("\n현재시각 %d 분\n", clock);
		if ((rand() % 7) < arrv_rate) { // 고객 도착
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % arrv_rate + 1;
			enqueue(&queue, customer);
			cur_wait++;
			printf(" 고객 %d 이(가) %d분에 들어옵니다. 업무처리시간 : %d분\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time1 > 0) {
			printf("  (창구 1) 고객 %d 업무처리중입니다. 남은 시간 : %d분 \n", service_customer1, service_time1);


			service_time1--;
			if (service_time1 == 0) printf("  (창구 1) 고객 %d 의 업무가 처리완료되었습니다! \n", service_customer1);
		}

		else {   //고객 창구로!
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer1 = customer.id;
				service_time1 = customer.service_time;
				cur_wait--;
				service_customer++;
				printf("  (창구 1) 고객 %d 이(가) %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}


		if (service_time2 > 0) {
			printf("  (창구 2) 고객 %d 업무처리중입니다. 남은 시간 : %d분 \n", service_customer2, service_time2);


			service_time2--;
			if (service_time2 == 0) printf("  (창구 2) 고객 %d 의 업무가 처리완료되었습니다! \n", service_customer2);
		}

		else {   //고객 창구로!
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer2 = customer.id;
				service_time2 = customer.service_time;
				cur_wait--;
				service_customer++;
				printf("  (창구 2) 고객 %d 이(가) %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}

		printf("현재까지 대기인 %d 명\n", cur_wait);
	}
	printf("\n전체 대기 시간 : %d 분 \n", total_wait);
	printf("응대한 고객수 : %d 명\n", service_customer);
	double avg_wait = (double)total_wait / (double)(service_customer);
	printf("평균 대기 시간 : %d / %d = %.2f분 \n", total_wait, service_customer, avg_wait);
	printf(" 201710272 이상준 입니다.");
	return 0;
}