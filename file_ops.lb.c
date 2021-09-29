#include <stdio.h>
#include <stdlib.h>

char * file_stringise(char * filename)
{
  char * buffer = 0;
  long length;
  FILE * f = fopen (filename, "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);   
  }
  return buffer;
}

#include <string.h>

FILE * file_switch(FILE *codex, char** codii, int index_codii)
{
  if (index_codii==0)
  { if (!*codii)
      return stdin;
  }
  else
    fclose(codex);
  return fopen(codii[index_codii],"r");
}

char ** strarr_allocate(int argc, char **argv, char **codii)
{ char buffer[0201];
  
  codii = calloc(argc, sizeof (char *));
  char **back = codii;
  
  while (argc--> 0)
  { strncpy(buffer, *++argv, 0200);
    *codii = malloc(strlen(buffer)+1);
    strcpy(*codii++,buffer);
  }
  return back;
}
