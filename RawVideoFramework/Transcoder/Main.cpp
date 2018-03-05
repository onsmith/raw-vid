#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <fstream>
using std::ios;
using std::ifstream;
using std::ofstream;

#include "ExternalLibrary/argparser.h"



/*
** Enumerate accepted raw frame formats.
*/
enum class RAW_FRAME_FORMAT {
  YUV444P,
  YUV422P,
  YUV420P,
  YUV400P,
  RGB444P,
  UNKNOWN,
};


/*
** Enumerate accepted pixel data types.
*/
enum class PIXEL_DATA_TYPE {
  INT8,
  INT10,
  INT16,
  FLOAT,
  DOUBLE,
  UNKNOWN,
};


/*
** Lookup function for raw frame formats.
*/
RAW_FRAME_FORMAT storff(const string frame_format) {
  if (frame_format == "yuv444p") {
    return RAW_FRAME_FORMAT::YUV444P;
  } else if (frame_format == "yuv422p") {
    return RAW_FRAME_FORMAT::YUV422P;
  } else if (frame_format == "yuv420p") {
    return RAW_FRAME_FORMAT::YUV420P;
  } else if (frame_format == "yuv400p") {
    return RAW_FRAME_FORMAT::YUV400P;
  } else if (frame_format == "rgb444p") {
    return RAW_FRAME_FORMAT::RGB444P;
  } else {
    return RAW_FRAME_FORMAT::UNKNOWN;
  }
}


/*
** Lookup function for pixel data types.
*/
PIXEL_DATA_TYPE stopdt(const string data_type) {
  if (data_type == "int8") {
    return PIXEL_DATA_TYPE::INT8;
  } else if (data_type == "int10") {
    return PIXEL_DATA_TYPE::INT10;
  } else if (data_type == "int16") {
    return PIXEL_DATA_TYPE::INT16;
  } else if (data_type == "float") {
    return PIXEL_DATA_TYPE::FLOAT;
  } else if (data_type == "double") {
    return PIXEL_DATA_TYPE::DOUBLE;
  } else {
    return PIXEL_DATA_TYPE::UNKNOWN;
  }
}



/*
** Main entry point for the command line application.
*/
int main(int argc, char* argv[]) {
  // Specify valid command line arguments and program usage
  ap::parser p(argc, argv);
  p.add("-i", "--input",            "Input raw video file name",             ap::mode::REQUIRED);
  p.add("-o", "--output",           "Output raw video file name",            ap::mode::REQUIRED);
  p.add("-f", "--input_format",     "Input raw video data format",           ap::mode::REQUIRED);
  p.add("-c", "--output_format",    "Output raw video data format",          ap::mode::REQUIRED);
  p.add("-l", "--height",           "Height of each video frame",            ap::mode::REQUIRED);
  p.add("-w", "--width",            "Width of each video frame",             ap::mode::REQUIRED);
  p.add("-d", "--input_data_type",  "Input pixel data type (default int8)",  ap::mode::OPTIONAL);
  p.add("-s", "--output_data_type", "Output pixel data type (default int8)", ap::mode::OPTIONAL);

  // Parse command line arguments
  auto args = p.parse();

  // Ensure command line arguments parsed successfully
  if (!args.parsed_successfully()) {
    p.print_usage();
    getchar();
    return 1;
  }

  // Copy data from command line arguments
  ifstream         input_file       = ifstream(args["--input"], ios::in | ios::binary);
  ofstream         output_file      = ofstream(args["--output"], ios::out | ios::binary | ios::trunc);
  RAW_FRAME_FORMAT input_format     = storff(args["--input_format"]);
  RAW_FRAME_FORMAT output_format    = storff(args["--output_format"]);
  int              frame_height     = stoi(args["--height"]);
  int              frame_width      = stoi(args["--width"]);
  PIXEL_DATA_TYPE  input_data_type  = stopdt(args["--input_data_type"].empty()  ? "int8" : args["-d"]);
  PIXEL_DATA_TYPE  output_data_type = stopdt(args["--output_data_type"].empty() ? "int8" : args["-s"]);

  // All done
  getchar();
  return 0;
}
