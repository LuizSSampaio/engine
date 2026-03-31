{
  description = "A simple game engine project";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {inherit system;};
      in {
        devShells.default = let
          runtimeLibs = with pkgs; [
            # Audio backends
            alsa-lib
            pipewire
            pulseaudio

            # X11 stack (development headers)
            libX11
            libXext
            libXrandr
            libXcursor
            libXi
            libXfixes
            libXScrnSaver
            libXtst

            # XCB (for Vulkan/X11)
            libxcb

            # Wayland stack
            wayland
            wayland-protocols
            wayland-scanner
            libxkbcommon

            # GL / GPU
            libGL
            mesa

            # HID / USB (for SDL_HIDAPI_LIBUSB)
            libusb1
          ];
        in pkgs.mkShell {
          nativeBuildInputs = with pkgs; [
            cmake
            clang
            lldb
            lua5_4
            pkg-config
            just
          ];

          buildInputs = runtimeLibs;

          shellHook = ''
            export LD_LIBRARY_PATH="${pkgs.lib.makeLibraryPath runtimeLibs}:$LD_LIBRARY_PATH"
          '';
        };
      }
    );
}
