#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *l;
int n;
nod* push(int info, nod *l)
{
    nod *aux;
    aux=new nod;
    aux->info=info;
    aux->next=l;
    return aux;
}

nod* pop(nod *l)
{
    nod *aux1, *aux2;
    if(l!=NULL)
    {
        aux1=l;
        aux2=l->next;
        cout<<"\nVoi sterge nodul care contine: "<<aux1->info<<endl;
        delete aux1;
        return aux2;
    }
    else
    {
        cout<<"\nStiva este goala. Nu mai am ce sa sterg"<<endl;
        return NULL;
    }
}
void creare_stiva()
{
    nod *a;
    int info;
    fstream f("in.txt");
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>info;
        l=push(info,l);
    }
}
void afisare_stiva(nod *a)
{
    a=l;
    if(a==NULL)
        cout<<"lista este vida";
    else
    {
        cout<<"\n Elementele listei sunt:";
        while (a)
        {
            cout<<a->info<<" ";
            a=a->next;
        }
    }
}
int main()
{
    int n;
    creare_stiva();
    afisare_stiva(l);
    l=pop(l);
    afisare_stiva(l);
    l=push(100,l);
    l=push(500,l);
    afisare_stiva(l);
    l=pop(l);
    afisare_stiva(l);
    while(l)
        l=pop(l);
    return 0;
}
