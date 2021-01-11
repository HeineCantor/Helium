C_SOURCES = $(wildcard include/*.cpp kernel/*.cpp idt/*.cpp task/*.cpp)
HEADERS = $(wildcard include/*.h kernel/*.h idt/*.h task/*.h)

OBJ = ${C_SOURCES:.cpp=.o kernel/kernel_main.o kernel/kernel_loader.o}

CC = $HOME/opt/cross/bin/i686-elf-g++

# Obiettivo di default
all: helium-os

# Emulazione da parte di QEMU
run: clean all
	qemu-system-i386 -drive format=raw,file=helium-os

# Immagine del sistema operativo
helium-os: boot/boot.bin kernel.bin
	cat $^ > $@
	#si sposta a 32kB-1 e scrive uno 0, portando la dimensione del file a esattamente 32kB
	dd if=/dev/zero bs=1 count=1 seek=32767 of=helium-os

# Kernel binary
kernel.bin: kernel/kernel_main.o ${OBJ} idt/irq_hand_asm.o task/task_asm.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Kernel core
%.o: %.cpp ${HEADERS}
	i686-elf-g++ -ffreestanding -c $< -o $@

# ASM -> ELF OBJECT
%.o: %.asm
	nasm -f elf $< -o $@

# ASM -> BIN
%.bin: %.asm
	nasm $< -f bin -o $@

# Pulisce tutti i file tranne i sorgenti
clean:
	rm -fr *.bin *.o
	rm -rf kernel/*.o boot/*.bin include/*.o boot/*.o idt/*.o
