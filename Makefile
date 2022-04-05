# indicate how the object files are to be created
CC         := icc 
#CFLAGS     := -g -O3 -axCORE-AVX2  -qopenmp
CFLAGS     := -g -O3 -axCORE-AVX2

OBJECT_FILES := saxpy.o driver.o helper.o
saxpy: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o saxpy

saxpy.o : saxpy.c
	$(CC) $(CFLAGS) -c saxpy.c

driver.o : driver.c
	$(CC) $(CFLAGS) -c driver.c

helper.o : helper.c
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm *.o 
