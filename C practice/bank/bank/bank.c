# include <stdio.h>
# include <stdlib.h>


// ���α׷� 5.2���� ������ ���� �κ��� �����Ѵ�. 
// ================ ����ť �ڵ� ���� =================
typedef struct { // ��� Ÿ��
	int id;
	int arrival_time;
	int service_time;
} element;			// ��ü!
// ================ ����ť �ڵ� ���� =================
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 60
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== ����ť �ڵ� �� ======

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
		printf("\n����ð� %d ��\n", clock);
		if ((rand() % 7) < arrv_rate) { // �� ����
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % arrv_rate + 1;
			enqueue(&queue, customer);
			cur_wait++;
			printf(" �� %d ��(��) %d�п� ���ɴϴ�. ����ó���ð� : %d��\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time1 > 0) {
			printf("  (â�� 1) �� %d ����ó�����Դϴ�. ���� �ð� : %d�� \n", service_customer1, service_time1);


			service_time1--;
			if (service_time1 == 0) printf("  (â�� 1) �� %d �� ������ ó���Ϸ�Ǿ����ϴ�! \n", service_customer1);
		}

		else {   //�� â����!
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer1 = customer.id;
				service_time1 = customer.service_time;
				cur_wait--;
				service_customer++;
				printf("  (â�� 1) �� %d ��(��) %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}


		if (service_time2 > 0) {
			printf("  (â�� 2) �� %d ����ó�����Դϴ�. ���� �ð� : %d�� \n", service_customer2, service_time2);


			service_time2--;
			if (service_time2 == 0) printf("  (â�� 2) �� %d �� ������ ó���Ϸ�Ǿ����ϴ�! \n", service_customer2);
		}

		else {   //�� â����!
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer2 = customer.id;
				service_time2 = customer.service_time;
				cur_wait--;
				service_customer++;
				printf("  (â�� 2) �� %d ��(��) %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}

		printf("������� ����� %d ��\n", cur_wait);
	}
	printf("\n��ü ��� �ð� : %d �� \n", total_wait);
	printf("������ ���� : %d ��\n", service_customer);
	double avg_wait = (double)total_wait / (double)(service_customer);
	printf("��� ��� �ð� : %d / %d = %.2f�� \n", total_wait, service_customer, avg_wait);
	printf(" 201710272 �̻��� �Դϴ�.");
	return 0;
}