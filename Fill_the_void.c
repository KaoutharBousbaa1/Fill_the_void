# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "Fill_the_void.h"
# include "mylibrary.h"
# define TETRI_SIZE 20


//create a new node
t_tet* create(char data)
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
t_node* push(t_node* head, char data)
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
char* listTo_array(t_tet* head)
{
    int len = count(head);
    char* arr = malloc(len * sizeof(char));
    int index = 0;
    t_tet* curr = head;
    while (curr != NULL) {
        arr[index++] = curr->data;
        curr = curr->next;
    }
    return arr;
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

//Compare two arrays
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
t_node* assign_tet(t_node* stack, t_tet* list, int i)
{
    int j = 0;
    while(j != i)
    {
        char* arr = listTo_array(list);
        stack = push(stack, arr[j]);
        list = list->next;
        j++;
    }
    stack = push(stack, '#');
    return stack;
}

//Recursive function to check if the assignment does work or not, if so return the solution
t_node* recur_assign(t_tet* list, int k)
{
    char* arr = listTo_array(list);
    list = list->next;
    k = assign_loc(arr, array_size, 0);
    t_node* stack = NULL;
    stack = assign_tet(stack, list, k);
    return recur_assign(list, assign_loc(arr, array_size, k));
}

//Check if the assignment is valid
_Bool check_assign(char array_1[], char array_2[])
{
    int j = 0;
    char* array = malloc(16 * sizeof(char));
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
t_node* solve(t_tet* list, int k)
{
    t_node* stack = NULL;
    if(check_assign)
        stack = recur_assign(list, k);
    else
    {
        char* arr = listTo_array(list);
        shift_left(arr);
        stack = solve(list, k);
        
        list = list->next;
        arr = listTo_array(list);
        shift_right(arr);
        stack = solve(list, k);

        list = list->next;
        arr = listTo_array(list);
        shift_up(arr);
        stack = solve(list, k);

        list = list->next;
        arr = listTo_array(list);
        shift_down(arr);
        stack = solve(list->next, k);
    }
    return stack;
}

//Print solution
void display(t_node* stack)
{
    int k = 0;
    if(stack == NULL)
    {
        return;
    }
    t_node* temp = stack;
    printf("Stack : ");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        k++;
        if(k > 4)
        {
            printf("\n");
            k = 0;
        }
        temp = temp->next;
    }
}

//Free list
void liberer(t_tet* L)
{
    while(L != NULL)
    {
        t_tet* temp = L;
        L = L->next;
        free(temp);
    }
}

//Read line
char* readline(char *in) 
{
    char *cptr;
    if (cptr = fgets(in, 10, stdin))
    {
    while(*cptr == ' ' || *cptr == '\t')
       cptr++;
    return cptr;
    }    
    else 
        return 0;
}

//Check if it is an empty line
int check_line(char* ptr)
{
    ptr = readline(ptr);
    while(*ptr==' ' || *ptr=='\t' || *ptr=='\n' || *ptr=='\r')
        ptr++;
    if(*ptr=='\0')
        return 1;
    return 0;
}
int		validate_newlines(char* tetrimino_str, int* ends_in_newline)
{
	int newline_placement;

	newline_placement = TETRI_SIZE - 1;
	while (newline_placement > 0)
	{
		if (tetrimino_str[newline_placement] != '\n')
			return (-1);
		newline_placement = newline_placement - 5;
	}
	if (tetrimino_str[TETRI_SIZE] != '\n' && tetrimino_str[TETRI_SIZE] != '\0')
		return (-1);
	if (tetrimino_str[TETRI_SIZE] != '\0')
		*ends_in_newline = 1;
	else
		*ends_in_newline = 0;
	return (0);
}

//Checks that the file passed in does not contain more than 26 or less than 1 tetrimino
int		check_tetrimino_count(int count)
{
	if (count > 26 || count < 0)
		return (-1);
	return (0);
}

//Reads the tetriminoes from a file that has already been opened, adding them to a linked list as it goes
t_tet* read_tetriminoes(int fd)
{
	char*   tetrimino_str;
	int		ends_in_newline;
	int		tetri_cnt;
	t_tet	*tail;
	t_tet	*head;

	tetrimino_str = ft_strnew(TETRI_SIZE + 1);
	tetri_cnt = 0;
	while (read(fd, tetrimino_str, (TETRI_SIZE + 1)))
	{
		if (validate_newlines(tetrimino_str, &ends_in_newline) == -1 ||
			check_tetrimino_count(tetri_cnt + 1) == -1)
			return (NULL);
		tetrimino_str[TETRI_SIZE] = '\0';
		if (lstadd_tetri(&head, &tail, tetrimino_str, tetri_cnt) == -1)
			return (NULL);
		ft_bzero(tetrimino_str, TETRI_SIZE + 1);
		tetri_cnt++;
	}
	ft_strdel(&tetrimino_str);
	if (tetri_cnt == 0 || ends_in_newline == 1)
		return (NULL);
	return (head);
}

//Takes in a file, opens it, reads the file, gets the tetriminoes and returns them in a linked list.
t_tet* get_tetriminoes_from_file(const char *filename)
{
	int		fd;
	t_tet* tetri_lst;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (!(tetri_lst = read_tetriminoes(fd)))
	{
		close(fd);
		return (NULL);
	}
	if ((close(fd) == -1))
		return (NULL);
	return (tetri_lst);
}

int main (int argc, char **argv) 
{ 
    char* arr_1 = malloc(16 * sizeof(char));
    char* arr_2 = malloc(16 * sizeof(char));
    t_tet* list = NULL;
    if (argc != 2)
        printf("usage: %s is provided,filename is not provided", argv[0]); 
    else  
    { 
        FILE *file = fopen(argv[1], "r"); 
        if ( file == 0 ) 
        { 
            printf("Could not open file\n"); 
        } 
        else  
        { 
            char* x; 
            while((fgetc(file)) != EOF) 
            { 
                t_tet* list = get_tetriminoes_from_file(x);
            }
        } 
    } 
    int i = 0;
    while(i < sizeof(list))
    {
        char* arr = listTo_array(list);
        moving_Tetrimino(arr);
        i++;
        list = list->next;
    }
    t_node* sol = solve(list, 0);
    display(sol);
}
