#set the following created file permission to 000;
umask 0777
echo "a umask test">test_umask.txt

#reset umask to default
umask 0002

