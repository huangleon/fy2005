#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"��¶��ʯ"NOR, ({"topaz", "huangshi", "yellow stone" }));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "��");
		set("long", "
�������֮Ӣ�۳ɵ���ˮʯ����������Ө������ȴ˿˿�����̷���
ϸϸ��ˮ������ʯ�棬�����پۡ�\n");
            	set("value", 200);
		set("imbue", 1);
		set("lore", 1);
        }
	::init_item();
}


