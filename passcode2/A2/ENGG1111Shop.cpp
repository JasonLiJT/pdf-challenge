// ENGG1111   2015-2016
// ENGG1111Shop.cpp
//
// Partial implementation of an image enhancement program
// for Assignment 2
//
// Write your function definitions after the main() function
//
// Note:
// Place the images in the same directory as this file (under windows) 
// and in the users home directory, e.g. /Users/<username>, (under Mac). 
// When promoted for file name type e.g., kitten

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

const int HEADER_SIZE = 1078;
const int IMAGE_HEIGHT = 528;
const int IMAGE_WIDTH = 1240;
const int AVG_REGION_DIM = 3;
const int PURE_BLACK = 0;
const int PURE_WHITE = 255;

// Functions already provided for you
char get_selection();
void open_image(int header[], int image[][IMAGE_WIDTH]);
void save_image(int header[], int image[][IMAGE_WIDTH]);

// Functions you must implement
int clip(int value);
void adjust_brightness(int source[][IMAGE_WIDTH],
                       int result[][IMAGE_WIDTH],
                       int adjustment);
void convert_to_bw(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]);
void blur(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]);
void copy_border(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]);
void average(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH]);
void sharpen(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH], int amount);


int main()
{
   int header[HEADER_SIZE] = {};
   int source[IMAGE_HEIGHT][IMAGE_WIDTH] = {};
   int result[IMAGE_HEIGHT][IMAGE_WIDTH] = {};

   open_image(header, source);

   char selection = get_selection();
   switch(selection)
   {
      case '1':
      {
         int adjustment;
         cout << "\n\tEnter the required adjustment\n"
              << "\t\t-ve number will darken,\n"
              << "\t\t+ve number will lighten\n"
              << "\t\t: ";
         cin >> adjustment;
         adjust_brightness(source, result, adjustment);
         break;
      }

      case '2':
         convert_to_bw(source, result);
         break;

      case '3':
         blur(source, result);
         break;

      case '4':
      {
         int amount;
         cout << "\n\tEnter the amount(%) of sharpening (0 to 500)\n"
              << "\t: ";
         cin >> amount;
         sharpen(source, result, amount);
         break;
      }

      default:
         cout << "\nOK.  Bye for now." << endl;
         return 0;
   }

   save_image(header, result);

   return 0;
 }

//********* DO NOT CHANGE ANYTHING ABOVE THIS COMMENT  ***********************
//----------------------------------------------------------------------------
// Write your function definitions here

#include "clip.cpp"
#include "adjust_brightness.cpp"
#include "convert_to_bw.cpp"
#include "copy_border.cpp"
#include "average.cpp"
#include "blur.cpp"
#include "sharpen.cpp"

//----------------------------------------------------------------------------
//******* DO NOT CHANGE ANYTHING BELOW THIS COMMENT BLOCK ********************
// These functions are called either directly or indirectly from main().
// You do not need to study or understand them.
// You do not need to call any of them from your function definitions.
//----------------------------------------------------------------------------

// Utility function declarations

void open_infile(ifstream& infile);
void open_outfile(ofstream& outfile);

string get_filename();

void read_header_to_ints(int header[], ifstream& infile);
void write_header_from_ints(int header[], ofstream& outfile);

void read_image_to_ints(int image[][IMAGE_WIDTH], ifstream& infile);
void write_image_from_ints(int image[][IMAGE_WIDTH], ofstream& outfile);

void read_data_block(uint8_t block[], int size, ifstream& infile);
void write_data_block(uint8_t block[], int size, ofstream& outfile);

// Definitions of functions called directly from main()
char get_selection()
{
   char selection = 0;
   bool is_valid = false;

   while (!is_valid)
   {
      cout << "\nSelect an action by number:\n"
           << "\t1 to brighten or darken the image\n"
           << "\t2 to convert the image to pure monochome (black and white)\n"
           << "\t3 to blur the image\n"
           << "\t4 to sharpen the image\n"
           << "\t5 to quit without an action\n\n"
           << "Please enter your selection: ";

      cin >> selection;
      if (selection < '1' || selection > '5')
      {
         cout << "\nInvalid selection. Please select again:" << endl;
      }
      else
      {
         is_valid = true;
      }
   }
   return selection;
}

void open_image(int header[], int image[][IMAGE_WIDTH])
{
   ifstream infile;
   open_infile(infile);
   read_header_to_ints(header, infile);
   read_image_to_ints(image, infile);
   infile.close();
}

void save_image(int header[], int image[][IMAGE_WIDTH])
{
   ofstream outfile;
   open_outfile(outfile);
   write_header_from_ints(header, outfile);
   write_image_from_ints(image, outfile);
   outfile.close();
}

// Definitions of utility functions
string get_filename()
{
   string filename;
   cin >> filename;
   return filename + ".bmp";
}

void open_infile(ifstream& infile)
 {
   cout << "Source image filename: ";
   string source_filename = get_filename();
   infile.open(source_filename.c_str(), ios::binary);
   if (!infile.is_open())
   {
      cout << "Failed to open source image." << endl;
      exit(EXIT_FAILURE);
   }
 }

void open_outfile(ofstream& outfile)
 {
   cout << "\nSave enhanced image as: ";
   string destination_filename = get_filename();
   outfile.open(destination_filename.c_str(), ios::binary);
   if (!outfile.is_open())
   {
      cout << "Failed to open output file." << endl;
      exit(EXIT_FAILURE);
   }
 }

void read_data_block(uint8_t block[], int size, ifstream& infile)
{
   infile.read(reinterpret_cast<char*>(block), size);
}

// to avoid exposing uint8_t type
void read_header_to_ints(int header[], ifstream& infile)
{
   uint8_t header_values[HEADER_SIZE];
   read_data_block(header_values, HEADER_SIZE, infile);
   for (int i = 0; i < HEADER_SIZE; ++i)
   {
      header[i] = header_values[i];
   }
}

// to avoid exposing uint8_t type
void read_image_to_ints(int image[][IMAGE_WIDTH], ifstream& infile)
{
   uint8_t row_values[IMAGE_WIDTH];
   for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
   {
      read_data_block(row_values, IMAGE_WIDTH, infile);
      for (int j = 0; j < IMAGE_WIDTH; ++j)
      {
         image[i][j] = row_values[j];
      }
   }
}

void write_data_block(uint8_t block[], int size, ofstream& outfile)
{
   outfile.write(reinterpret_cast<char*>(block), size);
}

// to avoid exposing uint8_t type
void write_header_from_ints(int header[], ofstream& outfile)
{
   uint8_t header_values[HEADER_SIZE];
   for (int i = 0; i < HEADER_SIZE; ++i)
   {
      header_values[i] = header[i];
   }
   write_data_block(header_values, HEADER_SIZE, outfile);
}

// to avoid exposing uint8_t type
void write_image_from_ints(int image[][IMAGE_WIDTH], ofstream& outfile)
{
   uint8_t row_values[IMAGE_WIDTH];
   for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
   {
      for (int j = 0; j < IMAGE_WIDTH; ++j)
      {
         row_values[j] = image[i][j];
      }
      write_data_block(row_values, IMAGE_WIDTH, outfile);
   }
}

