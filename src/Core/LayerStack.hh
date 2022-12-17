#pragma once

#include "pchTVE.hh"

#include "Layer.hh"

namespace TVE {
  class LayerStack {
  public:
    LayerStack();
    ~LayerStack();
    void pushLayer(Layer* l);
    void popLayer(Layer* l);

    std::vector<Layer*>::iterator begin();
    std::vector<Layer*>::iterator end();
    std::vector<Layer*>::reverse_iterator rbegin();
    std::vector<Layer*>::reverse_iterator rend();
    std::vector<Layer*>::const_iterator begin() const;
    std::vector<Layer*>::const_iterator end() const;
    std::vector<Layer*>::const_reverse_iterator rbegin() const;
    std::vector<Layer*>::const_reverse_iterator rend() const;

  private:
    std::vector<Layer*> _stack;
  };
}
