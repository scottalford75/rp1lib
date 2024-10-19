#include <stdio.h>
#include <stdlib.h>

//#include <stdbool.h>
#include <unistd.h>

#include "rp1lib.h"


int main()
{

    #define SIZE 20

    int ret;

    char txbuffer[SIZE];
    char rxbuffer[SIZE];

    int val = 'A';
    for (int i = 0; i<SIZE; i++)
    {
        txbuffer[i] = val;
        printf("val = %x\n", val);
        val++;
    }

    ret = rp1lib_init();

    if (ret < 0)
    {
        printf("failed to initialise rp1lib -%d\n", ret);
        return -1;
    }

    rp1spi_init(0, 0, SPI_MODE_1, 500000);   // spi_num, chip_select, SPI mode, frequency

    rp1spi_transfer(0, txbuffer, rxbuffer, SIZE);

    for (int i = 0; i<SIZE; i++)
    {
        printf("rx val = %x\n", rxbuffer[i]);
        val++;
    }

    ret = rp1lib_deinit();
    return EXIT_SUCCESS;
}
