#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(MAG"��ң����"NOR, ({ "magrobe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 3);
                set("long", @LONG
��ң��Ҵ�֮����������ң���үү������ɽ��ر���׽��һֻǧ����ϣ�����
���ñ��ϵ�˿������һ����ɫ�����ӡ�һ���ǧ�궯������Ķ��������������
�ã��������Ҳ�����⣬���۴������϶�ů��������ǹ���룬����������������     
LONG);
        }
	::init_cloth();
}
