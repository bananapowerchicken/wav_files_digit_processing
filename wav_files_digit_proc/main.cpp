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
	
	std::ifstream f("fspeech.wav", std::ios::binary);
	if (f.is_open()) std::cout << "file is opened"<< '\n'; // файл открыт, он открывается

	Header h;
	/*std::cout << sizeof(h);*/

	
	//f.read( (char*) buf, sizeof(buf));
	f.read( (char*) &h, sizeof(h) );
	
	short * data_buf = new short[h.subchunk2Size>>1]; //  динамический массив-буфер для считывания информации о файле
	f.read( (char*) data_buf, h.subchunk2Size);
	std::cout << *(data_buf + 2) << '\n';

	short* data_buf_out = new short[h.subchunk2Size];
	for (int i = 0; i < sizeof(data_buf_out); i++)
	{

	}



	delete data_buf; // 

	
	system("pause");
	return 0;

	
}

