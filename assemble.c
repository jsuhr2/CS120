/* Very very simple MIPS assembler.  It does not support
 * labels, or most of the instructions, but should give
 * an idea of how things work.
 *
 * The program parses input lines (maximum of 50 letters on each line),
 * and then if it recognizes things, converts the instruction into hex.
 * We're using $# to mean register names (so you have $4, not $a0).
 *
 */
#include <stdio.h>

int main()
{
  int rs, rt, rd;
  char line[50];

  /* fgets is a C library routine to read a line in from input. */
  while (fgets(line, 50, stdin) > 0)
    {
     // printf("%s", line);

      /* sscanf is a "string scanf" -- formatted scanner.
       * Here, we're looking for a line that looks like a register-to-register
       * add.
       */
      int n = sscanf(line, "add $%d, $%d, $%d", &rd, &rs, &rt);
      if (n == 3)
	{
	  // The instruction is Opcode - RS - RT - RD -- Function Code.
	  // For register-to-register, the op code is always zero
	  // The function code for add is 32
	  unsigned int code = (0 << 26) | (rs << 21) | (rt << 16) | (rd << 11) | 32;
	  printf("%08x ", code);
	  // If we match this instruction, we generate the code, and then move to the bottom
	  // of the loop.  The "continue" lets us jump past the rest of the stuff inside
	  // the loop.  We could do the same sort of thing with nested if-else instructions,
	  // but the code would get a lot harder to read.
	  continue;
	}

      int immediate;
      n = sscanf(line, "addi $%d, $%d, %d", &rt, &rs, &immediate);
      if (n == 3)
	{
	  unsigned int code = (8 << 26) | (rs << 21) | (rt << 16) | (immediate & 0xFFFF);
	  printf("%08x ", code);
	  continue;
	}

      int offset;
      n = sscanf(line, "lw $%d, %d($%d)", &rt, &offset, &rs);
      if (n == 3)
	{
	  unsigned int code = (35 << 26) | (rs << 21) | (rt << 16) | (offset & 0xFFFF);
	  printf("%08x ", code);
	  continue;
	}


      // Ok.  SIMPLE HACKING.  Add in code to handle the sw, and, and sub instructions.
      // Should just be a little bit of cut-and-paste, and some tweaking.  To get
      // the function and op codes...  Look here:
      // http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html
      // Test your program on the simplified MIPS assembly code, and check against
      // what you see in the SPIM simulator!
	
      n = sscanf(line, "sw $%d, %d($%d)", &rt, &offset, &rs);
      if (n == 3)
	{
	  unsigned int code = (43 << 26) | (rs << 21) | (rt << 16) | (offset & 0xFFFF);
	  printf("%08x ", code);
	  continue;
	}

	n = sscanf(line, "and $%d, $%d, $%d", &rd, &rs, &rt);
      if (n == 3)
	{
	  unsigned int code = (0 << 24) | (rs << 21) | (rt << 16) | (rd << 11) | 36;
	  printf("%08x ", code);

	  continue;
	}

	 n = sscanf(line, "sub $%d, $%d, $%d", &rd, &rs, &rt);
      if (n == 3)
	{
	  unsigned int code = (0 << 26) | (rs << 21) | (rt << 16) | (rd << 11) | 34;
	  printf("%08x ", code);

	  continue;
	}
	 printf("  %s\n", line);
    }
}
