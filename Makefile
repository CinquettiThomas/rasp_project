all : main main1

main : main.c
	gcc -o main main.c -lwiringpi

main1 : main1.c
	gcc -o main1 main1.c -lwiringpi

clean:
	rm -f main main1