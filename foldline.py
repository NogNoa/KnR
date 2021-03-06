# include "KnR_getline.h"
LNSIZ = 0x50


def equ_fold(string: str):
    print(string[:LNSIZ], end='')
    if len(string) > LNSIZ:
        print('\n')
        smrt_fold(string[LNSIZ:])


def smrt_fold(string: str):
    IN = 1
    OUT = 0
    state = IN
    last = 0

    for j in range(len(string)):
        if j >= LNSIZ:
            break
        elif string[j] in {' ', '\t', '\n'}:
            state = OUT
        elif state == OUT:
            last = j
            state = IN
    if not last:
        equ_fold(string)
    else:
        print(string[:last])
        if j <= LNSIZ:
            smrt_fold(string[last:])
        else:
            print(string[last:])


"""
void equ_fold (char str[])
{
   int j;

   for (j=0;j<LNSIZ && str[j] ;++j)
      {putchar(str[j]);}
   putchar('\n');
   if (str[j])
      equ_fold(&str[LNSIZ]);
}


def main()
   char line[MAXLINE];

   while ((len = KnR_getline(line, MAXLINE)) > 0){
      if (len <= LNSIZ)
         {printf("%s", line);}
      else 
         {smrt_fold(line);}
   }
   return 0;
"""

smrt_fold("       <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+\"://platform.twitter.com/widgets.js\";fjs.parentNode.insertBefore(js,fjs);}}(document,\"script\",\"twitter-wjs\");</script>\
 ")
