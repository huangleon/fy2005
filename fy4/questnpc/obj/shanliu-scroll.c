#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"ɽ����"NOR, ({ "shanliu-shu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long",
"�����ֽ񽭺����Ա������˾Ȳ���Ϊ��ּ�ġ�ɽ�����������������ǵ��ܺ���Ϊ��\n�ȹ��ڵ�Ⱥħ����֮�٣�ɽ����������ɽ���飬�����º�������������֮�¡�\n"NOR);
        }
	::init_item();
}

