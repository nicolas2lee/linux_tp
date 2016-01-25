#include<stdio.h>
#include<string.h>
#include<error.h>
#include<fcntl.h>
#define BUF_SIZE 8192

void encryptDecrypt(char *input, char *output) {
 char key[] = {'K', 'C', 'Q'}; //Can be any chars, and any size array
 
 int i;
 for(i = 0; i < strlen(input); i++) {
   output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
 }
}

int main(){
  int input_fd;
  int input2_fd;
  int encrypt_fd;
  int decrypt_fd ;
  ssize_t ret_in, ret_out, ret_recover;
  char buffer[BUF_SIZE];
  char buffer2[BUF_SIZE];
	char out_buffer[BUF_SIZE];
	char origin_buffer[BUF_SIZE];
//here is the path of the file in your usb
//   /media/u/KINGSTON
  input_fd=open("/mnt/toCrypt.txt",O_RDONLY);
  //input_fd=open("/media/u/KINGSTON/toCrypt.txt",O_RDONLY);	
  if (input_fd==-1){
    perror("open");
  }

 input2_fd=open("/mnt/toDecrypt.txt",O_RDONLY);
  if (input2_fd==-1){
    perror("open");
  }

  /* Create output file descriptor */
  encrypt_fd = open("/mnt/crypted.txt", O_WRONLY | O_CREAT, 0644);
  if(encrypt_fd == -1){
      perror("open");
  
  }

  decrypt_fd = open("/mnt/decrypted.txt", O_WRONLY | O_CREAT, 0644);
  if(decrypt_fd == -1){
      perror("open");
      
  }
 
  /* Copy process */
  while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0){
		encryptDecrypt(&buffer,&out_buffer);
    ret_out = write (encrypt_fd, &out_buffer, (ssize_t) ret_in);
    if(ret_out != ret_in){
			perror("write");
      return -3;
    }

  }

  while((ret_in = read (input2_fd, &buffer2, BUF_SIZE)) > 0){
		encryptDecrypt(&buffer2,&out_buffer);
    ret_out = write (decrypt_fd, &out_buffer, (ssize_t) ret_in);
    if(ret_out != ret_in){
			perror("write");
      return -3;
    }

  }

 
    /* Close file descriptors */
  close (input_fd);
  close (encrypt_fd);
	close (input2_fd);
	close (decrypt_fd);
  return 0;
}
