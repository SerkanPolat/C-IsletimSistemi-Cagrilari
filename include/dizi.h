
#ifndef DIZI_H
#define DIZI_H

typedef struct DIZI* Dizi;

struct DIZI{
	int *index;
	int LowIndex;
	char **elemanlar;
	void (*DiziyeElemanEkle)(const Dizi,char*,int);
	void (*DiziYikici)(const Dizi);
	char** (*getDizi)(const Dizi);
};
Dizi DiziKurucu();
void _DiziYikici(const Dizi);
void _DiziyeElemanEkle(const Dizi,char*,int);
char **_getDizi(const Dizi);
#endif
