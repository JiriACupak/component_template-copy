#include <stdio.h>
#include <string.h>

int console_cmd_register(int (*cmd)(int, char**), const char *name);

static int cmd_my_hello(int argc, char **argv) {
    printf("Ahoj z vlastního VCOM pluginu!\n");
    return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

void register_cli_cmds(void) {
    console_cmd_register(cmd_my_hello, "hello");
}

void get_version(char* semver, char* gitrev) {
    if (semver != NULL) {
        snprintf(semver, 16, "1.0.0.0");
    }
    if (gitrev != NULL) {
        snprintf(gitrev, 13, "v1.0.0");
    }
}

#ifdef __cplusplus
}
#endif