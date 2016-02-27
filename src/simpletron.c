//Simpletron My Computer
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

//KODLAR
#define OKU     10 //Belirtilen konuma kullancidan tamsayi ata
#define YAZ     11 //Belirtilen konumdaki degiskeni oku
#define YAZI    12 //Belirtilen konuma bir deger yaz

#define YUKLE 20 //Akumulatore belirtilen konumdaki degiskeni yukle
#define SAKLA 21 //Akumulatordeki degeri belirtilen konumda sakla


#define TOPLA 30    //akumulator = akumulatordekiDeger + belirtilenKonumdakiDeger 
#define CIKART 31   //akumulator = akumulatordekiDeger - belirtilenKonumdakiDeger
#define BOL 32      //akumulator = akumulatordekiDeger / belirtilenKonumdakiDeger
#define CARP 33     //akumulator = akumulatordekiDeger * belirtilenKonumdakiDeger
#define MOD 34      //akumulator = akumulatordekiDeger % belirtilenKonumdakiDeger
#define USAL 35     //akumulator = akumulatordekiDeger ^ belirtilenKonumdakiDeger
#define BIRAZAL 38  //belirtilenKonumundakiDeger--
#define BIRART 39   //belirtilenKonumundakiDeger++

#define DALLAN 40       //Belirtilen konuma git/dallan
#define DALLANNEG 41    //Akumulator negatifse belirtilen konuma dallan
#define DALLANPOZ 42    //Akumulator pozitifse belirtilen konuma dallan
#define DALLANSIFIR 43  //Akumulator sifir ise belirtilen konuma dallan

#define BITIR 99 //Programi bitir
//KODLAR SON

void diziYaz(const int[], const int);
void bilgi(void);
void kodGir(int[]);
void calistir(int[]);
int usAl(const int alt, const int us);
int kont(int);
int ara(const int taban, const int tavan);
int strUz(char *str);

int main(int argc, char *argv[])
{
    int a=0;
    bilgi();
    int ram[BOYUT] ={0};
    
    kodGir(ram);
    calistir(ram);
	
    printf("\n\n\nCopluk ciktisi gormek ici 1, cikis icin baska bir sayi girin : "); /**/ scanf("%d", &a);
    printf("\n");
    
    if(a==1) 
        diziYaz(ram, BOYUT);
    	
    printf("\n\n----------------------------\n\n");
    return 0;
}

void calistir(int ram[])
{
    int akumulator    = 0000, //gecici hafiza
        komutSayici   = 00,   //bulunulan satir
        komutRegister = 0000, //bulunulan satirdaki komut
        kod           = 00,   //Komut--sol iki
        konum         = 00;   //hafiza konumu--sag iki
    
    printf("\n\nHos geldiniz. Programiniz basliyor...\n\n");
    
    while(kod != BITIR)
    {
        komutRegister = ram[komutSayici];
        kod = komutRegister / 100;
        konum = komutRegister % 100;
        
        switch (kod)
        {
            case 00:
                printf("%d konumu islem yapilmadan gecildi.\n\n", konum);
                break;
            case OKU:
                printf("%d konumuna degeri girin : ", konum); /**/ scanf("%d", &ram[konum]);
                printf("%d konumuna istenilen deger yazildi.\n\n", konum);
                break;
            case YAZ:
                printf("%d konumundaki deger : %d\n\n", konum, ram[konum]);
                break;
            case YAZI:
                break;
            case YUKLE:
                akumulator = ram[konum];
                printf("Akumulatore %d konumundaki bilgi yuklendi.\n\n", konum);
                break;
            case SAKLA:
                ram[konum] = akumulator;
                printf("Akumulatordeki deger %d konumuna yazildi.\n\n", konum);
                break;
            case TOPLA:
                akumulator += ram[konum];
                printf("akumulator = akumulatordekiDeger + %dkonumudakiDeger islemi yapildi.\n\n", konum);
                break;
            case CIKART:
                akumulator -= ram[konum];
                printf("akumulator = akumulatordekiDeger - %dkonumudakiDeger islemi yapildi.\n\n", konum);
                break;
            case BOL:
                if(ram[konum] != 0)
                {
                    akumulator /= ram[konum];
                    printf("akumulator = akumulatordekiDeger / %dkonumudakiDeger islemi yapildi.\n\n", konum);
                }
                else
                    printf("Bir sayi sifira bolunemez. Adim atlandi.\n\n");
                break;
            case CARP:
                akumulator *= ram[konum];
                printf("akumulator = akumulatordekiDeger * %dkonumudakiDeger islemi yapildi.\n\n", konum);
                break;
            case MOD:
                akumulator %= ram[konum];
                printf("akumulator = akumulatordekiDeger %% %dkonumudakiDeger islemi yapildi.\n\n", konum);
                break;
            case USAL:
                akumulator = usAl(akumulator, ram[konum]);
                printf("akumulator = akumulatordekiDeger ^ %dkonumudakiDeger islemi yapildi.\n\n", konum);
                break;
            case BIRAZAL:
                ram[konum]--;
                printf("%dkonumundakiDeger = %dkonumundakiDeger - 1 islemi yapildi.\n\n", konum, konum);
                break;
            case BIRART:
                ram[konum]++;
                printf("%dkonumundakiDeger = %dkonumundakiDeger + 1 islemi yapildi.\n\n", konum, konum);
                break;
            case DALLAN:
                komutSayici = konum;
                printf("%d konumuna dallanildi.\n\n", konum);
                komutSayici--;
                break;
            case DALLANNEG:
                if(akumulator < 0)
                {	
                    komutSayici = konum;
                    printf("Akumulator negatif oldugu icin %d konumuna dallanildi.\n\n", konum);
                    komutSayici--;
                }else
                    printf("Akumulator negatif olmadigindan dallanilmadi.\n\n");
                
                break;
            case DALLANPOZ:
                if(akumulator > 0)
                {	
                    komutSayici = konum;
                    printf("Akumulator pozitif  oldugu icin %d konumuna dallanildi.\n\n", konum);
                    komutSayici--;
                }else
                    printf("Akumulator pozitif olmadigindan dallanilmadi.\n\n");
                break;
            case DALLANSIFIR:
                if(akumulator == 0)
                {	
                    komutSayici = konum;
                    printf("Akumulator 0 oldugu icin %d konumuna dallanildi.\n\n", konum);
                    komutSayici--;
                }else
                    printf("Akumulator 0 olmadigindan dallanilmadi.\n\n");
                break;
            case BITIR:
                printf("Program bitti. Iyi gunler.\n\n");
                break;
            default:
                printf("HATA! %d : Boyle bir komut bulunamadi.. Komut atlaniyor...\n\n", kod);
                break;
        }
        komutSayici++;
    }
}

void kodGir(int ram[])
{
    int i=0, cevap=0;
    
    
    printf("%2d ? ", i);
    cevap = ara(-9999, 9999);
    
    while(cevap != -9999)
    {
        if(cevap != -9998)
        {
            if((cevap / 100) == YAZI)
            {
                printf("         %d konumu = ", (cevap%100));
                scanf("%d", &ram[(cevap%100)]);
            }
            ram[i++] = cevap;
        }
        else
        {
            printf(" Konum girin : ");
            i = ara(0, 99);
        }
        
        printf("%2d ? ", i);
        cevap = ara(-9999, 9999);
    }
}

int kont(int c)
{
    return 0;
}

int ara(const int taban, const int tavan)
{
    int sayi=0;
    
    scanf("%d", &sayi);
    while(sayi < taban || sayi > tavan)
    {
        printf("Lutfen %d ile %d arasinda bir sayi girin : ", taban, tavan); /**/ scanf("%d", &sayi);
    }
    
    return sayi;
}

void bilgi(void)
{
    printf("-------------------------------------\n");
    printf(" %s %s %s %s %s %s %s",
             "***Simpletrona hos geldiniz !***\n",
             "***Hafiza konumunu ve ? ekrana yazdiracagim.***\n",
             "***Siz daha sonra o konuma bir word girin.***\n",
             "***Gireceginiz wordler bu sekilde olmali : 5312  ***\n",
             "***53 : Islem Kodu --- 12 : Islemin yapilacagi konumdur.***\n",
             "***Istediginiz konuma deger girmek icin -9998 yazin.***\n",
             "***Cikis icin -9999 nobetci degerini girin.***\n");
    printf("-------------------------------------\n\n");
}

void diziYaz(const int a[], const int boyut)
{
    int i=0;
    
    printf("--------------------------COPLUK CIKTISI--------------------------------\n");
    for(i=0; i <= boyut-1; i++)
    {
        if(a[i] == 0)
            printf("%7d : ----", i);
        else if((a[i] / 1000) > 0)
            printf("%7d : %d", i, a[i]);
        else if((a[i] / 100) > 0)
            printf("%7d : %d-", i, a[i]);
        else if((a[i] / 10) > 0)
            printf("%7d : %d--", i, a[i]);
        else
            printf("%7d : %d---", i, a[i]);
            
        if((i+1)%5 == 0)
            printf("\n");
    }
    printf("------------------------------------------------------------------------\n\n");
}

int usAl(const int alt, const int us)
{
    int i=0, sonuc=1;
    
    while(i++ < us)
        sonuc *= alt;
    
    return sonuc;
}

int strUz(char *str)
{
    int uz=0;
    
    for(; *str != '\0'; uz++, str++)
    ;
    
    return uz;
}
