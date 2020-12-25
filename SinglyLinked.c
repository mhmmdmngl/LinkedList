#include <stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* Start;

struct node* yeniDugum(int data)
{
  struct node* dugum = (struct node*)malloc(sizeof(struct node));
  dugum->data = data;
  dugum->next = NULL;
  return(dugum);
}

void traverseList()
{
    printf("\n");
    struct node* temp = Start;
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

void sonaElemanEkle(int data)
{
    struct node* eklenecekDugum = yeniDugum(data);
    if(Start == NULL)
    {
        Start = eklenecekDugum;
        return;
    }
    else
    {
        struct node* temp = Start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = eklenecekDugum;
    }

}

void basaEkle(int data)
{
    struct node* eklenecekDugum = yeniDugum(data);
    if(Start == NULL)
        Start = eklenecekDugum;
    else
    {
        struct node* temp = Start;
        Start = eklenecekDugum;
        Start->next = temp;
    }
}

void arayaElemanEkle(int eklenecekData, int onuneEklenecekData)
{
    struct node* eklenecekDugum = yeniDugum(eklenecekData);
    if(Start == NULL)
        basaEkle(eklenecekData);
    else
    {
        struct node* temp = Start;
        while(temp->data != onuneEklenecekData)
        {
            temp = temp->next;
        }
        if(temp->next == NULL)
            sonaElemanEkle(eklenecekData);
        else
        {
            struct node* sonrakiEleman = temp->next;
            temp->next = eklenecekDugum;
            eklenecekDugum->next = sonrakiEleman;
        }
    }
}

void sondanSil()
{
    if(Start == NULL)
        return;
    if(Start != NULL && Start->next == NULL)
        Start = NULL;
    else
    {
        struct node* temp = Start;
        while(temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}

void bastanSil()
{
    if(Start == NULL)
        return;
    if(Start->next == NULL)
        Start = NULL;
    else
    {
        struct node* ikinciDugum = Start->next;
        Start = ikinciDugum;
    }
}

void aradanElemanSil(int data)
{
    if(Start == NULL)
        return;
    if(Start->next == NULL && Start->data == data)
    {
        Start = NULL;
    }

    else
    {
        if(Start->data == data)
        {
            bastanSil();
            return;
        }
        struct node* temp = Start;
        while(temp->next->data != data && temp != NULL)
            temp = temp->next;

        if(temp->next->next == NULL && temp->next->data == data)
            sondanSil();
        else
        {
            struct node* silinecekEleman = temp->next;
            struct node* baglanacakEleman = silinecekEleman->next;
            temp->next = baglanacakEleman;
            free(silinecekEleman);

        }
    }
}

void Menu()
{
    int secim, deger, pozisyon;
    printf("\n1- Sona Eleman Ekle...");
    printf("\n2- Basa Eleman Ekle...");
    printf("\n3- Araya Eleman Ekle...");
    printf("\n4- Sondan Eleman Sil...");
    printf("\n5- Bastan Eleman Sil...");
    printf("\n6- Aradan Eleman Sil...");
    printf("\nYapmak istediginiz islemi Secin.... ");
    scanf("%d", &secim);
    switch(secim)
    {
        case 1:
            printf("\nEklemek istediginiz sayiyi girin... ");
            scanf("%d", &deger);
            sonaElemanEkle(deger);
            break;
        case 2:
            printf("\nEklemek istediginiz sayiyi girin... ");
            scanf("%d", &deger);
            basaEkle(deger);
            break;
        case 3:
            printf("\nEklemek istediginiz sayiyi girin... ");
            scanf("%d", &deger);
            traverseList();
            printf("\nHangi elemanin onune eklemek istiyorsunuz?... ");
            scanf("%d", &pozisyon);
            arayaElemanEkle(deger,pozisyon);
            break;
        case 4:
            sondanSil();
            break;
        case 5:
            bastanSil();
            break;
        case 6:
            printf("\nHangi Elemani Silmek istiyorsunuz... ");
            scanf("%d", &deger);
            aradanElemanSil(deger);
            break;
    }
    traverseList();
}

int main()
{
    while(1)
        Menu();
}

