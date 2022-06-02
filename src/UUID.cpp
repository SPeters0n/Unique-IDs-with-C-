#include <stdio.h>
#include <string.h>
#include <uuid/uuid.h>

#define UUIDTEXTSIZE (sizeof(uuid_t)*2) + 5

void printrawuuid(uuid_t id) {
    printf("RAW: ");
    for (int i=0; i < sizeof(uuid_t); i++) {
        printf("%x ", id[i]);
    }
    printf("\n");
}

int main() {
    uuid_t myuuid;
    printrawuuid(myuuid);

    char uuidtext[UUIDTEXTSIZE];
    uuid_unparse(myuuid, uuidtext);
    printf("UUID: %s\n", uuidtext);
}