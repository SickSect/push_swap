#include "push_swap.h"

static int count_rotation_a(t_node **head_a, int data)
{
    //SHIT
    //Нужно учитывать, что после первого пуша и поворотов
    // у меня сдвигается минимум и теперь мне чекать надо все иначе слегка
    //..ПОмучаемся да сделаем

}

static int count_rotation_b(t_node **head, int data)
{
    // FORGET ABOUT STANDING
}

static void count_act(t_node **head_a, t_node **head_b)
{
    t_node *mv;
    
    mv = (*head_b);
    while (mv != NULL)
    {
        mv->act = count_rotation_b(head_b, mv->data);
        mv->act += count_rotation_a(head_a, mv->data);
        mv = mv->p_next;
    }
}

static void move_in_a(t_node **head)
{
    int     min;
    int     counter;
    t_node  *mv;

    min = find_min(head);
    counter = 0;
    mv = (*head);
    while (mv->data != min)
    {
        counter++;
        mv = mv->p_next;
    }
    if  (counter == 1)
        basic_rotater(head, (*head)->data);
        //complex_rotater(head);
}

void main_sort(t_node **head_a, t_node **head_b)
{
    int it = 1;
    while(head_b != NULL && it--)
    {
		zero_act(head_a, head_b);
        count_act(head_a, head_b);
        chose_n_move(head_a, head_b);
        move_in_a(head_a);
    }
}