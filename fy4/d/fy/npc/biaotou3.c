
inherit NPC;

void create()
{
        set_name("˾����ʦ", ({ "biaotou sima","biaotou"}) );
        set("gender", "����" );
        set("age", 42);
		set("class","beggar");
		
		set("long", "����һλ��ʨ�ھֵ���ʦ��\n");
        set("combat_exp", 2800000);
        set("attitude", "friendly");
                
        set_skill("unarmed", 200);
        set_skill("dragonstrike",170);
		set_skill("dodge", 150);
		set_skill("move",200);
		set_skill("parry",170);
		set_skill("puti-steps",200);
	
		map_skill("dodge","puti-steps");
		map_skill("unarmed","dragonstrike");
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "˾����ʦ���˸���Ƿ˵����˯���ˡ�\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(2))
	carry_object(__DIR__"obj/hongbao");

}

