//  An example non-weapon type of weapon
// fist,fist1,fist2....����Խ�ߣ�dmgԽ��

#include <weapon.h>
inherit FIST;
void create()
{
    set_name("÷����", ({ "meihua fist","fist" }) );
    set_weight(1500);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "����һ�Դ��쾫�µ�÷���ۣ�ָ�״�����ĥ��ʮ�ֹ⻬��һ����֪����������֮��\n");
	set("value", 1);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
