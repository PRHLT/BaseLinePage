/*
 *   Copyright 2013, Jorge Martinez Vargas ( jormarv5@fiv.upv.es )
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 * 
 *      Author: Jorge Martinez Vargas ( jormarv5@fiv.upv.es )
 */

#include <QtWidgets/QApplication>

#include <unistd.h>
#include <iostream>

#include "mainwindow.h"

//#include "document.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    char* filename=0;

    bool single;
    if(argc==2){
        single = true;
        filename = argv[1];
    }else{
        int option;
        while ((option=getopt(argc,argv,"l:"))!=-1)
            switch (option)  {
            case 'l':
                single = false;
                filename=optarg;
                break;
            default:
              cerr << "Unknown parameter : -" << option << " " << optarg << endl;
            }
    }
    MainWindow w(filename,single);
    w.show();
    
    return a.exec();
}
