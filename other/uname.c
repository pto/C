// uname prints the output from the uname system call.

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main() {
	struct utsname u;
	int rc = uname(&u);
	if (rc < 0) {
		perror("uname");
		exit(1);
	}
	printf("sysname:    %s\n", u.sysname);
	printf("nodename:   %s\n", u.nodename);
	printf("release:    %s\n", u.release);
	printf("version:    %s\n", u.version);
	printf("machine:    %s\n", u.machine);
#ifdef _GNU_SOURCE
	printf("domainname: %s\n", u.domainname);
#else
	printf("domainname: not defined\n");
#endif
}
