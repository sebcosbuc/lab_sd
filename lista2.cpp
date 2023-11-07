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
    a=ultimul;//ma plasez pe ultimul nod al listei
    if(a==NULL)
        cout<<"lista este vida";
    else
    {
        cout<<"elementele listei sunt:";
        while (a)//atat timp cat nu am ajuns la NULL
        {
            cout<<a->info<<" ";//afisez informatia din nodul curent
            a=a->prev;//trec la nodul anterior
        }
    }
}

void adaugare_la_sfarsit()
{
    int informatie;
    cout<<"\n ----------\n";
    cout<<"adaugare la sfarsitul listei\n\n Ce informatie doriti sa adaugati la sfarsit?";
    cin>>informatie;//citesc informatia pe care o sa o adaug la sfarsit
    if(primul==NULL)//daca lista este vida
    {
        primul=new nod;//aloc memorie pentru primul nod
        primul->info=informatie;//pun informatia in nod
        primul->next=NULL;//fac legatura catre NULL
        primul->prev=NULL;
        ultimul=primul;//lista are un singur element, deci primul este si ultimul.
    }
    else
    {
        nod *aux;
        aux=new nod;
        aux->info=informatie;
        aux->next=NULL;
        aux->prev=ultimul;
        ultimul->next=aux;
    }
}

void adaugare_la_inceput()
{
    int informatie;
    cout<<"\n --------\n";
    cout<<"adaugare la inceputul listei\n\n Ce informatie doriti sa adaugati la inceput?";
    cin>>informatie;
    if(primul==NULL)//daca lista este vida
    {
        primul=new nod;//aloc memorie pentru primul nod
        primul->info=informatie;//pun informatia in nod
        primul->next=NULL;//fac legatura catre NULL
        primul->prev=NULL;
        ultimul=primul;//lista are un singur element, deci primul este si ultimul.
    }
    else
    {
        nod *aux;
        aux=new nod;//aloc memorie nodului nou
        aux->info=informatie;//pun informatia in nod
        aux->next=primul;//fac legatura catre primul nod
        aux->prev=NULL;
        primul=aux;//actualizez potizia primului nod
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
        curent=primul;//pozitionez nodul curent pe primul element al listei
        int i=1, ok=0;
        while(curent)//atat timp cat mai exista elemente in lista
        {
            if(i==pozitie-1)//daca am ajuns la pozitia anterioara celei care ma intereseaza
            {
                cout<<"i="<<i;
                aux=new nod;//aloc spatiu de memorie noului nod
                aux->info=informatie;//pun informatia in nod
                aux->next=curent->next;//fac legatura catre nodul urmator
                curent->next=aux;//fac legatura de la nodul curent la nodul nou adaugat
                ok=1;//marchez faptul ca am adaugat nodul pe pozitia ceruta
                break;
            }
            else
            {
                i++;//incrementez pozitia curenta
                curent=curent->next;//trec la nodul urmator
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
    cout<<"valoarea dupa care vreti sa inserati informatia";
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
        curent=primul;//pozitionez nodul curent pe primul element al listei
        int ok=0;
        while(curent)//atat timp cat mai exista elemente in lista
        {
            if(curent->info==valoare)//daca am gasit valoarea cautata
            {
                aux=new nod;//aloc spatiu de memorie noului nod
                aux->info=informatie;//pun informatia in nod
                aux->next=curent->next;//fac legatura catre nodul urmator
                curent->next=aux;//fac legatura de la nodul curent la nodul nou adaugat
                ok=1;//marchez faptul ca am adaugat nodul pe pozitia ceruta
                break;
            }
            else//daca nu am gasit valoarea cautata
            {
                curent=curent->next;//trec la nodul urmator
            }
        }
        if(ok==0)
            cout<<"in lista nu exista valoarea introdusa. informatia nu a fost adaugata";

    }
}

void stergere_primul_nod()
{
    if(primul==NULL)
        cout<<"lista nu exista. nu pot sterge";
    else
    {
        cout<<"\nsterg primul nod din lista\n";
        nod *aux;
        aux=primul;//memorez primului nod intr-o variabila auxiliara
        primul=primul->next;//trec primul nod pe a doua pozitie
        delete aux;//sterg primul nod memorat in aux
    }
}

void stergere_ultimul_nod()
{
    if(primul==NULL)
        cout<<"lista nu exista. nu pot sterge";
    else
    {
        if(primul==ultimul)
        {
            delete primul;
            primul=ultimul=NULL;
        }
        else
        {
            nod *curent;
            curent=primul;
            while(curent->next!=ultimul)//ma deplasez pana la penultimul nod
                curent=curent->next;
            delete curent->next;//sterg ultimul nod
            curent->next=NULL;
            ultimul=curent;//penultimul nod devine ultimul
        }
    }
}

void stergere_nod_de_pe_pozitia_data()
{
    int i,pozitie,ok;
    nod *aux;
    cout<<"dati pozitia de pe care sa se stearga nodul: ";
    cin>>pozitie;
    ok=0;i=1;
    if(primul==NULL)
        cout<<"lista nu exista. nu pot sterge";
    else
    {
        nod *curent;
        curent=primul;
        if(pozitie==1)
            stergere_primul_nod();
        else
        {
            while (curent)//ma deplasez in lista
                if(pozitie-1!=i)
            {
                curent=curent->next;
                i++;
            }
            else
                if(curent!=ultimul)
            {
                aux=curent->next;
                curent->next=curent->next->next;
                delete aux;
                ok=1;
                break;
            }
            else stergere_ultimul_nod();
            if(ok==0)
                cout<<"lista nu are nici un element pe pozitia data";
        }
    }
}

void stergere_nod_cu_valoare_data()
{
    int i,valoare,ok;
    nod *aux;
    cout<<"ce valoare vreti sa se stearga din lista?";
    cin>>valoare;
    ok=0;
    if(primul==NULL)
        cout<<"lista nu exista. nu pot sterge";
    else
        if(primul->info==valoare)
            stergere_primul_nod();
        if(ultimul->info==valoare)
            stergere_ultimul_nod();
        else
        {
            nod *curent;
            curent=primul;
            while(curent)
                if(curent->next->info!=valoare)
            {
                curent=curent->next;
                cout<<curent->info; getch();
            }
            else
                if(curent->next!=ultimul)
            {
                aux=curent->next;//retin valoarea intr-o variabila auxiliara
                curent->next=curent->next->next;//fac legatura peste nodul ce va fi sters
                delete aux;//sterg nodul
                ok=1;
                break;
            }
            if(ok==0)
                cout<<"nu exista aceasta valoare in lista";
        }
}

void stergere_lista()
{
    if(primul==NULL)
        cout<<"lista nu exista";
    else
        while(primul)//mai am inca elemente de sters
        if(primul!=ultimul)
            stergere_primul_nod();
        else
        {
            delete primul;
            delete ultimul;
            primul=ultimul=NULL;
        }
}

int main()
{
    int n;
    creare_lista();
    afisare_lista();
    cout<<endl;
    afisare_lista_invers();
    cout<<endl;
    adaugare_la_sfarsit();
    cout<<"\n\n dupa adaugare la sfarsit lista devine\n";
    afisare_lista();
    cout<<"\n";
    adaugare_la_inceput();
    cout<<"\n\n dupa adaugare la inceput lista devine\n";
    afisare_lista();
    cout<<"\n";
    adaugare_pe_pozitie_data();
    cout<<"\n\n dupa adaugare pe pozitia data lista devine\n";
    afisare_lista();
    cout<<"\n";
    adaugare_dupa_valoare_data();
    cout<<"\n\n dupa adaugare dupa valoarea data lista devine\n";
    afisare_lista();
    cout<<"\n";
    stergere_primul_nod();
    cout<<"\n\ndupa stergerea primului nod lista devine:";
    afisare_lista();cout<<"\n";
    stergere_ultimul_nod();
    cout<<"\n\ndupa stergerea ultimului nod lista devine:";
    afisare_lista();cout<<"\n";
    stergere_nod_de_pe_pozitia_data();
    cout<<"\n\ndupa stergerea unui nod cu pozitia data lista devine:";
    afisare_lista();cout<<"\n";
    stergere_nod_cu_valoare_data();
    cout<<"\n\ndupa stergerea unui nod cu valoarea data lista devine:";
    afisare_lista();cout<<"\n";
    stergere_lista();
    cout<<"\n\ndupa stergere lista devine";
    afisare_lista();cout<<"\n";
    return 0;
}
