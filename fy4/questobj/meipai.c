#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��÷��"NOR, ({ "duanmei-bi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "֧");
            set("material", "wood");
            set("long", "�꺮����֮��÷�������������һ֦��÷����˵���Ǻ�÷����ʱ��\n��ɽŮ�ӵĶ���֮���ϧ�鲻�٣�÷�Ѷϡ���\n");
          }

    ::init_item();
}
