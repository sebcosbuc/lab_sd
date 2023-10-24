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
nod *primul, *ultimul;
int n;
FILE f,g;

void creare_lista()
{
    nod *aux;
    ifstream f("in.txt");
    f>>n;
    for(int i=0;i<n;i++)
    {
        if(primul==NULL)
        {
            primul=new nod;
            f>>primul->info;
            primul->next=NULL;
            ultimul=primul;
        }
        else
        {
            aux=new nod;
            f>>aux->info;
            aux->next=NULL;
            ultimul->next=aux;
            ultimul=aux;
        }
    }
    f.close();
}

void afisare_lista()
{
    nod *a;
    a=primul;
    if(a==NULL)
        cout<<"lista este vida";
    else
    {
        cout<<"elementele listei sunt:";
        while (a)
        {
            cout<<a->info<<" ";
            a=a->next;
        }
    }
}

void adaugare_la_sfarsit()
{
    int informatie;
    cout<<"\n ----------\n";
    cout<<"adaugare la sfarsitul listei\n\n Ce informatie doriti sa adaugati la sfarsit?";
    cin>>informatie;
    if(primul==NULL)
    {
        primul=new nod;
        primul->info=informatie;
        primul->next=NULL;
        ultimul=primul;
    }
    else
    {
        nod *aux;
        aux=new nod;
        aux->info=informatie;
        aux->next=NULL;
        ultimul->next=aux;
    }
}

void adaugare_la_inceput()
{
    int informatie;
    cout<<"\n --------\n";
    cout<<"adaugare la inceputul listei\n\n Ce informatie doriti sa adaugati la inceput?";
    cin>>informatie;
    if(primul==NULL)
    {
        primul=new nod;
        primul->info=informatie;
        primul->next=NULL;
        ultimul=primul;
    }
    else
    {
        nod *aux;
        aux=new nod;
        aux->info=informatie;
        aux->next=primul;
        primul=aux;
    }
}

void adaugare_pe_pozitie_data()
{
    int informatie,pozitie;
    cout<<"\n --------\n";
    cout<<"\nadaugare pe pozitie data \n\n";
    cout<<"pozitia pe care vreti sa inserati informatia";
    cin>>pozitie;
    cout<<"\n ce informatie doriti sa adaugati? ";
    cin>>informatie;
    if(primul==NULL)
    {
        cout<<"\n lista este nula. Nu am adaugat informatia";
    }
    else
    {
        nod *aux, *curent;
        curent=primul;
        int i=1, ok=0;
        while(curent)
        {
            if(i==pozitie-1)
            {
                aux=new nod;
                aux->info=informatie;
                aux->next=curent->next;
                curent->next=aux;
                ok=1;
                break;
            }
            else
            {
                i++;
                curent=curent->next;
            }
        }
        if(ok==0)
            cout<<"lista are mai putine elemente decat pozitia data. informatia nu a fost adaugata";

    }
}

void adaugare_dupa_valoare_data()
{
    int informatie,valoare;
    cout<<"\n --------\n";
    cout<<"\nadaugare pe pozitie data \n\n";
    cout<<"pozitia pe care vreti sa inserati informatia";
    cin>>valoare;
    cout<<"\n ce informatie doriti sa adaugati? ";
    cin>>informatie;
    if(primul==NULL)
    {
        cout<<"\n lista este nula. Nu am adaugat informatia";
    }
    else
    {
        nod *aux, *curent;
        curent=primul;
        int i=1, ok=0;
        while(curent)
        {
            if(i==valoare)
            {
                aux=new nod;
                aux->info=informatie;
                aux->next=curent->next;
                curent->next=aux;
                ok=1;
                break;
            }
            else
            {
                i++;
                curent=curent->next;
            }
        }
        if(ok==0)
            cout<<"in lista nu exista valoarea introdusa. informatia nu a fost adaugata";

    }
}

int main()
{
    int n;
    creare_lista();
    afisare_lista(); cout<<"\n";
    adaugare_la_sfarsit();
    cout<<"\n\n dupa adaugare la sfarsit lista devine";
    afisare_lista();
    cout<<"\n";
    adaugare_la_inceput();
    cout<<"\n\n dupa adaugare la inceput lista devine";
    afisare_lista();
    cout<<"\n";
    adaugare_pe_pozitie_data();
    cout<<"\n\n dupa adaugare pe pozitia data lista devine";
    afisare_lista();
    cout<<"\n";
    adaugare_dupa_valoare_data();
    cout<<"\n\n dupa adaugare dupa valoarea data lista devine";
    afisare_lista();
    cout<<"\n";
    return 0;
}
