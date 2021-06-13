#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "Fill_the_void.h"
#define _GNU_SOURCE

//create a new node
t_tet* create(int data)
{
    t_tet* new_node = (t_tet*)malloc(sizeof(t_tet));
    if(new_node = NULL)  
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        printf("Error creating a new node");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Push an element into the stack
t_node* push(t_node* head, int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(new_node));
    if(new_node == NULL)
    {
        exit(0);
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

//Count the elements of the linked list
int count(t_tet* head)
{
    t_tet* temp = head;
    int c = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

//Add a new node at the end of the linked list
t_tet* append(t_tet* head, char data)
{
    t_tet* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    t_tet* new_node = create(data);
    temp->next = new_node;
    return head;
} 

//Create a linked of tetriminos 
t_tet* create_list(char block)
{
    t_tet* head = NULL;
    for(int i = 0; i < 16; i++)
    {
        head = append(head, block);
    }
    return head;
}

//Convert linked list to array
void listTo_array(t_tet* head)
{
    int len = count(head);
    int arr[len];
 
    int index = 0;
    t_tet* curr = head;
    while (curr != NULL) {
        arr[index++] = curr->data;
        curr = curr->next;
    }
}

//Moving the Tetrimino the to the top-most left position
void moving_Tetrimino(char array[])
{
    int k = 0;
    for(int i = 0; i < sizeof(*array); i++)
    {
        if(array[i] > 0)
        {
            k = i;
            break;
        }

    }
    for(int i = 0; i < sizeof(*array); i++)
    {
        array[i] = array[i-k-1];
    }
}

//Counting the number of tetriminos
int counting_tetriminos(t_tet *tet)
{
    int k = 0;
    t_tet *temp;
    temp = tet;
    while(temp != NULL)
    {
        k++;
        temp = temp->next;
    }
    k++;
    return k;
}

//Counting blocks (#)
int counting_blocks(char *character)
{
    int k = 0;
    if(!character)
        return 0;
    while(*character)
    {
        if (*character == '#')
            k++;
        character++;
    }
    return k;
}

int check_char(char *character)
{
    if(!character)
        return 0;
    while(*character)
    {
        if (*character != 0  && *character != '#')
            return 0;
        character++;
    }
    return 1;
}

//Comparing two arrays
_Bool compare_arrays(char array[])
{
    for(int i = 1; i < sizeof(*array); i++)
    {
        
        if(array[i] =! I_1[i] || array[i] != I_2[i] || array[i] != O[i] || array[i] != T_2[i] || array[i] != T_3[i] || array[i] != T_4[i] || array[i] != L_1[i] || array[i] != L_2[i] || array[i] != L_3[i] || array[i] != L_4[i] || array[i] != Z_1[i] || array[i] != Z_2[i])
            return false;
        return true;
    }
}

int check_tetrimino(char array[])
{
    if(compare_arrays(array) == 1)
        return 1;
    return 0;
}

//Read file
void read_file()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("Tetriminos.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }
    fclose(fp);
    if (line)
        free(line);
}

//Find the assignment location
int assign_loc(char array[], int s, int j)
{
    s = array_size;
    int i = j; 
    while(i < array_size)
    {
        if(array[i] == 0)
            return j;
        i++;
    }
}

//A function to assign a block to an empty space
t_node* assign_tet(t_node* stack, char array_1[], char array_2[], int i)
{
    int j = 0;
    while(j != i)
    {
        stack = push(stack, array_1[j]);
        j++;
    }
    stack = push(stack, '#');
    return stack;
}

//Recursive function to check if the assignment does work or not, if so return the solution
t_node* recur_assign(char array_1[], char array_2[], int k)
{
    k = assign_loc(array_1, array_size, 0);
    t_node* stack = NULL;
    stack = assign_tet(stack, array_1, array_2, k);
    return recur_assign(array_1, array_2, assign_loc(array_1, array_size, k));
}

//Check if the assignment is valid
_Bool check_assign(char array_1[], char array_2[])
{
    int j = 0;
    char array[16];
    while(j < array_size)
    {
        if(array_1[j] == '#')
            array[j] == 0;
        if(array_1[j] == 0)
        {
            if(counting_blocks(array) <= 4)
                array[j] == '#';
            else
                array[j] == 0;
        }
        j++;
    }
    if(compare_arrays(array) && array == array_2)
        return true;
    else
        return false;
}

//Create a function to shift a Tetrimino
void shift_left(char array[])
{
    if(array[0] == array[4] == array[8] == array[12] == '#')
        return;
    for(int i = 0; i < 16; i++)
        array[i-1] = array[i];
}

void shift_right(char array[])
{
    if(array[3] == array[7] == array[11] == array[15] == '#')
        return;
    for(int i = 0; i < 16; i++)
        array[i] = array[i+1];
}

void shift_up(char array[])
{
    if(array[0] == array[1] == array[2] == array[3] == '#')
        return;
    for(int i = 0; i < 16; i++)
        array[i] = array[i-4];
}

void shift_down(char array[])
{
    if(array[12] == array[13] == array[14] == array[15] == '#')
        return;
    for(int i = 0; i < 16; i++)
        array[i] = array[i+4];
}

//Return the solution
t_node* solve(char array_1[], char array_2[], int k)
{
    t_node* stack = NULL;
    if(check_assign)
        stack = recur_assign(array_1, array_2, k);
    else
    {
        shift_left(array_2);
        stack = solve(array_1, array_2, k);
        shift_right(array_2);
        stack = solve(array_1, array_2, k);
        shift_up(array_2);
        stack = solve(array_1, array_2, k);
        shift_down(array_2);
        stack = solve(array_1, array_2, k);
    }
    return stack;
}

//Print solution
void display(t_node* stack)
{
    if(stack == NULL)
    {
        return;
    }
    t_node* temp = stack;
    printf("Stack : ");
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{

    return 0;
}
