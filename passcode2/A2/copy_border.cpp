void copy_border(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]){
	for (int x = 0; x < IMAGE_HEIGHT; ++x){
		result[x][0] = source[x][0];
		result[x][IMAGE_WIDTH-1] = source[x][IMAGE_WIDTH-1];
	}
	for (int y = 0; y < IMAGE_WIDTH; ++y){
		result[0][y] = source[0][y];
		result[IMAGE_HEIGHT-1][y] = source[IMAGE_HEIGHT-1][y];
	}
}