#include "dizi.h"
#include <stdlib.h>
#include <stdio.h>
Dizi DiziKurucu(){
	Dizi this;
	this = (Dizi)malloc(sizeof(struct DIZI));
	this->elemanlar = calloc(sizeof(char),sizeof(char));
	this->elemanlar[0] = calloc(sizeof(char),sizeof(char));		
	this->LowIndex=1;
	this->index = malloc(sizeof(int)*this->LowIndex);
	this->DiziyeElemanEkle = &_DiziyeElemanEkle;
	this->DiziYikici = &_DiziYikici;
	this->getDizi = &_getDizi;
	return this;
}
void _DiziYikici(Dizi this){
	for(int i =0;i<this->LowIndex;i++){	
		free(this->elemanlar[i]);
	}
	free(this->elemanlar);
	this->LowIndex=1;
	free(this->index);
	free(this);
}
void _DiziyeElemanEkle(Dizi this,char* gelenEleman,int Uzunluk){
	this->elemanlar = realloc(this->elemanlar,sizeof(char)*this->LowIndex*150);
	this->elemanlar[this->LowIndex-1] = realloc(this->elemanlar[this->LowIndex-1],sizeof(char)*Uzunluk+2);
	int i = 0;
	for(i=0;i<Uzunluk;i++){
		this->elemanlar[this->LowIndex-1][i]=gelenEleman[i];
	}
	this->elemanlar[this->LowIndex-1][Uzunluk]=0;
	this->LowIndex++;
}
char** _getDizi(Dizi this){
	this->elemanlar[this->LowIndex]=NULL;
	int i =0;
	for(i;i<100;i++){
		if(this->elemanlar[this->LowIndex-2][i]==10){
			this->elemanlar[this->LowIndex-2][i]=0;
			break;
		}
	}
	return this->elemanlar;
	
}
