#ifndef UI_H_
#define UI_H_

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <functional>  // for function
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
#include <vector>  // for vector
 
#include "personer.h"
#include "person.h"

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Slider, Checkbox, Vertical, Renderer, Button, Input, Menu, Radiobox, Toggle
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, operator|, Element, size, xflex, text, WIDTH, hbox, vbox, EQUAL, border, GREATER_THAN
#include "ftxui/dom/table.hpp"
 
  using namespace ftxui;

Personer personer();
std::vector<Person> personer_vector;

// Display a component nicely with a title on the left.
Component Wrap(std::string name, Component component) {
  return Renderer(component, [name, component] {
    return hbox({
               text(name) | size(WIDTH, EQUAL, 6),
               separator(),
               component->Render() | xflex,
           }) |
           xflex;
  });
}


void ui() {
  auto screen = ScreenInteractive::TerminalOutput();
 

  auto input_name = Input(" ", "placeholder");
  input_name = Wrap("Name", input_name);

  auto input_share = Input(" ", "placeholder");
  input_share = Wrap("Share", input_share);
 
  // -- Button -----------------------------------------------------------------
  std::string button_label = "Quit";
  std::function<void()> on_button_clicked_;
  auto button = Button(&button_label, screen.ExitLoopClosure());
 

  auto layout = Container::Vertical({
      input_name,
      input_share,
      button,
  });

  auto component = Renderer(layout, [&] {
    return vbox({
               input_name->Render(),
               separator(),
               input_share->Render(),
               separator(),
               button->Render(),
           }) |
           xflex | size(WIDTH, GREATER_THAN, 40) | border;
  });

 
  screen.Loop(component);
}
 

#endif  // UI_H_