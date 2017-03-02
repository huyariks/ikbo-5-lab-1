#include <stdio.h>

struct reg {
    int num;
    char str[255];
    float numf;
};


int main(int argc, char **argv) {

    struct reg p;
    FILE *fp = fopen(argv[1], "rb");
    
    if (fp == NULL) {
        printf("Can't open file\n");
        return NULL;
    }

    while (fread(&p , sizeof(struct reg),1, fp))
        printf("%d %s %f\n", p.num, p.str, p.numf);

    int fileSize = ftell(fp);
    printf("Size in bytes : %d\n", fileSize);

    return 0;
}
