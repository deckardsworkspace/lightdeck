# Lightdeck

The poor man's Loupedeck.

Lightdeck is a Lightroom MIDI controller powered by Arduino, based on the fantastic [LRduino project by Ben Trew.](https://github.com/Bixx/LRduino) This is created in partial fulfillment of the PSHS-MC Design & Make Technologies course.

## Prerequisites

Lightdeck depends on a few pieces of software to make the magic happen:

- [Hairless-MIDIserial](https://github.com/projectgus/hairless-midiserial) to intercept MIDI messages sent over serial
- [LoopMIDI for Windows](https://www.tobias-erichsen.de/software/loopmidi.html) to route MIDI messages from Hairless-MIDIserial to MIDI2LR (use the built-in Audio MIDI Setup app on macOS)
- [MIDI2LR](https://rsjaffe.github.io/MIDI2LR/) to convert MIDI messages to Lightroom commands

## License

Lightdeck - the poor man's Loupedeck

Copyright (C) 2019 Jared Dantis, (C) 2018 Ben Trew

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

https://github.com/Bixx
