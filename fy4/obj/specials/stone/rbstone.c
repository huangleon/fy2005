#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("���ʯ", ({"rainbow stone", "stone" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "��");
		set("long", "��Ө��ʯͷ����һ����ʹ�â��ת����������ѣĿ��\n");
            	set("value", 2000000);
        }
	::init_item();
}


/* the design is bugged and thus temperary disabled.  by silencer 9/22/02

void init() {
	object me, *pros;
	me = this_player();
	pros = me->query_temp("protectors");
	if(pros) {
		pros +=  ({ this_object() });
	} else {
		me->set_temp("protectors", ({ this_object() }));
	}
}
int protection() {
	int result;
	
	result = random(4) > 0 ? 1 : 0;
	set("protected", result);
	return result;
}

string protection_msg() {
	object me = environment(this_object());
	
	return query("protected") ?  me->name() + MAG"��������ʯ�����ʺ�����ɫ��â������"NOR
			+ me->name() + MAG"��Χ��\n$N�����޷�������ϵķ�Χ�� \n"NOR
			: MAG"���ʯ������������ɫ��â���γ�һ���ⴱ��$N��Ȼ�ƴ����룡\n"NOR;
}
*/