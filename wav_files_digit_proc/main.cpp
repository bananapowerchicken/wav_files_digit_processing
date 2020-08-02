

#include <iostream> 
#include <fstream> 

// заголовок показывает проигрывателю, как надо читать данный аудиофайл. 
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
		
	f.read( (char*) &h, sizeof(h) ); // считывание идет по адресу
	unsigned long size_of_data_buf = h.subchunk2Size >> 1;
	short * data_buf = new short[size_of_data_buf/*h.subchunk2Size >> 1*/]; //  динамический массив-буфер для считывания информации о файле
	std::cout << data_buf << '\n';

	f.read( (char*) data_buf, h.subchunk2Size);
	std::cout << h.subchunk2Size <<" " << sizeof(data_buf)<< " " << size_of_data_buf << '\n';

	short * data_buf_out = new short[h.subchunk2Size >> 1];
	for (int i = 0; i < size_of_data_buf; i++)
	{
		data_buf_out[i] = data_buf[i] / 2; // уменьшаю амплитуду в два раза
		std::cout << data_buf[i] << " -> " << data_buf_out[i] << '\n';
	}



	delete data_buf; // 
	delete data_buf_out;

	
	system("pause");
	return 0;

	
}

