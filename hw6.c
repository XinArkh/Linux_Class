# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<pthread.h>

pthread_mutex_t mutex; //定义互斥锁 
int fib[100]; //共享数组,记录斐波那契序列 

//子进程，计算斐波那契序列
void *pthread(void *num){
	int i, j, k;
	pthread_mutex_lock(&mutex); //子线程要运行，锁定互斥锁
	
	fib[0] = 0;
	fib[1] = 1;
	for(i = 2; i <= (int)num-1; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	
	pthread_mutex_unlock(&mutex); //运行完毕，解锁互斥锁
	return 0; 
}

int main(void){
	pthread_t tid; // 
	pthread_mutex_init(&mutex, NULL); //互斥锁初始化
	
	int err, n, i;
	printf("输入要产生Fibonacci序列的个数：");
	scanf("%d", &n); 
	//创建进程
	err = pthread_create(&tid, NULL, pthread, (void *)n);
	if(err!=0){
		fprintf(stderr, "创建线程失败:%s\n", strerror(err));
		exit(1);
	}
	sleep(1); 
	pthread_mutex_lock(&mutex); //主程序要运行，锁定互斥锁 
	for(i = 0; i < n; i++){ 
		printf("第%2d个Fibonacci数为%2d\n", i+1, fib[i]);
	}
	pthread_mutex_unlock(&mutex); //运行完毕，解锁互斥锁
	
	pthread_mutex_destroy(&mutex); //释放mutex资源
	exit(0); 
} 
