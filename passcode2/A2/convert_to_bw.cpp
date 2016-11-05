void convert_to_bw(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]){
	for (int x = 0; x < IMAGE_HEIGHT; ++x){
		for (int y = 0; y < IMAGE_WIDTH; ++y){
			// // temporarily change to invert image
			// result[x][y] = PURE_WHITE - source[x][y];
			if (source[x][y] < (PURE_WHITE)) result[x][y] = PURE_BLACK;
			else result[x][y] = PURE_WHITE;
		}
	}
}