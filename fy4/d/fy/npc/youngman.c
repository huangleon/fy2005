inherit NPC;
int random_action();
void create()
{
        set_name("������", ({ "young man","man" }) );
        set("gender", "����" );
        set("age", random(5)+15);
        set("long", "һ������������ˣ��������һ��˵Ľ��١�\n");
	set("per",30);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 20);
      	set("chat_chance", 1);
        set("chat_msg", ({
                (: random_action :)
        }) );

	setup();
        carry_object("/obj/armor/cloth")->wear();
   
}

int random_action()
{
	switch(random(5)){
	case 0:
		command("smile");
		break;
	case 1:
		command("laugh");
		break;
	case 2:
		command("crazy");
		break;
		}
	return 1;
}
