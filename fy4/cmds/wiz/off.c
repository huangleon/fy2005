// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        {
        if(CHANNEL_D->query("block_chat"))
                write("chat     off\n");
        else    write("chat     on\n");
        if(CHANNEL_D->query("block_rumor"))
                write("rumor    off\n");
        else    write("rumor    on\n");
        if(CHANNEL_D->query("block_fy"))
                write("fy       off\n");
        else    write("fy       on\n");
        if(CHANNEL_D->query("block_new"))
                write("new      off\n");
        else    write("new      on\n");

        return 1;

        }

   if( arg == "rumor" || arg == "chat" || arg == "fy" || arg == "new")
	{
	CHANNEL_D->set_block(arg,1);
	EMOTE_D->set_block(arg,1);
	}
	else
	return notify_fail(" channel_name ֻ������ rumor, chat, fy,��new�е�һ����\n"); 

	tell_object(me, arg+"Ƶ�����ر��ˡ�\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	off <Ƶ��> [0m
[0;1;37m����������������������������������������������������������������[0m   

������ر�ĳ��Ƶ����Ƶ�������� rumor, chat, fy,��new�е�һ����

������� on 

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
