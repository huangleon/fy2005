// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name("����ɳ" , ({ "hu boots","boots" }) );
      set_weight(100);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
        set("long", "�������д����������һ��Ƥѥ��ʽ�����أ��ֹ����¡�\n");
        set("value", 1000);
        set("armor_prop/armor", 5 );
	}
	::init_boots();
}
