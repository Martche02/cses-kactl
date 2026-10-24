import os, re, json, glob, shutil, urllib.request
from bs4 import BeautifulSoup

CSES_DIR = r'c:\Users\Marce\codes\cpp\cses'
CODE_DIR = r'c:\Users\Marce\codes\cpp\code'
KACTL_DIR = os.path.join(CSES_DIR, 'kactl')
CACHE = r'C:\Users\Marce\.gemini\antigravity\brain\1cf2850f-b698-4687-950d-42d06ee725a4\scratch\cses_scraped.json'

cache = json.load(open(CACHE, encoding='utf-8'))
cses_cache = {v['task_id']: v for v in cache.values() if v.get('task_id')}

CAT_BY_ID = {}
def setcat(cat, ids):
    for i in ids: CAT_BY_ID[str(i)] = cat
setcat('mathematics', [1079,1081,1082,1086,1095,1146,1712,1713,2164,2182,2185,2209,2210,2417,2419,3154,3355,3396,3397,3398,3406])
setcat('combinatorics', [1715,1716,1717,1725,1726,1727,1728,2064,2187])
setcat('strings', [1110,1111,1112,1731,1732,1733,1753,2420,3138,3141])
setcat('data_structures', [1654,1655,3191,3192,3194,3195,3211,3233])
setcat('graph', [1096,1722,1723,1724])
setcat('game_theory', [1099,1729,1730,1754,2207,2208])
setcat('dynamic_programming', [1633,1634,1635,1636,1637])

CAT_NAMES = {
    'mathematics': 'Mathematics \\& Number Theory',
    'combinatorics': 'Combinatorics \\& Probability',
    'dynamic_programming': 'Dynamic Programming',
    'strings': 'String Algorithms',
    'data_structures': 'Data Structures \\& Bitwise',
    'graph': 'Graph \\& Matrix Exponentiation',
    'game_theory': 'Game Theory',
    'misc': 'Miscellaneous',
    'contests': 'Maratona SBC \\& Contests',
}

def fetch_cses(tid):
    if tid in cses_cache and cses_cache[tid].get('statement'):
        c = cses_cache[tid]; return c['title'], c['statement'], c.get('constraints', '')
    try:
        req = urllib.request.Request(f'https://cses.fi/problemset/task/{tid}', headers={'User-Agent': 'Mozilla/5.0'})
        soup = BeautifulSoup(urllib.request.urlopen(req, timeout=15).read().decode('utf-8'), 'html.parser')
        title = soup.find('h1').get_text().strip()
        div = soup.find('div', class_='content')
        st, cons, sec = [], [], 'st'
        for el in div.children:
            if getattr(el, 'name', None) == 'h2':
                t = el.get_text().lower()
                sec = 'cons' if 'constraint' in t else ('stop' if 'example' in t else 'st')
                continue
            txt = el.get_text().strip() if hasattr(el, 'get_text') else str(el).strip()
            if not txt or sec == 'stop': continue
            (cons if sec == 'cons' else st).append(txt)
        return title, '\n'.join(st), '\n'.join(cons)
    except Exception as e:
        print('fetch fail', tid, e); return f'CSES {tid}', '', ''

def clean(s):
    for a, b in [('–','-'),('—','-'),('“','"'),('”','"'),('’',"'"),('≤','<='),('≥','>='),('…','...'),('⋅','*'),('·','*')]:
        s = s.replace(a, b)
    return s

# ---- collect sources ----
items = []
used = set()
def add(path, rel_label):
    code = open(path, encoding='utf-8', errors='ignore').read()
    if len(code.strip()) < 5: return
    base = os.path.basename(path)[:-4]
    parent = os.path.basename(os.path.dirname(path))
    m = re.match(r'^(\d{3,4})(_.*)?$', base)
    tid = m.group(1) if m and parent in ('cses', '') else None
    if tid:
        cat = CAT_BY_ID.get(tid, 'misc')
        title, st, cons = fetch_cses(tid)
        if m.group(2): title += ' (v2)'
        out = base + '.cpp'
    else:
        cat = 'contests'
        if parent.lower() in ('cses',):
            title = base.rstrip('.'); out = base.rstrip('.') + '.cpp'
        else:
            title = f'Maratona {parent} - {base}'; out = f'{parent}_{base}.cpp'
        st, cons = '', ''
    while (cat, out) in used: out = out[:-4] + '_b.cpp'
    used.add((cat, out))
    items.append(dict(cat=cat, out=out, title=clean(title), tid=tid, st=clean(st), cons=clean(cons), code=code, src=rel_label))

for p in sorted(glob.glob(os.path.join(CSES_DIR, '**', '*.cpp'), recursive=True)):
    if '\\kactl\\' in p or os.path.basename(p) == 'ConstantProgramMaker.cpp': continue
    add(p, os.path.relpath(p, CSES_DIR))
for p in sorted(glob.glob(os.path.join(CODE_DIR, '**', '*.cpp'), recursive=True)):
    add(p, 'code/' + os.path.relpath(p, CODE_DIR).replace('\\', '/'))

# ---- write content ----
shutil.rmtree(os.path.join(KACTL_DIR, 'content'), ignore_errors=True)
shutil.rmtree(os.path.join(KACTL_DIR, 'build'), ignore_errors=True)
KEYWORDS = {'if','for','while','switch','return','main','sizeof','catch','else','do','case','define','operator'}
FUNC_RE = re.compile(r'^\s*(?:template\s*<[^>]*>\s*)?(?:(?:static|inline|constexpr|const|unsigned|signed|long|struct)\s+)*[\w:<>,\*&\[\]]+(?:\s*<[^;()]*>)?[\s\*&]+(\w+)\s*\(([^;]*)$')
LAMBDA_RE = re.compile(r'^\s*(?:auto|function\s*<[^>]*>)\s+(\w+)\s*=\s*\[')
DEFINE_RE = re.compile(r'^\s*#define\s+(\w+)\(')

func_index = []  # (name, label, item)
counter = 0
for it in items:
    d = os.path.join(KACTL_DIR, 'content', it['cat']); os.makedirs(d, exist_ok=True)
    hdr = ['/**', ' * Author: Team KACTL / Marce', f" * Category: {it['cat']}", f" * Source: {it['src']}"]
    if it['tid']:
        hdr += [f" * CSES Task ID: {it['tid']}", f" * CSES Problem: {it['title']}", f" * Link: https://cses.fi/problemset/task/{it['tid']}"]
    else:
        hdr += [f" * Problem: {it['title']}"]
    hdr.append(' * Description:')
    lines = [l.strip() for l in it['st'].split('\n') if l.strip()] or [f"Implementation for {it['title']}"]
    hdr += [f' *   {l}' for l in lines]
    if it['cons']: hdr.append(' * Constraints: ' + it['cons'].replace('\n', ' '))
    hdr.append(' */\n')
    full = '\n'.join(hdr) + it['code']
    open(os.path.join(d, it['out']), 'w', encoding='utf-8').write(full)

    # build copy with invisible labels at each function definition
    blines = full.split('\n')
    for i, ln in enumerate(blines):
        if ln.lstrip().startswith(('*', '/*', '//')): continue
        name = None
        m = LAMBDA_RE.match(ln) or DEFINE_RE.match(ln)
        if m: name = m.group(1)
        else:
            m = FUNC_RE.match(ln)
            if m and m.group(1) not in KEYWORDS:
                rest = ln + ' ' + ' '.join(blines[i+1:i+3])
                if '{' in rest.split(';')[0] or ln.rstrip().endswith(')'):
                    name = m.group(1)
        if name and name not in KEYWORDS:
            counter += 1
            lab = f'fn{counter}'
            blines[i] = ln + f'(*@\\label{{{lab}}}@*)'
            func_index.append((name, lab, it))
    bd = os.path.join(KACTL_DIR, 'build', it['cat']); os.makedirs(bd, exist_ok=True)
    open(os.path.join(bd, it['out']), 'w', encoding='utf-8').write('\n'.join(blines))

print(f'{len(items)} files, {len(func_index)} function entries')

# ---- README ----
rd = ['# KACTL - Competitive Programming Library & CSES Notebook', '', 'Notebook gerado a partir das soluções do CSES e da Maratona SBC.', '', '## Table of Contents', '']
for cat, nm in CAT_NAMES.items():
    ci = [x for x in items if x['cat'] == cat]
    if not ci: continue
    rd.append(f"### {nm.replace(chr(92)+'&', '&')}")
    for x in ci:
        link = f" [CSES {x['tid']}](https://cses.fi/problemset/task/{x['tid']})" if x['tid'] else ''
        rd.append(f"- [{x['title']}](content/{cat}/{x['out']}){link}")
    rd.append('')
rd += ['## Índice de funções', '', 'O PDF (`kactl.pdf`) traz no final um índice alfabético de todas as funções com a página de cada uma.', '',
       '```bash', 'python build_kactl.py   # regenera content/, build/ e kactl.tex', 'pdflatex kactl.tex; pdflatex kactl.tex', '```']
open(os.path.join(KACTL_DIR, 'README.md'), 'w', encoding='utf-8').write('\n'.join(rd))

# ---- LaTeX ----
def esc(s):
    return s.replace('\\', r'\textbackslash{}').replace('_', r'\_').replace('&', r'\&').replace('#', r'\#').replace('%', r'\%').replace('$', r'\$')

tex = r"""\documentclass[10pt, a4paper, twocolumn, landscape]{article}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[margin=0.4in]{geometry}
\usepackage{listings}
\usepackage{xcolor}
\usepackage{titlesec}
\usepackage{hyperref}
\usepackage{fancyhdr}
\pagestyle{fancy}\fancyhf{}
\rhead{Maratona de Programação --- KACTL Notebook}\lhead{CSES \& Maratona SBC}\cfoot{\thepage}
\definecolor{codegreen}{rgb}{0,0.6,0}\definecolor{codegray}{rgb}{0.5,0.5,0.5}
\definecolor{codepurple}{rgb}{0.58,0,0.82}\definecolor{backcolour}{rgb}{0.96,0.96,0.96}
\lstdefinestyle{mystyle}{backgroundcolor=\color{backcolour},commentstyle=\color{codegreen},
 keywordstyle=\color{blue},numberstyle=\tiny\color{codegray},stringstyle=\color{codepurple},
 basicstyle=\ttfamily\tiny,breaklines=true,keepspaces=true,numbers=left,numbersep=3pt,
 showstringspaces=false,tabsize=2,extendedchars=true,escapeinside={(*@}{@*)},
 literate={á}{{\'a}}1 {é}{{\'e}}1 {í}{{\'i}}1 {ó}{{\'o}}1 {ú}{{\'u}}1 {Á}{{\'A}}1 {É}{{\'E}}1
  {Í}{{\'I}}1 {Ó}{{\'O}}1 {Ú}{{\'U}}1 {à}{{\`a}}1 {ã}{{\~a}}1 {õ}{{\~o}}1 {Ã}{{\~A}}1 {Õ}{{\~O}}1
  {ç}{{\c c}}1 {Ç}{{\c C}}1 {â}{{\^a}}1 {ê}{{\^e}}1 {ô}{{\^o}}1 {–}{{-}}1 {—}{{-}}1 {≤}{{<=}}2 {≥}{{>=}}2}
\lstset{style=mystyle}
\titleformat{\section}{\large\bfseries\color{blue}}{}{0em}{}[\titlerule]
\titleformat{\subsection}{\bfseries\color{darkgray}}{}{0em}{}
\title{\Huge \textbf{KACTL Team Notebook} \\ \large CSES Problem Set \& Maratona SBC Solutions}
\author{Team Maratona}\date{\today}
\begin{document}
\maketitle
\tableofcontents
\newpage
"""
for cat, nm in CAT_NAMES.items():
    ci = [x for x in items if x['cat'] == cat]
    if not ci: continue
    tex += f'\\section{{{nm}}}\n'
    for x in ci:
        tex += f"\\subsection{{{esc(x['title'])}}}\n"
        if x['tid']: tex += f"\\textbf{{CSES ID:}} {x['tid']} \\\\\n"
        tex += f"\\lstinputlisting[language=C++]{{build/{cat}/{x['out']}}}\n\\vspace{{0.2cm}}\n"

tex += '\\clearpage\n\\section{Índice de Funções}\n{\\small\n'
letter = None
for name, lab, it in sorted(func_index, key=lambda t: (t[0].lower(), t[2]['title'])):
    L = name[0].upper()
    if L != letter:
        letter = L; tex += f'\\par\\medskip\\textbf{{\\large {esc(L)}}}\\par\n'
    tex += f"\\noindent função \\texttt{{{esc(name)}}} {{\\scriptsize\\color{{codegray}}({esc(it['title'])})}}\\dotfill\\hyperref[{lab}]{{pág.~\\pageref*{{{lab}}}}}\\par\n"
tex += '}\n\\end{document}\n'
open(os.path.join(KACTL_DIR, 'kactl.tex'), 'w', encoding='utf-8').write(tex)
print('kactl.tex written')
