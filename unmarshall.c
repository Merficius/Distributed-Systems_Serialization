#include <stdio.h>

// Variables globales
char c1 = 'U';
char c2 = 'U';

long i = -1; // entero a 64 bits representado en LITTLE-ENDIAN

char c3 = 'U';
char c4 = 'U';

int readSerializedData(void);

int main()
{

    readSerializedData();

    return 0;
}

int readSerializedData()
{

    //Reading binary data
    FILE *file = fopen("datos.mem", "rb");
    char *p = (char *)&i;

    c1 = fgetc(file);
    fgetc(file);
    c2 = fgetc(file);
    fgetc(file);

    p[3] = fgetc(file);
    fgetc(file);
    p[2] = fgetc(file);
    fgetc(file);
    p[1] = fgetc(file);
    fgetc(file);
    p[0] = fgetc(file);
    fgetc(file);
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;

    c3 = fgetc(file);
    fgetc(file);
    c4 = fgetc(file);
    fgetc(file);

    fclose(file);

    printf("%c\n", c1);
    printf("%c\n", c2);
    printf("%ld\n", i);
    printf("%c\n", c3);
    printf("%c\n", c4);

    return 0;
}
