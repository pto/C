#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
	time_t target = 1.4e9;
	struct timespec refresh_delay = {0, 1e8};

	printf("Time of    %ld: %s", (long)target, ctime(&target));

	for (;;) {
		struct timespec ts;

		clock_gettime(CLOCK_REALTIME, &ts);
		printf("Unix time: %.1f\r", ts.tv_sec + ts.tv_nsec / 1e9);
		fflush(stdout);
		nanosleep(&refresh_delay, NULL);
	}
}
