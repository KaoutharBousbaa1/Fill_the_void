# ifndef Fill_the_void
# define Fill_the_void

int const array_size = 16;
struct s_tet
{
    char data;
    size_t	content_size;
    struct s_tet *next;
};
typedef struct s_tet t_tet;

struct s_node
{
    char data;
    struct s_node* next;
};
typedef struct s_node t_node;

t_node*     push(t_node* head, char data);
t_tet*      create(char data);
int         count(t_tet* head);
t_tet*      append(t_tet* head, char data);
int         count(t_tet* head);
t_tet*      create_list(char block);
char*       listTo_array(t_tet* head);
void        moving_Tetrimino(char *array);
int         counting_tetriminos(t_tet* tet);
int         counting_blocks(char *character);
int         check_char(char *character);
_Bool       compare_arrays(char *array);
int         check_tetrimino(char *array);
int         assign_loc(char *array, int s, int j);
t_node*     assign_tet(t_node* stack, t_tet* list, int i);
t_node*     recur_assign(t_tet* list, int k);
_Bool       check_assign(char *array_1, char *array_2);
t_node*     solve(t_tet* list, int k);
void        display(t_node* stack);
char*       readline(char *in);
int         check_line(char *ptr);
int	    validate_newlines(char* tetrimino_str, int* ends_in_newline);
int	    check_tetrimino_count(int count);
t_tet*      read_tetriminoes(int fd);
t_tet*      get_tetriminoes_from_file(const char *filename);


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
