#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;

        if(!arg)
                return notify_fail("����help�鿴��ָ���÷���\n");
        ob=find_player(arg);
        if(!ob)
			return notify_fail("��ָ��ֻ�ܶ��������ʹ�á�\n");

        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
			link_ob->set("blocked",1);
			link_ob->save();
			destruct(ob);
			write("BLOCK��Ok.\n");
			return 1;
        }
        return notify_fail("Unknown error.\n");
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	block ID[0m
[0;1;37m����������������������������������������������������������������[0m   

ʹ�����ָ�����һ������ʺţ��ڽ�����ǰ���˺Ž��޷���½��

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
