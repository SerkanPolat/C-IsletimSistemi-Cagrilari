
#ifndef KOMUTYORUM_H
#define KOMUTYORUM_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
char* komutBul(char* );
void ArgumanlariBul(Dizi,char* );
char* FazlaliklariDuzenle(char* );
void KomutCalistir(char *,Dizi ,int );
void KomutYorumlama(char* ,Dizi ,int );
#endif

