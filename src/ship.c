#include "../headers/ship.h"
#include <stdlib.h>
#include <string.h>

struct Ship *createShip(int shipID, const char *shipName) {
    struct Ship *newShip = (struct Ship *)malloc(sizeof(struct Ship));

    if (newShip == NULL) {
        // Bellek tahsisi başarısız oldu
        return NULL;
    }

    newShip->shipID = shipID;
    strncpy(newShip->shipName, shipName, sizeof(newShip->shipName) - 1);

    // Diğer özellikleri varsayılan değerlere ayarlayabilirsiniz.

    return newShip;
}
