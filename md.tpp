--author Andreas Krennmair
--title A simple example
--date today %Y-%b-%d

This is the abstract of this presentation.
It may consist of zero or more lines, and may be as long as you want.

--newpage agenda
--heading Agenda

--withborder
--boldon 
  * Introduction

  * Concept

  * Implementation

  * Comparison with other implementations

  * Conclusions
--boldoff

--newpage intro
--heading Introduction

--beginslidetop
This is the introduction. And below, that's source code.
--endslidetop

--beginoutput
#include <stdio.h>

int main(void) {
  puts("Hello World!");
  return 0;
}
--endoutput

--newpage beginshelloutput
--heading How to install TPP
--color green
This is commands to install TPP
--color default

--beginshelloutput
#!/bin/sh
apt --y install ruby ruby--ncurses
git clone https://github.com/cbbrowne/tpp.git
cd tpp
make install
--endshelloutput


--newpage TPP 
--header I'm header
--horline
--heading TPP KeyWords

--huge Color
--color white
  * white
--color yellow
  * yellow
--color red
  * red
--color green
  * green
--color blue
  * blue
--color cyan
  * cyan
--color black
  * black
--color default
  * default

--color red
left
--center center
--right right
--color default

--boldon 
  * bold 
--boldoff
--revon 
  * reverse 
--revoff
--ulon 
  * underline 
--uloff

--beginslidetop
slide in from the top
--endslidetop
--beginslidebottom
slide in from the bottom
--endslidebottom
--beginslideleft 
slide in from left
--endslideleft
--beginslideright 
slide in from right
--endslideright

$$ lsb_release -a
--horline
--## This is comment
--footer This is footer 
