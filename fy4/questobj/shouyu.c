// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"��������"NOR,({ "shouyu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֽ");
                set("material", "paper");
                set("long", "����һ�ſհ׵ķ���ר�����ͼ㡣\n");
        }
	::init_item();
}
