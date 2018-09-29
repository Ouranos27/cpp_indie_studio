/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Path
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:24
*/

#include <unistd.h>
#include <string>
#include <sys/stat.h>
#include "FileSystem/Directory.hpp"
#include "FileSystem/Path.hpp"

FileSystem::Path::Path(const std::string &path)
: _givenPath(path)
{
	if (_givenPath[0] != '/') {
		char *current_dir = get_current_dir_name();
		_absolutePath = current_dir + std::string("/") + _givenPath;
		free(current_dir);
	} else {
		_absolutePath = _givenPath;
	}
}

bool FileSystem::Path::isFile(void) const
{
	FILE *file = fopen(_givenPath.c_str(), "r");

	if (!file) {
		return false;
	}
	std::fclose(file);
	return true;
}

/**
*	todo: better casting
* @return the last element of the past
*/
std::string FileSystem::Path::getName(void) const
{
	size_t 		first;

	first = _givenPath.find_last_of('/', _givenPath.length() - 1);
	if (first == std::string::npos)
		return _givenPath;
	return std::string(_givenPath, first + 1, _givenPath.length());
}

bool FileSystem::Path::isDirectory(void) const
{
	//auto dir = (new FileSystem::Directory(this->getName()) noexcept);

	return false;
}

const std::string &FileSystem::Path::getAbsolutePath() const
{
	return _absolutePath;
}

const std::string &FileSystem::Path::getGivenPath() const
{
	return _givenPath;
}

