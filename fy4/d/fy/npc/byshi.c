// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("����ʹ", ({ "baiyun emissary", "emissary" }) );
        set("nickname", HIC"�ν�����"NOR);
        set("gender", "����" );
        set("class","baiyun");
        set("long","
����ʹ���ǰ��Ƴ�������һָ�Ľܳ�һ��������ǲ��������������û��ʵս
�����������Զ�����Ϊ�����ĸ��ֵġ�\n"
	);
	
        set("age", 24);
        set("per", 40);
        set("attitude","friendly");
        
        create_family("���Ƴ�",3, "��ʹ");
	set("rank_nogen",1);
    	set("ranks",({"��ʹ","��ʹ","��ʹ","��ʹ","��ʿ",CYN"��ʹ"NOR,CYN"��ʦ"NOR,HIC"��ʦ"NOR}));
        
        set("combat_exp", 3000000);
        
        set("score", 20000);
    	set("reward_npc", 1);
	set("difficulty", 5);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ʹ΢΢һЦ�����ֵ����롣\n",
        }) );
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
        
        set_skill("move", 150);
        set_skill("daode",150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
        set_skill("sword", 150);
        set_skill("unarmed",150);
        set_skill("music",150);
        
        set_skill("feixian-steps",150);
        set_skill("feixian-sword",150);
        set_skill("calligraphy",150);
        set_skill("chessism",150);
        set_skill("magic",150);
        set_skill("painting",150);
        
        map_skill("magic","music");
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "chessism");
        map_skill("parry", "feixian-sword");

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();

}

void attempt_apprentice(object ob)
{
      	message_vision(CYN"����ʹ����Ц�������������ƶ����Ϊ���µ�һ���ɣ�\n"NOR, ob);
}

