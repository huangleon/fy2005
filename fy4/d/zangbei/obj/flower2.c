#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        string *flower_name=({ "�ҽ���","������","��ͷ��","ˮ�ɻ�"}) ;
        set_name(flower_name[random(sizeof(flower_name))], ({"flower"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ѥ�ÿ��ŵ��ʻ���\n");
                set("unit", "��");
                set("value", 10);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);
		
        }
        	::init_head();

}


