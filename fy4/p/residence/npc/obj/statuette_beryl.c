#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("������", ({ "emerald statuette"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("long", "һ������ɵ������񣬿ɹ��ڵ�������װ��Ʒ���ͼ���\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("desc_ext","װ�Σ�decorate��");
	set("item_type","n");
	set("item_effect",1);
	set("size",0);
	set("value", 1000000);
	set("tax",15);
	set("score_tax",2);
}

/*
void init()
{
	::init();
	
	if (environment() != this_player())
	   	add_action("do_touch","touch");
}


int do_touch(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	mapping buff;

	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;

	message_vision(CYN"$NС���������������һ��"+name()+"��\n"NOR, me);

	if (!ANNIE_D->check_buff(me,"statue"))
	{
			buff =
			([
				"caster":ob,
				"who":me,
				"type":"statue",
				"att":"bless",
				"name":"Ϧ�ռҾӡ�"+name(),
				"buff1":"apply/perception",
				"buff1_c":10,
				"time":900,
				"buff_msg":CYN"$N"CYN"ֻ��һ�����������������壮����\n"NOR,
			]);
			ANNIE_D->buffup(buff);
	}else
		tell_object(me,"���ֱ��䣬��ʲôҲû������\n");

	return 1;
}

*/

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
