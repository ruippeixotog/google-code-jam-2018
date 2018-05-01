# Google Code Jam 2018

This repository contains my solutions to the problems from [Google Code Jam 2018][1] and Distributed Google Code Jam 2018. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all Google Code Jam problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

Distributed Google Code Jam problems should be compiled and run using the local testing tool described in the [guide][2]. An example would be:

    $ dcj test --source <round_name>/<problem_id>.cpp --nodes <number_of_nodes>

You'll need to have an input header file with the name `<problem_id>.h` in the same directory as the source file. You can download sample inputs from each problem's page.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Practice Session

* ✓ [A. Number Guessing][prac1] (`number-guessing`)
* ✓ [B. Senate Evacuation][prac2] (`senate-evacuation`)
* ✓ [C. Steed 2: Cruise Control][prac3] (`steed2-cruise-control`)
* ✓ [D. Bathroom Stalls][prac4] (`bathroom-stalls`)

### Qualification Round

* ✓ [A. Saving The Universe Again][qual1] (`saving-the-universe-again`)
* ✓ [B. Trouble Sort][qual2] (`trouble-sort`)
* ✓ [C. Go, Gopher!][qual3] (`go-gopher`)
* ✓ [D. Cubic UFO][qual4] (`cubic-ufo`)

### Round 1A

* ✓ [A. Waffle Choppers][round1a1] (`waffle-choppers`)
* ✓ [B. Bit Party][round1a2] (`bit-party`)
* ✓ [C. Edgy Baking][round1a3] (`edgy-baking`)

### Round 1B

* ✓ [A. Rounding Error][round1b1] (`rounding-error`)
* ✗ [B. Mysterious Road Signs][round1b2] (`mysterious-road-signs`)
* ✓ [C. Transmutation][round1b3] (`transmutation`)

[1]: https://code.google.com/codejam
[2]: https://code.google.com/codejam/resources/quickstart-guide#dcj
[prac1]: https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard
[prac2]: https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/00000000000004c0
[prac3]: https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000524
[prac4]: https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000652
[qual1]: https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
[qual2]: https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
[qual3]: https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30
[qual4]: https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cc
[round1a1]: https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard
[round1a2]: https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard/000000000002fff6
[round1a3]: https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard/000000000002fff7
[round1b1]: https://codejam.withgoogle.com/2018/challenges/0000000000007764/dashboard
[round1b2]: https://codejam.withgoogle.com/2018/challenges/0000000000007764/dashboard/000000000003675b
[round1b3]: https://codejam.withgoogle.com/2018/challenges/0000000000007764/dashboard/000000000003675c
