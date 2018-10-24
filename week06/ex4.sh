echo Input pid: 
read pid
kill -SIGUSR1 $(($pid))
sleep 2
kill -SIGSTOP $(($pid))
sleep 2
kill -SIGKILL $(($pid))
