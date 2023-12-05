#include <iostream>
#include <string>

using namespace std;

struct nod
{
    string info;
    nod *fiu_stanga, *fiu_dreapta;
};

nod *radacina, *curent;

nod *adaugare_nod()
{
    nod *aux;
    aux=new nod;
    cout<<"ce informatie doriti sa contina noul nod? ";
    cin>>aux->info;
    aux->fiu_stanga=NULL;
    aux->fiu_dreapta=NULL;
    return aux;
}

nod *construire_arbore()
{
    nod *aux;
    aux=new nod;
    cout<<"ce informatie doriti sa contina noul nod? ";
    cin>>aux->info;
    char opt;
    cout<<"doriti ca nodul care contine "<<aux->info<<"sa aibe un fiu in stanga? (d/n) "
    cin>>opt;
    if(opt=='d')
        aux->fiu_stanga=construire_arbore();
    else
        aux->fiu_stanga=NULL;
    cout<<"doriti ca nodul care contine "<<aux->info<<"sa aibe un fiu in dreapta? (d/n) "
    cin>>opt;
    if(opt=='d')
        aux->fiu_dreapta=construire_arbore();
    else
        aux->fiu_dreapta=NULL;
    return aux;
}

void parcurgere_RSD(nod *start)
{
    cout<<start->info<<" ";
    if(start->fiu_stanga!=NULL)
        parcurgere_RSD(start->fiu_stanga);
    if(start->fiu_dreapta!=NULL)
        parcurgere_RSD(start->fiu_dreapta);
}

void parcurgere_SRD(nod *start)
{
    if(start->fiu_stanga!=NULL)
        parcurgere_SRD(start->fiu_stanga);
    cout<<start->info<<" ";
    if(start->fiu_dreapta!=NULL)
        parcurgere_SRD(start->fiu_dreapta);
}

void parcurgere_SDR(nod *start)
{
    if(start->fiu_stanga!=NULL)
        parcurgere_SDR(start->fiu_stanga);
    if(start->fiu_dreapta!=NULL)
        parcurgere_SDR(start->fiu_dreapta);
    cout<<start->info<<" ";
}

nod *cautare(nod *start, string ce)
{
    nod *rezultat=NULL;
    if(start->info==ce)
    {
        rezultat=start;
        return rezultat;
    }
    if(start->fiu_stanga!=NULL)
    {
        rezultat=cautare(start->fiu_stanga,ce)
        if(rezultat!=NULL)
            return rezultat;
    }
    if(start->fiu_dreapta!=NULL)
    {
        rezultat=cautare(start->fiu_dreapta,ce)
        if(rezultat!=NULL)
            return rezultat;
    }
    return NULL;
}

void stergere(nod *parinte)
{
    char opt;
    cout<<"sterg fiul din stanga, dreapta sau nimic? (s/d/n) ";
    cin>>opt;
    if(opt=='s')
    {
        nod *aux=parinte->fiu_stanga;
        cout<<"sterg nodul care contine "<<parinte->fiu_stanga->info<<endl;
        parinte->fiu_stanga=NULL;
        delete aux;
    }
        if(opt=='d')
    {
        nod *aux=parinte->fiu_dreapta;
        cout<<"sterg nodul care contine "<<parinte->fiu_dreapta->info<<endl;
        parinte->fiu_dreapta=NULL;
        delete aux;
    }
}
int main()
{
    radacina=construire_arbore();
    parcurgere_RSD(radacina);
    cout<<endl;
    parcurgere_SRD(radacina);
    cout<<endl;
    parcurgere_SDR(radacina);
    cout<<endl;
    
    string unde;
    cout<<"sub care nod doriti sa sterg? ";
    cin>>unde;
    curent=cautare(radacina,unde);
    stergere(curent);
    parcurgere_RSD(radacina);
    cout<<endl;
    parcurgere_SRD(radacina);
    cout<<endl;
    parcurgere_SDR(radacina);
    cout<<endl;
    
    cout<<"sub care nod doriti sa adaug? ";
    cin>>unde;
    curent=cautare(radacina,unde);
    char opt;
    cout<<"doriti ca la noul nod care contine "<<curent->info<<" sa adaug un fiu in stanga? (d/n) ";
    cin>>opt;
    if(opt=='d')
    {
        curent->fiu_stanga=adaugare_nod();
        parcurgere_RSD(radacina);
        cout<<endl;
        parcurgere_SRD(radacina);
        cout<<endl;
        parcurgere_SDR(radacina);
        cout<<endl;
    }
    cout<<"doriti ca la noul nod care contine "<<curent->info<<" sa adaug un fiu in dreapta? (d/n) ";
    cin>>opt;
    if(opt=='d')
    {
        curent->fiu_dreapta=adaugare_nod();
        parcurgere_RSD(radacina);
        cout<<endl;
        parcurgere_SRD(radacina);
        cout<<endl;
        parcurgere_SDR(radacina);
        cout<<endl;
    }
    return 0;
}
