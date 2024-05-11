// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref
 
int ui() {
  using namespace ftxui;
 
  // The data:
  std::string name;
  std::string share;
 
  // The basic input components:
  Component input_first_name = Input(&name, "Name");
 
 
  // The phone number input component:
  // We are using `CatchEvent` to filter out non-digit characters.
  Component input_share = Input(&share, "Share");
  input_share |= CatchEvent([&](Event event) {
    return event.is_character() && !std::isdigit(event.character()[0]) && !std::ispunct(event.character()[0]);
  });
  input_share |= CatchEvent([&](Event event) {
    return event.is_character() && share.size() > 10;
  });
 
  // The component tree:
  auto component = Container::Vertical({
      input_first_name,
      input_share
  });
 
  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    return vbox({
               hbox(text(" Name : "), input_first_name->Render()),
               hbox(text(" Share  : "), input_share->Render()),
               separator(),
               text("Hello " + name),
               text("Your share is " + share),
           }) |
           border;
  });
 
  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}