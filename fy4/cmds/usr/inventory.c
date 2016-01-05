//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, n;
	object *inv, ob, *inv_shown;
	string msg;
	
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	n = sizeof(inv);
	if( !n ) {
		write((ob==me)? "Ŀǰ������û���κζ�����\n"
			: ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}
	inv_shown = inv[0..26];
	
	msg = "%s���ϴ���������Щ����(���� %d%%, Я���� %d/26 )��";
	if (sizeof(inv)>26)
		msg += HIR"\n�ѳ�����Я�������14���뾡����٣�������ʧ��Ʒ����"NOR"\n%s\n";
		else 
		msg += "\n%s\n";
	
//	printf("%s���ϴ���������Щ����(���� %d%%, Я���� %d/15 )��\n%s\n",
	printf(msg,
		(ob==me)? "��": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		n,
		implode(map_array(inv_shown, "inventory_desc", this_object()), "\n") );

	return 1;
}

string inventory_desc(object obj) {
	string str, desc;
	object me, left, right;

	return sprintf("  %s%s", obj->query("equipped")? HIC "��" NOR: "  ",
			obj->short());
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	inventory[0m
[0;1;37m����������������������������������������������������������������[0m   

���г���(���)Ŀǰ������Я����������Ʒ��
һ����ҿ�Я����������Ʒ��Ϊ14��
ϵͳ�����Я������14��ʱ������ʾ����µ���Ʒ��ͬʱ�������棬
ϵͳ���������Я������17������Ʒ��
 
ע : ��ָ����� " i " ���档

[0;1;37m����������������������������������������������������������������[0m 
 
HELP
);
        return 1;
}
