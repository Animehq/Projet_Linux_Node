#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <err.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int boucleInfi = 0;

    while(boucleInfi == 0)
    {

    char *name = malloc (128);
    char *value = malloc (128);
    char *Receive = malloc (128);
    char line[1024];
    int Model_Name = 5;
    int MHz = 3;
    int Address_Size = 16;
    int MemTotal = 1 ;
    int MemFree = 1;
    int MemAvailable = 1 ;
    int MemActive = 4 ;
    int MemInactive = 1;
    int eth0 = 3 ;



        FILE *cpuinfo = fopen("/proc/cpuinfo","r");



        while (!feof (cpuinfo))
        {
            sleep(1);
            //Name cpu = valuel
            while(Model_Name --)
                if(!fgets(line, sizeof(line),cpuinfo))
                {
                    printf("1\n");
                    err(1, "fgets");
                    }
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            // MHz = value
            //----------------------------------------------

            while(MHz --)
                if(!fgets(line, sizeof(line),cpuinfo))
                {
                    printf("2\n");
                    err(1, "fgets");
                    }
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            // Taux occupation = value
            //----------------------------------------------

            while(Address_Size --)
                if(!fgets(line, sizeof(line),cpuinfo))
                {
                    err(1, "fgets");
                    }
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            break;

        }

        fclose(cpuinfo);




        FILE *meminfo = fopen("/proc/meminfo","r");

        while (!feof (meminfo))
        {
            sleep(1);
            while(MemTotal --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            while(MemFree --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            while(MemAvailable --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            while(MemActive --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);

            while(MemInactive --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);
            break;

        }

        fclose(meminfo);

        FILE *dev = fopen("/proc/net/dev","r");

        while (!feof (dev))
        {
            sleep(1);
            while(eth0 --)
                if(!fgets(line, sizeof(line),meminfo))
                    err(1, "fgets");
            sscanf(line,"%[^\t:] : %[^\t\n]",name,value);
            printf("%s = %s\n",name,value);
            sleep(1);



            break;

        }

        fclose(meminfo);


        sleep(10);

    }

    // Client TCP/Envois
    //----------------------------------------------


    return 0;
}
