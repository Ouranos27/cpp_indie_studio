/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#ifndef FS_FILE_HPP
#define FS_FILE_HPP

#include "FileSystem/Path.hpp"
/*
** todo create exist... and system basics
**
*/
namespace FileSystem {

	class File : public Path {
	public:
		File(const std::string &path);
		File(const Path &path);

	public:
		bool			hasExtension(const std::string &find = nullptr) const;
		void 		create(void) final;
		bool 		exist(void) final;
		void 		write(const std::string &str);
	};
}

#endif /* !FS_FILE_HPP*/
