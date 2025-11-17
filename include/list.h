#ifndef LIST_H
#define LIST_H

#include "vehicle.h"

// Node structure for linked list
typedef struct Node {
    VEHICULE data;
    struct Node *next;
} Node;

// Vehicle list structure
typedef struct {
    Node *head;
} VehicleList;

// Function prototypes
VehicleList* create_list();
Node* create_node(VEHICULE vehicle);
void add_vehicle(VehicleList *list, VEHICULE vehicle);
void remove_vehicle(VehicleList *list, Node *nodeToRemove);
void free_list(VehicleList *list);
void print_list(const VehicleList *list);

#endif
