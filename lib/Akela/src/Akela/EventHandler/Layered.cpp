/*
 * Akela -- Animated Keyboard Extension Library for Arduino
 * Copyright (C) 2016  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Akela.h"

namespace Akela {
  namespace EventHandler {

    Layered::Layered (Akela::AbstractHID *HID, Akela::LayeredKeyMap *keymap)
      : Akela::EventHandler::Base (HID, keymap) {
    }

    void
    Layered::press (uint8_t index) {
      LayerComponent::press (HID, keymap, index, keymap->lookup (index));
      Akela::EventHandler::Base::press (index);
    }

    void
    Layered::release (uint8_t index) {
      LayerComponent::release (HID, keymap, index, keymap->lookup (index));
      Akela::EventHandler::Base::release (index);
    }
  };
};
