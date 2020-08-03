

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
	if (f.is_open()) std::cout << "file is opened"<< '\n'; // файл открыт, он открываетс€

	Header h;
		
	f.read( (char*) &h, sizeof(h) ); // считывание идет по адресу
	
	short * data_buf = new short[h.subchunk2Size >> 1]; //  динамический массив-буфер дл€ считывани€ информации о файле
	std::cout << data_buf << '\n';

	f.read( (char*) data_buf, h.subchunk2Size);
	
	Header hout = h;
	hout.subchunk2Size = h.subchunk2Size / 2;
	short * data_buf_out = new short[hout.subchunk2Size >> 1];

	// редактирование сигнала по отсчетам
	for (int i = 0; i < (hout.subchunk2Size >> 1); i++)
	{
		data_buf_out[i] = data_buf[i]; // измен€ю сэмплы
		//std::cout << data_buf[i] << " -> " << data_buf_out[i] << '\n';
	}
	

	std::ofstream fout("fspeech_edited.wav", std::ios::binary); // новый отредактированный файл с измененной амплитудой
	fout.write((char*) &hout, sizeof(hout)); // записали новый заголовок
	fout.write((char*) data_buf_out, hout.subchunk2Size); // записали саму информационную часть

	// чистка
	f.close();
	fout.close();

	delete data_buf; // 
	delete data_buf_out;

	
	system("pause");
	return 0;

	
}

