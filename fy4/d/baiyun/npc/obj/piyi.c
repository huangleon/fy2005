#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIY"��ɫƤ��"NOR, ({ "brown cloth","cloth" }) );
	set_weight(13000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long","һ����ɫ��Ƥ�£���Ȼ�Ǿ�����˪�������˻�����\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	    set("value",20);

	}
	::init_cloth();
}

