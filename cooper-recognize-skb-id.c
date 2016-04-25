//算法思想：遍历应用层缓冲区，删除网络包ID，还原真实数据
//输入:{xxxx1460725892380380972xxxx}abcdefgh{xxxx1460725892380382340xxxx}mnopqrst
//		其中，xxxx表示int类型的0x81828384
//输出:abcdefghmnopqrst

recognize_skb_id(char *buffer, int data_length){
	int prev=0,i=0;
	while(prev<data_length){
		//发现网络包ID结构体 
		if(buffer[i]=='{' && (int)buffer[i+1]==0x81828384){
			process_skb_id(buffer+i);
			i += 29;	//29为网络包ID结构体的长度
		}else{
			if(prev<i)
				buffer[prev++]=buffer[i++];	//从后向前移动数据
		}
	}
}
