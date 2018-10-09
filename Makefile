C_SOURCES = $(wildcard include/*.cpp kernel/*.cpp)
HEADERS = $(wildcard include/*.h kernel/*.h)

OBJ = ${C_SOURCES:.cpp=.o kernel/kernel_main.o}

CC = $HOME/opt/cross/bin/i686-elf-g++

# Obiettivo di default
all: helium-os

# Emulazione da parte di QEMU
run: clean all
	qemu-system-i386 -drive format=raw,file=helium-os

# Immagine del sistema operativo
helium-os: boot/boot.bin kernel.bin
	cat $^ > $@

# Kernel binary
kernel.bin: kernel/kernel_main.o ${OBJ}
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
	rm -rf kernel/*.o boot/*.bin include/*.o boot/*.o
