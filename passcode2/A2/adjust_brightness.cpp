void adjust_brightness(int source[][IMAGE_WIDTH],
                       int result[][IMAGE_WIDTH],
                       int adjustment){
	for (int x = 0; x < IMAGE_HEIGHT; ++x){
		for (int y = 0; y < IMAGE_WIDTH; ++y){
			result[x][y]=clip(source[x][y]+adjustment);
		}
	}
}