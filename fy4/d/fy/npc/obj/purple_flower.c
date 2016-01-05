// pink_cloth.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name(HIM"������"NOR, ({ "purple flower", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�߹���ŵ�������������������һ�ɵ�������ζ����\n");
		set("unit", "��");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);
	}
	::init_head();
//	call_out("wither",600);
}
void init(){
	if(!userp(environment(this_object()))){
		call_out("flower_gone", 1);
	}
	return;
}

int flower_gone(){
	message_vision("$N����Ʈ�䣬����Ѹ�ٵ�л��ת˲�䳾�鳾������������һ˿�ۼ���\n", this_object());
	destruct(this_object());
	return 1;
}
void wither(){
	call_out("flower_fade", 600);
}

void flower_fade()
{
	if (query("delivery"))
	{
		set("name","��ή��"+name());
		set("long","��ԭ����һ��"+query("long")+"���������Ѿ���ή�ˡ�\n");
		delete("delivery");
	}
}