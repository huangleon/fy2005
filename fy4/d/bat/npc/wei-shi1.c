
#include <ansi.h>

inherit NPC;

void create()
{
    set_name("������ʿ", ({ "wu shi" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
"
����λ���𵺵�����ǰ������ʿ�������ּף���ִ������˫Ŀ���⾼����
�����Ѳ�������ܵ����Ρ�
\n"
    );
       	set("combat_exp", 2500000);
	set("attitude", "heroism");
	set("class","huashan");
	
	set_skill("sword", 200);
	set_skill("move", 200);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("force",100);
	set_skill("hanmei-force",150);
	set_skill("qingfeng-sword",180);
	set_skill("anxiang-steps",200);
	
	map_skill("force","hanmei-force");
	map_skill("dodge","anxiang-steps");
	map_skill("sword","qingfeng-sword");
	map_skill("parry","qingfeng-sword");

	setup();

        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/armor_steel")->wear();
}

