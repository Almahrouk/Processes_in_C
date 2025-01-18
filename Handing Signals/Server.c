#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal_continue(int signal) {
    printf("Process continued with signal: %d\n", signal);
}

int main() {
    pid_t id = getpid();
    printf("This is my Process ID (%d)\n", id);

    struct sigaction sa;
    sa.sa_handler = handle_signal_continue;  // Set the signal handler function
    sa.sa_flags = 0;                // No special flags
    sigemptyset(&sa.sa_mask);       // Clear all signals from the mask

    if (sigaction(SIGCONT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    int count = 1000;
    while (count--) {
        printf("This will Print Forever (%d)\n", count);
        sleep(1);
    }
    printf("This will never be shown\n");
    return 0;
}
