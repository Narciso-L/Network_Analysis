# Copyright (C) <2016>  <Narciso López-López>
    # This program is free software: you can redistribute it and/or modify
    # it under the terms of the GNU General Public License as published by
    # the Free Software Foundation, either version 3 of the License, or
    # (at your option) any later version.
    # This program is distributed in the hope that it will be useful,
    # but WITHOUT ANY WARRANTY; without even the implied warranty of
    # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    # GNU General Public License for more details.
    # You should have received a copy of the GNU General Public License
    # along with this program.  If not, see <https://www.gnu.org/licenses/>.




#------------------------------------------------------------------------------

SOURCE = Grafo.cpp main.cpp 
MYPROGRAM = grafos
CC = g++ -std=c++11 -O3 -DNDEBUG 

#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)

	$(CC) $(SOURCE) -o $(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)

