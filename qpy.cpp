#include "qpy.h"

int main(){
	// instance of my library
	lib lib;

	// useful declarations
	std::vector<std::string> file_names;
	std::vector<std::string> prev_file_names;
	std::vector<std::string> contents_of_file;

	// list of files that are passed in to be run
	lib.copy_lines_of_file_to_vector(file_names, "file_names.txt");

	// copies file_names to vector for later comparison
	prev_file_names = file_names;

	// changes the file names slightly as to not affect the users source files
	for (std::string& file : file_names){
		// inserts a "q" before ".py"
		file.insert(file.begin() + lib.first(file, '.'), 'q');
	}

	// debugging purposes
	//lib.print("files to make:");
	//lib.print(file_names );

	// makes the files with the added q
	lib.make_these_files(file_names);
	
	// copies the contents of the original source file, to the one with the added q
	for (int i = 0 ; i < file_names .size() ; i++){
		// copies the contents
		lib.copy_lines_from_one_file_to_another(prev_file_names[i], file_names [i]);
	}

	// iterates through the list of files
	for (std::string file_name : file_names){
		// if there is a file name in the list and not a blank space that could have been inserted for some reason
		if (file_name.length() > 0){
			// iterating through the list of predetermined identifiers to remove, these are declared in qpy.h
			for (std::string it : indentifiers){
				// copying the lines of file with the add q in the vector
				lib.copy_lines_of_file_to_vector(contents_of_file, file_name);
				// finds and deletes the indentifier in the file
				lib.search_for_and_replace_string_in_vector_with_options(contents_of_file, it, "", 2);
				// writes the lines back to the file now that the added identifiers are removed
				lib.write_lines_of_vector_to_file(contents_of_file, file_name);
			}
		}
	}

	// adding the python iterpreter call command
	std::string command = "python3 ";
	// adding the files with the added q to be run by the interpreter
	command += lib.vector_to_string(file_names , true);
	
	// running the command in terminal
	lib.run_command(command);

	// removing the files with the q in them so the user doesn't have to deal with them
	lib.remove_these_files(file_names);
	
	return 0;
}
