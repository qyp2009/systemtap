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

s64 get_timestamp(){
    struct timespec ts;
    cooper_ktime_t tstamp;
    
    clock_gettime(CLOCK_REALTIME, &ts);
    tstamp.tv64 = (s64)ts.tv_sec * NSEC_PER_SEC + (s64)ts.tv_nsec ;

    return tstamp.tv64;
}

int main(void)
{
	struct timespec time_start={0, 0},time_end={0, 0};
	cooper_ktime_t kts;
	s64 begin, end, tmp;
	int i;

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

	printf("timestamp: %lld\n",get_timestamp());

	begin=get_timestamp();
	for(i=0;i<1000;i++){
		tmp=get_timestamp();
	}
	end=get_timestamp();

	printf("\n\
timestamp begin: %lld ns\n\
after 10000 times get_timestamp ......\n\
timestamp   end: %lld ns\n",begin,end);
	printf("average offload: %lld/%d = %lf ns\n", end-begin,1000,(double)(end-begin)/1000);
	
	return 0;
}
