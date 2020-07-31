#include<iostream>
#include<pthread.h>
#include <time.h>
#include <unistd.h>

class WR_lock
{
    private:
        pthread_mutex_t wmutex;
        pthread_mutex_t rmutex;
        pthread_mutex_t count_mutex;
        pthread_cond_t wcond;
        pthread_cond_t rcond;

        int wcount;
        int rcount;
    
    public:
        WR_lock()
        {
            pthread_mutex_init(&wmutex, NULL);
            pthread_mutex_init(&rmutex, NULL);
            pthread_mutex_init(&count_mutex, NULL);
            pthread_cond_init(&wcond, NULL);
            pthread_cond_init(&rcond, NULL);
            wcount = 0;
            rcount = 0;
        }

        int read(void)
        {
            pthread_mutex_lock(&rmutex);
            while(wcount != 0)
                pthread_cond_wait(&wcond, &rmutex);
            rcount++;
            pthread_mutex_unlock(&rmutex);
            

            pthread_mutex_lock(&rmutex);
            rcount--;
            pthread_mutex_lock(&count_mutex);
            std::cout << "read:" << rcount  << std::endl;
            pthread_mutex_unlock(&count_mutex);
            pthread_mutex_unlock(&rmutex);

            if(rcount == 0)
                pthread_cond_signal(&rcond);

            return 0;
        }

        int write(void)
        {
            pthread_mutex_lock(&wmutex);
            while(rcount != 0)
                pthread_cond_wait(&rcond, &wmutex);
            
            wcount = 1;
            //std::cout <<"write:" <<wcount <<std::endl;
            wcount = 0;
            pthread_mutex_lock(&count_mutex);
            std::cout << "write:" << wcount <<std::endl;
            pthread_mutex_unlock(&count_mutex);
            pthread_cond_signal(&rcond);
            pthread_mutex_unlock(&wmutex);

            return 0;
        }
};

WR_lock wr_lock;

const static int count = 5;

void *read_thread(void *p)
{
    int *i = (int*)p;
    //std::cout << "read_thread:" << *i << " start" << std::endl;
    for(int j = 0; j < count; j++)
    {
        usleep(10000);
        wr_lock.read();
    }
    //std::cout << "read_thread:" << *i << " stop" << std::endl;
}


void *write_thread(void *p)
{
    int *i = (int*)p;
    //std::cout << "write_thread:" << *i <<" start" <<std::endl;
    for(int j = 0; j < count; j++)
    {
        usleep(10000);
        wr_lock.write();
    }
    //std::cout << "write_thread:" << *i << " stop" << std::endl;  
}

const static int read_thread_n = 5;
const static int write_thread_n = 2;
int main(void)
{
    pthread_t tid1[read_thread_n];
    pthread_t tid2[write_thread_n];
    for(int i = 0; i < write_thread_n; i++)
        pthread_create(&tid2[i], NULL, write_thread, (void *) &i);
    for(int i = 0; i < read_thread_n; i++)
        pthread_create(&tid1[i], NULL, read_thread, (void *) &i);

    for(int i = 0; i < read_thread_n; i++)
        pthread_join(tid1[i], NULL);

    for(int i = 0; i < write_thread_n; i++)
        pthread_join(tid2[i], NULL);

    return 0;
}