#include <ansi.h>
#include <armor.h>
inherit BOOTS;
//ϼ녲ʾc ��缆�� �����ƺ� ׹����ɴ
void create()
{
	set_name(WHT"�ذ׶���СЬ"NOR, ({ "shoes" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "��");
        set("female_only",1);
	}
	::init_boots();
}

