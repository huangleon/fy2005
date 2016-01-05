// help.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

void selete_main(string num,object ob);
void back_off(string num,object ob);
void quit_help(object ob);

int main(object me, string arg)
{
        int i;
        string file, map, *search;
        object ob;
        ob = this_player();

        write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main", ob);
        ob->set_temp("block_msg/all",1);
        return 1;
}

void selete_main(string num,object ob)
{
        
        string *code = ({"1","2","3","4","5","6","7","8"});
                
        if(member_array(num, code) != -1)
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                write(read_file("/doc/help/help/cmds_"+num+".txt"));
                input_to("back_off",ob);
        }
        else if( num == "q" || num == "Q" || num == "0") quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n    �Բ���û�����ѡ�������ѡ��\n"NOR);
                write(CYN"  ����- 8 ��ص�����˵������0���˳�����\n"NOR);
                write(CYN"\n    ������ѡ���1-8 �� 0����"NOR);
                ob->set_temp("block_msg/all");
                input_to("selete_main", ob);
        }
}

void back_off(string num,object ob)
{
	write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main", ob);
        ob->set_temp("block_msg/all",1);
}

void quit_help(object ob)
{
        ob->delete_temp("block_msg/all");
     	write(HIC"\n ллʹ�÷����������ϵͳ����һ����˵���ɲμ����������\n\n"NOR);
        return;
}

int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 		cmds[0m
[0;1;37m����������������������������������������������������������������[0m   

������������������ҿ���ʹ�õ����������б�
�밴����Ļ��ʾ����ѡ���Խ����Ӳ˵���

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
        return 1;
}

