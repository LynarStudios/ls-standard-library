/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-07-03
 * Changed:         2023-02-22
 *
 * */

#include <iostream>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-encoding.hpp>
#include <string>
#include <vector>

using CliCommand = ::std::vector<::std::string>;

void printHelp();
bool isValidCommand(const CliCommand &_command);

int main(int argc, char *argv[])
{
  CliCommand command(argv, argv + argc);

  if (isValidCommand(command))
  {
    if (command[1] == "--encode")
    {
      ::std::cout << ls::std::encoding::Base64{}.encode(command[2]) << ::std::endl;
    }

    if (command[1] == "--decode")
    {
      ::std::cout << ls::std::encoding::Base64{}.decode(command[2]) << ::std::endl;
    }

    if (command[1] == "--help")
    {
      printHelp();
    }
  }
  else
  {
    ::std::cerr << "There is an error in this command. Please use \"--help\" to get more information." << ::std::endl;
  }

  exit(0);
}

void printHelp()
{
  ::std::string help = "Base 64 CLI - " + ls::std::core::LibraryVersion::getVersion() + "\n\n";
  help += "(1) encode a string:\t\t";
  help += "--encode [string]\n";
  help += "(2) decode a string:\t\t";
  help += "--decode [string]";

  ::std::cout << help << ::std::endl;
}

bool isValidCommand(const CliCommand &_command)
{
  return _command.size() == 3 && _command[1] == "--encode" && !_command[2].empty() || _command.size() == 3 && _command[1] == "--decode" && !_command[2].empty() || _command.size() == 2 && _command[1] == "--help";
}
