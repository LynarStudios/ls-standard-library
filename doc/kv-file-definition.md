# Key Value File - Definition #

This document defines the standard of a key value file (__.kv__).

1. A Key Value File needs to have the file extension "__.kv__".
2. A Key Value Pair, which is defined in such a file, has the following format:
   ```
   port=8080;
   ```
   The key is defined at the beginning of a line followed by an "__=__" sign for assignment.  
   The value (which is the assigment) comes write after the "__=__" sign. Please note that no quotes are required.
   To mark the end of a pair definition a semicolon "__;__" is required.
3. Every line in a __.kv__ file, which does not contain a "__=__" and a "__;__" sign, will be considered as a comment. Also, adding any text to a line after a semicolon has been set - to mark the end of a pair definition - will be ignored.
