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
    // Write binary data
    FILE* file = fopen("datos.bin", "wb"); // Creating the file
    char* p = &c1;
    
    //char *p2 = (char *) &i;

    fprintf(file, "%d\n", *p);                
    fprintf(file, "%d\n", *(p+1));                
    
    fprintf(file, "%d\n", *(p+7));                
    fprintf(file, "%d\n", *(p+6));                
    fprintf(file, "%d\n", *(p+5));                
    fprintf(file, "%d\n", *(p+4));                

    fprintf(file, "%d\n", *(p+8)); 
    fprintf(file, "%d\n", *(p+9)); 

    //fprintf(file, "%d", *(p+2));                
    //fprintf(file, "%d", *(p+3));                
    //fprintf(file, "%d", c2);                
    fclose(file);                          // Closing the file
    return 0;

}
