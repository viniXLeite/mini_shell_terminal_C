#include <stdio.h>
#include <stdlib.h>

#ifndef __QUEUE__
#define __QUEUE__

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef struct queue_t {
    void* data;
    struct queue_t *next;
    struct queue_t *prev;
} queue_t;

void print_elem (void *ptr) {
    queue_t* elem = (queue_t*) ptr; // Atribui o tipo queue para ptr
    char *str = (char*) elem->data;

    printf("%s, ", str);
    return;
}

int queue_size (queue_t *queue) {
    int size = 0;
    queue_t* current = queue;
    queue_t* head =  queue;

    // Caso a lista esteja vazia 
    if (queue == NULL) return 0; 

    while (current->next != head) {
        size++;
        current = current->next;
    }

    return size+1;
}

int queue_append (queue_t **queue, queue_t *elem) {
    // Deferencia o ponteiro o ponteiro de ponteiro
    queue_t *head = *queue;
    queue_t *current = *queue;

    // Trata o caso da lista estar vazia
    if ((*queue) == NULL) {
        
        (*queue) = elem; // Utiliza o espaço alocado para 'elem'
        (*queue)->data = elem->data;
        (*queue)->next = (*queue);
        (*queue)->prev = (*queue);
        
        return 0;
    }

    else {
        // Percorre a lista até encontrar a cauda dela        
        while (current->next != head) {
            current = current->next;
        }
        // Adiciona elem ao último nó da lista
        current->next = elem;
        elem->prev = current;
        elem->next = head;
    }
    
    if (elem->prev == current && elem->next == head) {
        return 0;
    }
    else return -1;
}


void queue_print (char* name, queue_t *queue, void print_elem (void*) ) {
    queue_t *head = queue;
    queue_t *current =  queue;
    
    // Verifica se a lisra está vazia
    if (queue == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    else {
        print_elem(current);
        while (current->next != head) {
            current = current->next;
            print_elem(current);
        }
    }
    printf("\n\n");
}

// Ver se funciona
int queue_remove (queue_t **queue, queue_t *elem) {
    queue_t *head = *queue;
    queue_t *tail = *queue;
    queue_t *current = *queue;
    queue_t *node = NULL;

    // Verifica se a fila e se o elemento existem, caso não retorna -1
    if (*queue == NULL || elem == NULL) return -1;
    
    else {
        // Verifica se o elem pertence à lista
        while (current->next != head) {

            if (current == elem) {
                node = current;
                current = current->next;
            }
            else current = current->next;
        
        }
 
        // Armazena o valor da cauda da lista
        tail = current; 

        // Caso em que o elem é igual a cauda
        if (elem == tail) node = tail;

        // Caso em que o elem não pertence à lista
        if (node == NULL) return -1;

        // Caso em que o elem pertece à lista
        else {
            // Caso em que elem é igual à cabeça
            if (node == head) {
                // Caso em que a lista contém apenas um elemento
                if (queue_size((*queue)) == 1) {
                    (*queue) = NULL;
                    return 0;
                }

                else {
                    node->next->prev = tail;
                    tail->next = node->next;
                    // Substitui a cabeça da lista
                    (*queue) = node->next;
                }
            }

            // Caso que elem é igual à cauda
            else if (node == tail) {
                node->prev->next = head;
                head->prev = node->prev;
            }

            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            // Retorna 0 caso a remoção seja bem sucedida
            return 0; 
        }

    }

    // Retorna -1 caso haja algum erro na remoção de elem
    return -1;
}


#endif

