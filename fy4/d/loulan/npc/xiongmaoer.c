#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("��è��", ({ "xiong maoer","maoer" }) );
        set("gender", "����" );
        set("title", HIR"������һ������"NOR );
        set("long",
        "ֻ���������˳ߣ�Ũü���ۣ�����б���ű����ʶ̵�����������
ֻ�����ľ��ƾƺ���һ��߸裬һ��ʹ����\n"
                );
        set("attitude", "peaceful");
		set("class", "npc");
		
		set("perform_busy_d", "npc/dodge/shenji-steps/shenjimiaosuan");
		set("perform_weapon_attack","npc/blade/shenji-blade/jichulianhuan");	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
		set("age", 25);
        
        set("combat_exp", 800000);
        
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��è�������߸裺ǧ����������飬�����ԹŶ�Ӣ�ۣ��ҰѺ��г���ƣ�Ƽˮ����һЦ�ꡣ\n",
        "��è������������"YEL"����"NOR"�����ˣ��㵽���������\n",
        "��è�������ƾƺ������ع��˼���˵���д�"YEL"����"NOR"������ʲô���䲻������\n",
		}) );
        set("inquiry",  ([
                "����" : "�������˰����ˣ����Ƿ񻹻����˼䣿\n",
                "������" : "�������֪����Ѿͷ����Ϣô������������ô��\n",
                "������" : "�������ô����������ħ�ǣ���\n",
                "�����" : "����������˾���˭��Ц������أ�\n",
                "����":		"����ƺ����洫֮�����������¸������ơ�\n"
                ]));

        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("shenji-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("shenji-steps", 100);
        set_skill("dragonstrike",120);
        
        map_skill("unarmed","dragonstrike");
        map_skill("dodge", "shenji-steps");
        map_skill("blade", "shenji-blade");
        map_skill("parry", "shenji-blade");
                
        setup();
        carry_object("/obj/weapon/blade_l")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/winepot");
}


