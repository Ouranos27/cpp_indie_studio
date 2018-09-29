/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Directory
** Directory description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#include <dirent.h>
#include <iostream>
#include <sys/stat.h>
#include "FileSystem/Directory.hpp"

FileSystem::Directory::Directory(const std::string &path)
: Path(path)
{}

FileSystem::Directory::Directory(const FileSystem::Path &path)
: Path(path)
{}

void FileSystem::Directory::initialize(void)
{
	this->initDir();
}

std::vector<FileSystem::File> FileSystem::Directory::getFiles(bool recursive)
{
	this->exceptNoInit();
	std::vector<FileSystem::File>	files;

	(void)recursive;
	return files;
}

/*
** Check if the Directory exist and set _dir if exist
*/
bool FileSystem::Directory::exist(void) {
	if (!_dir) {
		initDirNoChecking();
		return _dir != nullptr;
	}
	return true;
}

void FileSystem::Directory::initDir(void)
{
	if (!_dir) {
		initDirNoChecking();
		if (!_dir) {
			fprintf(stderr,
				"FileSystem::Directory::initDir(void): fail\n");
			throw std::exception();
		}
	}
}


FileSystem::Directory::~Directory(void)
{
	closedir(_dir);
}

void FileSystem::Directory::exceptNoInit(void)
{
	if (!_init) {
		fprintf(stderr,
		"FileSystem::Directory::exceptNoInit(): fail\n");
		throw std::exception();
	}
}

void FileSystem::Directory::initDirNoChecking(void)
{
	_dir = opendir(this->getAbsolutePath().c_str());
}

void FileSystem::Directory::create(void)
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP;
	if (mkdir(this->getAbsolutePath().c_str(), mode) == -1) {
		fprintf(stderr, "FileSystem::Directory::create(void): fail\n");
		throw std::exception();
	}
}