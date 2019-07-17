#pragma once

/*
公共头文件，统一服务器和客户端的常量定义
*/
const int MSG_LOGIN = 0; // login msg
const int MSG_REG = 1; // register msg
const int MSG_ADD_FRIEND = 2; // add friend msg
const int MSG_ONE_CHAT = 3; // one to one chat msg
const int MSG_ACK = 4; // ack msg

const int ACK_SUCCESS = 100; // msg process ok
const int ACK_ERROR = 101; // msg process err