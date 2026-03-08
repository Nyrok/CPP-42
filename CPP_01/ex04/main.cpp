#include <iostream>
#include <fstream>

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream	infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return (1);
	}

	std::string		outname = filename + ".replace";
	std::ofstream	outfile(outname.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create file " << outname << std::endl;
		infile.close();
		return (1);
	}

	std::string	line;
	while (std::getline(infile, line))
	{
		std::size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.size());
			pos += s2.size();
		}
		outfile << line;
		if (!infile.eof())
			outfile << "\n";
	}

	infile.close();
	outfile.close();
	return (0);
}
