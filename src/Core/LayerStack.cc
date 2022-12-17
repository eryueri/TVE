#include "LayerStack.hh"

namespace TVE {
  LayerStack::LayerStack() {}
  LayerStack::~LayerStack() {}
  void LayerStack::pushLayer(Layer* l) {
    _stack.emplace_back(l);
  }
  void LayerStack::popLayer(Layer *l) {
    auto iter = std::find(_stack.begin(), _stack.end(), l);
    if (iter != _stack.end()) {
      _stack.erase(iter);
    }
  }

  std::vector<Layer*>::iterator LayerStack::begin() {
    return _stack.begin();
  }
  std::vector<Layer*>::iterator LayerStack::end() {
    return _stack.end();
  }
  std::vector<Layer*>::reverse_iterator LayerStack::rbegin() {
    return _stack.rbegin();
  }
  std::vector<Layer*>::reverse_iterator LayerStack::rend() {
    return _stack.rend();
  }
  std::vector<Layer*>::const_iterator LayerStack::begin() const {
    return _stack.begin();
  }
  std::vector<Layer*>::const_iterator LayerStack::end() const {
    return _stack.end();
  }
  std::vector<Layer*>::const_reverse_iterator LayerStack::rbegin() const {
    return _stack.rbegin();
  }
  std::vector<Layer*>::const_reverse_iterator LayerStack::rend() const {
    return _stack.rend();
  }
}
