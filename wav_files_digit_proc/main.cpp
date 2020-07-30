#include <iostream> 
#include <fstream>

struct Header
{
	char p1[4];
	unsigned long chunkSize;
	char format[4];
	char subchunk1Id[4];
	unsigned long subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2Id[4];
	unsigned long subchunk2Size;
};

int main( int argc, char ** argv )
{
	char buf[44] = {}; // массив-буфер для считывания
	std::ifstream f("fspeech.wav", std::ios::binary);
	if (f.is_open()) std::cout << "file is opened"<< '\n'; // файл открыт, он открывается

	Header h;
	std::cout << sizeof(h);

	
	//f.read( (char*) buf, sizeof(buf));
	f.read( (char*) &h, sizeof(h) );


	

	

	return 0;
}

