#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"����֮��"NOR, ({ "stargem" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("value", 500);
            set("no_sell",1);
  		set("no_drop",1); 
          set("long", "һö״����ѡ���ֵ���ǵı�ʯ��Ϊ���������֮�\n");
          }
	::init_item();
}
