#include <stdio.h>

// Variables globales
char c1 = 'A';
char c2 = 'B';

int i = 16; // Entero a 32 bits representado en LITTLE-ENDIAN

char c3 = 'C';
char c4 = 'D';

int serializeData(void);

int main()
{

    serializeData();

    return 0;
}

int serializeData()
{

    // Creación del archivo
    FILE *file = fopen("datos.mem", "wb");

    // Creación y asignación de la primera variable que aparece en memoria
    char *p = &c1;

    // Escritura de caracter 'A' y 'B' en archivo
    fprintf(file, "%c\n", p[0]);
    fprintf(file, "%c\n", p[1]);

    // Escritura de entero dividido en 4 bytes usando caracteres
    fprintf(file, "%c\n", p[7]);
    fprintf(file, "%c\n", p[6]);
    fprintf(file, "%c\n", p[5]);
    fprintf(file, "%c\n", p[4]);

    // Escritura de caracter 'C' y 'D' en archivo
    fprintf(file, "%c\n", p[8]);
    fprintf(file, "%c\n", p[9]);

    // Cierre de archivo
    fclose(file);
    
    return 0;
}
