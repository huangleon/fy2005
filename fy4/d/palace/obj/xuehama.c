inherit ITEM;

void create()
{
  	set_name("ѩ���",({"snowfrog","snow frog"}));
  	set("long", "����һֻ��������ѩ��󡡣\n");
  	set("value",100);
  	set("unit","ֻ");
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
	message_vision("$N��ѩ�����������������ȥ��\n",me);
	me->clear_condition();
        message_vision("$N�ĸ��ڣ�¡¡�����죡\n",me);
	destruct(this_object());
  	return 1;
}
