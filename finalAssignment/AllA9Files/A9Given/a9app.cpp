// File: a9app.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: This application does the following:
//   1. reads a line from the file named message.txt
//   2. encodes the line using a Huffman Tree Code
//   3. writes the resulting coded message to a file names coded-message.txt
//   4. decodes the coded message using the Huffman Tree Code 
//   5. displays the decoded message to the console.


#include <iostream>
#include <fstream>
#include <cstring>
#include "copy.h"
#include "Huffman.h"
#include "FrequencyList.h"
#include "LOCALE.h"

using namespace std;

// Algorithm read_from_file(fname)
//  attempt to open and read the first line from the file 'fname'
//  Pre: fname:: refToChar, a filename
//  Return: a reference to a cstring containing the first line 
//          of the file 'fname'
//          or the first MESSAGE_LIMIT characters, whichever is shorter.
char *read_from_file(char *fname, int size){

  ifstream fin;
  char *temp = new char[size];
  char *result = NULL;

  fin.open(fname, ios::in);

  if (fin.is_open()){
    fin.getline(temp,size);
    cout << "Read the text: " << temp << endl;
    result = copy(temp);

    fin.close();
  } 
  else {
    cerr << "Error in read_from_file(): could not read from file.  "
    	 << "Is there a file named " << fname 
         << " in the folder with this app?" 
	 << endl;
  }

  delete [] temp;

  return result;
}



// Algorithm write_to_file(fname)
//  attempt to open the file 'fname', and write 'msg' to the file
//  Pre: fname:: refToChar, a filename
//       msg:: refToChar, message to write to file
//  Return: true if successful, false otherwise.
bool write_to_file(char *fname, char* msg){
  ofstream fout;

  fout.open(fname, ios::out);

  if (fout.is_open()){
    fout << msg;
    fout.close();
    return true;
  } 
  else {
    cerr << "Error in write_to_file(): could not write to file" << endl;
    return false;
  }
}


int main(){
  // read one line of text from a file (you can hardcode the filename)
  char input_fname[] ="message.txt";
  cout << "Reading message from file: "<< input_fname <<endl;
  char *message = read_from_file(input_fname, MESSAGE_LIMIT);

  // create the HUffman codec
  FrequencyList *freqList = createFrequencyList(message);
  HuffmanTree   *htree    = createHuffmanTree(freqList);
  HuffmanCodec  *codec    = createHuffmanCodec(htree);

  // Encode the line of text using the Huffman Codec
  cout << "Encoding message"<<endl;
  char *coded_msg = encode(codec,message);
  delete [] message;

  // Write the coded text to a file 
  char output_fname[] = "coded-message.txt";
  cout << "Writing coded message to file: " << output_fname << endl;
  write_to_file(output_fname, coded_msg);
  delete [] coded_msg;

  // Use the Huffman ADT to decode the coded message, and display it
  // to the console.
  cout << "Decoding message read from file" << endl;
  char *result = decode(codec, read_from_file(output_fname, 2*MESSAGE_LIMIT));
  cout << "Decoded message: " << endl << result << endl;
  delete [] result;
  destroyHuffmanCodec(codec);
  
  return 0;
}
