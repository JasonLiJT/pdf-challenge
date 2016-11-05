#include <iostream>
using namespace std;

const int HEADER_SIZE = 1078;
// const int IMAGE_HEIGHT = 250;
// const int IMAGE_WIDTH = 200;
const int AVG_REGION_DIM = 3;
const int PURE_BLACK = 0;
const int PURE_WHITE = 255;
const int IMAGE_HEIGHT = 5;
const int IMAGE_WIDTH = 6;

#include "clip.cpp"
#include "adjust_brightness.cpp"
#include "convert_to_bw.cpp"
#include "copy_border.cpp"
#include "average.cpp"
#include "blur.cpp"
#include "sharpen.cpp"

void cout2DArray(int a[][IMAGE_WIDTH]){
	cout << endl;
	for (int i = 0; i < IMAGE_HEIGHT; ++i)
	{
		for (int j = 0; j < IMAGE_WIDTH; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int source[IMAGE_HEIGHT][IMAGE_WIDTH] =
	{
	{94, 94, 94, 160, 160, 160},
	{94, 94, 94, 160, 160, 160},
	{94, 94, 94, 160, 160, 160},
	{94, 94, 94, 160, 160, 160},
	{94, 94, 94, 160, 160, 160}
	};
	int result[IMAGE_HEIGHT][IMAGE_WIDTH] = {};
	int amount = 200;
	sharpen(source, result, amount);
	cout2DArray(result);
}