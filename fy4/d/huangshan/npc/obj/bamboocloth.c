#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
//ϼ녲ʾc ��缆�� �����ƺ� ׹����ɴ
void create()
{
        set_name(CYN"��Ҷ����"NOR, ({ "surcoat" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "bamboo");
                set("unit", "��");
                set("long","һ����Ҷ��֯�ɵ��·���Ҷ�����з��ĸ��֡�\n");
        }
        ::init_surcoat();
}

