#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("÷��ѩ", ({ "mei yinxue","mei" }) );
        set("gender", "Ů��" );
        set("title", "��ȸ����" );
        set("nickname", WHT"��������������ȸ���Կ�����"NOR );
        set("long",
		"�������������;��������գ������÷��ѩ�������������˵���������������һϮ����������\nһ�����׵ĳ�������紵�������۷��裬����������ҲҪ����ȥ��Ȼ����һ˫���ĵ��۾���\nȴ�����ޱߵĴ�һ��ᶨ��տ��������˭���뵽������һ��������Ů�ӣ�ʮ��ǰȴ��������\nΪһ����Ѫ����а��Ļ�ˮ������˭���뵽�����ഺ�ĺ��գ������ѹ����ػ�֮�䡣\n"
                );
        set("attitude", "peaceful");
		set("class","huashan");
		set("age", 22);
        set("per", 190);
        set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"÷��ѩ���ɺ��紵�ҳ������૵��� ƽ�������������������۵����ģ������ǣ��Ҷ�Ҫ�ҵ��㡣��\n",
		"÷��ѩ��Ȼ����ֻҪ�ܺ�����һ�𣬼�ʹ������ΰ��ҿ�����������������ʹ�������ֳ�\n��ֻҪ�ܺ�����һ��������һ������ʲô�ء�����\n",
		"÷��ѩ�ճյ����ź��ߣ���������ƽ��ƽ������ʹ��һ���������˷��ޣ������±��ӣ����±��ӣ�\n�������������������������������롣\n",
		}) );

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","diesword",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
        if (!random(10)) carry_object(BOOKS"sword_75");
}

