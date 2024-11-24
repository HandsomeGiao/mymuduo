#pragma once

#include <functional>
#include <memory>

#include "TimeStamp.hpp"
#include "noncopyable.hpp"

class EventLoop;
class TimeStamp;

namespace mymuduo {
class Channel : noncopyable {
 public:
  using EventCallback = std::function<void()>;
  using ReadEventCallback = std::function<void(TimeStamp)>;

  Channel(EventLoop *loop, int fd);
  ~Channel();

  // 设置回调操作
  void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
  void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
  void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
  void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }

  // 防止当Channel被销毁时，还在执行回调操作
  void tie(const std::shared_ptr<void> &);

  int fd() const { return fd_; }
  // epoll 监听后设置的事件
  void setRevents(int revt) { revents_ = revt; }

  // 事件处理
  void enableReading() {
    events_ |= kReadEvent;
    update();
  }
  void disableReading() {
    events_ &= ~kReadEvent;
    update();
  }
  void enableWriting() {
    events_ |= kWriteEvent;
    update();
  }
  void disableWriting() {
    events_ &= ~kWriteEvent;
    update();
  }
  void disableAll() {
    events_ = kNoneEvent;
    update();
  }

  // 判断是否在监听事件
  bool isWriting() const { return events_ & kWriteEvent; }
  bool isReading() const { return events_ & kReadEvent; }
  bool isNoneEvent() const { return events_ == kNoneEvent; }

  int index() { return index_; }
  void set_index(int idx) { index_ = idx; }

  // one loop per thread
  EventLoop *ownerLoop() { return loop_; }

 private:
  // 在Channel所属的EventLoop中更新Channel
  void update();
  void remove();

  void handleEvent(TimeStamp receiveTime);
  void handleEventWithGuard(TimeStamp receiveTime);

  static const int kNoneEvent;
  static const int kReadEvent;
  static const int kWriteEvent;

  EventLoop *loop_;
  const int fd_;
  int events_;   // 感兴趣的事件
  int revents_;  // 发生的事件
  int index_;

  // tie 防止访问无效指针  暂时不懂
  std::weak_ptr<void> tie_;
  bool tied_;

  ReadEventCallback readCallback_;
  EventCallback writeCallback_;
  EventCallback closeCallback_;
  EventCallback errorCallback_;
};
}  // namespace mymuduo