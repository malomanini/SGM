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

	struct shmid_ds* buf;

	shmId = semget(cle, 5*sizeof(laListe), IPC_CREAT | 0660);

	if(shmId == -1){
		printf("Echec creation\n");
		return -1;
	}

	addr = shmat(shmId, NULL, 0);

	if(addr == NULL){
		printf("Echec attachement\n");
		return -1;
	}

	laListe.val = 42;

	printf("la valeur partagee est %d\n",laListe.val);

	buf = (struct shmid_ds *) &laListe;

	clear = shmctl(shmId, IPC_SET,  buf);

	if(clear == -1){
		printf("Echec ecriture\n");
		return -1;
	}

	clear = shmctl(shmId, IPC_RMID,  NULL);

	if(clear == -1){
		printf("Echec destruction\n");
		return -1;
	}

	return 0;
}