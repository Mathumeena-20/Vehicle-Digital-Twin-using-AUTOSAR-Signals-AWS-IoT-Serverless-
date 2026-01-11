#include "Rte_VehicleState.h"

void VehicleStateSWC_Run(void)
{
    uint16 speed = 60;
    uint8 battery = 80;

    Rte_Write_VehicleSpeed(speed);
    Rte_Write_BatteryLevel(battery);
}
