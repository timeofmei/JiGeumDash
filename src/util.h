#ifndef UTIL_H
#define UTIL_H

#include "main.h"

#ifdef _WIN32
static const char path_separator = '\\';
static const char *extract_command = "7za.exe x -o";
static const char *rmdir_command = "rmdir /s /q ";
static const char *JiGeumDash_exe_name = "JiGeumDash.exe";
#define TEMP_PATH getenv("TEMP")
#else
static const char path_separator = '/';
static const char *extract_command = "7za x -o";
static const char *rmdir_command = "rm -rf ";
static const char *JiGeumDash_exe_name = "JiGeumDash";
#define TEMP_PATH (getenv("TMPDIR") ? getenv("TMPDIR") : "/tmp")
#endif

#define STR_PADDING_LEN 10

typedef enum
{
  RESOURCE_ZIP,
  MUSIC_ZIP
} ZIP_TYPE;

static const char *jigeum = "JiGeumDash";
static const char *resource = "resource";
static const char *music = "music";

int run_command(const char *command);

int dest_path_len(const char *music_name);

int inflate(const char *filename, const char *destloc);

int delete_dir_if_exist(const char *path);

int extract(ZIP_TYPE file_type, const char *fileloc, const char *music_name, char *destloc);

#endif