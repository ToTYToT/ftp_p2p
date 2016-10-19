if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <F8>yn yesno i
imap <F8>ww wordwrap i
imap <F8>wc wordcount i
imap <F8>ut urlizetrunc i
imap <F8>ur urlize i
imap <F8>ue urlencode i
imap <F8>up upper i
imap <F8>ul unordered_list i
imap <F8>twh truncatewords_html i
imap <F8>tw truncatewords i
imap <F8>tit title i
imap <F8>tu timeuntil i
imap <F8>ts timesince i
imap <F8>ti time i
imap <F8>st striptags i
imap <F8>sf stringformat i
imap <F8>slu slugify i
imap <F8>ss safeseq i
imap <F8>sa safe i
imap <F8>rj rjust i
imap <F8>rt removetags i
imap <F8>ra random i
imap <F8>pp pprint i
imap <F8>pl pluralize i
imap <F8>pn phone2numeric i
imap <F8>ml make_list i
imap <F8>lj ljust i
imap <F8>ln linenumbers i
imap <F8>lbb linebreaksbr i
imap <F8>lb linebreaks i
imap <F8>li length_is i
imap <F8>le length i
imap <F8>la last i
imap <F8>jo join i
imap <F8>ie iriencode i
imap <F8>gd get_digit i
imap <F8>fe force_escape i
imap <F8>ff floatformat i
imap <F8>fa fix_ampersands i
imap <F8>fs filesizeformat i
imap <F8>ej escapejs i
imap <F8>es escape i
imap <F8>di divisibleby i
imap <F8>dsr dictsortreversed i
imap <F8>ds dictsort i
imap <F8>din default_if_none i
imap <F8>de default i
imap <F8>da date i
imap <F8>cu cut i
imap <F8>ce center i
imap <F8>cf capfirst i
imap <F8>as addslashes i
imap <F8>ad add i
imap <F8>with {% with  as  %}{% endwith %}1ki
imap <F8>url {% url  %}2hi
imap <F8>sl slice i
imap <F8>rg {% regroup  %}2hi
imap <F8>lo lower i
imap <F8>in {% now  %}2hi
imap <F8>ifne {% ifnotequal  %}{% endifnotequal %}1ki
imap <F8>ifeq {% ifequal  %}{% endifequal %}1ki
imap <F8>ifc {% ifchanged  %}{% endifchanged %}1ki
imap <F8>ifel {% if  %}{% else %}{% endif %}10hi
imap <F8>ife {% if  %}{% else %}{% endif %}3ki
imap <F8>ifl {% if  %}{% endif %}10hi
imap <F8>if {% if  %}{% endif %}1ki
imap <F8>flp forloop.parentloop i
imap <F8>fll forloop.last i
imap <F8>flf forloop.first i
imap <F8>flr0 forloop.revcounter0 i
imap <F8>flr forloop.revcounter i
imap <F8>flc0 forloop.counter0 i
imap <F8>flc forloop.counter i
imap <F8>fore {% for o in object_list %}{% empty %}{% endfor %}3ki
imap <F8>forl {% for o in object_list %}{% endfor %}11hi
imap <F8>for {% for o in object_list %}{% endfor %}1ki
imap <F8>fi first i
imap <F8>ex {% extends  %}2hi
imap <F8>cy {% cycle  %}2hi
imap <F8>com {% comment %}{% endcomment %}1ki
imap <F8>bl {% block  %}{% endblock %}1ki
imap <F8>ae {% autoescape on/off %}{% endautoescape %}1ki
imap <F10> {{  }}2hi
inoremap <silent> <Plug>NERDCommenterInInsert  <BS>:call NERDComment(0, "insert")
inoremap <silent> <Plug>(CaptureClipboardInsertOne) x<BS>:1CaptureClipboard ""a
inoremap <silent> <SNR>69_AutoPairsReturn =AutoPairsReturn()
inoremap <Plug>ZenCodingAnchorizeSummary :call zencoding#anchorizeURL(1)a
inoremap <Plug>ZenCodingAnchorizeURL :call zencoding#anchorizeURL(0)a
inoremap <Plug>ZenCodingRemoveTag :call zencoding#removeTag()a
inoremap <Plug>ZenCodingSplitJoinTagInsert :call zencoding#splitJoinTag()
inoremap <Plug>ZenCodingToggleComment :call zencoding#toggleComment()a
inoremap <Plug>ZenCodingImageSize :call zencoding#imageSize()a
inoremap <Plug>ZenCodingPrev :call zencoding#moveNextPrev(1)
inoremap <Plug>ZenCodingNext :call zencoding#moveNextPrev(0)
inoremap <Plug>ZenCodingBalanceTagOutwardInsert :call zencoding#balanceTag(-1)
inoremap <Plug>ZenCodingBalanceTagInwardInsert :call zencoding#balanceTag(1)
inoremap <Plug>ZenCodingExpandWord u:call zencoding#expandAbbr(1,"")a
inoremap <Plug>ZenCodingExpandAbbr u:call zencoding#expandAbbr(0,"")a
inoremap <S-Tab> 
imap <F3>  :NERDTreeToggle
map  ggVG$"+y
vmap  "+y
nnoremap <silent>  :CtrlP
map  w
nmap  g'Z
vmap c <Plug>ZenCodingCodePretty
nmap A <Plug>ZenCodingAnchorizeSummary
nmap a <Plug>ZenCodingAnchorizeURL
nmap k <Plug>ZenCodingRemoveTag
nmap j <Plug>ZenCodingSplitJoinTagNormal
vmap m <Plug>ZenCodingMergeLines
nmap / <Plug>ZenCodingToggleComment
nmap i <Plug>ZenCodingImageSize
nmap N <Plug>ZenCodingPrev
nmap n <Plug>ZenCodingNext
vmap D <Plug>ZenCodingBalanceTagOutwardVisual
nmap D <Plug>ZenCodingBalanceTagOutwardNormal
vmap d <Plug>ZenCodingBalanceTagInwardVisual
nmap d <Plug>ZenCodingBalanceTagInwardNormal
nmap , <Plug>ZenCodingExpandNormal
vmap , <Plug>ZenCodingExpandVisual
nmap d :cs find d =expand("<cword>")	
nmap i :cs find i ^=expand("<cfile>")$
nmap f :cs find f =expand("<cfile>")	
nmap e :cs find e =expand("<cword>")	
nmap t :cs find t =expand("<cword>")	
nmap c :cs find c =expand("<cword>")	
nmap g :cs find g =expand("<cword>")	
nmap s :cs find s =expand("<cword>")	
nmap <silent> # <Plug>MarkSearchPrev
nmap <silent> * <Plug>MarkSearchNext
nmap \ca <Plug>NERDCommenterAltDelims
vmap \cA <Plug>NERDCommenterAppend
nmap \cA <Plug>NERDCommenterAppend
vmap \c$ <Plug>NERDCommenterToEOL
nmap \c$ <Plug>NERDCommenterToEOL
vmap \cu <Plug>NERDCommenterUncomment
nmap \cu <Plug>NERDCommenterUncomment
vmap \cn <Plug>NERDCommenterNest
nmap \cn <Plug>NERDCommenterNest
vmap \cb <Plug>NERDCommenterAlignBoth
nmap \cb <Plug>NERDCommenterAlignBoth
vmap \cl <Plug>NERDCommenterAlignLeft
nmap \cl <Plug>NERDCommenterAlignLeft
vmap \cy <Plug>NERDCommenterYank
nmap \cy <Plug>NERDCommenterYank
vmap \ci <Plug>NERDCommenterInvert
nmap \ci <Plug>NERDCommenterInvert
vmap \cs <Plug>NERDCommenterSexy
nmap \cs <Plug>NERDCommenterSexy
vmap \cm <Plug>NERDCommenterMinimal
nmap \cm <Plug>NERDCommenterMinimal
vmap \c  <Plug>NERDCommenterToggle
nmap \c  <Plug>NERDCommenterToggle
vmap \cc <Plug>NERDCommenterComment
nmap \cc <Plug>NERDCommenterComment
nnoremap <silent> \ff :call g:Jsbeautify()
nmap \j <Plug>(CommandTJump)
nmap \b <Plug>(CommandTBuffer)
nmap \t <Plug>(CommandT)
map \T <Plug>TaskList
nmap <silent> \? <Plug>MarkSearchAnyPrev
nmap <silent> \/ <Plug>MarkSearchAnyNext
nmap <silent> \# <Plug>MarkSearchCurrentPrev
nmap <silent> \* <Plug>MarkSearchCurrentNext
nmap <silent> \n <Plug>MarkClear
xmap <silent> \r <Plug>MarkRegex
nmap <silent> \r <Plug>MarkRegex
xmap <silent> \m <Plug>MarkSet
nmap <silent> \m <Plug>MarkSet
nmap \caL <Plug>CalendarH
nmap \cal <Plug>CalendarV
vmap \ \cc
nmap \ \cc
vmap ]f :call PythonDec("function", 1)
nmap ]f :call PythonDec("function", 1)
omap ]f :call PythonDec("function", 1)
vmap ]F :call PythonDec("function", -1)
nmap ]F :call PythonDec("function", -1)
omap ]F :call PythonDec("function", -1)
vmap ]j :call PythonDec("class", 1)
nmap ]j :call PythonDec("class", 1)
omap ]j :call PythonDec("class", 1)
vmap ]J :call PythonDec("class", -1)
nmap ]J :call PythonDec("class", -1)
omap ]J :call PythonDec("class", -1)
map ]<Down> :call PythonNextLine(1)
map ]<Up> :call PythonNextLine(-1)
map ]d :call PythonSelectObject("function")
map ]c :call PythonSelectObject("class")
vmap ]u :call PythonUncommentSelection()
nmap ]u :call PythonUncommentSelection()
omap ]u :call PythonUncommentSelection()
vmap ]# :call PythonCommentSelection()
nmap ]# :call PythonCommentSelection()
omap ]# :call PythonCommentSelection()
vmap ]> >
nmap ]> ]tV]e>
omap ]> ]tV]e>
vmap ]< <
nmap ]< ]tV]e<
omap ]< ]tV]e<
map ]v ]tV]e
vmap ]e :PEoBm'gv``
nmap ]e :PEoB
omap ]e :PEoB
vmap ]t :PBOBm'gv``
nmap ]t :PBoB
omap ]t :PBoB
nmap fi :!firefox %.html & 
nmap gx <Plug>NetrwBrowseX
nmap md :!~/.vim/markdown.pl % > %.html 
nmap tl :Tlist
nmap tt :%s/\t/    /g
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cfile>"),0)
vmap <F8>with `>a{% endwith %}`<i{% with  as  %}i
map <F8>sl islice i
vmap <F8>ifne `>a{% endifnotequal %}`<i{% ifnotequal  %}i
vmap <F8>ifeq `>a{% endifequal %}`<i{% ifequal  %}i
vmap <F8>ifc `>a{% endifchanged %}`<i{% ifchanged  %}i
vmap <F8>ifel `>a{% else %} {% endif %}`<i{% if  %}i
vmap <F8>ife `>a{% else %}{% endif %}`<i{% if  %}i
vmap <F8>ifl `>a{% endif %}`<i{% if  %}i
vmap <F8>if `>a{% endif %}`<i{% if  %}i
vmap <F8>forl `>a{% endfor %}`<i{% for o in object_list %} i
vmap <F8>for `>a{% endfor %}`<i{% for o in object_list %} i
map <F8>fi ifirst i
vmap <F8>com `>a{% endcomment %}`<i{% comment %} i
vmap <F8>bl `>a{% endblock %}`<i{% block  %} i
vmap <F8>ae `>a{% endautoescape %}`<i{% autoescape on/off %} i
map <F8>yn iyesno i
map <F8>ww iwordwrap i
map <F8>wc iwordcount i
map <F8>ut iurlizetrunc i
map <F8>ur iurlize i
map <F8>ue iurlencode i
map <F8>up iupper i
map <F8>ul iunordered_list i
map <F8>twh itruncatewords_html i
map <F8>tw itruncatewords i
map <F8>tit ititle i
map <F8>tu itimeuntil i
map <F8>ts itimesince i
map <F8>ti itime i
map <F8>st istriptags i
map <F8>sf istringformat i
map <F8>slu islugify i
map <F8>ss isafeseq i
map <F8>sa isafe i
map <F8>rj irjust i
map <F8>rt iremovetags i
map <F8>ra irandom i
map <F8>pp ipprint i
map <F8>pl ipluralize i
map <F8>pn iphone2numeric i
map <F8>ml imake_list i
map <F8>lj iljust i
map <F8>ln ilinenumbers i
map <F8>lbb ilinebreaksbr i
map <F8>lb ilinebreaks i
map <F8>li ilength_is i
map <F8>le ilength i
map <F8>la ilast i
map <F8>jo ijoin i
map <F8>ie iiriencode i
map <F8>gd iget_digit i
map <F8>fe iforce_escape i
map <F8>ff ifloatformat i
map <F8>fa ifix_ampersands i
map <F8>fs ifilesizeformat i
map <F8>ej iescapejs i
map <F8>es iescape i
map <F8>di idivisibleby i
map <F8>dsr idictsortreversed i
map <F8>ds idictsort i
map <F8>din idefault_if_none i
map <F8>de idefault i
map <F8>da idate i
map <F8>cu icut i
map <F8>ce icenter i
map <F8>cf icapfirst i
map <F8>as iaddslashes i
map <F8>ad iadd i
nmap <F8>with i{% with  as  %}{% endwith %}1ki
omap <F8>with i{% with  as  %}{% endwith %}1ki
map <F8>url i{% url  %}2hi
map <F8>rg i{% regroup  %}2hi
map <F8>lo ilower i
map <F8>in i{% now  %}2hi
nmap <F8>ifne i{% ifnotequal  %}{% endifnotequal %}1ki
omap <F8>ifne i{% ifnotequal  %}{% endifnotequal %}1ki
nmap <F8>ifeq i{% ifequal  %}{% endifequal %}1ki
omap <F8>ifeq i{% ifequal  %}{% endifequal %}1ki
nmap <F8>ifc i{% ifchanged  %}{% endifchanged %}1ki
omap <F8>ifc i{% ifchanged  %}{% endifchanged %}1ki
nmap <F8>ifel i{% if  %}{% else %}{% endif %}10hi
omap <F8>ifel i{% if  %}{% else %}{% endif %}10hi
nmap <F8>ife i{% if  %}{% else %}{% endif %}3ki
omap <F8>ife i{% if  %}{% else %}{% endif %}3ki
nmap <F8>ifl i{% if  %}{% endif %}10hi
omap <F8>ifl i{% if  %}{% endif %}10hi
nmap <F8>if i{% if  %}{% endif %}1ki
omap <F8>if i{% if  %}{% endif %}1ki
map <F8>flp iforloop.parentloop i
map <F8>fll iforloop.last i
map <F8>flf iforloop.first i
map <F8>flr0 iforloop.revcounter0 i
map <F8>flr iforloop.revcounter i
map <F8>flc0 iforloop.counter0 i
map <F8>flc iforloop.counter i
map <F8>fore i{% for o in object_list %}{% empty %}{% endfor %}3ki
nmap <F8>forl i{% for o in object_list %}{% endfor %}11hi
omap <F8>forl i{% for o in object_list %}{% endfor %}11hi
nmap <F8>for i{% for o in object_list %}{% endfor %}1ki
omap <F8>for i{% for o in object_list %}{% endfor %}1ki
map <F8>ex i{% extends  %}2hi
map <F8>cy i{% cycle  %}2hi
nmap <F8>com i{% comment %}{% endcomment %}1ki
omap <F8>com i{% comment %}{% endcomment %}1ki
nmap <F8>bl i{% block  %}{% endblock %}1ki
omap <F8>bl i{% block  %}{% endblock %}1ki
nmap <F8>ae i{% autoescape on/off %}{% endautoescape %}1ki
omap <F8>ae i{% autoescape on/off %}{% endautoescape %}1ki
map <F10> i{{  }}2hi
nmap <silent> <Plug>NERDCommenterAppend :call NERDComment(0, "append")
nnoremap <silent> <Plug>NERDCommenterToEOL :call NERDComment(0, "toEOL")
vnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(1, "uncomment")
nnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(0, "uncomment")
vnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(1, "nested")
nnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(0, "nested")
vnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(1, "alignBoth")
nnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(0, "alignBoth")
vnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(1, "alignLeft")
nnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(0, "alignLeft")
vmap <silent> <Plug>NERDCommenterYank :call NERDComment(1, "yank")
nmap <silent> <Plug>NERDCommenterYank :call NERDComment(0, "yank")
vnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(1, "invert")
nnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(0, "invert")
vnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(1, "sexy")
nnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(0, "sexy")
vnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(1, "minimal")
nnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(0, "minimal")
vnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(1, "toggle")
nnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(0, "toggle")
vnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(1, "norm")
nnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(0, "norm")
nnoremap <silent> <Plug>(CommandTTag) :CommandTTag
nnoremap <silent> <Plug>(CommandTSearch) :CommandTSearch
nnoremap <silent> <Plug>(CommandTMRU) :CommandTMRU
nnoremap <silent> <Plug>(CommandTLine) :CommandTLine
nnoremap <silent> <Plug>(CommandTCommand) :CommandTCommand
nnoremap <silent> <Plug>(CommandTJump) :CommandTJump
nnoremap <silent> <Plug>(CommandTHistory) :CommandTHistory
nnoremap <silent> <Plug>(CommandTHelp) :CommandTHelp
nnoremap <silent> <Plug>(CommandTBuffer) :CommandTBuffer
nnoremap <silent> <Plug>(CommandT) :CommandT
nnoremap <SNR>44_: :=v:count ? v:count : ''
vnoremap <Plug>ZenCodingCodePretty :call zencoding#codePretty()
nnoremap <Plug>ZenCodingAnchorizeSummary :call zencoding#anchorizeURL(1)
nnoremap <Plug>ZenCodingAnchorizeURL :call zencoding#anchorizeURL(0)
nnoremap <Plug>ZenCodingRemoveTag :call zencoding#removeTag()
nnoremap <Plug>ZenCodingSplitJoinTagNormal :call zencoding#splitJoinTag()
vnoremap <Plug>ZenCodingMergeLines :call zencoding#mergeLines()
nnoremap <Plug>ZenCodingToggleComment :call zencoding#toggleComment()
nnoremap <Plug>ZenCodingImageSize :call zencoding#imageSize()
nnoremap <Plug>ZenCodingPrev :call zencoding#moveNextPrev(1)
nnoremap <Plug>ZenCodingNext :call zencoding#moveNextPrev(0)
vnoremap <Plug>ZenCodingBalanceTagOutwardVisual :call zencoding#balanceTag(-2)
nnoremap <Plug>ZenCodingBalanceTagOutwardNormal :call zencoding#balanceTag(-1)
vnoremap <Plug>ZenCodingBalanceTagInwardVisual :call zencoding#balanceTag(2)
nnoremap <Plug>ZenCodingBalanceTagInwardNormal :call zencoding#balanceTag(1)
nnoremap <Plug>ZenCodingExpandWord :call zencoding#expandAbbr(1,"")
nnoremap <Plug>ZenCodingExpandNormal :call zencoding#expandAbbr(3,"")
vnoremap <Plug>ZenCodingExpandVisual :call zencoding#expandAbbr(2,"")
nnoremap <silent> <Plug>MarkSearchPrev :if !mark#SearchNext(1)|execute 'normal! #zv'|endif
nnoremap <silent> <Plug>MarkSearchNext :if !mark#SearchNext(0)|execute 'normal! *zv'|endif
nnoremap <silent> <Plug>MarkSearchAnyPrev :call mark#SearchAnyMark(1)
nnoremap <silent> <Plug>MarkSearchAnyNext :call mark#SearchAnyMark(0)
nnoremap <silent> <Plug>MarkSearchCurrentPrev :call mark#SearchCurrentMark(1)
nnoremap <silent> <Plug>MarkSearchCurrentNext :call mark#SearchCurrentMark(0)
nnoremap <silent> <Plug>MarkToggle :call mark#Toggle()
nnoremap <silent> <Plug>MarkAllClear :call mark#ClearAll()
nnoremap <silent> <Plug>MarkClear :if !mark#DoMark(v:count, (v:count ? '' : mark#CurrentMark()[0]))|execute "normal! \<C-\>\<C-n>\<Esc>"|endif
vnoremap <silent> <Plug>MarkRegex :call mark#MarkRegex(mark#GetVisualSelectionAsRegexp())
nnoremap <silent> <Plug>MarkRegex :call mark#MarkRegex('')
vnoremap <silent> <Plug>MarkSet :if !mark#DoMark(v:count, mark#GetVisualSelectionAsLiteralPattern())|execute "normal! \<C-\>\<C-n>\<Esc>"|endif
nnoremap <silent> <Plug>MarkSet :if !mark#MarkCurrentWord(v:count)|execute "normal! \<C-\>\<C-n>\<Esc>"|endif
nmap <Nul><Nul>d :vert scs find d =expand("<cword>")
nmap <Nul><Nul>i :vert scs find i ^=expand("<cfile>")$	
nmap <Nul><Nul>f :vert scs find f =expand("<cfile>")	
nmap <Nul><Nul>e :vert scs find e =expand("<cword>")
nmap <Nul><Nul>t :vert scs find t =expand("<cword>")
nmap <Nul><Nul>c :vert scs find c =expand("<cword>")
nmap <Nul><Nul>g :vert scs find g =expand("<cword>")
nmap <Nul><Nul>s :vert scs find s =expand("<cword>")
nmap <Nul>d :scs find d =expand("<cword>")	
nmap <Nul>i :scs find i ^=expand("<cfile>")$	
nmap <Nul>f :scs find f =expand("<cfile>")	
nmap <Nul>e :scs find e =expand("<cword>")	
nmap <Nul>t :scs find t =expand("<cword>")	
nmap <Nul>c :scs find c =expand("<cword>")	
nmap <Nul>g :scs find g =expand("<cword>")	
nmap <Nul>s :scs find s =expand("<cword>")	
nnoremap <silent> <F11> :call conque_term#exec_file()
nnoremap <silent> <Plug>CalendarH :cal Calendar(1)
nnoremap <silent> <Plug>CalendarV :cal Calendar(0)
map <F6> :call FormartSrc()
map <F8> :call Rungdb()
map <F5> :call CompileRunGcc()
map <C-F3> \be  
map <F3> :NERDTreeToggle
nnoremap <C-F2> :vert diffsplit 
nnoremap <F2> :g/^\s*$/d 
map <F12> gg=G
map <S-Right> :tabn
map <S-Left> :tabp
nmap <silent> <F9> :Tlist
imap  ^
imap  $
imap 	 
imap <NL> 
imap  ,
map!  ,
imap ? <Plug>(CaptureClipboardInsertOne)
imap  	
imap  "*pa
imap  =CtrlXPP()
imap A <Plug>ZenCodingAnchorizeSummary
imap a <Plug>ZenCodingAnchorizeURL
imap k <Plug>ZenCodingRemoveTag
imap j <Plug>ZenCodingSplitJoinTagInsert
imap / <Plug>ZenCodingToggleComment
imap i <Plug>ZenCodingImageSize
imap N <Plug>ZenCodingPrev
imap n <Plug>ZenCodingNext
imap D <Plug>ZenCodingBalanceTagOutwardInsert
imap d <Plug>ZenCodingBalanceTagInwardInsert
imap ; <Plug>ZenCodingExpandWord
imap , <Plug>ZenCodingExpandAbbr
map!  zzi
let &cpo=s:cpo_save
unlet s:cpo_save
set ambiwidth=double
set autochdir
set autoindent
set autoread
set autowrite
set background=dark
set backspace=2
set balloonexpr=BalloonDeclaration()
set cindent
set cmdheight=2
set completeopt=longest,menu
set confirm
set cscopetag
set cscopeverbose
set expandtab
set fileencodings=utf8,ucs-bom,gbk,cp936,gb2312,gb18030
set fillchars=vert:\ ,stl:\ ,stlnc:\\
set guioptions=
set helplang=cn
set hlsearch
set ignorecase
set incsearch
set iskeyword=@,48-57,_,192-255,.
set langmenu=zh_CN.UTF-8
set laststatus=2
set matchtime=1
set mouse=a
set mousemodel=popup
set printoptions=paper:letter
set report=0
set ruler
set runtimepath=~/.vim,~/.vim/bundle/vundle,~/.vim/bundle/vim-fugitive,~/.vim/bundle/sparkup/vim/,~/.vim/bundle/indentLine,~/.vim/bundle/L9,~/.vim/bundle/FuzzyFinder,~/.vim/bundle/command-t,~/.vim/bundle/Auto-Pairs,~/.vim/bundle/python-imports.vim,~/.vim/bundle/CaptureClipboard,~/.vim/bundle/ctrlp-modified.vim,~/.vim/bundle/last_edit_marker.vim,~/.vim/bundle/synmark.vim,~/.vim/bundle/SQLComplete.vim,~/.vim/bundle/Javascript-OmniCompletion-with-YUI-and-j,~/.vim/bundle/jslint.vim,~/.vim/bundle/vim-javascript,~/.vim/bundle/Vim-Script-Updater,~/.vim/bundle/ctrlp.vim,~/.vim/bundle/ctrlp-funky,~/.vim/bundle/jsbeautify,~/.vim/bundle/The-NERD-Commenter,~/.vim/bundle/django_templates.vim,~/.vim/bundle/Django-Projects,~/.vim/bundle/Auto-Pairs,~/.vim/bundle/Better-Javascript-Indentation,~/.vim/bundle/CaptureClipboard,~/.vim/bundle/Django-Projects,~/.vim/bundle/FuzzyFinder,~/.vim/bundle/JavaScript-Indent,~/.vim/bundle/Javascript-Indentation,~/.vim/bundle/Javascript-OmniCompletion-with-YUI-and-j,~/.vim/bundle/L9,~/.vim/bundle/OOP-javascript-indentation,~/.vim/bundle/PHP-correct-Indenting,~/.vim/bundle/SQLComplete.vim,~/.vim/bundle/The-NERD-Commenter,~/.vim/bundle/Vim-Script-Updater,~/.vim/bundle/command-t,~/.vim/bundle/ctrlp-funky,~/.vim/bundle/ctrlp-modified.vim,~/.vim/bundle/ctrlp.vim,~/.vim/bundle/django_templates.vim,~/.vim/bundle/indentLine,~/.vim/bundle/javascript.vim,~/.vim/bundle/jsbeautify,~/.vim/bundle/jslint.vim,~/.vim/bundle/last_edit_marker.vim,~/.vim/bundle/php.vim,~/.vim/bundle/php.vim-for-php5,~/.vim/bundle/php_funcinfo.vim,~/.vim/bundle/phpcomplete.vim,~/.vim/bundle/phpcs.vim,~/.vim/bundle/python-imports.vim,~/.vim/bundle/sparkup,~/.vim/bundle/synmark.vim,~/.vim/bundle/syntastic,~/.vim/bundle/vim-easymotion,~/.vim/bundle/vim-fugitive,~/.vim/bundle/vim-indent-guides,~/.vim/bundle/vim-javascript,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim74,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/bundle/indentLine/after,~/.vim/bundle/vim-javascript/after,~/.vim/after,$GOROOT/misc/vim,~/.vim/bundle/vundle/,~/.vim/bundle/vundle/after,~/.vim/bundle/vim-fugitive/after,~/.vim/bundle/sparkup/vim//after,~/.vim/bundle/indentLine/after,~/.vim/bundle/L9/after,~/.vim/bundle/FuzzyFinder/after,~/.vim/bundle/command-t/after,~/.vim/bundle/Auto-Pairs/after,~/.vim/bundle/python-imports.vim/after,~/.vim/bundle/CaptureClipboard/after,~/.vim/bundle/ctrlp-modified.vim/after,~/.vim/bundle/last_edit_marker.vim/after,~/.vim/bundle/synmark.vim/after,~/.vim/bundle/SQLComplete.vim/after,~/.vim/bundle/Javascript-OmniCompletion-with-YUI-and-j/after,~/.vim/bundle/jslint.vim/after,~/.vim/bundle/vim-javascript/after,~/.vim/bundle/Vim-Script-Updater/after,~/.vim/bundle/ctrlp.vim/after,~/.vim/bundle/ctrlp-funky/after,~/.vim/bundle/jsbeautify/after,~/.vim/bundle/The-NERD-Commenter/after,~/.vim/bundle/django_templates.vim/after,~/.vim/bundle/Django-Projects/after
set scrolloff=3
set selection=exclusive
set selectmode=mouse,key
set shiftwidth=4
set showmatch
set smartindent
set smarttab
set softtabstop=4
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set noswapfile
set tabstop=4
set tags=tags;
set termencoding=utf-8
set whichwrap=b,s,<,>,h,l
set wildignore=*/tmp/*,*.so,*.swp,*.zip,*.pyc,*.png,*.jpg,*.gif,*\\tmp\\*,*.swp,*.zip,*.exe,*.pyc,*.png,*.jpg,*.gif
set wildmenu
" vim: set ft=vim :
