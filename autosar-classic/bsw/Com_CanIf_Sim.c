#include <stdio.h>

void CanIf_Send(uint16_t id, uint8_t *data, uint8_t len)
{
    printf("CAN ID: %d | Data: ", id);
    for (int i = 0; i < len; i++)
        printf("%d ", data[i]);
    printf("\n");
}
