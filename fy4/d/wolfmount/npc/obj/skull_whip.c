#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIW"���Ǳ�"NOR, ({ "wolf whip","whip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 15000);
                set("long", "һ��������������ޡ�����ÿ�����߾���ʮ��ֻ���λεļ�����������ͷ����
һ��������������ͷ��\n");
                set("material", "skin");
		set("weapon_prop/courage",5);
		set("rigidity", 10000);
		set("experience",5000000);
        	set("wield_msg", "$N����������һ��һ����ͻȻ�ɳ�����Ҳ�Ƶ�һ���������������С�\n");
        	set("unwield_msg", "$N�����е�$n�������䡣\n");
        }

        ::init_whip(140);
}


int query_autoload() { return 1; }