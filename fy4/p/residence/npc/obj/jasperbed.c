#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("����", ({ "jasper bed"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ�鳤���������ʯ������ֻ�����Ų�ϯ��һ���ײ�����������laydown��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","o");
	set("size",1);
	set("tax",80);
	set("score_tax",10);
	set("value", 2000000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_laydown","laydown");
}


int do_laydown(string arg)
{
	   object me, obj, girl;
	   int gin, kee, sen;
		mapping buff;
		function f;
	
	   me = this_player();
	   obj = this_object();
	   if (!environment(me)->is_owner(me->query("id")))
			return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	   if (me->is_fighting() || me->is_busy()) {
	   		tell_object(me,"��������æ���ء�\n");
	   		return 1;
	   }
	   if (query_temp("marks/taken")) {
	      tell_object(me, "��������Ү��������\n");
	      return 1;
	   }
	  message_vision("$N�������ں����ϡ�\n", me);
	  tell_object(me, "��ֻ�����Ǳ������������ˡ�\n");
	  set_temp("marks/taken", 1);
	  me->perform_busy(5);
	  call_out("curePlayer",10,me);
      return 1;
}

void curePlayer(object me)
{
	if (!me) return;
	set_temp("marks/taken", 0);
	if (environment(me) == environment())
	{
		tell_object(me,WHT"���������ú�����ȥ���о���ͷ������ů������֮����Ϣ��ת��ͣ��\n "NOR);
		if(me->query("eff_kee") != me->query("max_kee"))
		{
			tell_object(me,WHT"�����ϵ����ƾ������غ��ˣ�\n"NOR);
			me->set("eff_kee",me->query("max_kee"));
		}
		message_vision("$N�Ӵ��ϻ�������������\n",me);
	}
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
