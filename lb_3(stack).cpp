#include <iostream>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996)

using namespace std;
//=============================================================
struct Stack
{
    int info;
    Stack *next;
} *begin = NULL, *t, * a1 = NULL, * a2 = NULL;
//==============================================================
Stack *Add(Stack *stk, int num)
{
    Stack *t = new Stack;
    t->info = num;
    t->next = stk;
    return t;
}
//==============================================================
void View(Stack* stk)
{
    Stack* t = stk;
    while (t != NULL)
    {
        cout << t->info << "   " ;
        t = t->next;
    }
    cout << endl;
}
//==============================================================
void Spl(Stack* stk)
{
    for (t = stk; t != NULL; t = t->next)
      if (t->info > 0)  a1 = Add(a1, t->info);
                   else a2 = Add(a2, t->info);
    cout << "Положительный стек " << endl;      View(a1);
    cout << "Отрицательный стек " << endl;      View(a2);
}
//===============================================================
void individual(Stack* stk)
{
    Stack* p = stk;
    Stack* t = p->next;
    while (t != NULL)
    {
        if (t->info % 10 == 5 || t->info % 10 == -5)
        {
            p->next = t->next;
            delete t;
            t= p->next;
        }
        else
        {
            p = t;
            t = t->next;
        }
    }
    cout << endl;
    View(stk);
}  
//================================================================
void DelStack(Stack **stk)
{
    Stack* t;
    while (*stk != NULL)
    {
        t = *stk;
        *stk = (*stk)->next;
        delete t;
    }
}
//=================================================================
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int i, n;
    Stack *begin = NULL;
    while (true) {
        system("cls");   //clear screen
        puts(" \nAdd - 1 \nView all stecks - 2 \nSplit list - 3 \nDel - 4 \nEXIT - 0 ");
        switch (getch())
        {
        case '1':
            cout << "Input kol = ";  cin >> n;
            for (i = 1; i <= n; i++)
                begin = Add(begin, rand()%40 - 20);
            break;
        case '2':
            View(begin);
            getch();
            break;
        case '3':
            Spl(begin);
            getch();
            break;
        case '4':
            DelStack(&begin);
            DelStack(&a1);
            DelStack(&a2);
            cout << "Memory Free! Stack was deleted" << endl;
            getch();
            break;
        case '5':
            individual(begin);
            getch();
            break;

        case '0':
            DelStack(&begin);
            DelStack(&a1);
            DelStack(&a2);
            return 0;
        }
    }

}