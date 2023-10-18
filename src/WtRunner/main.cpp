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
	// ָ��ԴĿ¼A��Ŀ��Ŀ¼B��·��
	fs::path sourceDirectory(arg3[0]);
	fs::path targetDirectory(arg3[1]);

	std::string filetypes[5] = { ".exp",".ilk",".lib",".pdb",".dll" };

	int flag = 0;
	for (int i = 0; i < 5; i++) {
		std::string sourceFileName = arg3[2]+ filetypes[i];
		std::string filetype = filetypes[i];
		
		// ����Դ�ļ�������·��
		fs::path sourceFilePath = sourceDirectory / sourceFileName;

		// ����Ŀ���ļ�������·��
		fs::path targetFilePath = targetDirectory / sourceFileName;
		try {
			// ʹ��create_directories��������Ŀ��Ŀ¼B
			fs::create_directories(targetDirectory);

			// ʹ��copy_file�������ļ���ԴĿ¼���Ƶ�Ŀ��Ŀ¼
			fs::copy_file(sourceFilePath, targetFilePath, fs::copy_options::overwrite_existing);

			std::cout << "���Ƴɹ�" << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "����ʧ��: " << e.what() << std::endl;
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
	// ��Debugģʽ������������ִ������Debug��ز���
	copy_files();
#endif

	WtRunner runner;
	runner.init();

	runner.config();

	runner.run(false);
	return 0;
}

