#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("����ױ̨", ({ "dressing table"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ������ӯӯ������ױ̨��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","n");
	set("size",1);
	set("value", 100000);
set("tax",10);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_makeup","makeup");
}



int do_makeup(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (me->is_fighting() || me->is_busy()) return 1;
	if (me->query("gender") != "Ů��")
		return notify_fail("������ŤŤ�����ױ����ô��\n");
	message_vision(CYN"$N����ױ̨ǰ������������ϸ�ش�����Լ���\n"NOR, me);
	// ��ü?
	if (!me->query_temp("annie/prup"))
		me->add_temp("apply/personality",1);
	me->set_temp("annie/prup",1);
	me->perform_busy(1);
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
