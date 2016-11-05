void blur(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]){
	copy_border(source, result);
	average(source, result);
}