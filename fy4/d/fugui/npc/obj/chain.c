#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
    set_name(HIY"������"NOR, ({ "gold chain" , "chain"}) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "gold");
            set("value",100);
            set("long", "һ������������ӣ����滹���Ÿ����ģ���������ֵǮ��\n");
            set("wear_msg", "$N����ذ�һ��$n���ڲ����ϡ�\n");
	    set("unwield_msg", "$N����ذ�$n�Ӳ����ϳ���������\n");
          }
	::init_neck();
}
