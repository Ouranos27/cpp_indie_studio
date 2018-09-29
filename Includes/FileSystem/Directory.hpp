/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#ifndef FS_DIRECTORY_HPP
#define FS_DIRECTORY_HPP

#include <vector>
#include <dirent.h>

#include "FileSystem/Path.hpp"
#include "FileSystem/File.hpp"

namespace FileSystem {

	class Directory : public Path {
	public:
		Directory(const std::string &path);
		Directory(const Path &path);
		~Directory(void);

	public:
		std::vector<FileSystem::File> getFiles(bool recursive = false);
		virtual bool 		exist(void) final;
		virtual void 		create(void);

	private:
		void	initialize(void);
		void 	initDir(void);
		void 	initDirNoChecking(void);
		void	exceptNoInit(void);

	private:
		bool 	_init = false;
		DIR	*_dir = nullptr;

	};
}

#endif /* !FS_DIRECTORY_HPP*/
