/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#include <iostream>
#include <fstream>
#include "FileSystem/File.hpp"

FileSystem::File::File(const std::string &path)
: Path(path)
{}

FileSystem::File::File(const FileSystem::Path &path)
: Path(path)
{}

/**
** Check if the Extension match
** @param find extension to find. For example "so".
** @return true when extension is found
*/
bool FileSystem::File::hasExtension(const std::string &find) const
{
	return this->getAbsolutePath().rfind(find) + find.length()
	== this->getAbsolutePath().length();
}

void FileSystem::File::create(void)
{
	std::ofstream outfile(getAbsolutePath());
	outfile.close();
}

bool FileSystem::File::exist(void)
{
	return this->isFile();
}

void FileSystem::File::write(const std::string &str)
{
	std::ofstream outfile(getAbsolutePath(), std::ios::app);
	outfile << str;
	outfile.close();
}
