#include <ansi.h>
#include <armor.h>
inherit NECK;
//ϼ녲ʾc ��缆�� �����ƺ� ׹����ɴ
void create()
{
	set_name("�����㴮", ({ "jasmine necklace","necklace" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "��");
        set("female_only",1);
	}
	::init_neck();
}

