// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"���ر���"NOR, ({ "ice" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "ice");
            set("long", "һ���͸���������������������ɢ�����ĺ�����\n");
			set("real",1);
			set("value",1000);
          }
	::init_item();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		call_out("freeze",3,me);
}

void freeze(object me)
{
	if (environment() == me || environment(environment()) == me)
	{
		tell_object(me,HIW"���ر������㻳��ɢ��˿˿��������\n");
		message_vision(NOR WHT"$N��Ȼ����һ�����������ݸ�����졣\n"NOR,me);
		me->set_temp("last_damage_from","���˺��춳���ˡ�");
		me->receive_damage("kee",300);
		me->start_busy(1+random(2));
		call_out("freeze",11,me);
	}
}
