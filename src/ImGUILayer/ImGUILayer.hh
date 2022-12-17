#pragma once

#include "Core/Layer.hh"

namespace TVE {
  class ImGUILayer : public Layer {
  public:
    ImGUILayer();
    ~ImGUILayer();
    void onAttach() override;
    void onDetach() override;
    void onEvent(Event& e) override;
    void onUpdate(float time) override;
  private:

  };
}
