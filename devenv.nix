{
  pkgs,
  ...
}:
{
  languages.python = {
    enable = true;
    venv.enable = true;
    package = pkgs.python3;
  };

  packages = [
    pkgs.python3Packages.matplotlib
    pkgs.python3Packages.click
    pkgs.python3Packages.kaitaistruct

    pkgs.clang-tools
    pkgs.cmake
    pkgs.gcc
    pkgs.pkg-config
  ];
}
