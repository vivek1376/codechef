//code accepted
#include <stdio.h>
#include <string.h>

int main()
{
    char s[2100];
    char *broken[] = {"????", "C???", "?H??", "??E?", "???F", "??EF", "?H?F", "?HE?", "C??F", "CH??", "C?E?", "?HEF", "C?EF", "CH?F", "CHE?"};	//see K&R sec 5.8
    int t,num_broken = sizeof (broken) / sizeof (broken[0]);
    unsigned int i, len;
    int j;		//j shouldn't be unsigned

    scanf ("%d", &t);

    while (t--)
    {
        scanf ("%s", s);
        len = strlen (s);

        //for(i=0;i<num_broken;i++)	//num_broken stores total possible no. of broken chefs
        for (j = len - 4; j >= 0; j--)
        {
            //check charaters from end
            for (i = 0; i < num_broken; i++)
            {
                //check every broken 'CHEF'
                if (strncmp (s + j, broken[i], 4) == 0)
                {
                    * (s + j + 0) = 'C';
                    * (s + j + 1) = 'H';
                    * (s + j + 2) = 'E';
                    * (s + j + 3) = 'F';
                    j = j - 3;
                    break;
                }
            }
        }

        i = 0;

        //replace remaining '?' with 'A'
        while (s[i])
        {
            s[i] = (s[i] == '?') ? 'A' : s[i];
            i++;
        }

        //finally print
        printf ("%s\n", s);
    }

    return 0;
}

/*
 better algorithm to find broken 'CHEF's
 	if(string[i] == 'F' || string[i] == '?' && i > 2)
{
if(string[i-1] == 'E' || string[i-1] == '?')
if(string[i-2] == 'H' || string[i-2] == '?')
if(string[i-3] == 'C' || string[i-3] == '?')
{
string[i-3] = 'C';
string[i-2] = 'H';
string[i-1] = 'E';
string[i] = 'F';
}
}
*
*
* or
*
*
 if(i-3>=0 && (S[i]=='?' || S[i]=='F') && (S[i-1]=='?' || S[i-1]=='E') && (S[i-2]=='?' || S[i-2]=='H') && (S[i-3]=='?' || S[i-3]=='C'))

*/

