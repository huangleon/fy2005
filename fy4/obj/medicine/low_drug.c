#include <condition.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("����ɢ",({"drug","depoison drug"}));
  	set("long", "���߽������������Щ���Σ�����һ����������ͨ������ҩ�ۣ�depoison��!\n");
  	set("base_value",5000);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",100);
  	set("volumn",2);
  	set_amount(2);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","depoison");
}

int do_cure()
{
	object me;
	me = this_player();
  	if (!me->query_all_condition())
		return notify_fail("��û���ж���\n");
	if  (sizeof(me->query_all_condition())<1)
		return notify_fail("��û���ж���\n");		
  	message_vision("$N��������ɢ��",me);
    me->clear_condition_type(LOW_POISON);
    
    if( sizeof(me->query_all_condition())>=1)
   		tell_object(me,"�����ϵĲ����ƺ���û����ȫ�����\n");
	else
        	tell_object(me,"������������������еĲ������о��ö��ˣ�\n",me);
  	add_amount(-1);
  	return 1;
}

