#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ɽʯ", ({ "stone" , "��ɽʯ"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep", "behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ɽʯ��֪���ж��¶�������Լ�������˸ߡ�ʯͷ�ı�������ʯ̦����ϡ\n" +
		"�ɱ� ����Դ�塱 �������֡���ϸ�����滹�м���С�֡�\n\n"
		YEL"  ��Դ�����ȴ���Զ�ܱ���֮�ء��������ǰ�����ҵ�����к�ƽ��\n"NOR
		YEL"  ����Ľ�����Թһ��˵أ���Ӧȫ�����������ж����������Դ\n"NOR
		YEL"  ����������Դ�������꣬���޷������ꡣ���ǰ�����Ȼ��ԭ��\n"NOR
		YEL"  ���и�����ʿ����ά����������ƽ��\n\n"NOR
		YEL"  ����Դ�����߽�������׷ɱ��Īν��֮��ԥ��\n\n"NOR
		);
		set("long_night", "ɽʯ��֪���ж��¶�������Լ�������˸ߡ�ʯͷ�ı�������ʯ̦����ϡ\n" +
		"�ɱ� ����Դ�塱 �������֡�\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
