#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(RED"���ɮ��"NOR, ({ "red cloth","cloth" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "cloth");
        set("long", "����һ�����ﴩ�ĺ��ۡ�\n");
        set("armor_prop/armor", 10);
    	set("value",400);
    }
    ::init_cloth();
}
