#include <stdio.h>

#include "utils.h"

int main() {
    t_adjlist g = readGraph("../data/exemple_valid_step3.txt");
    display_adjlist(g);
    createMermaidFile(g, "../data/mermaid_file.txt");
    return 0;
}
