#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIW"�̶�"NOR, ({ "yandou" }) );
   	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "����һ������ͨ���̶�������װ�����̲ݣ������ϲ�����Գ飨�����壩���ڡ�\n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N�ӻ���ĥĥ�����ͳ�һ��$n�������С�\n");
        	set("unwield_msg", "$N�����е�$n����������\n");
	}
    	::init_hammer(20);
}


void init(){
	if (userp(environment(this_object())))
		add_action("do_smoke","smoke");
	return;
}



int do_smoke(){
	message_vision(WHT"$N�����̶����������鼸�£��������˿�����������ѽ����\n"NOR,this_player());
	if (!this_player()->query_condition("cough"))
		this_player()->apply_condition("cough",random(10)+10);
	return 1;
}


