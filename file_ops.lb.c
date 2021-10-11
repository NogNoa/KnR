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

FILE * file_switch(FILE *codex, char** codii)
{ //open next file in a list of file-names
  static int index_codii; //static variables are guaranteed to init 0;
  
  if (index_codii==0)
  { if (!*codii)
    { index_codii++;
      return stdin;
    }
  }
  else
    fclose(codex);
  return fopen(codii[index_codii++],"r");
}

FILE * file_switch_index(FILE *codex, char** codii, int index_codii)
{   //open by index file in a list of file-names
    if (codex) //sadly caller's responsibilty to initialize unopened file ptr to null
        fclose(codex);
    return fopen(codii[index_codii],"r");
}

char ** strarr_allocate(int nom_cnt, char **nomi, char **codii)
{ //create a list of names
  codii = calloc(nom_cnt, sizeof (char *));
  char **back = codii;
  
  while (nom_cnt--> 0)
  { *codii = malloc(strlen(*nomi)+1);
    strcpy(*codii++,*nomi++);
  }
  return back;
}

#include <fcntl.h>
#include <unistd.h>

int file_switch_low(int codex, char** codii)
{ //open next file in a list of file-names
  static int index_codii; //static variables are guaranteed to init 0;
  
  if (index_codii==0)
  { if (!*codii)
    { index_codii++;
      return 0;
    }
  }
  else
    close(codex);
  return open(codii[index_codii++],O_RDONLY, 0);
}
