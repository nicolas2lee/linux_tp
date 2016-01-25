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
  int output_fd;
	int recover_fd;
  ssize_t ret_in, ret_out, ret_recover;
  char buffer[BUF_SIZE];
	char out_buffer[BUF_SIZE];
	char origin_buffer[BUF_SIZE];
//here is the path of the file in your usb
  input_fd=open("/mnt/toCrypt.txt",O_RDONLY);
  if (input_fd==-1){
    perror("open");
    return -1;
  }
  /* Create output file descriptor */
  output_fd = open("/mnt/output.txt", O_WRONLY | O_CREAT, 0644);
  if(output_fd == -1){
      perror("open");
      return -2;
  }

  recover_fd = open("recover.txt", O_WRONLY | O_CREAT, 0644);
  if(recover_fd == -1){
      perror("open");
      return -3;
  }
 
  /* Copy process */
  while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0){
		encryptDecrypt(&buffer,&out_buffer);
    ret_out = write (output_fd, &out_buffer, (ssize_t) ret_in);
    if(ret_out != ret_in){
			perror("write");
      return -3;
    }
		encryptDecrypt(&out_buffer,&origin_buffer);
    ret_recover = write (recover_fd, &origin_buffer, (ssize_t) ret_out);
    if(ret_out != ret_recover){
			perror("write");
      return -3;
    }
  }
 
    /* Close file descriptors */
  close (input_fd);
  close (output_fd);
	close (recover_fd);
  return 0;
}
