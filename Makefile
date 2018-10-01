# Obiettivo di default
all: helium-os

# Emulazione da parte di QEMU
run: clean all
	qemu-system-i386 -drive format=raw,file=helium-os

# Immagine del sistema operativo
helium-os: boot.bin kernel.bin
	cat $^ > $@

# Kernel binary
kernel.bin: kernel_main.o kernel.o vga_graphics.o io_iasm.o str_util.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Kernel core
%.o: %.cpp
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
