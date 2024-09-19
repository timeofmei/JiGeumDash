#include "util.h"

int run_command(const char *command)
{
    printf("Run command %s\n", command);
    char psBuffer[128];
    FILE *pPipe = _popen(command, "r");
    if (!pPipe)
    {
        printf("Error: Failed to open the pipe.\n");
        return -1;
    }
    while (fgets(psBuffer, 128, pPipe))
        printf(psBuffer);
    const int endOfFileVal = feof(pPipe);
    const int closeReturnVal = _pclose(pPipe);
    if (!endOfFileVal)
    {
        printf("Error: Failed to read the pipe to the end.\n");
        return -2;
    }
    printf("Command %s returned %d\n", command, closeReturnVal);
    return closeReturnVal;
}

int dest_path_len(const char *music_name)
{
    return strlen(TEMP_PATH) + strlen(jigeum) + strlen(music_name) + strlen(resource) + strlen(music) + STR_PADDING_LEN;
}

int dest_path(const ZIP_TYPE file_type, const char *music_name, char *destloc)
{
    if (destloc[strlen(TEMP_PATH) - 1] != path_separator)
        sprintf(destloc, "%s%c%s%c%s%c", TEMP_PATH, path_separator, jigeum, path_separator, music_name, path_separator);
    else
        sprintf(destloc, "%s%s%c%s%c", TEMP_PATH, jigeum, path_separator, music_name, path_separator);
    switch (file_type)
    {
    case RESOURCE_ZIP:
        strcat(destloc, resource);
        break;
    case MUSIC_ZIP:
        strcat(destloc, music);
        break;
    default:
        return -1;
    }
    return 0;
}

int inflate(const char *filename, const char *destloc)
{
    char command[strlen(extract_command) + strlen(destloc) + strlen(filename) + STR_PADDING_LEN];
    sprintf(command, "%s\"%s\" \"%s\"", extract_command, destloc, filename);
    return run_command(command);
}

int delete_dir_if_exist(const char *path)
{
    if (!DirectoryExists(path))
        return 0;
    char command[strlen(rmdir_command) + strlen(path) + STR_PADDING_LEN];
    sprintf(command, "%s\"%s\"", rmdir_command, path);
    return run_command(command);
}

int extract(const ZIP_TYPE file_type, const char *fileloc, const char *music_name, char *destloc)
{
    dest_path(file_type, music_name, destloc);
    delete_dir_if_exist(destloc);
    return inflate(fileloc, destloc);
}