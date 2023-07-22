{
  description = "NetVision Test";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        lib = pkgs.lib;
      in
      {
        devShells.default = (pkgs.mkShell.override { stdenv = pkgs.llvmPackages_16.stdenv; }) {

          nativeBuildInputs = with pkgs; [
            cmake-language-server
            cmake
            ninja
            clang-tools
            gtest
            gtest.dev
          ];
          shellHook = ''
            rm -rf .build
            # Set up a local CMake build directory.
            cmake -B .build -S . -D CMAKE_EXPORT_COMPILE_COMMANDS=1

            # Link compile_commands.json back into the cwd.
            ln -sf .build/compile_commands.json .

            # Optional: Make a build. This is useful if your project has generated code, or for testing.
            cmake --build .build -j$NIX_BUILD_CORES
          '';
        };
        packages.default = pkgs.callPackage ./default.nix { };
      });
}
