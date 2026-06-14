#!.venv/bin/python
import subprocess

builddir = 'build'
reconf = False
wipe = False

def run_meson_build(build_dir=builddir):
    # 1. Configure the build (equivalent to 'meson setup build')
    # Note: Replace 'meson' with 'python -m mesonbuild.mesonmain' if meson is not in PATH
    if reconf is False and wipe is False:
        setup_cmd = ['meson', 'setup', build_dir]
        print(f"Running: {' '.join(setup_cmd)}")
        subprocess.run(setup_cmd, check=True)
    elif reconf is True:
        setup_cmd = ['meson', 'setup', '--reconfigure', build_dir]
        print(f"Running: {' '.join(setup_cmd)}")
        subprocess.run(setup_cmd, check=True)
    elif wipe is True:
        setup_cmd = ['meson', 'setup', '--wipe', build_dir]
        print(f"Running: {' '.join(setup_cmd)}")
        subprocess.run(setup_cmd, check=True)
    else:
        raise RuntimeError("-- Uncheck either <reconf> or <wipe> to proceed --")

    # 2. Build the project (equivalent to 'ninja -C build' or 'meson compile -C build')
    compile_cmd = ['meson', 'compile', '-C', build_dir]
    print(f"Running: {' '.join(compile_cmd)}")
    subprocess.run(compile_cmd, check=True)


if __name__ == "__main__":
    run_meson_build()
