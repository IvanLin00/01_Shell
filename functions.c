void ls(char *directory_name){
	DIR *stream = opendir(directory);
	if(stream == NULL){
		printf("Error Number: %d %s\n", errno, strerror(errno));
		return 0;
	}
	struct dirent *directory = readdir(stream);
	if(directory == NULL){
		printf("Error Number: %d %s\n", errno, strerror(errno));
		return 0;
	}
	int total_size = 0;
	while(directory != NULL){
		printf("%s ", directory->d_name);
	}
}

void echo(char *prompt){
  printf("%s\n", prompt);
}
