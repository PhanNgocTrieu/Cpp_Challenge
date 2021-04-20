//Last night you partied a little too hard.
//Now there's a black and white photo of you that's about to go viral!You can't let this ruin your reputation, 
//so you want to apply the box blur algorithm to the photo to hide its content.
//
//The pixels in the input image are represented as integers.
//The algorithm distorts the input image in the following way : 
//Every pixel x in the output image has a value equal to the average value of the pixel values from the 3 × 3 square
//that has its center at x, including x itself.All the pixels on the border of x are then removed.
//
//Return the blurred image as an integer, with the fractions rounded down.
//
//Example
//
//For
//image = [[1, 1, 1],
//[1, 7, 1],
//[1, 1, 1]]
//the output should be boxBlur(image) = [[1]] .
//
//To get the value of the middle pixel in the input 3 × 3 square: (1 + 1 + 1 + 1 + 7 + 1 + 1 + 1 + 1) = 15 / 9 = 1.66666 = 1. The border pixels are cropped from the final result.
//
//For
//
//image = [[7, 4, 0, 1],
//[5, 6, 2, 2],
//[6, 10, 7, 8],
//[1, 4, 2, 0]]
//the output should be
//
//boxBlur(image) = [[5, 4],
//[4, 4]]
//There are four 3 × 3 squares in the input image, so there should be four integers in the blurred output.
//To get the first value : (7 + 4 + 0 + 5 + 6 + 2 + 6 + 10 + 7) = 47 / 9 = 5.2222 = 5.
//The other three integers are obtained the same way, 
//then the surrounding integers are cropped from the final result.

#include <iostream>
#include <vector>


std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) {
	int max_rows = image.size() - 2;
	int rows = 0;
	int max_cols = image[0].size() - 2;
	std::vector<std::vector<int>> image_output;
	while (rows < max_rows)
	{
		int cols = 0;
		int rows_max = rows + 3;
		std::vector<int> temp;
		while (cols < max_cols)
		{
			int sum = 0;
			int cols_max = cols + 3;
			int accomulation = 0;
			for (int i = rows; i < rows_max; i++)
			{
				for (int j = cols; j < cols_max; j++)
				{
					accomulation += image[i][j];
				}
			}
			sum = accomulation / 9;
			temp.push_back(sum);
			cols++;
		}
		image_output.push_back(temp);
		rows++;
	}
	return image_output;
}



int main()
{
	/*std::vector<std::vector<int>> image = {
		{ 0,18,9 },
		{ 27,9,0 },
		{ 81,63,45 }
	};*/

	/*std::vector<std::vector<int>> image_2 = {
		{36,0,18,9},
		{27,54,9,0},
		{81,63,72,45}
	};*/

	std::vector<std::vector<int>> image_3 = {
		{ 7,4,0,1 },
		{5,6,2,2},
		{6,10,7,8 },
		{1,4,2,0}
	};

	/*std::cout << image_3.size() << std::endl;
	std::cout << image_3[0].size() << std::endl;*/
	
	std::vector<std::vector<int>> temp = boxBlur(image_3);
	for (int i = 0; i < temp.size(); i++)
	{
		for (int jj = 0; jj < temp[i].size(); jj++)
		{
			std::cout << temp[i][jj] << " ";
		}
		std::cout << std::endl;
	}

	//std::cout << row << std::endl;
	//boxBlur(image);
	return 0;
}
