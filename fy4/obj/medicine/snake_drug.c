inherit COMBINED_ITEM;

void create()
{
  	set_name("��ҩ",({"drug","snake drug"}));
  	set("long", "����һ���������߶���ҩ,������(cure)�����߶�!\n");
  	set("base_value",500);
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

int do_cure()
{
	object me;
	me = this_player();
  	if  (((int) me->query_condition("snake_poison")) <= 0)
		return notify_fail("��û�����߶���\n");
  	
  	message_vision("$N������ҩ����ʱ�о��ö��ˡ�",me);
        me->change_condition_duration("snake_poison",-2);
  	 	 	
  	if(me->query_condition("snake_poison")>1)
   		message_vision("����$N�е��߶���û����ȫ�����\n",me);
	else
    {
    	message_vision("$N����������������е��߶���\n",me);
    	me->change_condition_duration("snake_poison",0);
    }
    	
  	add_amount(-1);
  	return 1;
}

