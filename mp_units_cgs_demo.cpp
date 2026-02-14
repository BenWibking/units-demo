#include <iostream>

#include <mp-units/systems/cgs.h>
#include <mp-units/systems/si.h>

using namespace mp_units;

namespace cgs_gaussian {

inline constexpr struct gauss final
    : named_unit<"G", pow<1, 2>(cgs::gram) / (pow<1, 2>(cgs::centimetre) * cgs::second)> {} gauss;
inline constexpr struct code_gauss final : named_unit<"code_G", gauss / pow<1, 2>(mag<4> * π)> {} code_gauss;

namespace unit_symbols {
inline constexpr auto G = gauss;
inline constexpr auto code_G = code_gauss;
}  // namespace unit_symbols

}  // namespace cgs_gaussian

int main()
{
  // fractional unit example
  const auto asd = 3.0 * inverse(pow<1, 2>(si::hertz));  // Hz^(-1/2), amplitude spectral density unit

  // CGS-Gaussian units examples
  const auto magnetic_field = 125.0 * cgs_gaussian::unit_symbols::G;
  const auto code_magnetic_field = 125.0 * cgs_gaussian::unit_symbols::code_G;
  const auto magnetic_energy_density_code = 0.5 * code_magnetic_field * code_magnetic_field;  // 0.5 * B^2

  std::cout << "  ASD unit sample  = " << asd << "\n\n";
  std::cout << "Electromagnetic quantities:\n";
  std::cout << "  magnetic field   = " << magnetic_field << '\n';
  std::cout << "  code B field     = " << code_magnetic_field << '\n';
  std::cout << "  u_B = 0.5*B^2    = " << magnetic_energy_density_code.in(square(cgs_gaussian::unit_symbols::code_G))
            << " = " << magnetic_energy_density_code.in(cgs::barye) << '\n';

  return 0;
}
