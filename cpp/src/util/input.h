#include <fstream>
#include <string>
#include <vector>

namespace aoc {
    class input_reader {
    public:

        /**
         * Default Constructor
         */
        input_reader();

        /**
         * Construct an input reader that reads from the given path
         */
        input_reader(const std::string& path);

        /**
         * Construct an input reader that finds the input file for this solution
         * given the current working directory and the input file name.
         * 
         * This will only succeed if the input file is in the 'inputs' directory of
         * the host repository.
         */
        input_reader(const std::string& cwd, const std::string& filename);

        /**
         * Attempt to open the given file.
         * 
         * @param path - Path to the file
         * @returns true - If the file was opened successfuly, false otherwise.
         */
        bool open(const std::string& path);

        /**
         * Attempt to open an input file with the given name. The input reader will
         * search the file system for an inputs directory above the working directory
         * and try to find an input file with the given name.
         * 
         * @param cwd - Current working directory
         * @param filename - Name of the input file
         * @returns true - If the file was opened successfuly, false otherwise.
         */
        bool open(const std::string& cwd, const std::string& filename);
    
        /**
         * Check whether the input reader can currently read values from the input source
         */
        bool can_read() const;

        /**
         * Get the path to the input file being used by this reader.
         */
        const std::string& path() const;

        /**
         * Read an integer value from the input reader   
         */
        bool read(int& val);

        /**
         * Read a list of integers
         */
        bool read(std::vector<int>& numbers, const char separator = '\n');

        /**
         * Read a line of text from the input
         */
        bool read_line(std::string& out);

        /**
         * Reset the reader's position to the beginning of the input file
         */
        void reset();

    private:

        std::string m_path;

        std::ifstream m_in;
    };
}