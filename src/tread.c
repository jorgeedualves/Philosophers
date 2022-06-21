#include "../include/philosophers.h"

void* routine(){
    printf("Test from threads\n");
}
int main(int argc, char*argv[]){
    pthread_t t1;
    pthread_t t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return(1);
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return(2);
    if(pthread_join(t1, NULL) != 0);
       return(3);
   if(pthread_join(t1, NULL) != 0);
       return(4);
    return (0);
}