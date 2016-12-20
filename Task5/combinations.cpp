// Task 5
// Task: Combinations
// Need to implement a simple console application which takes a text file as an input. Input's file format:
//	1st line - integer number (N)
//	2nd line - space-separted words
//	As an output it prints into all combinations of the words from it with up to N words. The output is printed into output file is specified as a second parameter.
// Constraints: 
// 1. combinations should not be duplicated - i.e. combinations like "X Y" and "Y X" are treated as the same ones.
// 2. words should not be duplicated - i.e. combinations like "A A" or "B B B" should be skipped.
// An order of the combinations in file is up to the author.
// It is expected that the code will show a good design approach, with possibilities of extensibility, algorithm implementation is effective and some basic test coverage is provided.
// Please send the result in form of MS Visual Studio solution.
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <assert.h>

namespace CombiSpace{
	class Combinations {
	public:
		explicit Combinations(std::string in_file, std::string out_file) :
			path_to_input_file_(in_file), 
			path_to_output_file_(out_file),
			count_of_combinations_(0) {}

		bool Read_file() {
			std::ifstream infile(path_to_input_file_);
			
			if (!infile) {
				return false;
			}

			if (!(infile >> count_of_combinations_)) {
				return false;
			}

			std::string word;
			while(infile >> word) {
				words_.push_back(word);
			}

			infile.close();

			return true;
		}

		void Combinate() {
			Recursive_Combinator(0);
			combination_word_.empty();
		}

		bool Save_file() {
			std::ofstream output_file(path_to_output_file_);

			if (!output_file) {
				return false;
			}

			for (auto line:possible_combinations_) {
				output_file << line << std::endl;
			}

			output_file.close();

			return true;
		}
		
		size_t GetCountOfCombinations() {return possible_combinations_.size();}
	private:
		Combinations &operator=(const Combinations&) {return *this;}

		void Recursive_Combinator(const unsigned int start_position) {
			for (auto i = start_position; i < words_.size(); i++) {
				combination_word_ += words_[i];
				possible_combinations_.insert(combination_word_);
				if (i < words_.size() && combination_word_.length() < count_of_combinations_) {
					Recursive_Combinator(i + 1);
				}
				combination_word_.erase(combination_word_.length() - 1);
			}
		}

		const std::string path_to_input_file_;
		const std::string path_to_output_file_;
		unsigned int count_of_combinations_;
		std::vector<std::string> words_;
		std::set<std::string> possible_combinations_;
		std::string combination_word_;
	};
} // namespace Combinations
 
int main_flow(int argc, char* argv[] ) {
	using namespace CombiSpace;

	if (argc < 3 || !strcmp(argv[1], "help")) {
		std::cout << "Help message:\n" \
			<< " task5.exe [in_path] [out_path]" \
			<< "   in_path - path to file with conditions to task" \
			<< "   out_path - path with name to output file" \
			<< std::endl;
		return 1;
	}

	Combinations combinator(argv[1], argv[2]);

	if (!combinator.Read_file()) {
		std::cout << "Unable to open file: " << argv[1] << std::endl;
		return 1;
	}

	combinator.Combinate();

	if (!combinator.Save_file()) {
		std::cout << "Unable to save file: " << argv[2] << std::endl;
		return 1;
	}

	return 0;
}

void SelfTest() {
	{
		char *argv[] = {"Self", "input_normal.txt", "output.txt"};
		assert(!main_flow(3, argv) && "Normal flow");
	}
	{
		char *argv[] = {"Self", "file_do_not_exist.txt", "output.txt"};
		assert(main_flow(3, argv) && "No input file");
	}
	{
		char *argv[] = {"Self", "input_empy.txt", "output.txt"};
		assert(main_flow(3, argv) && "Input file is empty");
	}
	{
		char *argv[] = {"Self", "input_normal.txt", ""};
		assert(main_flow(3, argv) && "No output file");
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");	
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");	
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");	
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");	
	}
	{
		CombiSpace::Combinations combinator("input_empty.txt", "output_empty.txt");
		assert(combinator.Read_file() && "Input empty: open file");
		combinator.Combinate();
		assert(combinator.GetCountOfCombinations() != 0 && "Input empty: open file");
		assert(combinator.Save_file() && "Input empty: save file");
	}
}

int main(int argc, char* argv[] ) {
	if (argc == 2 && !strcmp(argv[1], "test")) {
		SelfTest();
	} else {
		main_flow(argc, argv);
	}
}