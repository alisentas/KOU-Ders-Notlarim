#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int kenar1, kenar2, hipotenuskare, chip, fhip;
    float hipotenus;
    for(kenar1 = 1; kenar1 <= 500; kenar1++){
        for(kenar2 = kenar1; kenar2 <= 500; kenar2++){
            hipotenuskare = kenar1 * kenar1 + kenar2 * kenar2;
            hipotenus = sqrt(hipotenuskare);
            fhip = (int)floor(hipotenus);
            chip = (int)ceil(hipotenus);
            if(hipotenus <= 500)
                if(chip * chip == hipotenuskare || fhip * fhip == hipotenuskare)
                    printf("%d\t%d\t%d\n", kenar1, kenar2, (int)hipotenus);
        }
    }
    return 0;
}
