/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Path
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:24
*/

#ifndef FS_PATH_HPP
#define FS_PATH_HPP

#include <string>
/*
** Improvements:
** 	- fileSystem's shell tricks: ls, cd, mkdir, chmod, chown
* 		- mkdir add va_arg
*/
namespace FileSystem {

	class Path {
	public:
		Path(const std::string &path);

	public:
		bool 			isFile(void) const;
		bool 			isDirectory(void) const;
		virtual bool		exist(void) = 0;
		virtual void		create(void) = 0;
		std::string 		getName(void) const;
		const std::string 	&getAbsolutePath() const;
		const std::string &getGivenPath() const;

	private:
		const std::string 		_givenPath;
		std::string 			_absolutePath;
	};
}

#endif /* !FS_PATH_HPP */