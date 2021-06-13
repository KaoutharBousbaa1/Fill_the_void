#ifndef Fill_the_void
#define Fill_the_void

int const array_size = 16;

struct s_tet
{
    char data;
    struct s_tet *next;
};
typedef struct s_tet t_tet;

struct s_node
{
    char data;
    struct s_node* next;
};
typedef struct s_node t_node;

t_node* push(t_node* head, int data);
t_tet* create(int data);
int count(t_tet* head);
t_tet* append(t_tet* head, char data);
int count(t_tet* head);
t_tet* create_list(char block);
void listTo_array(t_tet* head);
void moving_Tetrimino(char array[]);
int counting_tetriminos(t_tet* tet);
int counting_blocks(char *character);
int check_char(char *character);
_Bool compare_arrays(char array[]);
int check_tetrimino(char array[]);
void read_file();
int assign_loc(char array[], int s, int j);
t_node* assign_tet(t_node* stack, char array_1[], char array_2[], int i);
t_node* recur_assign(char array_1[], char array_2[], int k);
_Bool check_assign(char array_1[], char array_2[]);
t_node* solve(char array_1[], char array_2[], int k);
void display(t_node* stack);

# define I_1 (char[16]) {'#',0,0,0,'#',0,0,0,'#',0,0,0,'#',0,0,0}
# define I_2 (char[16]) {'#','#','#','#',0,0,0,0,0,0,0,0,0,0,0,0}
# define O (char[16]) {'#','#',0,0,'#','#',0,0,0,0,0,0,0,0,0,0}
# define T_1 (char[16]) {'#','#','#',0,0,'#',0,0,0,0,0,0,0,0,0,0}
# define T_2 (char[16]) {'#',0,0,0,'#','#',0,0,'#',0,0,0,0,0,0,0}
# define T_3 (char[16]) {0,'#',0,0,'#','#',0,0,0,'#',0,0,0,0,0,0}
# define T_4 (char[16]) {0,'#',0,0,'#','#','#',0,0,0,0,0,0,0,0,0}
# define L_1 (char[16]) {'#','#','#',0,'#',0,0,0,0,0,0,0,0,0,0,0}
# define L_2 (char[16]) {'#','#',0,0,0,'#',0,0,0,'#',0,0,0,0,0,0}
# define L_3 (char[16]) {'#',0,0,0,'#',0,0,0,'#','#',0,0,0,0,0,0}
# define L_4 (char[16]) {0,0,0,'#','#','#','#',0,0,0,0,0,0,0,0,0}
# define Z_1 (char[16]) {0,'#',0,0,'#','#',0,0,'#',0,0,0,0,0,0,0}
# define Z_2 (char[16]) {'#','#',0,0,0,'#','#',0,0,0,0,0,0,0,0,0}

#endif
