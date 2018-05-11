#ifndef SHUDOCRACKER
#define SHUDOCRACKER
#include <vector>
#include <string>
class ShudoCracker {
    public:
        enum {
            mazeTypeStd,
            mazeTypeX,
            mazeTypeColor,
            mazeTypeHyper,
            mazeTypePercent,
        };
        static bool crack(const int (&src_maze)[9][9],
                int (&dst_maze)[9][9],
                const int mazeType);
        static const std::vector<std::string> mazeTypes;
    private:
        ShudoCracker();
        static bool isMazeValid(const int (&maze)[9][9]);
        static bool isPositionValid(const int (&maze)[9][9],
                const int y, const int x,  const int value,
                const int mazeType);
        static void coreCrack(
                const int (&src_maze)[9][9],
                int (&dst_maze)[9][9],
                const int y, const int x,
                const int mazeType,
                bool & isSolved);
};

#endif // SHUDOCRACKER
