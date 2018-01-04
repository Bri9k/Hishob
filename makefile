hishob : hishob.c 
	 gcc hishob.c -o hishob
init :  init.c
	gcc init.c -o init
clean : 
	 rm init hishob bal.raw hishob.txt main hishob.log log.txt rr
	 
main: main.c
	gcc main.c -o main
	
rr: readnprint.c
	gcc readnprint.c -o rr
