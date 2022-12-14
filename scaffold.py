import argparse

template = '''#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ {name}.cpp -o {name}.out && ./{name}.out < {name}.in

void solve() {{
}}

int main() {{
    li t;
    cin >> t;
    for (li i = 0; i < t; i++) {{
        solve();
    }}
}}
'''

parser = argparse.ArgumentParser(description="scaffold boilerplate")
parser.add_argument("name", help="name of the output file")
args = parser.parse_args()

with open(f"{args.name}.cpp", "x") as f:
    f.write(template.format(name=args.name))

# create input file
open(f"{args.name}.in", "x")