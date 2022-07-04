/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-07-03
 * Changed:         2022-07-03
 *
 * */

#include <iostream>
#include <vector>
#include <string>
#include <ls_std/ls_std_encoding.hpp>
#include <ls_std/ls_std_core.hpp>

using CLICommand = std::vector<std::string>;

void printHelp();
bool isValidCommand(const CLICommand &_command);

int main(int argc, char *argv[])
{
  CLICommand command(argv, argv + argc);

  if (isValidCommand(command))
  {
    if (command[1] == "--encode")
    {
      std::cout << ls::std::encoding::Base64{}.encode(command[2]) << std::endl;
    }

    if (command[1] == "--decode")
    {
      std::cout << ls::std::encoding::Base64{}.decode(command[2]) << std::endl;
    }

    if (command[1] == "--help")
    {
      printHelp();
    }
  }
  else
  {
    std::cerr << "There is an error in this command. Please use \"--help\" to get some support." << std::endl;
  }

  exit(0);
}

void printHelp()
{
  std::string help = "Base 64 CLI - " + ls::std::core::getVersion() + "\n\n";
  help += "(1) encode a string:\t\t";
  help += "--encode [string]\n";
  help += "(2) decode a string:\t\t";
  help += "--decode [string]";

  std::cout << help << std::endl;
}

bool isValidCommand(const CLICommand &_command)
{
  return _command.size() == 3 && _command[1] == "--encode" && !_command[2].empty() || _command.size() == 3 && _command[1] == "--decode" && !_command[2].empty() || _command.size() == 2 && _command[1] == "--help";
}
