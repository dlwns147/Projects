#include <stdio.h>
#include <stdlib.h>

#define NUM_QUEUE 4

typedef int data;

typedef struct Process {
    data pid;
    data arrival_time;
    data init_queue;
    data num_cycles;
    data *burst_time;
} process;

typedef struct ProcessNode {
    process proc;
    process *next;
} process_node;

void InitQueue(process_node *root) {
    root = NULL;
}

void PushQueue(process_node *root, process proc) {

    // Make a node that contains the new process.
    process_node *temp = (process_node *)malloc(sizeof(process_node));
    temp->proc = proc;
    temp->next = NULL;

    // When the root node does not have any node.
    if (root == NULL) 
        root = temp;

    // When the root node has any node.
    else {
        process_node *cur = root;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
}

process PopQueue(process_node *root) {
    if (root == NULL) {
        perror("Queue is empty.");
        exit(1);
    }
    process proc = root->proc;
    process_node *temp = root;
    root = root->next;
    free(temp);
    return proc;
}

int main(int argc, char **argv){
    // if (argc == 1) {
    //     printf("There is no input file.");
    //     return 0;
    // }
    // fopen();
    int num_process;
    scanf("%d", &num_process);
    process *process_list =(process *)malloc(sizeof(process) * num_process);
    for (int i = 0; i < num_process; i++) {
        
        scanf("%d %d %d %d", 
                &process_list[i].pid,
                &process_list[i].arrival_time,
                &process_list[i].init_queue,
                &process_list[i].num_cycles);
        int num_burst_time = process_list[i].num_cycles * 2 + 1;
        process_list[i].burst_time = (data *)malloc(sizeof(data) * num_burst_time);
        for (int j = 0; j < num_burst_time; j++) {
            scanf("%d", process_list[i].burst_time[j]);
        }
    }

    return 0;
}