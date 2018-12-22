//
//  main.cpp
//  datastructure
//
//  Created by duchunhui on 2018/10/8.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#include <iostream>
#include "seqList.hpp"
#include "sLinkList.hpp"
#include "dLinkList.hpp"
#include "seqStack.hpp"
#include "linkStack.hpp"
#include "seqQueue.hpp"
#include "linkQueue.hpp"
#include "calc.hpp"
#include "binaryTree.hpp"
#include "childBrotherTree.hpp"
#include "graph.hpp"
#include "adjListGraph.hpp"
#include "simulator.h"


using namespace std;

int main() {
    simulator sim;
    cout << sim.avgWaitTime();
    return 0;
}
