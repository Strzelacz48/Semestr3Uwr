#include "csapp.h"

static pid_t spawn(void (*fn)(void)) {
  pid_t pid = Fork();
  if (pid == 0) {
    fn();
    printf("(%d) I'm done!\n", getpid());
    exit(EXIT_SUCCESS);
  }
  return pid;
}

static void grandchild(void) {
  printf("(%d) Waiting for signal!\n", getpid());
  /* TODO: Something is missing here! */
  pause(); // czekamy na sygnal
  printf("(%d) Got the signal!\n", getpid());
}

static void child(void) {
  pid_t pid;
  /* TODO: Spawn a child! */
  //If the calling process is not already a session leader, setpgrp() sets the process group ID of the calling process to the process ID of the calling process. If setpgrp() creates a new session, then the new session has no controlling terminal. 
  //The setpgrp() function has no effect when the calling process is a session leader.
  setpgrp();
  pid = spawn(grandchild);
  printf("(%d) Grandchild (%d) spawned!\n", getpid(), pid);
}

/* Runs command "ps -o pid,ppid,pgrp,stat,cmd" using execve(2). */
static void ps(void) {
  /* TODO: Something is missing here! */
  char *argv[] = {"ps", "-o", "pid,ppid,pgrp,stat,cmd", NULL};
  // execvp - sprawdza PATH, używa envp = environ sposób użycia z neta :D
  execvp(argv[0], argv);
}

int main(void) {
  /* TODO: Make yourself a reaper. */
  
#ifdef LINUX
  Prctl(PR_SET_CHILD_SUBREAPER, 1);
#endif
  printf("(%d) I'm a reaper now!\n", getpid());

  pid_t pid, pgrp;
  int status;

  /* TODO: Start child and grandchild, then kill child!
   * Remember that you need to kill all subprocesses before quit. */
  printf("(%d) Spawning child\n", getpid());
  pid = spawn(child);
  waitpid(pid, &status, 0);
  printf("(%d) Child quit with %d\n", getpid(), status);
  pgrp = -pid;

  printf("(%d) Spawning ps\n", getpid());
  pid = spawn(ps);
  waitpid(pid, &status, 0);
  printf("(%d) ps quit with %d\n", getpid(), status);

  printf("(%d) Killing grandchild\n", getpid());
  kill(pgrp, SIGINT);
  waitpid(pgrp, &status, 0);//czeka na proces który jest liderem grupy którym jest wnuk
  printf("(%d) Granchild quit with %d\n", getpid(), status);
  return EXIT_SUCCESS;
}
