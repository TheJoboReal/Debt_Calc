#ifndef UI_H_
#define UI_H_

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
#include <vector>  // for vector
 
#include "personer.h"
#include "person.h"

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref
 

Personer personer();
std::vector<Person> personer_vector;



void ui() {
  using namespace ftxui;
 
  // The data:
  std::string name;
  std::string share;
 
  // The basic name input components:
  Component input_name = Input(&name, "Name");
 
 
  // The share component:
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
      input_name,
      input_share
  });
 
  auto screen = ScreenInteractive::TerminalOutput();

  // Add a button_exit component:
Component button_exit = Button({
  .label = "Click to quit",
  .on_click = screen.ExitLoopClosure(),
});

  // Render the button_exit:
  auto button_renderer = Renderer(button_exit, [&] {
    return button_exit->Render();
  });

  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    // Person person(name, share);
    // personer.addPerson(person);

    return vbox({
               hbox(text(" Name : "), input_name->Render()),
               hbox(text(" Share  : "), input_share->Render()),
               separator(),
               text("Hello " + name),
               text("Your share is " + share),
               separator(),
               button_renderer->Render(), // Add the button_exit component to the renderer
           }) |
           border;
  });

  // Add the button_exit component to the component tree:
  component->Add(button_exit);

 
  screen.Loop(renderer);
}
 

#endif  // UI_H_