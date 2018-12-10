#include "dizi.c"
#include "KomutYorum.h"
void GirisYonlendirme(char* gelenKomut,Dizi dizi,int ArkaPlan){
	int save_stdin = dup(0);
	int index=0;
	char *IslenecekKomut=malloc(sizeof(char));
	char *dosyaAdi=malloc(sizeof(char));
	int Bayrak=0;	
	for(int i = 0;i<100;i++){
		if(gelenKomut[i]==10){
			gelenKomut[i]=0;
			break;		
		}
		if(gelenKomut[i]=='<'){
			IslenecekKomut[i]=32;
			IslenecekKomut[i+1]=1;
			Bayrak=1;
			index=0;	
		}else if(Bayrak){
			if(gelenKomut[i]!=32){
				dosyaAdi[index] = gelenKomut[i];
				index++;
				dosyaAdi = realloc(dosyaAdi,(index+1)*sizeof(char));
			}
		}else{
			IslenecekKomut[index] = gelenKomut[i];
			index++;
			IslenecekKomut = realloc(IslenecekKomut,(index+1)*sizeof(char));
		}
	}
	int file = open(dosyaAdi,O_RDONLY);
	if(file<0){
		printf("Çıkış dosyası bulunamadı.");
	}else{
	dup2(file,0);
	KomutCalistir(IslenecekKomut,dizi,ArkaPlan);
	dup2(save_stdin,0);
	}
}

void CikisYonlendirme(char* gelenKomut,Dizi dizi,int ArkaPlan){
	int save_stdout = dup(1);
	int index=0;
	char *IslenecekKomut=malloc(sizeof(char));
	char *dosyaAdi=malloc(sizeof(char));
	int Bayrak=0;	
	for(int i = 0;i<100;i++){
		if(gelenKomut[i]==10){
			gelenKomut[i]=0;
			break;		
		}
		if(gelenKomut[i]=='>'){
			IslenecekKomut[i]=32;
			IslenecekKomut[i+1]=1;
			Bayrak=1;
			index=0;	
		}else if(Bayrak){
			if(gelenKomut[i]!=32){
				dosyaAdi[index] = gelenKomut[i];
				index++;
				dosyaAdi = realloc(dosyaAdi,(index+1)*sizeof(char));
			}
		}else{
			if(gelenKomut[i]!='>'){
			IslenecekKomut[index] = gelenKomut[i];
			index++;
			IslenecekKomut = realloc(IslenecekKomut,(index+2)*sizeof(char));
			}
		}
	}	
	int file = open(dosyaAdi,O_WRONLY | O_APPEND);
	if(file<0){
		printf("Giriş dosyası bulunamadı.");
	}else{
	dup2(file,1);
	KomutCalistir(IslenecekKomut,dizi,ArkaPlan);
	dup2(save_stdout,1);
	}
}
