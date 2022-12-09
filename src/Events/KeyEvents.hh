#pragma once

#include "Event.hh"

namespace TVE {
  class KeyPressed : public Event {
  public: 
    KeyPressed(int code) 
      : _code(code) {}

    EVENT_CLASS_TYPE(KeyPressed);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);

    std::string verboseStr() const override;
  private:
    int _code;
  };

  class KeyReleased : public Event {
  public: 
    KeyReleased(int code) 
      : _code(code) {}

    EVENT_CLASS_TYPE(KeyReleased);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);

    std::string verboseStr() const override;
  private:
    int _code;
  };

  class KeyRepeated : public Event {
  public: 
    KeyRepeated(int code) 
      : _code(code) {}

    EVENT_CLASS_TYPE(KeyRepeated);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard);

    std::string verboseStr() const override;
  private:
    int _code;
  };
}
