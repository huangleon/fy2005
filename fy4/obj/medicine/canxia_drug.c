#include <condition.h>
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name(HIG"������¶"NOR,({"yueming"}));
  	set("long", "����һ���������ֵ�ҩ�࣬����������������ϼ(cure canxia)��\n");
  	set("base_value",80000);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",100);
  	set("volumn",10);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}

int do_cure(string arg)
{
	object me;
	me = this_player();
  	if (!arg || arg!="canxia")	return 0;
  	  	
  	if (me->query_condition("canxia")<1)
  		return notify_fail("��û����������ϼ��\n");
  			
  	message_vision("$N����������¶��",me);
  	me->change_condition_duration("canxia",0);
    tell_object(me,"���е�������ϼ����ȥ�ˡ�\n");
    add_amount(-1);
  	return 1;
}

