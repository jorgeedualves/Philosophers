#include "../include/philosophers.h"

void* routine(){
    printf("Test from threads\n");
}
int main(int argc, char*argv[]){
    pthread_t t1;
    pthread_create(&t1, NULL, &routine, NULL);

    return (0);
}