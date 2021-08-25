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
    FILE* file = fopen("datos.bin", "rb");  
    c1 = fgetc(file) + "" + fgetc(file);
    fclose(file);

    printf("%c", c1);
    return 0;
}
