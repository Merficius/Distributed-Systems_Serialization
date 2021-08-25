#include <stdio.h>

// Variables globales
char c1 = 'U';
char c2 = 'U';

// entero a 64 bits representado en LITTLE-ENDIAN
long i = -1;

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

    // Creación de archivo para lecture
    FILE *file = fopen("datos.mem", "rb");

    // Creación y asignación del puntero en el primer espacio de memoria para el entero de 64 bits
    char *p = (char *)&i;

    // Lecture de primeros dos caracteres 'A' y 'B'
    c1 = fgetc(file);
    fgetc(file);
    c2 = fgetc(file);
    fgetc(file);

    // Lectura de caracteres de archivo (representados en big-endian) para los primeros 4 bytes del long (representado en little-endian)
    p[3] = fgetc(file);
    fgetc(file);
    p[2] = fgetc(file);
    fgetc(file);
    p[1] = fgetc(file);
    fgetc(file);
    p[0] = fgetc(file);
    fgetc(file);
    // últimos 4 bytes del long puestos en 0 ya que no tenemos información para llenarlos
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;

    // Lecture de últimos dos caracteres 'C' y 'D'
    c3 = fgetc(file);
    fgetc(file);
    c4 = fgetc(file);
    fgetc(file);

    // Cierre del archivo
    fclose(file);

    // Impresión de valores de tipo caracter y de tipo long en consola
    printf("%c\n", c1);
    printf("%c\n", c2);
    printf("%ld\n", i);
    printf("%c\n", c3);
    printf("%c\n", c4);

    return 0;
}
