#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"�Ͼ���ʯ"NOR, ({ "stone" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ö");
            set("material", "stone");
            set("jile",1);
            set("value", 500);
            set("long", "һö��ӨӨ�ı�ʯ��������ʵ�ڿ�����ʲô���á�\n");
            set("thief_obj",1);
          }
	::init_item();
}
