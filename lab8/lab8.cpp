// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void print_image(const char* fname)
{
	ifstream input(fname, ios::binary);

	BITMAPFILEHEADER fileh;
	BITMAPINFOHEADER infoh;
	input.read((char*)&fileh, sizeof(fileh));
	input.read((char*)&infoh, sizeof(infoh));

	struct Color { BYTE b, g, r; };
	vector<Color> pixels(infoh.biHeight * infoh.biWidth);

	input.read((char*)pixels.data(), infoh.biHeight * infoh.biWidth * 3);
	int y = infoh.biHeight;
	while(y > 0)
	{
		y = y - 1;
		for (int x = 0; x < infoh.biWidth; x++)
		{
			if (pixels[y * infoh.biWidth + x].r <= 50)
				cout << "\xdb\xdb";
			else if ((pixels[y * infoh.biWidth + x].r >= 51) && (pixels[y * infoh.biWidth + x].r <= 101))
				cout << "\xd2\xd2";
			else if ((pixels[y * infoh.biWidth + x].r >= 102) && (pixels[y * infoh.biWidth + x].r <= 152))
				cout << "\xd1\xd1";
			else if ((pixels[y * infoh.biWidth + x].r >= 153) && (pixels[y * infoh.biWidth + x].r <= 203))
				cout << "\xd0\xd0";
			else cout << "  ";
		}
		cout << endl;
	}

}

int main()
{
	print_image("1.bmp");
	print_image("2.bmp");
	print_image("3.bmp");
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
