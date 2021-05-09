#include <iostream>
#include <conio.h>
#include <time.h>

#pragma warning(disable : 4996)

using namespace std;
//========================================================
struct list2
{
    int info;
    list2* next, * prev;
} *begin, * t, * end;

void delstack(list2**, list2**);
//======================================================
void add(int n, list2** b, list2** e, int num)
{
    if (*b == NULL && *e == NULL) {
        list2* p = new list2;
        p->info = num;
        p->next = p->prev = NULL;
        *b = p;
        *e = p;
        return;
    }
    t = new list2;
    t->info = num;

    if (n == 0) {
        t->prev = NULL;
        t->next = *b;
        (*b)->prev = t;
        *b = t;

    }
    else {
        t->next = NULL;
        t->prev = *e;
        (*e)->next = t;
        *e = t;
    }
    return;
}
//============================================================
void view(list2* t, int n = 0)
{
    while (t != NULL)
    {
        cout << "     " << t->info;
        if (n == 0)t = t->next;
        else t = t->prev;
    }
}
//==============================================================
void spl(list2* stk)
{
    list2* begin1 = NULL, * end1 = NULL, * begin2 = NULL, * end2 = NULL;
    while (stk != NULL)
    {
        if (stk->info > 0)  add(0, &begin1, &end1, stk->info);
        else  add(0, &begin2, &end2, stk->info);
        stk = stk->next;
    }
    cout << "positive list " << endl;      view(end1, 1);
    cout << "\nnegative list " << endl;      view(end2, 1);
}
void readochdd(list2* sp)
{
    if (sp->next)
        (sp->next)->prev = sp->prev;
    if (sp->prev)
        (sp->prev)->next = sp->next;
    delete sp;
    return;
}
//==============================================================
void individual(list2** b, list2** e)
{
    list2* t = *b;
    list2* p = *b;
    while (p != NULL)
    {
        t = p->next;
        if (p->info % 10 == 5 || p->info % 10 == -5)
        { 
            if (p == *b)
                *b = p->next;
            if (p == *e)
                *e = p->prev;
            readochdd(p);
        }
        p = t;
    }
    cout << endl;
}
//==============================================================
void delstack(list2** b, list2** e)
{
    if (*b == NULL && *e == NULL) {
        cout << "list has already been deleted! ";
        return;
    }
    list2* t = (*b)->next;
    while (t != *e)
    {
        readochdd(t);
        t = (*b)->next;
    }
    delete* b; *b = NULL;
    delete* e; *e = NULL;
    return;
}
//=================================================================
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int i, n, der, m;
    list2* begin = NULL, * end = NULL;

    while (true) {
        system("cls");   //clear screen
        puts("\nadd - 1 \nview - 2 \nsplit - 3 \ndelete - 4 \nindividual - 5 \nexit - 0 ");
        switch (getch())
        {
        case '1':
            cout << "add from: \n begin - 0\n end - 1 ";    cout << endl;  der = getch() - '0';
            cout << "\ninpute kol = ";  cin >> n;
            for (i = 1; i <= n; i++) {
                cout << i << "-й элемент: ";  cin >> m;
                add(der, &begin, &end, m);
            }

            break;
        case '2':
            if (!begin && !end) {
                cout << "list is empty\n";
                getch();
                break;
            }
            cout << "--- list ---" << endl;
            cout << "View from: \n begin - 0\n end - 1 ";    cout << endl;  der = getch() - '0';
            if (der == 0) {
                cout << "--- begin ---\n";
                view(begin, der);
            }
            else {
                cout << "--- end ---" << endl;
                view(end, der);
            }
            getch();
            break;
        case '3':
            spl(begin);
            getch();
            break;
        case '4':
            delstack(&begin, &end);
            cout << "memmory is free! list deleted!!!" << endl;
            getch();
            break;
        case '5':
            individual(&begin, &end);
            view(begin);
            getch();
            break;

        case '0':
            cout << "memmory is free! list deleted!!!" << endl;
            delstack(&begin, &end);
            return 0;
        }
    }
}
