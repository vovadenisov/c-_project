#include "wrapper.h"

wrapper::wrapper(): sendBufSize(0), sendBuf(NULL), realSize(0){}

void wrapper::add(string name, string value){
    name_set[name] = value;
}

wrapper::~wrapper(){
    delete[] sendBuf;
}

void wrapper::pack(string name, uint8_t* data, int dataSize){
    //формирование открывающего тега и длины данных
    string start = name_set[name];
    stringstream ss;
    ss << dataSize;
    string length = " " + ss.str();
    start.insert(start.length() - 1, length);
    int startLen = start.size();
    if (realSize < dataSize + startLen){
        delete[] sendBuf;
        sendBuf = new uint8_t[dataSize + startLen];
        if (sendBuf != 0){
            realSize = dataSize + startLen;
        }
        else{
            realSize = 0;
            sendBufSize = 0;
            return;
        }
    }
    sendBufSize = dataSize + startLen;
    memcpy(sendBuf, start.c_str(), startLen);
    memcpy(sendBuf + startLen, data, dataSize);
}

void wrapper::pack(string name){

    return ;
}

int wrapper::DataCont::find(string search){
    int searchSize = search.size();
    for(int i = 0; i < size - searchSize + 1; i++){
        bool find = true;
        if(((char*)current)[i] == search[0]){
            for (int j = 0; j < search.size(); j++){
                if ( search[j] != current[i + j]){
                    find = false;
                    break;
                }
            }
            if( find ){
                return i;
            }
        }
    }
    return string::npos;
}

bool wrapper::find(int& posStart, int& posEnd, DataCont& buf, int& data){
    posStart = buf.find("<");
    if(posStart == string::npos){
        return false;
    }
    posEnd = buf.find(">");
    if(posEnd == string::npos){
        return false;
    }
    if (posStart != 0){
        buf.erase(posStart);
        posStart = 0;
    }
    data += posEnd + 1;
    return true;
}

bool wrapper::DataCont::erase(int shift){
    if (shift < size ){
        current = current + shift;
        size -= shift;
        return true;
    }
    return false;
}

wrapper::DataCont::DataCont(){
    current = NULL;
    size = 0;
    realSize = 0;
}

wrapper::DataCont::~DataCont(){}

void wrapper::DataCont::take(uint8_t* data, int comSize){
    size = comSize;
    realSize = comSize;
    current = data;
}

bool wrapper::DataCont::empty(){
    return !size ? true : false;
}

string wrapper::DataCont::getConstStr(int start, int end){
    if (end < start){
        return NULL;
    }
    string buf = "";
    for (int i = start; i < end - start; i++){
        buf += (char)(((char*)current)[i]);
    }
    return buf;
}

void wrapper::unpack(uint8_t* pack, int& size){
    try{
    cout << "вход в функцию unpack size: " << size << endl;
    command.clear();
    dataCont.take((uint8_t*)pack, size);
    int pos = 0;
    int positionStart = 0;
    int positionEnd = 0;
    int counter = 0;
    if (trash){
        dataCont.erase(trash - 1);
        trash = 0;
    }
    while(!dataCont.empty()){
        counter++;
        if(counter > 50){
            counter = 0;
            cout << "beda" << endl;
            cout << "size: " << size << " pack: " <<  pack << endl;
        }
        cout << "wrapper" << endl;
//        while(1){
//            if (!wrapper::find(positionStart, positionEnd, dataCont, pos)){
//                return;
//            }
//            if(positionEnd - positionStart > 30){
//                dataCont.erase(positionStart);
//            }
//            else{
//                break;
//            }
//        }
        if (!wrapper::find(positionStart, positionEnd, dataCont, pos)){
            return;
        }
        if(positionEnd - positionStart > 30){
            return;
        }
        cout << "posStart: " << positionStart << " posEnd: " << positionEnd << endl;
        if(positionEnd > 30){
            return;
        }
        string comm(dataCont.getConstStr(0, positionEnd + 1));
        cout << "comm: " << comm << endl;
        int posLength = 0;
        int length = 0;
        //если есть пробел означающий наличие данных
        posLength = comm.find(" ");
        cout << "posLen: " << posLength << endl;
        if (posLength != string::npos){
            //получаем длину данных
            length = atoi(string(comm.begin() + posLength + 1, comm.end() - 1).c_str());
            cout << "получаем длину данных: "<< length << endl;
            //проверка, что все данные поместились в пакет
            if (length + comm.size() > dataCont.size){
                cout << "не полный пакет" << endl;
                return;
            }
            //убираем пробел и числа
            comm.erase(comm.begin() + posLength, comm.end() - 1);
            cout << "команда без чисел: " << comm << endl;
        }
        //смещаем указатель на позицию окончания данных
        if(!dataCont.erase(positionEnd + length)){
            trash = positionEnd + length - dataCont.size;
            cout << "битый пакет при удалении" << endl;
            return;
        }
        pair<string, pair< int, uint8_t* > > value;
        value.first = "";
        value.second.first = 0;
        value.second.second = NULL;
        //выбираем соответствующую команду и записываем ее в массив команд
        for (map<string, string >::iterator i = name_set.begin();i != name_set.end(); i++){
            //если комманда совпала
            if (i->second == comm){
                value.first = i->first;
                value.second.first = length;
                value.second.second = pack + pos;
                cout << "записана команда: " << value.first <<  " размер данных: " << value.second.first << endl;
            }
        }
        if(value.first != ""){
            command.push_back(value);
            //cout << command.back().first << " size: " << command.back().second.first << endl;
        }
    }
    }
    catch(...){}
}


