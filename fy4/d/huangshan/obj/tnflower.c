#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��Ů��"NOR, ({ "angel flower", "��Ů��" }) );
    set_weight(3);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    	set("unit", "��");
        set("long", "������Ƭ������ɣ�������Ƭ�����ۺ�ɫ�������ɫ��΢΢�ſ�����׵��š�
���������������Ů������ɴ���������衣\n");
		set("value", 3000);
    }
	::init_item();
}
