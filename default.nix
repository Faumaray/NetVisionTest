{ lib
, llvmPackages_16
, cmake
, ninja
, gtest
}:

llvmPackages_16.stdenv.mkDerivation rec {
  pname = "NetVisionTest";
  version = "0.0.1";

  src = ./.;

  nativeBuildInputs = [ cmake ninja gtest.dev gtest ];


  meta = with lib; {
    description = ''
      NetVision test project.";
    '';
    licencse = licenses.mit;
    platforms = with platforms; linux ++ darwin;
    maintainers = [ maintainers.faumaray ];
  };
}
