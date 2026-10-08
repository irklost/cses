#!/usr/bin/env python3

import subprocess
import sys
from pathlib import Path

cwd = Path.cwd()
tests = Path(str(cwd) + "/tests")

cxx = "clang++"
src = "main.cpp"
target = "main"

def get_test_count():
    test_count = 0
    for path in tests.iterdir():
        if path.is_file() and path.suffix in [".in",".out"]:
            test_count += 1
    test_count //= 2
    return test_count

def build():
    result = subprocess.run([cxx,src, "-o", target], capture_output=True, text=True)
    if result.returncode != 0:
        print("Compilation Error:")
        print(result.stderr)
        sys.exit(1)

def run_tests():
    test_count = get_test_count()
    for t in range(1,test_count+1):
        stem = str(t)
        inp = Path(f"tests/{t}.in")
        out = Path(f"tests/{t}.out")
        given = inp.read_text(encoding="utf-8")
        want = out.read_text(encoding="utf-8")
        run_result = subprocess.run([f"./{target}"],input=given,capture_output=True,text=True)
        got = run_result.stdout
        want = want.split()
        got = got.split()
        if not (want==got):
            print(f"Test #{t} failed.")
            sys.exit(1)
    print("All tests passed.")

def clean():
    fp = Path(target)
    fp.unlink(missing_ok=True)

def main():
    build()
    run_tests()
    clean()

    return 0

if __name__ == "__main__":
    main()
