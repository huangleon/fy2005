#include <weapon.h>
inherit HAMMER;
#include <ansi.h>

void create()
{
        set_name(HIB"�Ž��ڻ�"NOR, ({ "jiujin","hammer" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�Ž��ڻ�����˵���þ��ֲ�ͬ���ʵ��ڽ����ɵĻ�����Ӳ�ȼ��ߡ�\n");
                set("value", 3000);
                set("material", "iron");
                set("level_required",150);
                set("wield_msg", "$N˫��һ�֣��ͳ�һ��$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(80);
}
