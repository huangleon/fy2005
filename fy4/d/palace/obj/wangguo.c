inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"�����"NOR,({"wangguo"}));
  set("long", HIG
      "����һ������������������Ϊ�˼�����ǰ��ʹ��\n"
      "�������ѣ����壩�Ķ�����\n"NOR);
  set("value",100);
  set("unit","��");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","die");
}

int do_cure()
{
	object me;
	me = this_player();
	message_vision("$N�������һ��������ȥ��\n",me);
	me->clear_condition();
	me->unconcious();
	destruct(this_object());
	return 1;
}
