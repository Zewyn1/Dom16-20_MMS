#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pthread.h>
#include <uastrfnc.h>

pid_t fork();

void *thread_function(void *arg)
{
    char *str = (char *)arg;
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(){
    int N;
    printf("Enter the number of threads: ");
    scanf("%d", &N);
    pthread_t threads[N];
    for(int i = 0; i < N; i++){
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }
    for(int i = 0; i < N; i++){
        pthread_join(threads[i], NULL);
    }
    int num_files;
    printf("Enter the number of files: ");
    scanf("%d", &num_files);
    char *files[num_files];
    for(int i = 0; i < num_files; i++){
        printf("Enter the name of the file: ");
        scanf("%s", files[i]);
    }
    int P, T;
    char *msg;
    printf("Enter the number of processes: ");
    scanf("%d", &P);
    printf("Enter the number of threads: ");
    scanf("%d", &T);
    printf("Enter the message: ");
    scanf("%s", msg);
    pid_t pids[P];
    for(int i = 0; i < P; i++){
        pids[i] = fork();
    }
    pthread_t threads_p[P][T];
    for(int i = 0; i < P; i++){
        for(int j = 0; j < T; j++){
            pthread_create(&threads_p[i][j], NULL, thread_function, msg);
        }
    }
    for(int i = 0; i < P; i++){
        for(int j = 0; j < T; j++){
            pthread_join(threads_p[i][j], NULL);
        }
    }
    for(int i = 0; i < P; i++){
        if(pids[i] == 0){
            printf("Process %d: ", i);
            for(int j = 0; j < T; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    int max_products = 10;
    struct product{
        char name[20];
        int amount;
        int price;
        struct product *next;
    };
    struct product *head = NULL;
    struct product *current = NULL;
    struct product *new_product = NULL;
    struct product *temp = NULL;
    int choice;
    while(1) {
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Show all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (head == NULL) {
                    head = (struct product *) malloc(sizeof(struct product));
                    current = head;
                } else {
                    new_product = (struct product *) malloc(sizeof(struct product));
                    current->next = new_product;
                    current = new_product;
                }
                printf("Enter the name of the product: ");
                scanf("%s", current->name);
                printf("Enter the amount of the product: ");
                scanf("%d", &current->amount);
                printf("Enter the price of the product: ");
                scanf("%d", &current->price);
                current->next = NULL;
                break;
            case 2:
                if (head == NULL) {
                    printf("The warehouse is empty\n");
                } else {
                    printf("Enter the name of the product: ");
                    scanf("%s", temp->name);
                    temp = head;
                    while (temp != NULL) {
                        if (strcmp(temp->name, temp->name) == 0) {
                            temp->amount -= 1;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("The product is not in the warehouse\n");
                    }
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("The warehouse is empty\n");
                } else {
                    temp = head;
                    while (temp != NULL) {
                        printf("%s %d %d\n", temp->name, temp->amount, temp->price);
                        temp = temp->next;
                    }
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
pid_t fork() {
    return 0;
}
