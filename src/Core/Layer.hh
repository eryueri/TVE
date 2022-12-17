#pragma once

#include "Events/Event.hh"

namespace TVE {
  class Layer {
  public:
    Layer() = default;
    virtual ~Layer() = default;
    virtual void onAttach() = 0;
    virtual void onDetach() = 0;
    virtual void onEvent(Event& e) = 0;
    virtual void onUpdate(float time) = 0;
  };
}
