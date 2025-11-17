#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Creates a new empty vehicle list
VehicleList* create_list() {
    VehicleList *list = (VehicleList*) malloc(sizeof(VehicleList));
    if (!list) {
        perror("Failed to allocate VehicleList");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// Creates a new vehicle node with given data
Node* create_node(VEHICULE vehicle) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate Node");
        exit(EXIT_FAILURE);
    }
    newNode->data = vehicle;
    newNode->next = NULL;
    return newNode;
}

// Adds a vehicle at the end of the list
void add_vehicle(VehicleList *list, VEHICULE vehicle) {
    Node *newNode = create_node(vehicle);

    // If the list is empty, new node becomes the head
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    // Otherwise, find the last node and attach it
    Node *temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Removes a vehicle by pointer (used when one exits the parking lot)
void remove_vehicle(VehicleList *list, Node *nodeToRemove) {
    if (!list || !list->head || !nodeToRemove)
        return;

    if (list->head == nodeToRemove) {
        list->head = nodeToRemove->next;
        free(nodeToRemove);
        return;
    }

    Node *prev = list->head;
    while (prev->next && prev->next != nodeToRemove)
        prev = prev->next;

    if (prev->next == nodeToRemove) {
        prev->next = nodeToRemove->next;
        free(nodeToRemove);
    }
}

// Frees all nodes and resets the list
void free_list(VehicleList *list) {
    Node *current = list->head;
    Node *nextNode;

    while (current) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    list->head = NULL;
    free(list);
}

// Debugging helper: prints all active vehicles
void print_list(const VehicleList *list) {
    Node *current = list->head;
    int count = 0;

    while (current) {
        printf("Vehicle #%d | Type: %c | Pos: (%d, %d)\n",
               count, current->data.type,
               current->data.posx, current->data.posy);
        current = current->next;
        count++;
    }

    if (count == 0)
        printf("No vehicles in the list.\n");
}
