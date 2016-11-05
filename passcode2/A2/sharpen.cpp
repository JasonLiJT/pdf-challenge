void sharpen(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH], int amount){
	int blurred[IMAGE_HEIGHT][IMAGE_WIDTH]={};
	blur(source,blurred);
	for (int x = 0; x < IMAGE_HEIGHT; ++x){
		for (int y = 0; y < IMAGE_WIDTH; ++y){
			result[x][y]=clip(source[x][y]+(source[x][y]-blurred[x][y])*amount/100);
		}
	}
}