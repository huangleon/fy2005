//  An example non-weapon type of weapon
// fist,fist1,fist2....����Խ�ߣ�dmgԽ��

#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
    set_name(HIY"����"NOR+HIW"��צ"NOR, ({ "gold claw","claw" }) );
    set_weight(3000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "����һ�Ե��Ž�ɫ���Ƶİ���צ������ϸ�¾��ɣ���Ȼ���˲���Ѱ���˵ȡ�\n");
	set("value", 1);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
