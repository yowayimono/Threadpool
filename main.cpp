/*
 * @Author: yowayimono
 * @Date: 2023-06-10 12:49:35
 * @LastEditors: yowayimono
 * @LastEditTime: 2023-06-10 12:53:11
 * @Description: nothing
 */
#include <iostream>
#include <thread>
#include "thread_pool.h"

// 模拟需要执行的任务
void task(int id) {
    std::cout << "Task " << id << " is running in thread " << std::this_thread::get_id() << std::endl;
}

int main() {
    // 创建一个包含3个线程的线程池
    thread_pool& pool = thread_pool::get(3);

    // 提交多个任务给线程池执行
    for (int i = 1; i <= 10; ++i) {
        pool.submit([i]() {
            task(i);
        });
    }

    // 等待所有任务完成
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
