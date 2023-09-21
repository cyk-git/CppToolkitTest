// CppToolkitTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 此项目用于常用C++工具库CppTookit的开发测试。CppTookit拥有独立的仓库，其作为一个子模块导入该仓库

#include <iostream>
#include <cpp_toolkit\async_consumer.h>
#include <string>
#include <Windows.h>

bool flag_procudce_ = true;

void ProducerLoop() {
  using namespace cpptoolkit;
  int i = 0;
  AsyncConsumerTest consumer(1024, 1024);
  consumer.Init();
  while (flag_procudce_) {
    std::unique_ptr<int[]> data = std::make_unique<int[]>(1024 * 1024);
    data[0] = i++;
    consumer.ProcessDataAsync(std::move(data));
    //Sleep(1);
  }
}

int main() { 
  using namespace cpptoolkit;
  InitLogger("logs", GetLogFileName("log.txt"), spdlog::level::debug);
  std::thread producer(&ProducerLoop);
  system("pause");
  flag_procudce_ = false;
  producer.join();
  system("pause");
}