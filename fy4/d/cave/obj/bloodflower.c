inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIB"��Ѫ����"NOR,({"bloodflower"}));
  set("long", HIB
      "����һ���ڲ��������µĺڰ��гɳ��ı�Ѫ���Ļ�����ȡ����Ѫ������Ҳ��������ص�������\n�ݴ������Ĵ̿��Ƕ�����������ȡ��absorb����������������\n"NOR);
  set("value",0);
  set("unit","��");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","absorb");
}

int do_cure()
{
	object me;
	me = this_player();
    message_vision(HIB"$N����ؽ���Ѫ���ķ������У�̰���ؼ�ȡ�����еĲұ̵�֭Һ����\n"NOR,me);
	me->clear_condition();
	me->unconcious();
	destruct(this_object());
	me->unconcious();
  return 1;
}
