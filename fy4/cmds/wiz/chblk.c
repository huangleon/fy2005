// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("ָ���ʽ��chblk name \n");
    
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("����˲��ڣ�\n");
	if (wizardp(ob)) return notify_fail("���ܹر���ʦ��Ƶ����\n");
	ob->set("chblk_on",1);	
	tell_object(me, (string)ob->query("name")+"��Ƶ�����ر��ˡ�\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	chblk <ĳ��> [0m
[0;1;37m����������������������������������������������������������������[0m   

������ر�ĳ�˵�����Ƶ����
�����������������򣬣�����������ͣ�����

������� unchblk

[0;1;37m����������������������������������������������������������������[0m    
HELP
    );
    return 1;
}
