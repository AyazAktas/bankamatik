#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int bakiye;

int menu()
{
    system("cls");
    
    printf("\nHesabınızdaki para miktarı:%d\n\n",bakiye);
    
    int secim;
    printf("\n\t*** BANKAMATİK ***\n");
    
    printf("\t1-  Para çekme işlemi\n");
    
    printf("\t2-Para yatırma işlemi\n");
    
    printf("\t3-Fatura ödeme işlemi\n");
    
    printf("\t4- Havale/EFT işlemi\n");
    
    printf("5- Çıkış\n");
    
    scanf("%d",&secim);
    
    return secim;

}


void paraCek()
{
    int miktar;
    printf("Çekeceğiniz para miktarını yazınız:");
    scanf("%d",&miktar);
    printf("İşleminiz gerçekleştiriliyor..\n");
    sleep(2);
    if (bakiye<miktar)
    {
        printf("Hesabınızda yeterli miktarda para bulunmamaktadır.\n");
    }
    else
    {
        bakiye-=miktar;

        
        printf("Para çekme işleminiz başarılı.!\n");
        sleep(2);
        printf("Lütfen paranızı hazneden almayı unutmayın.\n");
        sleep(2);

    }
    printf("Ana menüye yönlendiriliyorsunuz...\n");
    sleep(2);

    
}

void paraYatir()
{
    int miktar;
    printf("Yatırmak istediğiniz para miktarını yazınız:");
    scanf("%d",&miktar);
    printf("İşleminiz gerçekleştiriliyor..\n");
    sleep(2);
    printf("Açılan hazneye parayı koyunuz...");
    sleep(2);
    bakiye+=miktar;   
    printf("İşleminiz yapılıyor.. Lütfen bekleyiniz...");sleep(2);
    printf("Para yatırma işleminiz başarılı.!\n");sleep(2);
    printf("Ana menüye yönlendiriliyorsunuz...\n");sleep(2);

}


void faturaOdeme()
{
    int miktar,secim,numara;
    printf("Ödeyeceğiniz fatura tipini seçiniz.\n");
    printf("1-- Elektrik Faturası\n");
    printf("2-- Su Faturası\n");
    printf("3-- Doğalgaz Faturası\n");
    printf("4-- Telefon Faturası\n");

    scanf("%d",&secim);
    if (secim<1 && secim>4)
    {
        printf("Hatalı bir tuşlama yaptınız.!!\n");
    }
    else
    {
        printf("Fatura No giriniz:");
        scanf("%d",&numara);
        sleep(1);
        miktar=rand()%100 + 20;
        printf("Fatura borcunuz:%d tl dir.\n",miktar);
        printf("Ödemek istiyor musunuz ? [Kabul Ediyorsanız 1 i tuşlayınız]:");
        scanf("%d",&secim);
        sleep(2);
        if (secim!=1)
        {
           printf("Fatura ödeme işlemi iptal edildi.\n");
           printf("Ana menüye yönlendiriliyorsunuz..\n");
           

        }
        else
        {
            bakiye -=miktar;
            printf("Fatura ödeme işleminiz başarı ile tamamlandı..\n");
            sleep(2);
            printf("Yeni Bakiyeniz:%d",bakiye);
        }

    }
    printf("Ana menüye yönlendiriliyorsunuz...\n");
    sleep(2);
    
    
}


void havaleEft()
{
    int miktar,iban;
    printf("Havale ile para göndereceğiniz kişinin IBAN numarasını yazınız:");
    scanf("%d",&iban);
    printf("Kaç TL göndermek istiyorsunuz?:");
    scanf("%d",&miktar);
    
    printf("İşleminiz yapılıyor.. Lütfen bekleyiniz...");sleep(2);
    if (bakiye<miktar)
    {
        printf("Bu işlemi yapmak için hesabınızda yeterli miktarda para bulunmamaktadır.\n");
    }
    else
    {
        bakiye-=miktar;

        printf("İşlem gerçekleştiriliyor.Lütfen bekleyiniz...\n");
        sleep(2);
        printf("Havale/EFT işleminiz başarılı.!\n");
        printf("Yeni Bakiyeniz:%d",bakiye);

    }
    printf("Ana menüye yönlendiriliyorsunuz...\n");sleep(2);

    
}




int main()
{
    int parola,i=0; 
    printf("Şifrenizi giriniz:"); 
    scanf("%d",&parola);
    
    while (parola!=1800)
    {
        printf("Hatalı şifre girdiniz!\n");
        sleep(1);
        printf("Tekrar giriniz:");
        scanf("%d",&parola);
        i++;
        if (i==2)
        {
            printf("Kartınız bloke edilmiştir.!!\n");
            printf("Lütfen müşteri hizmetleri ile iletişime geçiniz.\n");
            return 0;
        }
        
        

        
    }
    printf("Giriş başarılı..\n");
    sleep(2);
    
    srand(time(0));
    
    bakiye=rand()%900 + 100;
    
    int secim;
    while (1)
    {
        secim=menu();
        switch (secim)
        {
        case 1 : paraCek(); break;
        case 2 : paraYatir(); break;
        case 3 : faturaOdeme(); break;
        case 4 : havaleEft(); break;    
        case 5 : printf("Çıkış yapılıyor bekleyiniz...,Kartınızı almayı unutmayınız..\n"); return 0 ;
         

        
        default: 
            printf("Hatalı seçim yaptınız.");   sleep(2);
            break ;
        }

   
    }

    

    


    return 0;
}
