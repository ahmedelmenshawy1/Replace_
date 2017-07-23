MainFile = main.c
ReplaceDriver = Replace/Replace_prog.c

all:$(MainFile)
	gcc -E $(MainFile) $(ReplaceDriver) -o output.i
	gcc -S $(MainFile) $(ReplaceDriver) -o output.asm
	gcc -C $(MainFile) $(ReplaceDriver) -o output.obj
	gcc -O $(MainFile) $(ReplaceDriver) -o output.exe
	
preprocessor: $(MainFile)
	gcc -E $(MainFile) $(ReplaceDriver) -o output.i

Compile:$(MainFile)
	gcc -S $(MainFile) $(ReplaceDriver) -o output.asm

link:
	gcc -C $(MainFile) $(ReplaceDriver) -o output.obj

Output:
	gcc -O $(MainFile) $(ReplaceDriver) -o output.exe

clean:
	rm output.i output.asm output.obj output.exe
	
