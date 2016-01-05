#include <ansi.h>
#include <armor.h>
inherit NECK;
//Ï¼ë…²Ê¾c Õæºç¼†Óğ ÊèÓêÔÆºÓ ×¹ÔÂĞşÉ´
void create()
{
	set_name("ÜÔÀòÏã´®", ({ "jasmine necklace","necklace" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "¼ş");
        set("female_only",1);
	}
	::init_neck();
}

