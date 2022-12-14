// list/list.c
//
// Implementation for linked list.
//
// <Author>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
  }
node_t *node_alloc(){
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->next = NULL;
  return node;

}
void node_free(node_t *n){
  free(n);

}
void list_free(list_t *l) {
  node_t *current = l->head;
  while (current){
    node_t *temp = current;
    current = current->next;
    free(temp);
  }
  free(l->head);
  l->head = NULL;
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while (current){
    printf("%d " ,current->value);
    current = current->next;
  }
}

int list_length(list_t *l) { 
  int counter = 0;
  node_t *current = l->head;
  while (current){
    counter++;
    current = current->next;
  }
  return counter; }

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = node_alloc();
  new_node->value = value;
  node_t *current = l->head;
  if (l->head){
    while(current->next){
      current = current->next;
    }
    current->next = new_node;
  }
  else{
    l->head = new_node;
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = node_alloc();
  new_node->value = value;
  if (l->head){
    new_node->next = l->head;
    l->head = new_node;
  }
  else{
    l->head = new_node;
  }

}
void list_add_at_index(list_t *l, elem value, int index) {
  int counter = 0;
  node_t *new_node = node_alloc();
  new_node->value = value;
  node_t *current = l->head;

  if(index == 0){
    list_add_to_front(l,value);
  }
  else if (l->head){
    while(counter != index-1){
      current = current->next;
      counter++;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
  else{
    l->head = new_node;
  }
}

elem list_remove_from_back(list_t *l) { 
  if (list_length(l) == 1){
    node_t* temp = l -> head;
    elem val = temp->value;
    free(temp);
    l->head = NULL;
    return val;
  }
  node_t* current = l -> head;
  while(current->next->next != NULL){
    current = current -> next;
  }
  node_t* temp = current -> next;
  elem val = temp->value;
  free(temp);
  current -> next = NULL;
  return val;
}
elem list_remove_from_front(list_t *l) { 
  node_t *temp = l -> head;
  if (temp != NULL){
  l -> head = temp -> next;
  elem val = temp->value;
  free(temp);
  return temp -> value;
  }
  return -1; 
  }
elem list_remove_at_index(list_t *l, int index) { node_t *temp = l -> head;
  int i;
  if (index == 0){
    temp = temp->next;
    temp->next = NULL;
    elem output = temp->value;
    free(temp);
    return output;
  }
  else{
    for(i=0; i < index - 1; i++){
      temp = temp->next;
    }
    node_t* del = temp->next;
    temp->next = temp->next->next;
    printf("\nElement deleted is : %d\n", del->value);
    elem output = del->value;
    del->next = NULL;
    free(del);
    return output;
  }
  }

bool list_is_in(list_t *l, elem value) { 
  if (l->head == NULL){
    return false;
  }
  else{
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return true;
      }
      current = current->next;
    }
  }
  return false; 
  }

elem list_get_elem_at(list_t *l, int index) { 
  int counter = 0;
  node_t *current = l->head;
  if (l->head){
    while(counter != index){
      current = current->next;
      counter++;
    }
    return current->value;
  }
  else{
    return -1;
  }
} 
  

int list_get_index_of(list_t *l, elem value) { 
  if (l->head == NULL){
    return -1;
  }
  else{
    int counter = 0;
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return counter;
      }
      current = current->next;
      counter++ ;
    }
  }
  return -1;
  }



