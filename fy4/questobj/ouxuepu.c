#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"ŻѪ��"NOR, ({ "ouxue-pu" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", HIR"�ഫһ����ʥ���ٸ�����ɽ��һ������������һ�ٶ�ʮ�ţ���ɱ�ô�ܣ���ʱŻѪ
��������������ǧ�����֡�\n"NOR);
          }

    ::init_item();
}
