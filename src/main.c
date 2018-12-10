#include "KomutYorum.c"
struct sigaction act;
void sighandler(int signum) {
	int pid;
	int status;
	pid = waitpid(-1, NULL,0);
	if(pid>0){
	printf("[%d]retval: %d \n", pid, WEXITSTATUS(0));
	waitpid(pid, NULL,0);
	}fflush(stdout);
}
int main(){
	Dizi dizi;
	char gelenKomut[100];
	int ArkaPlan=0;
	memset(&act, 0, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = sighandler;
	while(strcmp(gelenKomut,"quit")){
		printf("\n>");
		fgets(gelenKomut, 100, stdin);
		strcpy(gelenKomut,FazlaliklariDuzenle(gelenKomut));
		if(strcmp(gelenKomut,"quit")){
			KomutYorumlama(gelenKomut,dizi,ArkaPlan);
		}
	}
}











