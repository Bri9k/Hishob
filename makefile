hishob : hishob.c 
	 gcc hishob.c -o hishob
init :  init.c
	gcc init.c -o init
clean : 
	 rm init hishob bal.raw hishob.txt
