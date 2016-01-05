#include <ansi.h>
inherit COMBINED_ITEM;

int do_cure(string arg);

void create()
{
	set_name("����ɢ", ({ "pill" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
      	set("long","�����ɺ��ӻ��������Ƶ�����ɢ��������ʲô���Ķ��Σ�
���������ܰ�Ȼ���(cure malaria)��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 2000);
		set("volumn",1);
	}
	set_amount(5);
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}


int do_cure(string arg)
{
  	object me = this_player();
	
		
	if (!arg || arg != "malaria")	
		return 0;
		
	message_vision("$Nȡ��һ������ɢ������ȥ��\n",me);
	tell_object(me,"������������㣬�������\n");
	me->set_temp("maze/�һ�������ɢ",1);     
	if (me->query_condition("mag_mushroom")) {
		me->change_condition_duration("mag_mushroom",-5);
		if(me->query_condition("mag_mushroom")>1)
   			tell_object( me, "���е��ζ�������һЩ������û����ȫ�����\n",me);
		else
	    {
	    	tell_object(me, "���������е��ζ���������ˣ�\n",me);
	    	me->change_condition_duration("mag_mushroom",0);
	    }
	}	
  	add_amount(-1);
  	return 1;
}