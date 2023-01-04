
#ifndef _WIN32

    #include <service/service.POSIX.h> 

    void serviceMain(int _argument_count, char *_argument_values[])
    {

        char *_directory_binary = se_GetDirectoryBinary();

        if (_directory_binary == NULL) goto _LEAVE_SERVICE_DIRECTLY;

        if (!se_SetCurrentDirectory(_directory_binary)) goto _LEAVE_SERVICE_DIRECTLY;

        free(_directory_binary);

        if (!loadServiceName()) goto _LEAVE_SERVICE_DIRECTLY;

        pthread_attr_t _attributes_for_worker_thread;

        pthread_attr_init(&_attributes_for_worker_thread);

        if (pthread_attr_setstacksize(&_attributes_for_worker_thread, STACK_SIZE_FOR_WORKER_THREAD)) goto _LEAVE_SERVICE_DIRECTLY;
 
        pthread_t worker_thread;
        
        int result_of_creating_the_worker_thread = pthread_create(&worker_thread, &_attributes_for_worker_thread, posixServiceWorkerThreadRoutine, NULL);

        if (result_of_creating_the_worker_thread != 0) goto _LEAVE_SERVICE_DIRECTLY;



        int result;

        int policy;
        
        struct sched_param param;
        
        result = pthread_getschedparam(worker_thread, &policy, &param);
        
        if (result != 0)
        {
           
        }

        param.sched_priority = sched_get_priority_max(policy);
        
        result = pthread_setschedparam(worker_thread, policy, &param);
        
        if (result != 0)
        {

           
        
        }

        

        pthread_join(worker_thread, NULL);
    
    _LEAVE_SERVICE:

        

    _LEAVE_SERVICE_DIRECTLY:

        exit(exit_code_for_service);

    }
    
#endif
