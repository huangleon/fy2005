
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("���¾Ŷ�  "+YEL"ͽ��֮��"NOR, ({ "ding" }) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", CYN"Զ��ʱ�������վ���֮�����ɾŶ���ÿһ�ڶ������˾���֮��\n��ɽ��ͼ�Σ����ھ��ݸ����Ա�������ҵ��\n\n"NOR               +YEL"                       ͽ��֮��\n\n"NOR+CYN"����������ÿһ������һͽ�͡�ͽ���������ӣ�������������ϲŭ��\n���Ͽ��С�����֮���ݡ������׭���֡�\n"NOR);
		set("value", 1);
	}
        ::init_item();
}


