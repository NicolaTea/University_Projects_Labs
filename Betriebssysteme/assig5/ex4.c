#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int numar_blocuri(const char* filename){
	int fd;
	off_t file_size;
	int block_size=1024;
	int num_blocks;
	fd=open(filename,O_RDONLY);
	if(fd==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	file_size=lseek(fd,0,SEEK_END);
	if(file_size==-1){
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	num_blocks=file_size/block_size;
	close(fd);
	return num_blocks;
	
}

int numar_blocuri_identice(const char* filename1,const char* filename2){
	int fd1,fd2;
	off_t file1_size,file2_size;
	int block_size=1024;
	int num_blocks1,num_blocks2;
	int blocuri_identice=0;
	num_blocks1=numar_blocuri(filename1);
	num_blocks2=numar_blocuri(filename2);
	fd1=open(filename1,O_RDONLY);
	if(fd1==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	fd2=open(filename2,O_RDONLY);
	if(fd2==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<num_blocks1 &&i<num_blocks2;i++){
		char buf1[block_size],buf2[block_size];
		ssize_t bytes_read_1=read(fd1,buf1,block_size);
		ssize_t bytes_read_2=read(fd2,buf2,block_size);
		if(bytes_read_1==-1 || bytes_read_2==-1){
			perror("read");
			exit(EXIT_FAILURE);
		}
		if(bytes_read_1==bytes_read_2){
			int ok=1;
			for(int j=0;j<bytes_read_1 && ok==1;j++){
				if(buf1[j]!=buf2[j]){
					ok=0;
				}
			}
			if(ok==1){
				blocuri_identice++;
			}
		}
		
	}
	close(fd1);
	close(fd2);
	return blocuri_identice;
	
}

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("Wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	int blocuri_fisier_1=numar_blocuri(argv[1]);
	printf("Numarul de blocuri pentru %s: %d\n",argv[1],blocuri_fisier_1);
	int blocuri_fisier_2=numar_blocuri(argv[2]);
	printf("Numarul de blocuri pentru %s: %d\n",argv[2],blocuri_fisier_2);
	int blocuri_identice=numar_blocuri_identice(argv[1],argv[2]);
	printf("Numarul de blocuri identice: %d\n",blocuri_identice);
	return EXIT_SUCCESS;
	
}