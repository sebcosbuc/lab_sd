#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct nod
{
    int info;
    nod *next, *prev;
};
nod *primul, *ultimul;
int n;
FILE f,g;

void creare_lista()
{
    nod *aux;
    ifstream f("in.txt");//deschid pentru citire fisierul in.txt
    f>>n;//citesc nr de elemente
    for(int i=0;i<n;i++)
    {
        if(primul==NULL)//daca lista nu exista
        {
            primul=new nod;//aloc memorie pentru primul element
            f>>primul->info;//citesc informatia din fisier
            primul->next=NULL;//fac legatura catre NULL (nu mai urmeaza nimic dupa primul)
            primul->prev=NULL;
            ultimul=primul;//lista are un singur element, deci primul este si ultimul.
        }
        else//daca lista exista deja
        {
            aux=new nod;//aloc memorie pentru un nod nou
            f>>aux->info;//citesc informatia si o pun in nod
            aux->next=NULL;//fac legatura catre NULL
            ultimul->next=aux;//fac legatura de la ultimul nod al listei la noul nod
            aux->prev=ultimul;
            ultimul=aux;//actualizez pozitia ultimului nod
        }
    }
    f.close();//inchid fisierul in.txt
}

void afisare_lista()
{
    nod *a;
    a=primul;//ma plasez pe primul nod al listei
    if(a==NULL)
        cout<<"lista este vida";
    else
    {
        cout<<"elementele listei sunt:";
        while (a)//atat timp cat nu am ajuns la NULL
        {
            cout<<a->info<<" ";//afisez informatia din nodul curent
            a=a->next;//trec la urmatorul nod
        }
    }
}

void afisare_lista_invers()
{
    nod *a;
    a=ultimul;//ma plasez pe primul nod al listei
    if(a==NULL)
        cout<<"lista este vida";
    else
    {
        cout<<"elementele listei sunt:";
        while (a)//atat timp cat nu am ajuns la NULL
        {
            cout<<a->info<<" ";//afisez informatia din nodul curent
            a=a->prev;//trec la urmatorul nod
        }
    }
}

int main()
{
    int n;
    creare_lista();
    afisare_lista();
    afisare_lista_invers();
    return 0;
}
