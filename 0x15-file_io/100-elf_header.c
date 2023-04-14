#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

/**
* print_osabi - prints the operating system/ABI used by the ELF file
*
* @e_ident: the ELF identification bytes
*/
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_AIX:
printf("UNIX - AIX\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_MODESTO:
printf("Novell - Modesto\n");
break;
case ELFOSABI_OPENBSD:
printf("UNIX - OpenBSD\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
* main - entry point
*
* @argc: argument count
* @argv: argument vector
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
int fd, i;
Elf64_Ehdr header;
ssize_t bytes_read;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
exit(1);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("open");
exit(1);
}

bytes_read = read(fd, &header, sizeof(header));
if (bytes_read == -1)
{
perror("read");
exit(1);
}

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");

printf("  Class:                             ");
switch (header.e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
break;
}

printf("  Data:                              ");
switch (header.e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
break;
}

printf("  Version:                           %d", header.e_ident[EI_VERSION]);
switch (header.e_ident[EI_VERSION])
{
case EV_NONE:
printf(" (invalid)\n");
break;
case EV_CURRENT:
printf("\n");
break;
default:
printf(" <unknown>\n");
break;
}

printf("  OS/ABI:                            ");
print_osabi(header.e_ident);

printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

printf("  Type:                              ");
switch (header.e_type)
{
case ET_NONE:
printf("NONE (Unknown type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", header.e_type);
break;
}

printf("  Entry point address:               %lx\n", (unsigned long)header.e_entry);

printf("  Start of program headers:          %lu (bytes into file)\n", (unsigned long)header.e_phoff);

printf("  Start of section headers:          %lu (bytes into file)\n", (unsigned long)header.e_shoff);

printf("  Flags:                             0x%x\n", header.e_flags);

printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);

printf("  Size of program headers:           %d (bytes)\n", header.e_phentsize);

printf("  Number of program headers:         %d\n", header.e_phnum);

printf("  Size of section headers:           %d (bytes)\n", header.e_shentsize);

printf("  Number of section headers:         %d\n", header.e_shnum);

printf("  Section header string table index: %d\n", header.e_shstrndx);

if (close(fd) == -1)
{
perror("close");
exit(1);
}

return (0);
}
