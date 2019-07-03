//
// Created by Aref on 19/06/30.
//

#include <malloc.h>
#include "vector.h"

Vector *pushback(Vector *head, int data_size) {
    Vector *new = (Vector *) malloc(sizeof(Vector) * 1);
    if (data_size == 0)
        new->data = NULL;
    else
        new->data = malloc(data_size * 1);
    new->next = NULL;
    if (head == NULL)
        return new;
    while (head->next != NULL)
        head = head->next;
    head->next = new;
    return new;
}

void *index(Vector *head, int i, int data_size) {
//    while (i--)
//        head = head->next;
//    return head->data;
    int j = 0;
    for (Vector *it = head; it != NULL; it = it->next) {
        if (it->data == NULL)
            continue;
        if (j == i)
            return it->data;
        j += 1;
    }
    return NULL;
}

int length_list(Vector *head) {
    int n = 0;
    for (Vector *it = head; it != NULL; it = it->next)
        if (it->data != NULL)
            n += 1;
    return n;
}

void free_vector(Vector *head) {
    for (Vector *it = head; it != NULL;) {
        free(it->data);
        Vector *tmp = it;
        it = it->next;
        free(tmp);
    }
}

Object *find_by_point(Vector *head, Point x) {
    if (same_point(x, INVALID_POINT))
        return NULL;
    for (Vector *it = head; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *obj = (Object *) it->data;
        if (same_point(obj->point, INVALID_POINT))
            continue;
        if(same_point(obj->point, x))
            return obj;
    }
    return NULL;
}
