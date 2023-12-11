#include "../headers/ship.h"
#include <stdlib.h>
#include <string.h>

Ship *createShip(int shipID, const char *shipName) {
    Ship *newShip = (Ship *)malloc(sizeof(Ship));

    if (newShip == NULL) {
        // Bellek tahsisi başarısız oldu
        return NULL;
    }

    newShip->shipID = shipID;
    strncpy(newShip->shipName, shipName, sizeof(newShip->shipName) - 1);

    // Diğer özellikleri varsayılan değerlere ayarlayabilirsiniz.

    return newShip;
}
