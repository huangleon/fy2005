#include <condition.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("���Ʊ�����",({"drug","depoison drug"}));
  	set("long", "����һ����������ͨ��ʹ��ҩ��,������(depoison)����!\n");
  	set("base_value",50000);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",100);
  	set("volumn",10);
  	set_amount(5);
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
  	if  (!me->query_all_condition())
		return notify_fail("��û���ж���\n");
	if  (sizeof(me->query_all_condition())<1)
		return notify_fail("��û���ж���\n");		
  	message_vision("$N�������Ʊ����衣",me);
        me->clear_condition_type(GENERIC);
        if( sizeof(me->query_all_condition())>=1)
   		tell_object(me,"�����ϵĲ����ƺ���û����ȫ�����\n");
	else
        	tell_object(me,"������������������еĲ������о��ö��ˣ�\n",me);
  	add_amount(-1);
  	return 1;
}

