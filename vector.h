//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_VECTOR_H
#define GAME_CONSOLE_VECTOR_H

typedef struct Vector Vector;

struct Vector {
    void *data;
    Vector *next;
};

Vector *pushback(Vector *head, int data_size);

void *index(Vector *head, int i, int data_size);

int length_list(Vector *head);

void free_vector(Vector* head);

#endif //GAME_CONSOLE_VECTOR_H
