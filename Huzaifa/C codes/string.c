#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
char* strtok_r(
    char *str, 
    const char *delim, 
    char **nextp)
{
    //return str;
    char *ret;

    if (str == NULL)
    {
        str = *nextp;
    }

    str += strspn(str, delim);

    if (*str == '\0')
    {
        return NULL;
    }

    ret = str;

    str += strcspn(str, delim);

    if (*str)
    {
        *str++ = '\0';
    }

    *nextp = str;

    return ret;
}
struct GPRMC_TEMP{
    int time;
    char warning;
    float lat;
    char lat_dir;
    float Lon;
    char lon_dir;
    float SOG;
    float COG;
    int date;
    float mag;
    char mag_dir;
}; 

struct GPRMC_TEMP ParseRMC(char * message)
{
    struct GPRMC_TEMP G;
    char*test;// = message;
    char *token =  strtok_r(message, ",",&test);  
    if (strcmp(token, "$GPRMC") == 0)
    {

     
        token =  strtok_r(NULL,",",&test);
        G.time = atoi(token);
        printf("Time:%d\n",G.time);
        token = strtok_r(NULL,",",&test);
        G.warning = *token;
        printf("Warning:%c\n",G.warning);
        token =strtok_r(NULL,",",&test);
        G.lat = atof (token);
        printf("Lat: %f\n",G.lat);
        token =strtok_r(NULL,",",&test);
        G.lat_dir = *token;
        printf("Lat dir: %c\n",G.lat_dir);
        token =strtok_r(NULL,",",&test);
        G.Lon = atof (token);
        printf("Lon: %f\n",G.Lon);
        token =strtok_r(NULL,",",&test);
        G.lon_dir=*(token);
        printf("Long_dir: %c\n",G.lon_dir);
        token =strtok_r(NULL,",",&test);
        G.SOG=atof(token);
        printf("SOG: %f\n",G.SOG);
        token =strtok_r(NULL,",",&test);
        G.COG=atof(token);
        printf("COG: %f\n",G.COG);
        token =strtok_r(NULL,",",&test);
        G.date = atoi (token);
        printf("date: %d\n",G.date);
        token =strtok_r(NULL,",",&test);
        G.mag=atof (token);
        printf("mag: %f\n",G.mag);
        token =strtok_r(NULL,",",&test);
        G.mag_dir=*(token);
        printf("mag_dir: %c\n",G.mag_dir);
    }
    return G;
}
int main() {
    char nmea[] = "$GPGGA,184353.07,1929.045,S,02410.506,E,1,04,2.6,100.00,M,-33.9,M,,0000*6D\n\r$GPRTE,2,1,c,0,PBRCPK,PBRTO,PTELGR,PPLAND,PYAMBU,PPFAIR,PWARRN,PMORTL,PLISMR*73\n\r$GPR00,A,B,C*29\n\r$GPRMC,183729,A,3907.356,N,12102.482,W,000.0,360.0,080301,015.5,E*6F\r\n$GPRMB,A,,,,,,,,,,,,V*71\r\n$GPGGA,183730,3907.356,N,12102.482,W,1,05,1.6,646.4,M,-24.1,M,,*75\r\n$GPGSA,A,3,02,,,07,,09,24,26,,,,,1.6,1.6,1.0*3D\r\n$GPGSV,2,1,08,02,43,088,38,04,42,145,00,05,11,291,00,07,60,043,35*71\r\n$GPGSV,2,2,08,08,02,145,00,09,46,303,47,24,16,178,32,26,18,231,43*77\r\n$PGRME,22.0,M,52.9,M,51.0,M*14\r\n$GPGLL,3907.360,N,12102.481,W,183730,A*33\r\n$PGRMZ,2062,f,3*2D\r\n$PGRMM,WGS84*06\r\n$GPBOD,,T,,M,,*47\r\n$GPRTE,1,1,c,0*07\r\n$GPRMC,183731,A,3907.482,N,12102.436,W,000.0,360.0,080301,015.5,E*67\r\n$GPRMB,A,,,,,,,,,,,,V*71\r\n";
    char message[1024];
    char *token = strtok(nmea, "\n\r");
    printf("token:%s\n",token);
    while (token != 0) {
       strcpy(message, token);
        ParseRMC(message);
        printf("%s\n", message);
        token = strtok(0, "\n\r*");
    }

    return 0;
}
