#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("�ؾ�", ({ "silk sheet", "sheet"}) );
	set_weight(100);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("value", 0);
        set("long",
"һ���ؾ����д�ţ�
������֪�������ӣ�����Ը��������·�ĺ������ܽ���������ɺ���ͬ������
Сľ���� ������ͬ�ޣ�����ͬڣ����\n"NOR);
        }
	::init_item();
}
