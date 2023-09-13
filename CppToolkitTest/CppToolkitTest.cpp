// CppToolkitTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 此项目用于常用C++工具库CppTookit的开发测试。CppTookit拥有独立的仓库，其作为一个子模块导入该仓库

#include <iostream>
#include <cpp_toolkit\handle_exception.h>
#include <string>

int main() { 
  using namespace cpptoolkit;
  InitLogger();
  try {
    //boost::throw_exception(boost::enable_error_info(std::runtime_error("test"))
    //                           << error_level(ErrorLevel::E_ERROR),
    //                       BOOST_CURRENT_LOCATION);
    CPPTOOLKIT_THROW_EXCEPTION(std::runtime_error("test"), ErrorLevel::E_WARNING);
  } catch (...) {
    handle_exception(boost::current_exception());
    //LOG_ERROR(boost::diagnostic_information(boost::current_exception()));
  }
}