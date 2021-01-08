#include <chiaki/pidecoder.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "H264_Decoder.h"

int main (int argc, char **argv)
{
	std::string filename(argv[1]);
	
	//im not actually using the callback and its not set up properly.
	h264_decoder_callback frameCallback;
	H264_Decoder* stream_decoder = new H264_Decoder(frameCallback, stream_decoder);
	
	
	stream_decoder->load(filename, 60.0f);
	
	while(1)
	{	
		usleep(10000);
		stream_decoder->readFrame();
	}
	
	printf("Woof\n");
}
