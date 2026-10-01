import os

# ========================================================
# ÁREA DE CONTROLE (Edite rápido aqui durante a prova)
# ========================================================
CPP_TYPE = "long long"  # "int", "double", "string", etc.
DIMS = [11, 11]         # Tamanhos. 1D: [100], 2D: [11, 11], 3D: [5, 5, 5]...

def fmt(val):
    """ Formata a saída. Use str(val) para int, f'{val:.6f}' para double. """
    return str(val)

def solve(*args):
    """ Sua função bruta. Acessa os parâmetros via args[0], args[1]... """
    # Exemplo: args[0] = a, args[1] = b
    return args[0] * args[1]

# ========================================================
# MOTOR GERADOR (Recursivo - Suporta infinitas dimensões)
# ========================================================
def build(dims, args=()):
    if not dims: return fmt(solve(*args))
    
    # Chama a si mesmo pra montar a matriz N-dimensional
    elementos = [build(dims[1:], args + (i,)) for i in range(dims[0])]
    
    # Quebra a linha apenas no nível mais externo para não bugar o editor de texto
    sep = ",\n" if len(dims) == len(DIMS) else ", "
    return "{" + sep.join(elementos) + "}"

# Monta o '[N][M]...' da variável C++
str_dims = "".join(f"[{d}]" for d in DIMS)

cpp_code = f"""#include <bits/stdc++.h>
using namespace std;

{CPP_TYPE} ans{str_dims} = {build(DIMS)};

int main() {{
    // Use ans[a][b]...
    return 0;
}}
"""

# Salva e testa o tamanho
with open("sol.cpp", "w") as f: f.write(cpp_code)
kb = os.path.getsize("sol.cpp") / 1024
print(f"Gerado! Tamanho: {kb:.2f} KB | " + ("SEGURO (<= 64KB)" if kb <= 64 else "ALERTA: ARQUIVO GIGANTE"))