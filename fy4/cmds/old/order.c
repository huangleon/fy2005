#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string target, cmds;
	object obj;	

        if(!arg || sscanf(arg, "%s to %s", target, cmds)!=2 )
                return notify_fail("ָ���ʽ��order <����> to ������>\n");

        if( !(obj = present(target, environment(me))) || !obj->is_character())
                return notify_fail("��Ҫ��˭�����\n");

        if( !living(obj) )
                return notify_fail("��....����Ȱ�" + obj->name() +
"Ū����˵��\n");
	
	if (obj->query("acc_cmd")!=me)
		return notify_fail("�Է����󲻻����������������ӡ�\n");

	obj->ccommand(cmds);
	return 1;
}
