#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("С��", ({ "mini pagoda"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ��СС��ʯ�����������й����Ƕ�����۵�����\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","n");
	set("size",1);
set("tax",10);
set("score_tax",1);
	set("value", 100000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_kneel","kneel");
}

int do_kneel(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;
	if(me->query("sen") <=20)
		return notify_fail("����񲻹���\n");
	message_vision("$N����С��Ĥ����һ�¡�\n" ,me);
	if( me->query("bellicosity") > 0)
	   me->set("bellicosity",0 );
	message_vision("$N���ϵ�ɱ��֮���ƺ�һ˲���������Ρ�\n" , me);
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
