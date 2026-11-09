#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum status {
    NO_ERR,
    FILE_OPEN_ERR,
    OPERATION_ERR
};

enum status encrypt(char *original, char *secret)
{
    enum status res = NO_ERR;
    FILE *fin = fopen(original, "r"); 
    FILE *fsec = fopen(secret, "r");
    if (!fin || !fsec) {
        res = FILE_OPEN_ERR;
        goto f_open_err;
    }

    /* byte by byte XOR encryption */
    FILE *fout = fopen("outfile", "w");
    while (!feof(fin)) {
        for (int s = fgetc(fsec); s != EOF; s = fgetc(fsec)) {
            int ch = fgetc(fin);
            if (ch == EOF) {
                break;
            }
            fputc(ch ^ s, fout);
        }
        rewind(fsec);
    }
    fclose(fout);
f_open_err:
    if (fin) {
        fclose(fin);
    }
    if (fsec) {
        fclose(fsec);
    }
    return res;
}

enum status decrypt(char *encoded, char *secret)
{
    enum status res = NO_ERR;
    FILE *fen = fopen(encoded, "r+");
    FILE *fs = fopen(secret, "r");
    if (!fen || !fs) {
        res = FILE_OPEN_ERR;
        goto f_open_err;
    }
    /* byte by byte decryption */
    while (!feof(fen)) {
        for (int s = fgetc(fs); s != EOF; s = fgetc(fs)) {
            int en = fgetc(fen);
            if (en == EOF) {
                break;
            }
            fseek(fen, -1L, SEEK_CUR);
            fputc(en ^ s, fen);
        }
        rewind(fs);
    }

f_open_err:
    if (fen) {
        fclose(fen);
    }
    if (fs) {
        fclose(fs);
    }
    return res;
}

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


