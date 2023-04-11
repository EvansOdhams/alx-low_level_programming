#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

void error_exit(char *msg);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);

/**
* error_exit - prints an error message and exits with status code 98
* @msg: the error message
*/
void error_exit(char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
* print_magic - prints the magic number of the ELF header
* @e_ident: the ELF header identification array
*/
void print_magic(unsigned char *e_ident)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", e_ident[i]);
printf("\n");
}

/**
* print_class - prints the class of the ELF file
* @e_ident: the ELF header identification array
*/
void print_class(unsigned char *e_ident)
{
const char *class_str;
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
class_str = "none";
break;
case ELFCLASS32:
class_str = "ELF32";
break;
case ELFCLASS64:
class_str = "ELF64";
break;
default:
class_str = "<unknown>";
break;
}
printf("  Class:                             %s\n", class_str);
}

/**
* print_data - prints the data encoding of the ELF file
* @e_ident: the ELF header identification array
*/
void print_data(unsigned char *e_ident)
{
const char *data_str;
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
data_str = "none";
break;
case ELFDATA2LSB:
data_str = "2's complement, little endian";
break;
case ELFDATA2MSB:
data_str = "2's complement, big endian";
break;
default:
data_str = "<unknown>";
break;
}
printf("  Data:                              %s\n", data_str);
}

/**
* print_version - prints the version of the ELF file
* @e_ident: the ELF header identification array
*/
void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d (current)\n",
e_ident[EI_VERSION]);
}

/**
* print_osabi - prints the operating system and ABI of the ELF file
* @e_ident: the ELF header identification array
*/
void print_osabi(unsigned char *e_ident)
{
const char *osabi_str;
switch (e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
osabi_str = "UNIX - System V";
break;
case ELFOSABI_HPUX:
osabi_str = "UNIX - HP-UX";
break;
case ELFOSABI_NETBSD:
osabi_str = "UNIX - NetBSD";
break;
case ELFOSABI_LINUX:
osabi_str = "UNIX - Linux";
break;
case ELFOSABI_SOLARIS:
osabi_str = "UNIX - Solaris";
break;
case ELFOSABI_IRIX:
osabi_str = "UNIX - IRIX";
break;
case ELFOSABI_FREEBSD:
osabi_str = "UNIX - FreeBSD";
break;
case ELFOSABI_TRU64:
osabi_str = "UNIX - TRU64";
break;
case ELFOSABI_ARM:
osabi_str = "ARM";
break;
case ELFOSABI_STANDALONE:
osabi_str = "Standalone App";
break;
default:
osabi_str = "<unknown>";
break;
}
printf("  OS/ABI:                            %s\n", osabi_str);
}

