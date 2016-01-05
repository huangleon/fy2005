// bat_drug.c

inherit COMBINED_ITEM;

int do_cure(string arg);

void create()
{
    	set_name("�߲����𶾽�ҩ", ({ "bat drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
      	set("long", "����һ���������߲����𶾵�ҩ�����Խ��߲�����(cure 7batpoison)\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 1000);
		set("volumn",20);
	}
	set_amount(20);
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
  	
  	if (!arg || arg!= "7batpoison")
  		return 0;
  		
 	if  (((int) me->query_condition("qicaibat")) <= 0)
  		return notify_fail("��û�����߲����𶾡�\n");
  	message_vision("$N���½�ҩ����ʱ�о��ö��ˡ�",me);
        me->change_condition_duration("qicaibat",-5);
  	  	
  	if(me->query_condition("qicaibat")>1)
    	tell_object(me,"�������е��߲����𶾲�û����ȫ�����\n");
  	else	
  	{
       	tell_object(me,"������������������е��߲����𶾣�\n");
       	me->change_condition_duration("qicaibat",0);
    }
  	add_amount(-1);
  	return 1;
}


