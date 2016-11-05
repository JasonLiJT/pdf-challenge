void average(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]){
	int cmask[3][3] = {
		1, 1, 1,
		1, 1, 1,
		1, 1, 1
	};
	for (int x = 1; x < IMAGE_HEIGHT-1; ++x){
		for (int y = 1; y < IMAGE_WIDTH-1; ++y){
			int sum = 0;
			int white = 0, black = 0;
			for (int i = x-1; i <= x+1; ++i){
				for (int j = y-1; j <= y+1; ++j){
					// original: average
					// sum += source[i][j];

					// Composite Laplacian Mask
					sum += source[i][j] * cmask[i-x+1][j-y+1];

					// Non-linear mask for highest frequency
					// if (source[i][j] < PURE_WHITE / 2) black++;
					// else white++;
				}
			}
			// Original: average
			// result[x][y] = clip(sum/9);

			// mirror
			result[x][y] = clip(0.5*(source[x][y] + source[IMAGE_HEIGHT-1-x][y]));

			// Non-linear mask for highest frequency
			// if (white >= black) result[x][y] = PURE_WHITE;
			// else result[x][y] = PURE_BLACK;
		}
	}
}