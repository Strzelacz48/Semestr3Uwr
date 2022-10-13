#include "include/csapp.h"

static char buf[256];

#define LINE1 49
#define LINE2 33
#define LINE3 78

static void do_read(int fd) {
  /* TODO: Spawn a child. Read from the file descriptor in both parent and
   * child. Check how file cursor value has changed in both processes. */
    pid_t pid;
    pid = fork();
    int pidint=pid;
    if(pid == 0){//dziecko
        read(fd,buf,16);
        printf("%d: %d\n",pidint, lseek(fd,0,SEEK_CUR));
      }
    else{//rodzic
        read(fd,buf,16);
        printf("%d: %d\n",pidint,lseek(fd,0,SEEK_CUR));
      }
      exit(0);
}

static void do_close(int fd) {
  /* TODO: In the child close file descriptor, in the parent wait for child to
   * die and check if the file descriptor is still accessible. */
    int child_status;
    pid_t pid; // pid_t to typ zmiennej na PIDY istnieje taki naprawdę
    pid = fork();
    int pidint=pid;
    if(pid == 0){//to robi dziecko
        printf("%d: Closing the file %d\n",pidint,fd);
        close(fd);
        exit(0);
    }
    else {//to robi rodzic
        waitpid(pid,&child_status,0);
        printf("%d: Child status: %d\n",pidint,child_status);
        printf("%d: Cursor position: %d\n",pidint, lseek(fd,0,SEEK_CUR));
        read(fd,buf,16);
        printf("%d: Reading from file %d: %s\n",pidint,fd,buf);
        exit(0);
      }
    exit(0);
}

int main(int argc, char **argv) {
  if (argc != 2)
    app_error("Usage: %s [read|close]", argv[0]);

  int fd = Open("test.txt", O_RDONLY, 0);

  if (!strcmp(argv[1], "read"))
    do_read(fd);
  if (!strcmp(argv[1], "close"))
    do_close(fd);
  app_error("Unknown variant '%s'", argv[1]);
}
