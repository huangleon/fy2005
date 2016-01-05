#include <condition.h>
#include <ansi.h>
inherit COMBINED_ITEM;

int do_cure(string arg);
void create()
{
  	set_name("����Ҷ",({"drug","depoison drug"}));
  	set("long", "�������������˷���Ե�һ��ҩ�ݣ�cure cough��!\n");
  	set("base_value",800);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",100);
	set("volumn",10);
  	set_amount(10);
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
  	
  	if (!arg || arg != "cough")
  		return 0;
  		
  	if (me->query_condition("cough")<1)
  		return notify_fail("��û�п��ԡ�\n");		
  		
  	message_vision("$N���´���Ҷ��",me);
    me->change_condition_duration("cough",-2);	
    
    if( me->query_condition("cough") >1)
   		tell_object(me,"��Ŀ��Ժ�һЩ�ˡ�\n");
	else
    {
        tell_object(me,"������������������еĲ������о��ö��ˣ�\n",me);
        me->change_condition_duration("cough",0);	
    }
  	add_amount(-1);
  	return 1;
}

