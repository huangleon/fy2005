#include <ansi.h>

inherit NPC;
void create()
{
        set_name("˾��С��", ({ "sima"}) );
        set_temp("condition_type",RED"< ����һϢ >"NOR);
        set("gender", "����");
        set("age", 12);
        set("long",	"
һ��ʮ�������С��������¶���������䲻����ϵĳ��졣
���������������ϣ�����Խ������(Loose)
�����ؿڲ���һ�Ѽ⵶���Ѿ�����һϢ�ˡ�\n"
	);
		set("inquiry",	([
			"*":	"actionС����Ϣ���٣�˵����ʲô�����ˡ�\n",
			]));
		
		set("combat_exp",3000);
		set("loose",0);
        set("NO_KILL","��ô������С��������ô���ɱ��\n");
        setup();
		carry_object("/obj/armor/cloth")->wear();
}


		