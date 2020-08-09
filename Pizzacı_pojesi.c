#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a=0;
typedef struct musteri
{
	char id[10];// müşteri id'si
	char isim[20];
	char soyisim[20];
	char telno[20];
	char adres[100];
	
} Musteri;
Musteri m;

typedef struct siparis
{
	char id[20];// siparis id'si
	char mid[20];// müşteri id'si
	int pid;// pizzanın id'si
	char fiyat[10];// pizzanın fiyatı
	char tarih[15];
	
} Siparis;
Siparis s;

char *pizzalar[100] = 
	{"vejeteryan,ince,kucuk","vejeteryan,ince,orta","vejeteryan,ince,buyuk",
	"vejeteryan,kalin,kucuk","vejeteryan,kalin,orta","vejeteryan,kalin,buyuk",
	"margarita,ince,kucuk","margarita,ince,orta","margarita,ince,buyuk",
	"margarita,kalin,kucuk","margarita,kalin,orta","margarita,kalin,buyuk",
	"mexico,ince,kucuk","mexico,ince,orta","mexico,ince,buyuk",
	"mexico,kalin,kucuk","mexico,kalin,orta","mexico,kalin,buyuk"};
	
	
float fiyatlar[100] = {15.99,18.99,19.99,18.99,19.99,20.99,16.99,17.99,20.99,
					17.99,19.99,21.99,17.99,18.99,20.99,15.99,17.99,27.99};


void pizza_yazdir(char *pizzalar[], float fiyatlar[])
{
	printf("\nPizzalar:\n");
	for(int i = 0; i < a; i++)
	{
		printf("%d - %s = ",i+1,pizzalar[i]);
		printf("%.2f $\n", fiyatlar[i]);
	}
	
}


void pizza_txtyazdir(char *pizzalar[],float fiyatlar[])
{
	FILE *file2 = fopen("pizza.txt","w");
	
	
	for(int i = 0; i < a; i++)
	{
		fprintf(file2,"%d - %s = %.2f $\n",i+1,pizzalar[i],fiyatlar[i]);
	}
	
	
}

void musteri_yazdir()
{
	char l[150];
	FILE *file3 = fopen("musteri.txt","r");
	printf("\nKayitli Musteriler:");
	printf("\nID\tISIM\tSOYISIM\tNUMARA\t\tADRES\n");
	
	while(fgets(l,150,file3) != NULL)
	{
		printf("%s",l);
	}

}

void musteriekle(struct musteri Musteri)
{
	FILE* file3 = fopen("musteri.txt", "a");

	printf("\nMusteri Ekle");
	printf("\nID: ");
	scanf("%s",m.id);
	printf("Isim: ");
	scanf("%s",m.isim);
	printf("Soyisim: ");
	scanf("%s",m.soyisim);
	printf("Telefon: ");
	scanf("%s",m.telno);
	printf("Adres: ");
	scanf("%s,",m.adres);
	
	fprintf(file3,"%s\t%s\t%s\t%s\t%s\n",m.id,m.isim,m.soyisim,m.telno,m.adres);


}

void musteri_sil()
{
	char temp1[150];
	char temp2[150];
	
	char id[20];
	printf("\nSilinecek musterinin ID'si: ");
	scanf("%s",id);
			

	FILE* f = fopen("musteri.txt", "r+");
	FILE* temp = fopen("temp.txt", "w");

	while (fgets(temp1, 150, f) != NULL) 
	{
		
		memcpy(temp2, temp1, 150); //byte kopyalama işlemi.

		char* tmp = strtok(temp1, "\t");

		if (!strcmp(tmp,id)) {
			continue;
		}                                     
		else {
			fprintf(temp, "%s", temp2);
		}
	}
	fclose(f);
	fclose(temp);
	
	

	f = fopen("musteri.txt", "w");
	temp = fopen("temp.txt", "r+");

	while (fgets(temp1, 150, temp) != NULL) {
		memcpy(temp2, temp1, 150); //byte kopyalama işlemi.
		fprintf(f, "%s", temp2);
	}
	fclose(f);
	fclose(temp);
}

void musteri_guncelle(struct musteri Musteri)
{
	char temp1[150];
	char temp2[150];
	
	char id[20];
	printf("\nMusteri guncelle");
	printf("\nGuncellenecek musterinin ID'si: ");
	scanf("%s",id);
			

	FILE* f = fopen("musteri.txt", "r+");
	FILE* temp = fopen("temp.txt", "w");

	while (fgets(temp1, 150, f) != NULL) 
	{
		
		memcpy(temp2, temp1, 150); //byte kopyalama işlemi.

		char* tmp = strtok(temp1, "\t");
		fclose(temp);
		if (!strcmp(tmp,id)) 
		{
			FILE* file3 = fopen("temp.txt", "a");

			printf("Isim: ");
			scanf("%s",m.isim);
			printf("Soyisim: ");
			scanf("%s",m.soyisim);
			printf("Telefon: ");
			scanf("%s",m.telno);
			printf("Adres: ");
			scanf("%s,",m.adres);
	
			fprintf(file3,"%s\t%s\t%s\t%s\t%s\n",id,m.isim,m.soyisim,m.telno,m.adres);
			fclose(file3);
		}                                     
		else 
		{
			FILE* temp = fopen("temp.txt", "a");
			fprintf(temp, "%s", temp2);
		}
	}
	fclose(f);
	fclose(temp);

	

	f = fopen("musteri.txt", "w");
	temp = fopen("temp.txt", "r+");

	while (fgets(temp1, 150, temp) != NULL) {
		memcpy(temp2, temp1, 150); //byte kopyalama işlemi.
		fprintf(f, "%s", temp2);
	}
	fclose(f);
	fclose(temp);
		
}


	
void pizza_ekle(char *pizzalar[], float fiyatlar[])
{	
	printf("\nPizza Ekle");

	int i = 1;
	
	while(i!=0)
	{
		pizzalar[a] = (char*)malloc(50);
		printf("\nPizza ismi,Kenar,Boyut olarak virgulle ayirarak giriniz: ");
		scanf("%s",pizzalar[a]);
		
		printf("Fiyatini giriniz:");
		scanf("%f",&fiyatlar[a]);
		a++;
		
		printf("\nDevam etmek icin 1,cikmak icin 0'a basin.");
		scanf("%d",&i);
		
		
	}
	
	
}


void pizza_fiyat_guncelle(float fiyatlar[])
{
	int id;
	float yenifiyat;
	
	printf("\nFiyat guncellemek istediginiz pizzanin ID'sini giriniz :");
	scanf("%d",&id);
	printf("\nSu anki fiyat: %.2f",fiyatlar[id-1]);

	printf("\n\nYeni fiyatini giriniz :");
	scanf("%f",&yenifiyat);
	fiyatlar[id-1]=yenifiyat;
	printf("\nYeni fiyat: %.2f",fiyatlar[id-1]);
	
}

void pizza_sil(char *pizzalar[],float fiyatlar[])
{
	int id;
	printf("Silinecek pizzanin ID'si :");
	scanf("%d",&id);
	
	pizzalar[id-1]="--------Silindi----------";
	fiyatlar[id-1]=0.0000000;
	
}



void siparis_al(struct siparis Siparis, float fiyatlar[])
{
	printf("\nSiparis ID: ");// siparis IDsi
	scanf("%s",Siparis.id);
	printf("Musterinin ID'si: ");
	scanf("%s",Siparis.mid);
	printf("Tarih: ");
	scanf("%s",Siparis.tarih);
	printf("Pizzanin ID'si: ");
	scanf("%d",&Siparis.pid);
	
	FILE *file1 =  fopen("siparis.txt","a");
	fprintf(file1,"%s\t%s\t%.2f\t%s\n",Siparis.id,Siparis.mid,fiyatlar[Siparis.pid-1],Siparis.tarih);

	
}

int main()
{
	int secim;
	pizza_txtyazdir(pizzalar,fiyatlar);
	printf("---------PIZZA MEDENIYET ADMIN SISTEMINE HOSGELDINIZ---------\n");
	
	label:
	a=0;
	while(pizzalar[a]!=NULL)
	{
		a++;
	}
	printf("\n1.MUSTERI EKLE\n");
	printf("2.MUSTERI SIL\n");
	printf("3.MUSTERI BILGILARI GUNCELLE\n");
	printf("4.PIZZA EKLE\n");
	printf("5.PIZZA GUNCELLE\n");
	printf("6.PIZZA SIL\n");
	printf("7.SIPARIS AL\n");
	printf("0.AYRIL\n");
	printf("YUKARIDAKI ISLEMLERDEN BIRINI SECINIZ:");
	scanf("%d",&secim);
	printf("\n");
	
	
	switch(secim)
	{
		case 1:
			musteriekle(m);
			break;
		case 2:
			musteri_yazdir();
			
			musteri_sil();
			break;
		case 3:
			musteri_yazdir();
			musteri_guncelle(m);
			break;
		case 4:
			pizza_ekle(pizzalar,fiyatlar);
			pizza_txtyazdir(pizzalar,fiyatlar);
			
			break;
		case 5:
			pizza_yazdir(pizzalar,fiyatlar);
			pizza_fiyat_guncelle(fiyatlar);
			pizza_yazdir(pizzalar,fiyatlar);
			pizza_txtyazdir(pizzalar,fiyatlar);
			break;
		case 6:
			pizza_yazdir(pizzalar,fiyatlar);
			pizza_sil(pizzalar,fiyatlar);
			pizza_txtyazdir(pizzalar,fiyatlar);
			break;
		case 7:
			pizza_yazdir(pizzalar,fiyatlar);
			musteri_yazdir();
			siparis_al(s,fiyatlar);
			break;
		case 0:
			return 0;
		default:
			printf("Gecersiz islem!\n");
			return 0;
	}
	
	goto label;
	
	return 0;
}
