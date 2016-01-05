#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
    set_name(HIY"�ﺣ��"NOR, ({ "begonia" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ���ļ��������ﺣ�ģ�������ˡ�\n");
		set("unit", "��");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("lore", 1);
		set("female_only", 1);

	}
	::init_head();
}


void init(){

	if(this_player() != environment()) {
		add_action("do_get", "get");
	}
}


int flower_gone(){
	message_vision("$N������л�ˣ���ΪƮ����еĻ��ꡣ\n", this_object());
	destruct(this_object());
	return 1;
}

int do_get(string arg) {
	if (arg == query("id")) 
		call_out("flower_gone", 360);
	return 0;
}