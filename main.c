

/***** Question 4.2 ********
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char *file_log = malloc(sizeof(char));
    file_log = argv[1];

    if(file_log == NULL){
        return 0;
    }
    int out = open(file_log, O_RDWR|O_CREAT|O_APPEND, 0600);
    if (-1 == out) { perror("opening cout.log"); return 255; }

    printf("redirect to the file \n");
    int save_out = dup(fileno(stdout));

    if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); return 255; }



    puts("doing an ls or something now");

    fflush(stdout); close(out);

    dup2(save_out, fileno(stdout));

    close(save_out);

    puts("back to normal output");

    return 0;
}

*/

/*
#include <stdio.h>

int main() {
    FILE *stream;
    stream = fopen("./my_file", "w");
    int fno = fileno(stream);
    if(fno != -1){
        if(fno == stdin) {
        printf("In");
        }
        if(fno == stdout) {
            printf("Out");
        }
        if(fno == stderr) {
            printf("Error");
        }
        fclose(stream);
    }else{
        printf("mistake");
    }
    return 0;
}
*/