#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"���"NOR, ({ "jade piece","jade" }) );
    set_weight(10);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("material", "stone");
	set("item_owner","����");
	set("long", "һ����ͨ����赣������侫������Ҳûʲô�ر�֮����
������š����ˡ����֡�\n");
    }
    ::init_item();
}
