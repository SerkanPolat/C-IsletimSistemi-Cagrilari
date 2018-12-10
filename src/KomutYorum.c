#include "dizi.h"
#include "Yonlendirme.c"
struct sigaction act;
char* komutBul(char* gelenKomut){
	int i;
	char* komut = malloc(sizeof(char));
	for(i = 0;i<100;i++){
		if(gelenKomut[i]!=10&&gelenKomut[i]!=32){
			komut = realloc(komut,sizeof(char)*i+3);
			komut[i] = gelenKomut[i]; 			
		}else{
			komut[i]=0;
			gelenKomut[i]=0;
			break;
		}			
	}
	return komut;
}

void ArgumanlariBul(Dizi gelenDizi,char* gelenKomut){
	int Uzunluk=0;
	char *EklenecekArguman=malloc(sizeof(char));
	for(int i =0;i<100;i++){
		if(gelenKomut[i]==1){
			break;		
		}
		if(gelenKomut[i]!=32&&gelenKomut[i]!=0){
			
			EklenecekArguman[Uzunluk]=gelenKomut[i];
			Uzunluk++;
			EklenecekArguman = realloc(EklenecekArguman,sizeof(char)*Uzunluk+2);
		}else{
			if(Uzunluk!=0){
			gelenDizi->DiziyeElemanEkle(gelenDizi,EklenecekArguman,Uzunluk);
			free(EklenecekArguman);
			EklenecekArguman = malloc(sizeof(char));
			Uzunluk=0;
			}
		}
	}			
	free(EklenecekArguman);
}

char* FazlaliklariDuzenle(char *gelenKomut){
	int Temizle=0;
	for(int i =0;i<100;i++){
		if(Temizle){
			gelenKomut[i]=0;
		}
		if(gelenKomut[i]==10){
			gelenKomut[i]=0;
			Temizle=1;
		}
	}
	return gelenKomut;
}

void KomutCalistir(char *gelenKomut,Dizi dizi,int ArkaPlan){
	int arkaplan=0;
	int pid;
	pid = fork();
		if(pid==0){
			dizi = DiziKurucu();
			ArgumanlariBul(dizi,gelenKomut);
			if(execvp(komutBul(gelenKomut),dizi->getDizi(dizi))){
				if(strcmp(gelenKomut,"quit"))			
					printf("Komut Gecersiz. \"%s\"\n",komutBul(gelenKomut));
			}
			dizi->DiziYikici(dizi);
			exit(pid);
		}else if(pid>0){
			if(!ArkaPlan){
				waitpid(pid,NULL,0);
			}else{
				sigaction(SIGCHLD, &act, 0);
			}
		}
}

void KomutYorumlama(char* gelenKomut,Dizi dizi,int ArkaPlan){
	int Bayrak=0;
	for(int i=0;i<100;i++){
		if(gelenKomut[i]=='>'){
			Bayrak=1;
			CikisYonlendirme(gelenKomut,dizi,ArkaPlan);	
		}else if(gelenKomut[i]=='<'){
			Bayrak=1;
			GirisYonlendirme(gelenKomut,dizi,ArkaPlan);
		}
		if(gelenKomut[i]=='&'){
			ArkaPlan=1;
			gelenKomut[i]=0;
		}
	}
	if(!Bayrak){
		KomutCalistir(gelenKomut,dizi,ArkaPlan);
	}
}
