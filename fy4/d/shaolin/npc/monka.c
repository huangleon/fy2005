inherit NPC;
void smart_fight();

void create()
{
        string *name = ({"����","�λ�","��ʧ","�ζ�","����","�ζ�","����",
"�γ�","�ο�","��԰", "����"});
        
        set_name("����", ({ "meng yi", "shaolin monk", "monk"}));
        
        create_family("������", 20, "����");
        set("class","shaolin");
        set("gender", "����" );
        set("age",random(20)+ 32);
		set("nickname","��ɮ");
        set("long", "���������µĹ�ɮ��\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 40000);
        set("attitude", "friendly");
		
		set("cps",80);
        set_skill("staff", 40+random(100));
		set_skill("xingyi-stick",random(100)+20);
		set_skill("move",400);
		set_skill("force",200);
		set_skill("parry",40);
		
		map_skill("staff", "xingyi-stick");
		map_skill("parry","xingyi-stick");
		
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );

		setup();
		carry_object(__DIR__"obj/monk23_cloth")->wear();
		carry_object(__DIR__"obj/stick")->wield();
}

void smart_fight()
{
	object *inv, ob;
	int i,j;
	j = 0;
	
	ob = this_object();
	ob->dismiss_team();
	
	inv = all_inventory(environment());

	for(i=0 ;i < sizeof(inv);i++) {
		if (j>=7)	break;
		if(inv[i]->query("stickguy") && inv[i]!= ob && inv[i]->query_temp("weapon"))
		{
			j++;	
			if (j<=7 ) ob->add_team_member(inv[i]);
		}
	}

	ob->ccommand("team name �˹�ɮ");
	ccommand("say teamed");
	perform_action("staff.powerjam");
	return;
}
