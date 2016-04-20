#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <linux/time.h>

#define NSEC_PER_SEC	1000000000L
typedef signed int s32;
typedef signed long s64;

typedef union cooper_ktime{
	s64 tv64;
	struct {
		s32 nsec,sec;
	}tv;
}cooper_ktime_t;


union udata{
	char ch;
	int idata;
};


int main(void)
{
	struct timespec time_start={0, 0},time_end={0, 0};
	cooper_ktime_t kts;
	
	union udata ud;
	ud.idata = 0x01020304;
	printf("char:0x%02x,int:0x%08x,%s\n",ud.ch,ud.idata,ud.ch==(char)1 ? "big endian" : (ud.ch==(char)4 ? "little endian" : "can't judge endian"));
	printf("sizeof(int):%d,sizeof(long):%d,sizeof(long long):%d\n",sizeof(int),sizeof(long),sizeof(long long));

	clock_gettime(CLOCK_REALTIME, &time_start);
	//getnstimeofday(&time_start);
	printf("start time %llus,%llu ns\n", time_start.tv_sec, time_start.tv_nsec);
	kts.tv64 = (s64)time_start.tv_sec * NSEC_PER_SEC + (s64)time_start.tv_nsec ;
	printf("start time ktime %lld\n", kts.tv64);

	clock_gettime(CLOCK_REALTIME, &time_end);
	//getnstimeofday(&time_end);
	printf("endtime %llus,%llu ns\n", time_end.tv_sec, time_end.tv_nsec);
	kts.tv64 = (s64)time_end.tv_sec * NSEC_PER_SEC + (s64)time_end.tv_nsec ;
	printf("start time ktime %lld\n", kts.tv64);
	
	printf("duration:%llus %lluns\n", time_end.tv_sec-time_start.tv_sec, time_end.tv_nsec-time_start.tv_nsec);
	return 0;
}
