#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ͯ��", ({ "jinyi tongzi","tongzi" }) );
        set("long","������ĸ�����ͯ��������ֻ��ʮ����������ӣ�ü��Ŀ�㣬��������ϲ����\n");
	
	set("title", "�Ҹ�");
        set("attitude", "friendly");
        set("class", "assassin");
        
        set("age",15);
        set("agi", 10);
        set("combat_exp", 1500000);

	set("inquiry", ([
                "���³���":	"���³������ҵ�����Ү��\n",
                "di qinglin" : 	"��С��ү��\n",
                "������" : 	"��С��ү��\n",
                "��С��ү":	"��ϧС��ү�������Ү��\n",
                "��������":	"��ϧС��ү�������Ү��\n",
        ]));
        
	set_skill("sword",200);
	set_skill("sharen-sword",180);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("lefthand-sword",200);
	set_skill("jinhong-steps",200);
	set_skill("unarmed",200);
	set_skill("flame-strike",180);
		
	map_skill("unarmed","flame-strike");
	map_skill("dodge","jinhong-steps");
	map_skill("parry","lefthand-sword");
	map_skill("sword","sharen-sword");

	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"sword.sharenruma"  :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    					"name":  "����",
    					 ]))->wear();
}
