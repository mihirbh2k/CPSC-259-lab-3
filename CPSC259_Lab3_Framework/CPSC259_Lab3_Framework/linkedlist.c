/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Mihir Bhatia and Peter Hancak
 Student #s:   76149921 and 89283139
 CS Accounts:  mbhati01 and l7i9m
 Date:         23rd october
 */

 /* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

 /*
  Returns a pointer to a new, empty linked list of struct node.
  PRE:       NULL (no pre-conditions)
  POST:      NULL (no side-effects)
  RETURN:    A pointer to a new, empty linked list of struct node (NULL)
  */
struct node* create_linked_list()
{
    struct node* ptr = NULL;
    return ptr;

}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
struct node* create_node(struct airplane plane)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->plane.flight_number = plane.flight_number;
    new_node->plane.city_origin = plane.city_origin;
    new_node->plane.city_destination = plane.city_destination;
    new_node->plane.priority = plane.priority;
    new_node->plane.maximum_speed_kph = plane.maximum_speed_kph;
    new_node->plane.cruising_altitude = plane.cruising_altitude;
    new_node->plane.capacity = plane.capacity;
    new_node->next = NULL;
    return new_node;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_mode is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
struct node* prepend_node(struct node* list, struct node* new_node)
{
    if (list == NULL) {
        list = new_node;

    }
    else {
        struct node* temp = list;
        list = new_node;
        new_node->next = temp;
    }

    return list;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
struct node* delete_node(struct node* list)
{
    // Insert your code here
    if (list == NULL) {
        return NULL;
    }
    else {
        struct node* nextNode = list->next; //keeps a link to the next node
        //Frees the city_origin and city_destination memory
        //free(list->plane.city_origin);
        //free(list->plane.city_destination);
        //Frees the memory location of the current node
        free(list);
        //Returns the pointer to the send node in the list
        return nextNode;
    }



}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(struct node* list)
{

    int count = 0;
    struct node* cursor = list;
    while (cursor != NULL)
    {
        count++;
        cursor = cursor->next;
    }

    return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
struct node* delete_list(struct node* list)
{

    //When there are no nodes in the list return NULL
    if (list == NULL) {
        return NULL;
    }
    //If there are nodes in the list earase the first and then second and so on
    else {
        while (list != NULL) {
            list = delete_node(list);
        }
        return list;
    }
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(struct node* node_to_print)
{
    // Insert your code here
    if (node_to_print == NULL) {
        printf("The node is empty\n");
    }
    else {
        printf("Flight_number: %d\n", node_to_print->plane.flight_number);
        //Prints and tests data for the city_origin pointer
        if (node_to_print->plane.city_origin == NULL) {
            printf("City of origin: Link = NULL\n");
        }
        else {
            printf("City of origin: Link points to address %p\n", node_to_print->plane.city_origin);
        }
        //Prints and tests data for the city_destination pointer
        if (node_to_print->plane.city_destination == NULL) {
            printf("Destination city: Link = NULL\n");
        }
        else {
            printf("Destination city: Link points to address %p\n", node_to_print->plane.city_destination);
        }
        printf("Priority: %d\n", node_to_print->plane.priority);
        printf("Maximum speed (kph): %d\n", node_to_print->plane.maximum_speed_kph);
        printf("Cruising altitude: %d\n", node_to_print->plane.cruising_altitude);
        printf("Capacity: %d\n", node_to_print->plane.capacity);
    }
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(struct node* list_to_print)
{
    // Insert your code here
    struct node* currentNodePointer = list_to_print; //Pointer to current node
    if (list_to_print == NULL) {
        printf("There are no data in the list.");
    }
    else {
        while (currentNodePointer != NULL) {
            print_node(currentNodePointer); //Prints the current node
            printf("\n");
            currentNodePointer = currentNodePointer->next;
        }
    }

}

/*
 Reverses a list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
struct node* reverse(struct node* list)
{
    struct node* current = list;
    struct node* next = NULL;
    struct node* prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    list = prev;

    return list;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
struct node* remove_from_list(struct node* list, char* destination_city)
{
    if (list == NULL) {
        return NULL;
    }
    struct node* currentNode = list;
    struct node* nextNode = NULL;
    struct node* previousNode = NULL; //Keeps a pointer to the previous node
    int firstNode = 1;
    //Erases all matches that would occur in the first spot
    while (firstNode == 1) {
        firstNode = 0; //Assumes the first node will not be deleted
        if (strcmp(list->plane.city_destination, destination_city) == 0) {
            list = delete_node(list);
            firstNode = 1;
        }
        //All nodes are deleted
        if (list == NULL) {
            return NULL; //Returns NULL if all nodes are deleted
        }
    }
    //Erases all remaining matches
    previousNode = list;
    //Checks if there is only one node left in the list - next pointer would be NULL
    if (list->next == NULL) {
        return list;
    }
    else { //There are at lest two nodes left in the list
        currentNode = list->next;
        //Examines the remainder of the list
        do {
            //Checks for the destination city
            if (strcmp(currentNode->plane.city_destination, destination_city) == 0) {
                currentNode = delete_node(currentNode);
                previousNode->next = currentNode;
            }
            else {
                //Moves ahead by one node
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            //Reached the end of the list
            if (currentNode == NULL) {
                return list; //Returns pointer to the start of the list
            }
        } while (1);
    }


}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
struct node* retrieve_nth(struct node* list, int ordinality)
{
    // Insert your code here
    if (list == NULL) {
        return NULL;
    }
    //If the ordinality is greater than the list lentgh
    else if (get_length(list) < ordinality) {
        return NULL;
    }
    else {
        struct node* currentNode = list;
        int nodeNumber = 1;
        do {
            if (nodeNumber == ordinality) {
                return currentNode;
            }
            else {
                nodeNumber = nodeNumber + 1;
                currentNode = currentNode->next;
            }
        } while (1);
    }
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
            correct location
            ELSE a pointer to the unchanged list
 */
struct node* insert_nth(struct node* list, struct node* node_to_insert, int ordinality)
{
    struct node* currentNode = NULL;
    //Empty list
    if (ordinality == 1) {
        //Preappends the node if ordinality is 1
        return prepend_node(list, node_to_insert);
    }
    else if (list == NULL && ordinality > 1) {
        return NULL;
        //Will return the pointer to the list
    }
    else if (ordinality > 1 + get_length(list)) {
        return list;
    }
    //Will append to the list
    else if (ordinality == 1 + get_length(list)) {
        currentNode = list;
        struct node* nextNode = currentNode->next;
        //Locates the last node in list
        while (nextNode != NULL) {
            currentNode = nextNode;
            nextNode = currentNode->next;
        }
        //Adds the last node
        currentNode->next = node_to_insert;
        return list;
    }
    //Locates the node with the specific ordinality and adds the new node
    else {
        //Locates the node
        currentNode = retrieve_nth(list, ordinality - 1);
        //Inserts the new node
        currentNode->next = prepend_node(currentNode->next, node_to_insert);
        return list;
    }

    
 }