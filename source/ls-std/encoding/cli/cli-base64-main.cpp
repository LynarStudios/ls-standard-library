/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-07-03
 * Changed:         2023-02-23
 *
 * */

#include <iostream>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-encoding.hpp>
#include <string>
#include <vector>

using ls::std::core::LibraryVersion;
using ls::std::encoding::Base64;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using CliCommand = vector<string>;

void printHelp();
bool isValidCommand(const CliCommand &_command);

int main(int argc, char *argv[])
{
  CliCommand command(argv, argv + argc);

  if (isValidCommand(command))
  {
    if (command[1] == "--encode")
    {
      cout << Base64{}.encode(command[2]) << endl;
    }

    if (command[1] == "--decode")
    {
      cout << Base64{}.decode(command[2]) << endl;
    }

    if (command[1] == "--help")
    {
      printHelp();
    }
  }
  else
  {
    cerr << "There is an error in this command. Please use \"--help\" to get more information." << endl;
  }

  exit(0);
}

void printHelp()
{
  string help = "Base 64 CLI - " + LibraryVersion::getVersion() + "\n\n";
  help += "(1) encode a string:\t\t";
  help += "--encode [string]\n";
  help += "(2) decode a string:\t\t";
  help += "--decode [string]";

  cout << help << endl;
}

bool isValidCommand(const CliCommand &_command)
{
  return _command.size() == 3 && _command[1] == "--encode" && !_command[2].empty() || _command.size() == 3 && _command[1] == "--decode" && !_command[2].empty() || _command.size() == 2 && _command[1] == "--help";
}
