#include <fstream>
#include <iostream>
#include <iomanip>

double map_fun(double j)
{	// manda punti che stanno nell'intervallo [1,5] in [-1,2] 
	double i = j*3.0/4.0 - 7.0/4.0;
	return i;
}


int main()
{
	std::ifstream file("./data.txt");
	
	if(file.fail())
	{
		std::cerr << "Non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	
	double val;
	int counter = 1;
	double sum = 0.0;
	double mean = 0.0;
	std::ofstream of("result.txt");
	of << "# N Mean" << std::endl;
	while(file >> val)
	{ 
		double i = map_fun(val);
		sum += i;
		mean = sum/counter;
		of << counter << " " << std::setprecision(16) << 
			std::scientific << mean << std::endl;
		counter++;
	}
	
    return 0;
}
