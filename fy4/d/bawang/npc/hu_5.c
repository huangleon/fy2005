inherit NPC;
#include <ansi.h>

void create()
{
    set_name("������", ({ "hu laowu", "hu","laowu" }) );
	set("gender", "����" );
        set("nickname", HIB "����"NOR);
	set("age", 50);
	set("per", 30);
	set("class","wolfmount");
	set("attitude","friendly");
	set("long",
		"˫��һ��һ�ͣ�˫��һ��һ�̡�����ȥ�ǲ���һ������������һ˫��\n��������۾���͸�Ż��������ϣ�ǫ�ͣ��ͼ�������顣\n"
		);
	
	set("cor",200);
	set("combat_exp", 2000000);
	set("score", 1000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
   set_skill("xinyue-dagger", 111);
	set_skill("parry", 150);
	set_skill("dodge", 100);
	set_skill("dagger", 100);
	set_skill("dragonstrike",150);
	set_skill("xueyeqianzong",160);
        
      	
	map_skill("unarmed","dragonstrike");
	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","xueyeqianzong");
	map_skill("parry","xinyue-dagger");
	
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
     		(: perform_action, "dagger.douzhuanxingyi" :),
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
}
