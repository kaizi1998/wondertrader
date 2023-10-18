/*!
 * /file main.cpp
 * /project	WonderTrader
 *
 * /author Wesley
 * /date 2020/03/30
 * 
 * /brief 
 */

#include "WtRunner.h"

#include "../WTSTools/WTSLogger.h"

#ifdef _MSC_VER
#include "../Common/mdump.h"
#endif

#ifdef _DEBUG
#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

int copy_file(const std::string arg3[]) {
	// 指定源目录A和目标目录B的路径
	fs::path sourceDirectory(arg3[0]);
	fs::path targetDirectory(arg3[1]);

	std::string filetypes[5] = { ".exp",".ilk",".lib",".pdb",".dll" };

	int flag = 0;
	for (int i = 0; i < 5; i++) {
		std::string sourceFileName = arg3[2]+ filetypes[i];
		std::string filetype = filetypes[i];
		
		// 构建源文件的完整路径
		fs::path sourceFilePath = sourceDirectory / sourceFileName;

		// 构建目标文件的完整路径
		fs::path targetFilePath = targetDirectory / sourceFileName;
		try {
			// 使用create_directories函数创建目标目录B
			fs::create_directories(targetDirectory);

			// 使用copy_file函数将文件从源目录复制到目标目录
			fs::copy_file(sourceFilePath, targetFilePath, fs::copy_options::overwrite_existing);

			std::cout << "复制成功" << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "复制失败: " << e.what() << std::endl;
			flag = 1;
		}
	}
	return flag;
}

void copy_files() {
	std::string arg3[3];
	arg3[0] = "..\\x64\\Debug";
	arg3[1] = ".\\cta";
	arg3[2] = "WtCtaStraFact";
	copy_file(arg3);
}
#endif

//#include <vld.h>



int main()
{
#ifdef _MSC_VER
	CMiniDumper::Enable("WtRunner.exe", true);
#endif

#ifdef _DEBUG
	// 在Debug模式下声明变量或执行其他Debug相关操作
	copy_files();
#endif

	WtRunner runner;
	runner.init();

	runner.config();

	runner.run(false);
	return 0;
}

