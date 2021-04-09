#include <bits/stdc++.h>
using namespace std;
 
struct A
{
    int key; 
};

struct List
{
    A a;
    List* next;
};

void Print(List *b)
{
    List *print = b;
    while (print)
    {
        cout << print->a.key << " -> ";
        print = print->next;
    }
    cout << "NULL\n";
}

void Init(List **begin)
{
    *begin = new List;
    A a[5] = {40, 60, 80, 100, 120};

    (*begin)->a.key = 20;
    (*begin)->next = NULL;

    List *end = *begin;

    for (int i(0); i < 5; ++i)
    {
        end->next = new List;
        end = end->next;
        end->a = a[i];
        end->next = NULL;
    }
}

void Add_begin(List ** begin, const A &a)
{
    List *t = new List;
    t->a = a;
    t->next = *begin; 
    *begin = t;
}

void Insert(List **begin, const A &a)
{
    List *ins = new List;
    ins->a = a;
    
    if (!*begin)
    {
        ins->next = NULL;
        *begin = ins;
        return;
    }

    List *t = *begin;

    if (t->a.key >= ins->a.key)
    {
        ins->next = t;
        *begin = ins;
        return;
    }

    List *t1 = t->next;

    while (t1)
    {
        if (t->a.key < ins->a.key && t1->a.key >= ins->a.key)
        {
            t->next = ins;
            ins->next = t1;
            return;
        }

        t = t1;
        t1 = t1->next;

    }
    
    t->next = ins;
    ins->next = NULL;
}

void Delete(List **begin, const A &a)
{
    if (!*begin)
    {
        return;
    }

    List *t = *begin;
    
    if (t->a.key == a.key)
    {
        *begin = t->next;
        delete t;
        return;
    }

    List *t1 = t->next;

    while (t1)
    {
        if (t1->a.key == a.key)
        {
            t->next = t1->next;
            delete t1;
            return;
        }
        t = t1;
        t1 = t1->next;
    } 
}

void Free(List **begin)
{
    if (!*begin) return;
    List *p = *begin;
    List *t;

    while(p)
    {
        t = p;
        p = p->next;
        delete t;
    }
    *begin = NULL;
}

int main()
{
    List* begin = NULL;
    A a = {90}, b = {60};
    Init(&begin);
    Print(begin);
    Insert(&begin, a);
    Print(begin);
    Delete(&begin, b);
    Print(begin);
    Free(&begin);
    Print(begin);
    return 0;
}