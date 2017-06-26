/**
 * Author: Liu Chaoyang, Sun Wei, Liu Huisen, Ma Jun
 * E-main: chaoyanglius@outlook.com
 *
 * Software License Agreement (GPL License)
 * A simple DMS system
 * Copyright (c) 2017, Northwest A&F University
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************/
#include <iostream>
#include <cstdlib>

#include "header/log_queue.h"
#include "header/server.h"

using namespace std;

// define global variable 'g_log_queue'
LogQueue g_log_queue = LogQueue();

int main(int argc, char *argv[])
{
    Server *server;
    if (argc == 1)
    {
        // use default ip and port
        server = new Server();
    }
    else
    {
        // get ip and port from command arguements
        short port = atoi(argv[2]);
        server = new Server(argv[1], port);
    }
    // start working
    server->dataMine();

    cout << "Server halt..." << endl;
    // terminate server
    delete server;
    return 0;
}

