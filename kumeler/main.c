#include <stdio.h>
#include <stdlib.h>
#define max 10
void olustur(int kumem[])
{
    int n;
    printf("kume kac elemanli olacak\n");
    scanf("%d",&n);
    kumem[0]=n;
    for(int i=1;i<=n;i++)
    {
        printf("\n%d. degiri giriniz\n",i);
        scanf("%d",&kumem[i]);
    }
}
void bas(int kumecik[])
{
    int i;
    for(i=1;i<=kumecik[0];i++)
    {
        printf("\n%3d",kumecik[i]);
    }
}
void birlestir(int kume1[],int kume2[],int kume3[])
{
    int i,n;
    int say=0;
    n=kume1[0];
    for(i=0;i<=n;i++)
    {
        kume3[i]=kume1[i];
            say++;
    }
    n=kume2[0];
    for(i=1;i<=n;i++)
    {
        if(!yok(kume3,kume2[i]))
        {
            kume3[++kume3[0]]=kume2[i];
            say++;
        }
    }
    kume3[0]=say;
}
void uclu(int kume1[],int kume2[],int kume3[],int kume4[])
{
    int i,n;
    n=kume1[0];
    for(i=0;i<=n;i++)
    {
        kume4[i]=kume1[i];
    }
    n=kume2[0];
    for(i=1;i<=n;i++)
    {
        if(!yok(kume4,kume2[i]))
        {
            kume4[++kume4[0]]=kume2[i];
        }
    }
    n=kume3[0];
    for(i=1;i<=n;i++)
    {
        if(!yok(kume4,kume3[i]))
        {
            kume4[++kume4[0]]=kume3[i];
        }
    }
}
int yok(int kume[],int x)
{
    int i;
    int n=kume[0];
    for(i=1;i<=n;i++)
    {
        if(kume[i]==x)
        {
            return 1;
        }
    }
    return 0;
}
void kesisim(int kume1[],int kume2[],int kume3[])
{
    int i;
    int n=kume1[0];
    int a=0;
    kume3[0]=0;
    for(i=1;i<=n;i++)
    {
        if(yok(kume2,kume1[i]))
        {
            kume3[++kume3[0]]=kume1[i];
            a++;
        }
    }
    kume3[0]=a;
}
void kume_farki(int kume1[],int kume2[],int kume3[])
{
    int i,n;
    n=0;
    kume3[0]=0;
    for(i=1;i<=kume1[0];i++)
    {
        if(!yok(kume2,kume1[i]))
        {
            kume3[++kume3[0]]=kume1[i];
            n++;
        }
    }
    kume3[0]=n;
}
int main()
{
    int kume1[max],kume2[max],kume3[max],kumet[max],kumeti[max];
    int op;
    do
    {
        printf("\nkumeleri olusturmak icin :1\n");
        printf("kumeleri basmak icin :2\n");
        printf("kume 1 ve 2 yi birlestirmek icin :3\n");
        printf("kume 1 ve 3 u birlestirmek icin :4\n");
        printf("kume 2 ve 3 u birlestirmek icin :5\n");
        printf("3 kumeyi birlestirmek icin :6\n");
        printf("kume 1 ile kume 2 nin kesisimi icin : 7\n");
        printf("kume 2 ile kume 3 un kesisimi icin : 8\n");
        printf("kume 1 ile kume 3 un kesisimi icin : 9\n");
        printf("uc kumenin kesisimi icin :10\n");
        printf("kume 1 ile kume 2 farki icin: 11\n");
        printf("kume 1 ile kume 3 farki icin: 12\n");
        printf("kume 2 ile kume 3 farki icin: 13\n");
        printf("kume 1 in kume 2 ve kume 3 den farki icin: 14\n");
        printf("cikmak icin: -1\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nkume 1: \n");
            olustur(kume1);
            printf("\nkume 2: \n");
            olustur(kume2);
            printf("\nkume 3: \n");
            olustur(kume3);
            break;
        case 2:
            printf("\nkume 1:\n");
            bas(kume1);
            printf("\nkume 2:\n");
            bas(kume2);
            printf("\nkume 3:\n");
            bas(kume3);
            break;
        case 3:
            birlestir(kume1,kume2,kumet);
            bas(kumet);
            break;
        case 4:
            birlestir(kume1,kume3,kumet);
            bas(kumet);
            break;
        case 5:
            birlestir(kume2,kume3,kumet);
            bas(kumet);
            break;
        case 6:
            uclu(kume1,kume2,kume3,kumet);
            bas(kumet);
            break;
        case 7:
            kesisim(kume1,kume2,kumet);
            bas(kumet);
            break;
        case 8:
            kesisim(kume2,kume3,kumet);
            bas(kumet);
            break;
        case 9:
            kesisim(kume1,kume3,kumet);
            bas(kumet);
            break;
        case 10:
            kesisim(kume1,kume2,kumet);
            kesisim(kume3,kumet,kumeti);
            bas(kumeti);
            break;
        case 11:
            kume_farki(kume1,kume2,kumet);
            bas(kumet);
            break;
        case 12:
            kume_farki(kume1,kume3,kumet);
            bas(kumet);
            break;
        case 13:
            kume_farki(kume2,kume3,kumet);
            bas(kumet);
            break;
        case 14:
            birlestir(kume2,kume3,kumet);
            kume_farki(kume1,kumet,kumeti);
            bas(kumeti);
            break;
        case -1:
            continue;
        default:
            printf("yanlis sayi girdinizzz");

        }

    }while(op!=-1);
    return 0;
}
