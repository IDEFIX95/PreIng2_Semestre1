#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("La file est vide.\n");
        exit(1);
    }
    Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return value;
}

void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Aucun client en caisse.\n");
    } else {
        Node* current = queue->front;
        printf("Clients restants en caisse : ");
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Queue* queue = createQueue();

    // Ajout de 3 clients en caisse
    for (int i = 0; i < 3; i++) {
        int articles = (rand() % 50) + 1; // Nombre aléatoire entre 1 et 50
        enqueue(queue, articles);
    }

    int clientPaye;
    int tours = 0;
    while (true) {
        if (isQueueEmpty(queue)) {
            printf("Plus de clients en caisse.\n");
            break;
        }
        printf("Tour %d\n", tours + 1);
        clientPaye = dequeue(queue);
        printf("Client paye avec %d articles.\n", clientPaye);
        printQueue(queue);

        // 33% de chances d'ajouter de nouveaux clients
        int random = rand() % 3;
        if (random == 0) {
            int clientsToAdd = (rand() % 3) + 1; // Ajouter entre 1 et 3 clients
            printf("Ajout de %d nouveaux clients en caisse.\n", clientsToAdd);
            for (int i = 0; i < clientsToAdd; i++) {
                int articles = (rand() % 50) + 1; // Nombre aléatoire entre 1 et 50
                enqueue(queue, articles);
            }
            printQueue(queue);
        }
        tours++;
    }

    return 0;
}