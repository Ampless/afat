#pragma once

#define MAXNAMLEN 255		/* sizeof(struct dirent.d_name)-1 */

struct dirent {
  int d_ino;
  char d_name[MAXNAMLEN+1];
};

typedef struct {
    int dd_fd;		/* directory file */
    int dd_loc;		/* position in buffer */
    int dd_seek;
    char *dd_buf;	/* buffer */
    int dd_len;		/* buffer length */
    int dd_size;	/* amount of data in buffer */
    /*_LOCK_RECURSIVE_T dd_lock;*/
    struct dirent dd_dirent;
} DIR;

#define __dirfd(dir) (dir)->dd_fd

/* --- redundant --- */

DIR *opendir(const char *);
struct dirent *readdir(DIR *);
void rewinddir(DIR *);
int closedir(DIR *);

/* internal prototype */
void _seekdir(DIR *dir,off_t offset);
DIR *_opendir(const char *);

#ifndef _POSIX_SOURCE
long telldir (DIR *);
void seekdir (DIR *, off_t loc);

int scandir (const char *__dir,
             struct dirent ***__namelist,
             int (*select) (const struct dirent *),
             int (*compar) (const struct dirent **, const struct dirent **));

int alphasort (const struct dirent **__a, const struct dirent **__b);
#endif /* _POSIX_SOURCE */

#endif
