#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

struct 
{
    int val;
    struct laListe *next;
}laListe;

int main(){
	key_t cle = 1234;
	char *addr;
	int shmId, clear;

	addr = shmat(shmId, NULL, 0);

	if(addr == NULL){
		printf("Echec attachement\n");
		return -1;
	}

	printf("la valeur partagee est %d\n",laListe.val);

	clear = shmctl(shmId, IPC_RMID,  NULL);

	if(clear == -1){
		printf("Echec destruction\n");
		return -1;
	}

	return 0;
}