#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum status {
    NO_ERR,
    FILE_OPEN_ERR,
    OPERATION_ERR
};

enum status encrypt(char *original, char *secret);
enum status decrypt(char *encoded, char *secret);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        goto err_exit;
    }

    if (0 == strcmp("-e", argv[1])) {
        switch (encrypt(argv[2], argv[3])) {
        case FILE_OPEN_ERR: case OPERATION_ERR:
            goto err_exit;
        case NO_ERR:
        default:
            break;
        }
    } else if (0 == strcmp("-d", argv[1])) {
        switch (decrypt(argv[2], argv[3])) {
        case FILE_OPEN_ERR: case OPERATION_ERR:
            goto err_exit;
        case NO_ERR:
        default:
            break;
        }
    } else {
        goto err_exit;
    }

    return EXIT_SUCCESS;
err_exit:
    printf("usage: %s -[e|d] <original> <key>\n", __FILE__);
    return EXIT_FAILURE;
}


