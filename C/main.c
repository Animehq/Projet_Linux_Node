#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <err.h>
#include <unistd.h>
#include <regex.h>
#include<math.h>

int main(int argc, char *argv[])
{

    int BoucleInfinie = 0;

    while (BoucleInfinie == 0)
    {



        char *name = malloc (128);
        char *value = malloc (128);
        //char *teste = malloc (128);
        char line[1024];
        int Model_Name = 5;
        int MHz = 3;
        int Address_Size = 16;
        int MemTotal = 1;
        int MemFree = 1;
        int MemAvailable = 1;
        int Active = 4;
        int Inactive = 1;
        int Receive = 3;
        //char *buffer ;
        char *temp = malloc (128);
        float mhztot = 0;
        float mtot=0;
        float memavail=0;
        char *cpufinal = malloc (128);
        char *memfinal = malloc (128);
        char *memusefinal = malloc (128);
        char *recut  = malloc (128);
        char *envoyer  = malloc (128);
        //buffer = malloc(1024);

        char *str_sub(const char *s, unsigned int start, unsigned int end)
        {
            char *new_s = NULL;
            if (s != NULL && start < end)
            {
                new_s = malloc(sizeof(*new_s) * (end - start + 2));
                if (new_s != NULL)
                {
                    int i;
                    for (i = start; i <= end; i++)
                    {
                        new_s[i-start]= s[i];
                    }
                    new_s[i-start] = '\0';
                }
                else
                {
                    fprintf (stderr, "Memoire insuffisante\n");
                    exit (EXIT_FAILURE);
                }
            }
            return new_s;
        }


        void reverse(char *str, int len)
        {
            int i=0, j=len-1, temp;
            while (i<j)
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i++;
                j--;
            }
        }

        int intToStr(int x, char str[], int d)
        {
            int i = 0;
            while (x)
            {
                str[i++] = (x%10) + '0';
                x = x/10;
            }

            // If number of digits required is more, then
            // add 0s at the beginning
            while (i < d)
                str[i++] = '0';

            reverse(str, i);
            str[i] = '\0';
            return i;
        }

        void ftoa(float n, char *res, int afterpoint)
        {
            // Extract integer part
            int ipart = (int)n;

            // Extract floating part
            float fpart = n - (float)ipart;

            // convert integer part to string
            int i = intToStr(ipart, res, 0);

            // check for display option after point
            if (afterpoint != 0)
            {
                res[i] = '.';  // add dot

                // Get the value of fraction part upto given no.
                // of points after dot. The third parameter is needed
                // to handle cases like 233.007
                fpart = fpart * pow(10, afterpoint);

                intToStr((int)fpart, res + i + 1, afterpoint);
            }
        }



        FILE *cpuinfo = fopen("/proc/cpuinfo","r");

        //Name cpu = value
        while(Model_Name --)
            if(!fgets(line, sizeof(line),cpuinfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);
        temp = str_sub(strchr(value, '@'), 2, 5);
        mhztot = atof(temp)*1000;
        //printf("Mhztot : %lf\n",mhztot);
        sleep(1);

        // MHz = value
        //----------------------------------------------

        while(MHz --)
            if(!fgets(line, sizeof(line),cpuinfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);
        float tempmhz = 0 ;
        tempmhz = atof(value);
        ftoa(tempmhz / mhztot * 100, cpufinal  , 2);
        printf("Cpu : %s %% \n", cpufinal);
        sleep(1);

        // Taux occupation = value
        //----------------------------------------------

        while(Address_Size --)
            if(!fgets(line, sizeof(line),cpuinfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);

        //sleep(1);


        fclose(cpuinfo);

        FILE *meminfo = fopen("/proc/meminfo","r");

        //Name cpu = value

        while(MemTotal --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);
        mtot = atof(value);
        //sleep(1);

        // MHz = value
        //----------------------------------------------

        while(MemFree --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);

        //sleep(1);

        // Taux occupation = value
        //----------------------------------------------

        while(MemAvailable --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);
        memavail = atof(value);
        ftoa(memavail / mtot*100, memfinal, 2);
        printf("Memoire disponible : %s %%\n", memfinal);
        sleep(1);

        while(Active --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);
        ftoa(atof(value)/mtot*100, memusefinal, 2);
        printf("Memoire active : %s %%\n", memusefinal);
        sleep(1);

        while(Inactive --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
        //printf("%s = %s\n",name,value);

        //sleep(1);


        fclose(meminfo);

        FILE *dev = fopen("/proc/net/dev","r");

        while(Receive --)
            if(!fgets(line, sizeof(line),meminfo))
                err(1, "fgets");
        sscanf(line,"%[^\t:] : %[^\t\n] ",name,value);
        //printf("%s = %s\n", name, value);
        recut = str_sub(value, 0, 8);
        printf ("Bande passante reçue : %s Bits\n", recut);
        sleep(1);
        envoyer = str_sub(value, 60, 69);
        printf("Bande passante envoyée : %s Bits\n", envoyer);
        fclose(dev);

        sleep(5);
        system("clear");
    }


    return 0;
}


