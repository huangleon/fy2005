inherit ITEM;
#include <ansi.h>
#include <condition.h>

void create()
{
  	set_name(MAG"���̲�"NOR,({"ziyan","ziyan grass"}));
  	set("long", "һ��ͨ����̵�С�ݣ���Ҷ�ı���΢΢͸����ɫ����˵���Խ�ĳһ���涾�������壩��\n");
  	set("value",100);
  	set("unit","��");
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure", "cure");
}

int do_cure()
{
	object me;
	me = this_player();
	message_vision("$N�����̲�ϸϸ����������ȥ��\n",me);
	if (me->query_condition("canxia"))
		tell_object(me,"���е�"MAG"������ϼ"NOR"������ʧ�ˡ�\n");
	me->change_condition_duration("canxia",0); 
	destruct(this_object());
        return 1;
}


