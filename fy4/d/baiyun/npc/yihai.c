#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("ɮ�庣", ({ "monk yihai","yihai" }) );
        set("gender", "����" );
        set("class", "shaolin");
        set("nickname",WHT"��ɮ"NOR);
        set("age", 32);
        set("long", "ɮ�庣Ϊ��ʱ������һ����ɮ�������е����ŵ��ӡ���Խ�ݷ���ɽѧ�٣���ʮ�겻��ɽ��\n
��ҹ�ֲ����ң��������Ҷ�³����Ե��ŷ�����������Ƶ���������ի��\n");
        set("combat_exp", 900000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "ɮ�庣̾�˿������૵���Сɮ��Զ�������˰��Ƶ����������ɴ������Ĺ���ḧ������ɢ��\n
������������������أ�ȴδ��ı��һ�档����������\n",
        "ɮ�庣�ճյ�������˭����ƶɮ����һ������ɢ��Сɮ��Ը��ƽ������������������\n",
	}) );
        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",100,120,0,"/obj/weapon/","fighter_w","feixian-sword",1);
		setup();
        carry_object(__DIR__"obj/sengyi")->wear();
		carry_object(__DIR__"obj/sinny1");
}
int accept_fight(object me)
{
        command("say �������գ�Сɮ��ͨ�����ʩ������Ц��\n");
        return 0;
}
