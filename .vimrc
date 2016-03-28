set nocompatible    " This line must be first or the changes you are expecting
                    " may not be the changes that occur

set noautoread	    " Changing code in another window maintains two versions
set backspace=2     " Allows backspace of indent, eol, and start
set confirm         " Starts dialog when exiting without saving
set title           " filename [+=-] (path) - GVIM
set showmatch       " Show match when inserting {}, [], or ()'s
set showmode        " Display the current mode on the last line

syntax on 

autocmd BufNewFile [Mm]akefile* set formatoptions=croql comments=:#
autocmd BufNewFile .vimrc,*.vim set formatoptions=croql comments=:\"
autocmd FileType c,cpp,java set mps+==:;

:set autowrite          " Automatically save before commands like :next/:make
:set nobackup           " Do not make a backup before overwriting	
:set columns=80         " Set the number of columns a new window will have
:set expandtab	        " Tabs are extended into spaces
:set formatoptions=tcrq " How to autoindent
:set nogdefault         " Controls how the search and replace command is used
:set helpheight=40      " Numbers of row the help window will have when opened
:set history=20	        " Stores the last 20 ':' commands
:set noincsearch        " Does not go immediately to pattern typed so far
:set nolist	        " Tabs are not shown as <TABS> and EOL as <EOL>
:set matchtime=2        " Tenths of seconds to show matching pairs
:set mousehide	        " Hides the mouse pointer when typing characters
:set ruler              " Always show position in file
:set scrolloff=12       " Number of lines to keep around cursor
:set shiftround         " Rounds < & > command to the nearest mod of shiftwidth
:set shiftwidth=4       " Indent 4 instead of 8
:set smartindent        " Next line indentation is based on previous line
:set splitbelow         " Extra window open below the current window  
:set noswapfile	        " No intermidiate files are used when saving
:set tabstop=4	        " Tab stop is 4 instead of 8
:set textwidth=80       " I do not like going all the way to the edge 
:set undolevels=100     " The commands that can be stored in for undo
:set virtualedit=all    " Cursor can go beyond the end of a line
:set wrapmargin=2       " Word wraps 2 character spaces from the margin
:set wildchar=<Tab>     " Character that starts the autocompletion
:set wildmenu           " Shows a list of possible autocompletions
:set wildmode=list      " show list and complete the first match 
:set nowritebackup      " No intermidate files when saving

set mouse=a
map <ScrollWheelUp> <C-Y>
map <ScrollWheelDown> <C-E>

set nu
set cin
set si
set softtabstop=4
set showmatch

" Ignores files when autocompleting      
:set wildignore=*.o,*.bak,*.data,*.class

