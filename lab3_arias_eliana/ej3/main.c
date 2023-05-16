#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}
unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size){
	FILE *fd = NULL;
	unsigned int fscanf_result = 0;
	unsigned int length = 0;
	fd = fopen(path, "r");
	if(fd == NULL)
	{
	    printf("Error al abrir el archivo");
		exit(EXIT_FAILURE);
        printf("\n");
	}
	while(!feof(fd) && length < max_size)
	{
		fscanf_result = fscanf(fd, "%u -> *%c*\n", &indexes[length], &letters[length]);
		if(fscanf_result != 2)
		{
		    printf("Error: el archivo no tiene el formato correcto");
			exit(EXIT_FAILURE);
		}
		length = length + 1;
	}
	if(length == max_size)
	{
	    printf("Error: el archivo es demasiado grande");
		exit(EXIT_FAILURE);
	}
	fclose(fd);
	return length;
}

void sort_letters(unsigned int length,
                    unsigned int indexes[],
                    char letters[],char sorted[]){
	unsigned int j=0;
	unsigned int k=0;
	while(k < length)
	{
		j = indexes[k];
		if(j >= length)
		{
		    printf("Error: el archivo tiene un indice fuera de rango");
			exit(EXIT_FAILURE);
		}
		sorted[j] = letters[k];
		k = k + 1;
	}
}
int main(int argc, char *argv[]) {
    char *file = NULL;
    file = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
  
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    length = data_from_file(file, indexes, letters, MAX_SIZE);

    sort_letters(length, indexes, letters, sorted);

    dump(sorted, length);
    
    return EXIT_SUCCESS;
}